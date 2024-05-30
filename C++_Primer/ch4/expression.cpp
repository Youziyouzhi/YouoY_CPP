#include <iostream>
#include <vector>
#include <string>

void test1();
void test2();
void test3();
void test4();
void test5();

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}

void test1() {
    int i = 0;
    std::cout << i << " " << ++i << std::endl;
}
void test2() {
    const char *cp = "Hello Word!";
    while(true) {
        if(cp && *cp) {
            std::cout << *cp << std::endl;
            cp++;
        }
        else {
            break;
        }
    }

}
void test3() {
    std::vector<std::string>::iterator iter;
    std::vector<std::string> svec = {"fds", "fdsfsad", "fewtwda"};
    iter = svec.begin();
    std::cout << *iter++ <<std::endl; // OK
    //std::cout << (*iter)++ <<std::endl; // NON
    //std::cout << *iter.empty() <<std::endl; // NON
    std::cout << iter->empty() <<std::endl; // OK
    //std::cout << ++*iter <<std::endl; //NON
    std::cout << iter++->empty() <<std::endl; //OK

    std::cout << ((5<60) ? "true":"false");
}

void test4() {
    int grade;
    std::cin >> grade;
    std::cout << ((grade > 90) ? "high pass":((grade > 60) ? ((grade <= 75) ? "low pass" : "pass") : "fail")) << std::endl;
}

void test5() {
    std::cout << sizeof(char) << " " << sizeof(short) << " "  << sizeof(int) << " "  << sizeof(float) << " "  
                << sizeof(double) << " " << sizeof(long) << std::endl;
}