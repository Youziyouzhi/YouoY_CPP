#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void test1();
void test2();
void test3();

std::istream& T8(std::istream &is);
void readtext(const std::string &filename, std::vector<std::string> &res);

int main() {
  // test1();
  test2();
  return 0;
}


void test1() {
  T8(std::cin);
}

void test2() {
  std::vector<std::string> svec;
  const std::string filename = "test.txt";
  readtext(filename, svec);
  for (std::string  str : svec) {
    // std::cout << str << std::endl;
    std::istringstream iss(str);
    std::string leter;
    while (iss >> leter) {
      std::cout << leter << std::endl;
    }
  }
}


std::istream& T8(std::istream &is) {
  std::ios::iostate old_state;
  old_state = is.rdstate();
  std::string buffer;
  while (is >> buffer) {
    std::cout << buffer << std::endl;
  }
  is.setstate(old_state);
  return is;
}

void readtext(const std::string &filename, std::vector<std::string> &res) {
  std::ifstream input(filename);
  if (input) {
    std::string buf;
    while (getline(input,buf)) {
      res.push_back(buf);
    }
  }
}