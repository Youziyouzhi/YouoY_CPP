#include <iostream>
#include <string>
#include <vector>

class Screen {
 public:
  typedef std::string::size_type pos;  // 定义类型成员
  // using pos = std::string::size_type;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  char get() const {
    return contents[cursor];
  }  // 读取光标内容，因为是类内定义所以是内联的
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);  // 能在之后被设为内联
  Screen &set(char);
  Screen &set(pos, pos, char);
  pos size() const;
  void some_member() const; 
  Screen &display(std::ostream &os) 
                  {do_display(os); return *this;}
  const Screen &display(std::ostream &os) const
                  {do_display(os); return *this;}
  friend class Window_mgr;//Window_mgr的成员可以访问Screen类的私有部分
 private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  mutable size_t access_ctr; //可变数据成员，任何成员函数包括const函数也能改变它的值
  void do_display(std::ostream &os) const { os << contents;}
};

//*******************注意：内联最好只在类外定义的地方说明inline*************************
inline //在类外函数定义处指定内联
Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

char Screen::get(pos r, pos c) const {
  pos row = r * width; //计算行的位置
  return contents[row + c];
}

inline Screen &Screen::set(char c) {
  contents[cursor] = c; //设置当前光标所在位置的新值
  return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
  contents[r * width + col] = ch;
  return *this; //将this对象作为左值返回
}

void Screen::some_member() const {
  ++access_ctr; // 保存一个计数值，用于记录成员函数被调用的次数
}

Screen::pos Screen::size() const {
  return height * width;
}

//**********************************************************************

class Window_mgr {
public:
  using ScreenIndex = std::string::size_type;
  void clear(ScreenIndex);
private:
  //这个class追踪Screen
  //默认情况下，这个Window_mgr包含一个标准尺寸的空白Screen
  std::vector<Screen> screens{Screen(24, 80, ' ')};

};
void Window_mgr::clear(ScreenIndex i) {
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width,' ');
}

void test1();

int main() { 
  test1();
  return 0; 
}

void test1() {
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(std::cout);
  std::cout << "\n";
  myScreen.display(std::cout);
  std::cout << "\n";
}