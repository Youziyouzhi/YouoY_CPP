#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <initializer_list>

void test1();
void test2();
void test3();
void test4(const std::initializer_list<int>  &il);  
void test5();
void test6();
void test7();
void chage(int *p1, int *p2);
int func(int a, int b);
int add(int a, int b);
int subtrace(int a, int b);
bool isShorter(const std::string &s1, const std::string &s2);
std::string::size_type find_char(const std::string &s1, char c,
                                 std::string::size_type &occurs);
void reset(int (*x)[5]);
const std::string &shortstring(const std::string &s1,
                                const std::string &s2);
std::string &shortstring(std::string &s1, 
                          std::string &s2);
bool lengthCompare(const std::string&, const std::string&);

int main(int argc, char *argv[]) {
  // test1();
  // test2();
  // test3();
  // std::string s1 = argv[1];
  // std::string s2 = argv[2];
  // std::cout << s1+s2 << std::endl;
  // test4({1,23,4,5,6,7,8,9,4,5});
  // test5();
  // test6();
  test7();
  return 0;
}

void test1() {
  int n1 = 3, n2 = 5;
  std::cout << "n1 = " << n1 << " n2 = " << n2 << std::endl;
  chage(&n1, &n2);
  std::cout << "n1 = " << n1 << " n2 = " << n2 << std::endl;

  std::string s1 = "1234568797";
  std::string s2 = "fdsagdsagjiwoq";
  std::cout << isShorter(s1, s2) << std::endl;
}
void test2() {
  std::string n1 = "fdsjlncdjsoiefjodsfdsnkjgioq";
  std::string::size_type cnt;
  std::cout << find_char(n1,'s',cnt) << " " << cnt << std::endl;
}
void test3() {
  int vec[5][5];
  reset(vec);
  for (int i = 0; i < 5; ++i) {
    for (int j =0; j < 5; ++j) {
      std::cout << vec[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
void test4( const std::initializer_list<int>  &il) {
  for (int num : il) {
    ++num;
    std::cout << num << " ";
  }
  for (std::initializer_list<int>::iterator beg = il.begin(); beg != il.end(); ++beg) {
    // (*beg)++;
    std::cout << *beg << " ";
  }
  std::cout << std::endl;
}
void test5() {
  std::string s1 {"hello,word!"};
  std::string s2 {"hello,word!!!!"};
  std::cout << shortstring(s1, s2) << std::endl;
}
void test6() {
  bool (*pf)(const std::string&, const std::string&);
  pf = &lengthCompare;
  std::cout << pf("hello", "goodbye") << std::endl;
}
using MyType = std::function<int(int,int)>;
void test7() {
  int (*pf)(int, int);
  // pf = func;
  //std::cout << pf(2,2) << std::endl;
  // std::vector<MyType> v;
  std::vector<decltype(pf)> v;
  // std::vector<decltype(func)*> v;
  v.push_back(add);
  v.push_back(subtrace);
  for (auto f : v) {
    std::cout << f(2,2) << std::endl;
  }  
}
void chage(int *p1, int *p2) {
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}
bool isShorter(const std::string &s1, const std::string &s2) {
  return s1.size() < s2.size();
}

std::string::size_type find_char(const std::string &s1, char c,
                                 std::string::size_type &occurs) {
  std::string::size_type ret = s1.size();
  occurs = 0;
  for (decltype(ret) i = 0; i < s1.size() - 1; ++i) {
    if (s1[i] == c) {
      if (ret == s1.size()) {
        ret = i;
      }
      ++occurs;
    }
  }
  return ret;
}
void reset(int (*x)[5]) {
  //5是第二个数组的第二个元素
  for (int i = 0; i < 5; ++i) {
    for (int j =0; j < 5; ++j) {
      x[i][j] =j;
    }
  
  }
}
const std::string &shortstring(const std::string &s1, const std::string &s2) {
  return s1 < s2 ? s1 : s2;
}

std::string &shortstring(std::string &s1, std::string &s2) {
  auto &r = shortstring(const_cast<const std::string&>(s1), const_cast<const std::string&>(s2));
  std::cout << "const_cast<std::string&>" << std::endl;
  return const_cast<std::string&>(r); 
}

bool lengthCompare(const std::string &s1, const std::string &s2) {
  return (s1.size() < s2.size()) ? true : false;
}

int add(int a, int b) { return a + b;}
int subtrace(int a, int b) { return a - b;}