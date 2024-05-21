#include <iostream>

void test1();
void test2();
void test3();
void test4();


int main() {
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}

void test1() {
    unsigned u = 10;
    int i = -42;
    std::cout << i + i << std::endl;
    std::cout << u + i << std::endl;
    // 这个地方i会被转化成无符号的整数和u相加 所以结果是4294967264
}
void test2() {
    int units1 = 0;
    int units2 = {0};
    int units3(0);
    int units4{0};
    int units5(1.52);//使用（）可以对数据类型不一样的数据进行初始化，但是会数据丢失
    //int units6{1.52};//使用{}没法对数据类型不一样的数据进行初始化
    std::cout << units1 << units2 << units3 << units4 << units5 << std::endl;
}

void test3() {
    //引用练习
    int i, &ri = i;
    i = 7; 
    ri = 10;
    std::cout << i << " " << ri << std::endl;
}


void test4() {
    //指针练习
    int ival = 42;
    int *p = &ival;
    std::cout << *p << std::endl;

    int *p1 = nullptr;
    //指针的初始化
}