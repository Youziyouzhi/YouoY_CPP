#include <iostream>
#include <string>
#include <utility>
#include <vector>

void test1();

int main() {
  test1();
  return 0;
}

void test1() {
  std::vector<char> chars = {'a','a','b','b','c','c','c'};
  std::vector<std::pair<int, char>> res;
  int cnt = 0;
  char pre = chars[0];
  int csize = chars.size();

  for (int i = 0; i <= csize; ++i) {
    if (pre == chars[i]) {
      ++cnt;
    } else {
      res.push_back(std::make_pair(cnt, pre));
      pre = chars[i];
      cnt = 1;
    }
  }
  // res.push_back(std::make_pair(cnt, pre));
  for (auto &p : res) {
    std::cout << p.second << " " << p.first << std::endl;
  }
  std::string sres;
  int vpsize = res.size();
  for (int i = 0; i < vpsize; ++i) {
    int num = res[i].first;
    // std::cout << num;
    sres += res[i].second;
    if (num >= 10) {
      sres += std::to_string(num / 10);
      sres += std::to_string(num % 10);
    } else {
      sres += std::to_string(num);
      std:: cout << sres << std::endl;
    }
  }
  std::cout << sres << std::endl;
}