#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &tref)	:	name(n), typeREF(tref)
{
}

HumanA::~HumanA()
{
}

void	HumanA::setName(std::string n)
{
	name = n;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << typeREF.getType() << std::endl;
}