
#include <iostream>
#include "String.h"




void Print() {
	gbLib::String name = "Gabriel";
	gbLib::String name1 = "Jose";
	name = "Maria";
	gbLib::String name2 = name + name1;
	std::cout << name2 << "\n";
	name.Reverse();
	std::cout << name << "\n";

}


int main()
{


	Print();



	std::cout << "F\n";
}

