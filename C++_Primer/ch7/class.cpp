#include <iostream>
#include <string>

class Sales_data {
  friend Sales_data add(const Sales_data&, const Sales_data&);
  friend std::istream &read(std::istream&, Sales_data&);
  friend std::ostream &print(std::ostream&, const Sales_data&);
private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  inline double avg_price() const
    {return units_sold ? revenue/units_sold : 0;}
public:
  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p) :
              bookNo(s), units_sold(n), revenue(n * p) {}
  Sales_data(std::istream &);
  std::string isbn() const {return bookNo;}
  Sales_data& combine(const Sales_data &rhs);
};

Sales_data::Sales_data(std::istream &is) {
  read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);

std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.bookNo << " " << item.units_sold << " " << item.revenue << " "
     << item.avg_price();
  return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

void test1();

int main() {
  test1();
  return 0;
}

void test1() {
    Sales_data item1;
    print(std::cout, item1) << std::endl;
    
    Sales_data item2("0-201-78345-X");
    print(std::cout, item2) << std::endl;
    
    Sales_data item3("0-201-78345-X", 3, 20.00);
    print(std::cout, item3) << std::endl;
    
    Sales_data item4(std::cin);
    print(std::cout, item4) << std::endl;
    
}