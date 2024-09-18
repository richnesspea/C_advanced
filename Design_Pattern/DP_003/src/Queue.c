#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


/* Khởi tạo Queue */
void Queue_Init(Queue* const me,                            //Con trỏ me không thể bị thay đổi nhưng dữ liệu mà nó trỏ tới có thể thay đổi
    int (*isFullfunction)(Queue* const me),                 //Tham số này thể hiện muốn truyền vào hàm -> cần sử dụng function pointer
    int (*isEmptyfunction)(Queue* const me),
    int (*getSizefunction)(Queue* const me),
    void (*insertfunction)(Queue* const me, int k),
    int (*removefunction)(Queue* const me)) 
{
    /* Khởi tạo các thuộc tính */
    me->head = 0;
    me->size = 0;
    me->tail = 0;

    /* Khởi tạo các con trỏ hàm */
    me->isFull = isFullfunction;
    me->isEmpty = isEmptyfunction;
    me->getSize = getSizefunction;
    me->insert = insertfunction;
    me->remove = removefunction;
}

/* Hàm dọn dẹp Queue */
void Queue_Cleanup(Queue* const me) {
    (void)me;
    // Chưa có xử lý dọn dẹp cụ thể, chỉ khai báo trống
}

/* Hàm kiểm tra đầy */
int Queue_isFull(Queue* const me) {
    return (me->head + 1) % QUEUE_SIZE == me->tail; //Comparing the positions of the head and tail pointers in a circular buffer
    //The queue is considered to be full when the next position of the head pointer is equal to the tail
    //This means that there is no space left to insert a new element without overwriting the element at the tail position.
}

/* Hàm kiểm tra rỗng */
int Queue_isEmpty(Queue* const me) {
    return (me->head == me->tail);
}

/* Hàm lấy kích thước hàng đợi */
int Queue_getSize(Queue* const me) {
    return me->size;
}

/* Hàm chèn phần tử */
void Queue_insert(Queue* const me, int k) {
    if (!me->isFull(me)) {
        me->buffer[me->head] = k;
        me->head = (me->head + 1) % QUEUE_SIZE;
        ++me->size;
    }
}

/* Hàm xóa phần tử */
int Queue_remove(Queue* const me) {
    int value = -9999; /* Giá trị sentinel */
    if (!me->isEmpty(me)) {
        value = me->buffer[me->tail];
        me->tail = (me->tail + 1) % QUEUE_SIZE;
        --me->size;  // Đã sửa dấu '-' cho chính xác
    }
    return value;
}

/* Hàm tạo Queue */
Queue* Queue_Create(void) {
    Queue* me = (Queue *) malloc(sizeof(Queue)); //me là con trỏ kiểu Queue, lưu trữ địa chỉ mà được cấp phát
    if (me != NULL) {
        Queue_Init(me, Queue_isFull, Queue_isEmpty, Queue_getSize, Queue_insert, Queue_remove);
    }
    return me;
}

/* Hàm hủy Queue */
void Queue_Destroy(Queue* const me) {
    if (me != NULL) {
        Queue_Cleanup(me);
        free(me);
    }
}
