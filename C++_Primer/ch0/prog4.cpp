#include<iostream>
#include "Sales_item.h"

int main()
{
    Sales_item Curritem, item;
    if(std::cin >> Curritem){
        while(std::cin >> item){
            if(Curritem.isbn()==item.isbn())
                Curritem += item;
            else{
                std::cout << Curritem.isbn() << " : " << Curritem <<std::endl;
                Curritem = item;
            }
        }
        std::cout << Curritem.isbn() << " : " << Curritem <<std::endl;
    }else{
        std::cerr << "No data ?!" <<std::endl;
        return -1;
    }
    return 0;
}