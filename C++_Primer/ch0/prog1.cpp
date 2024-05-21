#include <iostream>

int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0, v3 = 0;
	std::cin >> v1 >> v2;
	if(v1<v2)
		v3 = v1;
	else
		v3 = v2;
	while(v3<=v1 || v3<=v2)
	{
		std::cout << v3 << std::endl;
		++v3;
	}
	//std::cout << "The sum of " << v1 <<" and "<< v2 << " is " <<  v1 + v2 << std::endl;	
	return 0;	
	
}
