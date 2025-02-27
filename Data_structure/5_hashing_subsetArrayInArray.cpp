#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


void coutVector(std::vector<int>& v) {
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}



//x2 is subset array of x1
bool Is_Subset_Sorting_TwoPointer(std::vector<int> &x1, std::vector<int> &x2){
    //Sort 2 arrays
    sort(x1.begin(), x1.end());
    sort(x2.begin(), x2.end());
    //print 2 vectors after sorting
    //coutVector(x1);
    //coutVector(x2);

    int i = 0, j = 0;
    while(i < x1.size() && j < x2.size()){
        if(x1[i] == x2[j]){
            i++;
            j++;
        }
        else if(x1[i] <= x2[j]){
            i++;
        }
        else {
            return false;
        }
    }
    return (j == x2.size()); // if j < x2.size(): some elements in b are not found in x1
}

bool Is_Subset_Unordered_Set(std::vector<int> x1, std::vector<int> x2){
    std::unordered_set<int> hashSet(x1.begin(), x1.end());
    for(int i : x2){
        if(hashSet.find(i) == hashSet.end()){// if any elements in b is not found in hashSet, the function returns false immediately
            return false;
        }
    }
    return true;
}


int main(){
    std::vector<int> a = {4,1,2,5,3,6,7,8};
    std::vector<int> b = {3,2,1,4};
    std::vector<int> c = {11,9,10};
    // if(Is_Subset_Sorting_TwoPointer(a, b)){
    //     std::cout << "b is a subset of a" << std::endl;
    // }
    // else {
    //     std::cout << "b is not a subset of a" << std::endl;
    // }

    // if(Is_Subset_Sorting_TwoPointer(a, c)){
    //     std::cout << "c is a subset of a" << std::endl;
    // }
    // else {
    //     std::cout << "c is not a subset of a" << std::endl;
    // }
    if(Is_Subset_Unordered_Set(a, b)){
        std::cout << "b is a subset of a" << std::endl;
    }
    else {
        std::cout << "b is not a subset of a" << std::endl;
    }

    if(Is_Subset_Unordered_Set(a, c)){
        std::cout << "c is a subset of a" << std::endl;
    }
    else {
        std::cout << "c is not a subset of a" << std::endl;
    }
}