#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

Base* generate(void)
{
	int random = rand() % 3;
	switch(random)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C" << std::endl;
	else
		std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a_ref = dynamic_cast<A&>(p);
		(void)a_ref; // Évite l'avertissement de variable inutilisée
		std::cout << "Type is A" << std::endl;
	}
	catch (std::bad_cast&)
	{
		try
		{
			B& b_ref = dynamic_cast<B&>(p);
			(void)b_ref;
			std::cout << "Type is B" << std::endl;
		}
		catch (std::bad_cast&)
		{
			try
			{
				C& c_ref = dynamic_cast<C&>(p);
				(void)c_ref;
				std::cout << "Type is C" << std::endl;
			}
			catch (std::bad_cast&)
			{
				std::cout << "Unknown Type" << std::endl;
			}
		}
	}
}
