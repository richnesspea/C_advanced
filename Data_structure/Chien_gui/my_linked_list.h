#ifndef _singly_LINKED_LIST_H_
#define _singly_LINKED_LIST_H_

#include <stdint.h>
#include <stdlib.h>

template<class element_type>
struct singly_linked_list_node{
    element_type val;
    singly_linked_list_node* next;
    singly_linked_list_node() : next(NULL) { } //default constructor
    singly_linked_list_node(const element_type &_val, singly_linked_list_node *_next = NULL) {
        this->val = _val;
        this->next = _next;
    }
};

// template<class element_type>
// class linked_list_iterator {
// public:
//     singly_linked_list_node<element_type> *_node_ptr;
//     linked_list_iterator<element_type> *_iter_next;
//     linked_list_iterator() {
//         _node_ptr = new singly_linked_list_node<element_type>;
//         _iter_next = NULL;
//     }
//     linked_list_iterator(const element_type &_val) {
//         _node_ptr = new singly_linked_list_node<element_type>(_val);
//         _iter_next = NULL;
//     }
//     ~linked_list_iterator() {
//         delete _node_ptr;
//     }
//     element_type& operator* () {
//         return _node_ptr->val;
//     }
//     linked_list_iterator& operator++ () {
//         _node_ptr = _node_ptr->next;
//     }
// };

template<class element_type>
class singly_linked_list {
public:
    typedef singly_linked_list_node<element_type> node;
    node* reverse(node *_head) { //reverse using recursive approach
        if(_head == NULL || _head->next == NULL) return _head;
        node *ptr = _head->next;
        while(ptr->next != NULL) ptr = ptr->next;
        node *new_head = _head->next;
        ptr->next = _head;
        _head->next = NULL;
        new_head->next = reverse(new_head);
        return new_head;
    }
private:
    node* _head;
public:
    // Default constructor
    singly_linked_list();
    // Fill constructor: Create a list with n nodes, each containing val.
    singly_linked_list(size_t n, const element_type val = element_type());
    // Range constructor
    singly_linked_list(node* _first, node* _last);
    // Copy constructor
    singly_linked_list(singly_linked_list &lst);
    // Move constructor
    singly_linked_list(singly_linked_list &&lst);
    // Destructor
    ~singly_linked_list();
    // Assign new contents to the list with n elements initialized to a copy of val
    void assign(size_t n, const element_type &val = element_type());
    // Assign new contents to the list using range of nodes from other linked l;
    void assign(node* _first, node* _last);
    // Resize the list to contain n elements with initialized value eual to val
    void resize(size_t n, const element_type &val = element_type());
    // Check if the list is empty
    bool empty();
    // Return the number of elements in the list
    size_t size();
    // Return the maximum number of elements that the list can hold
    size_t max_size();
    // Return the pointer to the first node
    node* begin();
    // Return the pointer that points before the first element
    node* before_begin();
    // Return the pointer that points past the last element
    node* end();
    // Insert a new element initialized with val after the element at _pos, return the pointer to the new elements
    node* insert_after(node* _pos, const element_type &val);
    // Insert n new elements initialized with val after the element at _pos, return the pointer to the new elements
    node* insert_after(node* _pos, size_t n, const element_type &val);
    // Insert new elements from a range of other list after the element at _pos, return the pointer to the new elements
    node* insert_after(node* _pos, node* _first, node* _last);
    // Erase an element after the element at _pos, return the pointer to the next element
    node* erase_after(node* _pos);
    // Erase elements from the element at _pos to the element before _last, return the pointer to the next element
    node* erase_after(node* _pos, node* _last);
    // Remove all elements with the value of val
    void remove(const element_type &val);
    // Clear list contents
    void clear();
    // Remove duplicated content of the list
    void unique();
    // Sort the linked list using merge sort
    void sort();
    // Reverse the element of the list
    void reverse();
    // Swap the content with another list
    void swap(singly_linked_list &lst);

    singly_linked_list& operator= (singly_linked_list &lst);
    singly_linked_list& operator= (singly_linked_list &&lst);
private:
    node* merge(node *left_first, node *right_first) {
        if(left_first == NULL) return right_first;
        if(right_first == NULL) return left_first;

        if(left_first->val <= right_first->val) {
            left_first->next = merge(left_first->next, right_first);
            return left_first;
        }
        else {
            right_first->next = merge(left_first, right_first->next);
            return right_first;
        }
    }
    node* mergeSort(node *first) {
        if(first == NULL || first->next == NULL) return first;

        node *ptr = first, *mid = first;
        int pause = 0;
        while(ptr->next != NULL) {
            ptr = ptr->next;
            if(pause) mid = mid->next;
        }
        node *right_first = mid->next;
        mid->next = NULL;
        first = mergeSort(first);
        right_first = mergeSort(right_first);
        first = merge(first, right_first);
        return first;
    }
};

