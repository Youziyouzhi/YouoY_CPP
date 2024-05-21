#include <iostream>

int main()
{
    int Currval = 0, val = 0;
    if(std::cin >> Currval)
    {
        int cnt = 1;
        while(std::cin >> val)
        {
            if(Currval == val)
                ++cnt;
            else{
                std::cout << Currval << " occurs " << cnt << " times " << std::endl;
                Currval = val;
                cnt = 1;
            }
        }
        std::cout << Currval << " occurs " << cnt << " times " << std::endl;
    }
    return 0;
}