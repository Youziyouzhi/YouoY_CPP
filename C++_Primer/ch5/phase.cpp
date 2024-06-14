#include <exception>
#include <iostream>
#include <string>
#include <vector>

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
  // std::string s;
  // std::vector<std::string> svec;
  // while(std::cin >> s) {
  // 需要用到数据结构及算法知识
  // }
  std::pair<std::string, int> maxCharacter;
  int cnt = 1;
  for (std::string pre, cur; std::cin >> cur; pre = cur) {
    if (cur == pre) {
      ++cnt;
    } else {
      cnt = 1;
    }

    if (cnt > maxCharacter.second) {
      maxCharacter = {cur, cnt};
    }
  }
  std::cout << maxCharacter.first << " " << maxCharacter.second << std::endl;
}
void test2() {
  std::vector<int> vec1{0, 1, 3, 2};
  std::vector<int> vec2{0, 1, 1, 2, 3, 5, 8};
  std::vector<int>::size_type Size =
      (vec1.size() < vec2.size() ? vec1 : vec2).size();
  int i = 0;
  for (; vec1[i] == vec2[i]; ++i) {
  }
  std::cout << i << " " << Size << std::endl;
  // if(i==int(Size)){
  //     std::cout << "true" << std::endl;
  // }
  // else{
  //     std::cout << "false" << std::endl;
  // }
  std::cout << (i == int(Size) ? "true" : "false") << std::endl;
}
void test3() {
  do {
    std::string str1;
    std::string str2;
    std::cout << "输入两个字符串" << std::endl;
    std::cin >> str1 >> str2;
    std::cout << "短的是 " << (str1 < str2 ? str1 : str2) << std::endl;
  } while (1);
}
void test4() {
  std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (auto num : vec) {
    if (num % 2 != 0) {
      continue;
    }
    std::cout << num << " ";
  }
  std::cout << std::endl;
}
void test5() {
  int n1, n2;
  while (std::cin >> n1 >> n2) {
    // std::cout << n1 / (n2 == 0 ? (throw std::out_of_range("除数为0")) : n2)
    // << std::endl;
    try {
      if (n2 == 0) {
        throw std::runtime_error("除数为0");
      }
      std::cout << (double)n1 / n2;
    } catch (std::runtime_error err) {
      std::cout << err.what() << "\n 重新输入？ Y or N" << std::endl;
      char c;
      std::cin >> c;
      if (!std::cin || c == 'n' || c == 'N') {
        break;
      }
    }
  }
}