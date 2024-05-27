#include <iostream>
#include <string>

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main() {
//     std::string s1;
//     std::string s2 = s1;
//     std::string s3 = "hey";//拷贝初始化
//     std::string s4(10,'c');

//     std::string s5("hey");//直接初始化

//     std::cout << s1 << " " << s2 << " " << s3 << " " << s4 << std::endl;
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
    return 0;
}
void test1() {
    // std::string s;
    // std::cin >> s;//只读取第一个空白符前的字符串，fdsafs fdasfsa fdasfsadfdas
    // std::cout << s << std::endl;//只会输出 fdsafs
    std::string word;
    while(std::cin >> word) {
        std::cout << word << std::endl;
    }
}
void test2() {
    std::string line;
    while(std::getline(std::cin, line)) { //读取一行代码，包括换行符但是写入line中会剔除换行符
        std::cout << line << std::endl;
    }
}
void test3() {
    std::string line;
    while(std::getline(std::cin, line)) {
        if(!line.empty()) {
            std::cout << "line :" << line << std::endl;
        }
    }
}
void test4() {
    std::string s("Hello Word !!!");
    decltype(s.size()) pucnt_cnt = 0;
    for (auto &c : s) {
        c = toupper(c);
        if(ispunct(c)) { //判断是否是标点符号
            pucnt_cnt++;
        }
    }
    std::cout << s << std::endl;
    std::cout << pucnt_cnt << std::endl;
}
void test5() {
    std::string s("some string");
    for(decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); index++) {
        s[index] = toupper(s[index]);
    }
    std::cout << s << std::endl;
}
void test6() {
    const std::string s("Keep out!");
    for(auto &c : s) {
         std::cout << c << std::endl;
         std::cout << typeid(c).name() << std::endl;

    }
    std::cout << typeid(s).name() << std::endl;
}