#include <iostream>
#include <string>
#include <vector>

struct Sales_data {

  std::string bookNo;
  unsigned unit_sold = 0;
  double revenue = 0.0;

  std::string isbn() const {return this->bookNo;}
  Sales_data& combine(const Sales_data&);
  double avg_price() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read()
Sales_data& Sales_data::combine(const Sales_data &rhs) {
  unit_sold += rhs.unit_sold;
  revenue += rhs.revenue;
  return *this;
}

void test1();

int main() {
  return 0;
}

void test1() {

}
std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.unit_sold >> price;
  item.revenue = price * item.unit_sold;
  return is;
}
std::ostream &print(std::ostream &os, Sales_data &item) {
  os << item.isbn() << " " << item.unit_sold << " " << item.revenue << " "
     << item.avg_price();
  return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}