#include <iostream>
#include "Dictionary.h"
#include "NotFoundException.h"
#include <string>

int main()
{
	myDictionary<int, std::string> m;
	m.Set(1, "boyz");
	m.Set(2, "girls");

	bool a = m.IsSet(3);

	try
	{
		std::string mystrget = m.Get(2);
		std::cout << mystrget << std::endl;
	}
	catch (const myNotFoundException<int> & ex)
	{
		std::cout << ex.GetKey() << std::endl; 
	}

	__asm nop

	try
	{
		std::string mystrget = m.Get(3);
		std::cout << mystrget << std::endl;
	}
	catch (const myNotFoundException<int> & ex)
	{
		std::cout << ex.GetKey() << std::endl;
	}

	__asm nop
}