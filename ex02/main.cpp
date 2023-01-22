
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main()
{
	srand(time(NULL));
	Base *p = generate();
	if (p == 0)
		return (1);

	std::cout << "identify Type from pointer : ";
	identify(p);
	std::cout << "identify Type from reference : ";
	identify(*p);

	delete p;
	return (0);
}


Base* generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		std::cout << "random selected: A\n";
		return (new A());
	case 1:
		std::cout << "random selected: B\n";
		return (new B());
	case 2:
		std::cout << "random selected: C\n";
		return (new C());
	default:
		std::cout << "Invalid Number selected\n";
		return 0;
	}
}

void	identify(Base *p)
{
	if (p == 0)
		return ;
	if (dynamic_cast<A*>(p))
		(dynamic_cast<A*>(p))->show();
	else if (dynamic_cast<B*>(p))
		(dynamic_cast<B*>(p))->show();
	else if (dynamic_cast<C*>(p))
		(dynamic_cast<C*>(p))->show();
	else
		std::cout << "unknow Type\n";
}

void	identify(Base& p)
{
	try
	{
		(dynamic_cast<A&>(p)).show();
	}
	catch(std::exception &e)
	{
		try
		{
			(dynamic_cast<B&>(p)).show();
		}
		catch (std::exception &e)
		{
			try
			{
				(dynamic_cast<C&>(p)).show();
			}
			catch(std::exception &e)
			{
				std::cout << "unkown Type!\n";
			}
		}
	}
}
