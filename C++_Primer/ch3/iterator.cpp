#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void test1();
void test2();
void test3();

int main() {
    // test1();
    // test2();
    test3();
    return 0;
}

void test1() {
    std::vector<int> vec;
    for(int i = 0 ; i < 10; ++i) {
        vec.push_back(i);
    }
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        *it = 2*(*it);
    }
    for(auto num : vec){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void test2() {
    //使用迭代器完成二分查找
    std::vector<int> vec{ 1, 4, 48, 45, 164, 134, 89, 46, 789, 456, 5465, 878};
    int sought = 1;
    std::sort(vec.begin(), vec.end());
    std::vector<int>::iterator beg = vec.begin();
    std::vector<int>::iterator end = vec.end();
    std::vector<int>::iterator mid = vec.begin() + (end - beg) / 2;
    // for(auto num : vec) {
    //     std::cout << num << std::endl;
    // }
    while(mid != end && *mid != sought) {

        if(sought < *mid) {
            end = mid;
            std::cout << *mid << std::endl;
        }
        else if(sought > *mid) {
            beg = mid + 1;
        }
        mid = beg + (end - beg) / 2;
    }

    if(*mid == sought) {
        std::cout << "找到sought,值为" << sought << std::endl;
    }
}
void test3() {
    int arr[5][5];
    for(int (*p)[5] = arr; p != arr + 5; ++p) {
        for (int *q= *p; q != *p + 5; ++q) {
            *q = 1;
        }
    }
    for(int (*p)[5] = arr; p != arr + 5; ++p) {
        for (int *q = *p; q != *p + 5; ++q) {
            std::cout << *q << " ";
        }
        std::cout << std::endl;
    }

}