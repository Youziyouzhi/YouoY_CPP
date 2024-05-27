#include <iostream>
#include <vector>
#include <string>

void test1();
void test2();
void test3();
void test4();

int main() {
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}

void test1() {
    std::vector<std::string> svec;

    std::vector<int> v1 (10); // 一共10个元素
    std::vector<int> v2 {10}; //一个元素10
    std::vector<int> v3 (10,1); //十个元素都是1
    std::vector<int> v4 {10,1};//两个元素10和1

    std::vector<int> v5;
    for(int i = 0; i < 100; i++) {
        v2.push_back(i);
    }

}
void test2() {
    int i;
    std::vector<int> vec;
    while(std::cin >> i) {
        vec.push_back(i);
    }
    //输入有误
    for(auto num: vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << vec.size() << std::endl;

}

void test3() {
    std::string tmp;
    std::vector<std::string> svec;
    while(std::cin >> tmp) {
        svec.push_back(tmp);
    }
    //输入有问题 
    for(auto str : svec) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    std::cout << svec.size() << std::endl;
}
void test4() {
    std::string tmp;
    std::vector<std::string> svec;
    while(std::cin >> tmp) {
        svec.push_back(tmp);
    }
    std::cout << std::endl;
    for(auto &str : svec) {
        for (auto &ch : str) {
            ch = std::toupper(ch);
        }
        std::cout << str << " ";
    }
    std::cout << std::endl;
    std::cout << svec.size() << std::endl;
}