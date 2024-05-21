#include <iostream>

int main()
{
    int sum = 0, value = 0;
    while(std::cin >> value)
    //输入非value类型或者文件结束符Ctrl+d来退出while
        sum += value;
    std::cout << "Sum is:" << sum <<std::endl;
    return 0;
}