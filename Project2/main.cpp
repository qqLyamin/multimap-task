#include <iostream>
#include "Dictionary.h"
#include "NotFoundException.h"

int main()
{
	Dictionary ()
	try
	{

	}
	catch (const NotFoundException & ex)
	{
		std::cout << ex.what() << std::endl; //как-то так наверно это выглядит
	}
}