// Default constructor
template<class element_type>
singly_linked_list<element_type>::singly_linked_list(){
    this->_head = new node;
}
// Fill constructor
template<class element_type>
singly_linked_list<element_type>::singly_linked_list(size_t n, const element_type val) {
    this->_head = new node;//new node calls the default constructor node
    node* ptr = this->_head;
    while(n--) {
        node* tmp = new node(val);// assign val to tmp->val;
        ptr->next = tmp;//the previous node (pointed by ptr) now points to tmp
        ptr = tmp;//Move the pointer forward
    }
}

// Range constructor
template<class element_type>
singly_linked_list<element_type>::singly_linked_list(node* _first, node* _last) {
    this->_head = new node;
    node *ptr = this->_head;
    for(node* i=_first;i!=_last;i=i->next) {
        node *tmp = new node(i->val, i->next);
        ptr->next = tmp;
        ptr = ptr->next;
        if(ptr->next == NULL) break;
    }
}

// Copy constructor
template<class element_type>
singly_linked_list<element_type>::singly_linked_list(singly_linked_list &lst) {
    this->_head = new node;
    *this = lst;
}

// Move constructor
template<class element_type>
singly_linked_list<element_type>::singly_linked_list(singly_linked_list &&lst) {
    this->_head = new node;
    *this = std::move(lst);
}

// Destructor
template<class element_type>
singly_linked_list<element_type>::~singly_linked_list() {
    node *ptr = this->_head;
    while(ptr != NULL) {
        node *prev = ptr;
        ptr = ptr->next;
        prev->next = NULL;
        delete prev;
    }
}

// Assign new contents to the list with n elements initialized to a copy of val
template<class element_type>
void singly_linked_list<element_type>::assign(size_t n, const element_type &val) {
    node *ptr = this->_head->next;
    while(ptr != NULL) {
        node *prev = ptr;
        ptr = ptr->next;
        prev->next = NULL;
        delete prev;
    }
    this->_head->next = NULL;
    ptr = this->_head;
    while(n--) {
        node *new_node = new node(val);
        ptr->next = new_node;
        ptr = ptr->next;
    }
}

// Assign new contents to the list using range of nodes from other linked list
template<class element_type>
void singly_linked_list<element_type>::assign(node* _first, node* _last) {
    node *ptr = this->_head->next;
    while(ptr != NULL) {
        node *prev = ptr;
        ptr = ptr->next;
        prev->next = NULL;
        delete prev;
    }
    this->_head->next = NULL;

    ptr = this->_head;
    for(node* i=_first;i!=_last;i=i->next) {
        if(i == NULL) break;
        node *tmp = new node(i->val);
        ptr->next = tmp;
        ptr = ptr->next;
    }
}

template<class element_type>
void singly_linked_list<element_type>::resize(size_t n, const element_type &val) {
    size_t i = 0;
    node *ptr = this->begin();
    node *end = ptr;
    while(ptr != NULL) {
        i++;
        if(i == n) {
            node *erase_node = ptr->next;
            ptr->next = NULL;
            while(erase_node != NULL) {
                node *tmp = erase_node;
                erase_node = erase_node->next;
                tmp->next = NULL;
                delete tmp;
            }
            return;
        }
        end = ptr;
        ptr = ptr->next;
    }
    while(i < n) {
        node *new_node = new node(val);
        end->next = new_node;
        end = new_node;
        i++;
    }

}

// Check if the list is empty
template<class element_type>
bool singly_linked_list<element_type>::empty() {
    return this->_head->next == NULL;
}

// Return the number of elements in the list
template<class element_type>
size_t singly_linked_list<element_type>::size() {
    size_t i = 0;
    node *ptr = this->_head;
    while(ptr != NULL) {
        ptr = ptr->next;
        i++;
    }
    return i;
}

// Return the maximum number of elements that the list can hold
template<class element_type>
size_t singly_linked_list<element_type>::max_size() {
    return UINT64_MAX / sizeof(node);
}

// Return the pointer to the first node
template<class element_type>
typename singly_linked_list<element_type>::node* singly_linked_list<element_type>::begin() {
    return this->_head->next;
}

// Return the pointer that points before the first element
template<class element_type>
typename singly_linked_list<element_type>::node* singly_linked_list<element_type>::before_begin() {
    return this->_head;
}

// Return the pointer that points past the last element
template<class element_type>
typename singly_linked_list<element_type>::node* singly_linked_list<element_type>::end() {
    return NULL;
}

// Insert a new element initialized with val after the element at _pos, return the pointer to the new element
template<class element_type>
typename singly_linked_list<element_type>::node* singly_linked_list<element_type>::insert_after(node* _pos, const element_type &val) {
    node *ptr = this->_head;
    while(ptr != NULL) {
        if(ptr == _pos) {
            node *tmp = new node(val);
            tmp->next = ptr->next;
            ptr->next = tmp;
            return tmp;
        }
        ptr = ptr->next;
    }
    return NULL;
}

// Insert n new elements initialized with val after the element at _pos, return the pointer to the first new element
template<class element_type>
typename singly_linked_list<element_type>::node* singly_linked_list<element_type>::insert_after(node* _pos, size_t n, const element_type &val) {
    node *ptr = this->_head;
    while(ptr != NULL) {
        if(ptr == _pos) {
            while(n--) {
                node *tmp = new node(val);
                tmp->next = ptr->next;
                ptr->next = tmp;
                ptr = ptr->next;
            }
            return _pos->next;
        }
        ptr = ptr->next;
    }
    return NULL;
}

