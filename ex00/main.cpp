#include <iostream>
#include "Convert.hpp"


int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Program <Argument>\n";
		return (1);
	}

	try
	{
		Convert conv(argv[1]);
		conv.getLine();
		conv.showInfo();
	}	
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