// Insert new elements from a range of other list after the element at _pos, return the pointer to the new elements
template<class element_type>
typename singly_linked_list<element_type>::node* singly_linked_list<element_type>::insert_after(node* _pos, node* _first, node* _last) {
    node *ptr = this->_head;
    while(ptr != NULL) {
        if(ptr == _pos) {
            for(node *i=_first;i!=_last;i=i->next) {
                if(i == NULL) return NULL;
                node *tmp = new node(i->val);
                tmp->next = ptr->next;
                ptr->next = tmp;
                ptr = ptr->next;
            }
            return _pos->next;
        }
        ptr = ptr->next;
    }
    return NULL;
}

// Erase an element after the element at _pos, return the pointer to the next element
template<class element_type>
typename singly_linked_list<element_type>::node* singly_linked_list<element_type>::erase_after(node* _pos) {
    node *ptr = this->_head;
    while(ptr != NULL) {
        if(ptr == _pos) {
            node *erase_node = ptr->next;
            if(erase_node == NULL) return NULL;
            ptr->next = ptr->next->next;
            erase_node->next = NULL;
            delete erase_node;
            return ptr->next;
        }
        ptr = ptr->next;
    }
    return NULL;
}

// Erase elements after the element at _pos to the element before _last, return the pointer to the next remain element (_last)
template<class element_type>
typename singly_linked_list<element_type>::node* singly_linked_list<element_type>::erase_after(node* _pos, node* _last) {
    node *ptr = this->_head;
    while(ptr != NULL) {
        if(ptr == _pos) {
            while(ptr->next != NULL) {
                if(ptr->next == _last) break;
                node *erase_node = ptr->next;
                ptr->next = ptr->next->next;
                erase_node->next = NULL;
                delete erase_node;
            }
            return ptr->next;
        }
        ptr = ptr->next;
    }
    return NULL;
}

// Remove all elements with the value of val
template<class element_type>
void singly_linked_list<element_type>::remove(const element_type &val) {
    node *ptr = this->_head;
    while(ptr != NULL && ptr->next != NULL) {
        if(ptr->next->val == val) {
            ptr = erase_after(ptr);
            continue;
        }
        ptr = ptr->next;
    }
}

// Clear list contents
template<class element_type>
void singly_linked_list<element_type>::clear() {
    node *ptr = this->begin();
    while(ptr != NULL) {
        node *prev = ptr;
        ptr = ptr->next;
        prev->next = NULL;
        delete prev;
    }
}

// Remove duplicated content of the list
template<class element_type>
void singly_linked_list<element_type>::unique() {
    node *ptr = this->begin();
    while(ptr != NULL && ptr->next != NULL) {
        for(node *i=this->begin();i!=ptr->next;i=i->next) {
            if(ptr->next->val == i->val) {
                ptr = erase_after(ptr);
                break;
            }
            else if(i == ptr) ptr = ptr->next;
        }
    }
}

// Sort the linked list using merge sort
template<class element_type>
void singly_linked_list<element_type>::sort() {
    node *new_begin = singly_linked_list<element_type>::mergeSort(this->begin());
    this->_head->next = new_begin;
}

// Reverse the element of the list
template<class element_type>
void singly_linked_list<element_type>::reverse() {
    node *ptr = this->begin();
    if(ptr == NULL || ptr->next == NULL) return;
    node *new_begin = ptr;
    while(ptr->next != NULL) {
        node *nxt = ptr->next;
        ptr->next = nxt->next;
        nxt->next = new_begin;

        new_begin = nxt;
    }
    this->_head->next = new_begin;
}

// Swap the content with another list
template<class element_type>
void singly_linked_list<element_type>::swap(singly_linked_list &lst) {
    singly_linked_list tmp = lst;
    lst = *this;
    *this = tmp;
}


template<class element_type>
singly_linked_list<element_type>& singly_linked_list<element_type>::operator= (singly_linked_list<element_type> &lst) {
    node *ptr_other = lst.begin(); 
    node *ptr_this = this->begin();
    // Delete the value of 
    while(ptr_this != NULL) {
        node *prev = ptr_this;
        ptr_this = ptr_this->next;
        prev->next = NULL;
        delete prev;
    }
    this->_head->next = NULL;

    ptr_this = this->before_begin();
    while(ptr_other != NULL) {
        node *new_node = new node(ptr_other->val);
        ptr_this->next = new_node;
        ptr_this = ptr_this->next;
        ptr_other = ptr_other->next;
    }
    return *this;
}

template<class element_type>
singly_linked_list<element_type>& singly_linked_list<element_type>::operator= (singly_linked_list<element_type> &&lst) {
    node *ptr_this = this->begin();
    while(ptr_this != NULL) {
        node *prev = ptr_this;
        ptr_this = ptr_this->next;
        prev->next = NULL;
        delete prev;
    }
    this->_head->next = NULL;

    ptr_this = this->_head;
    ptr_this->next = lst.begin();
    (lst._head)->next = NULL;
    return *this;
}


#endif
