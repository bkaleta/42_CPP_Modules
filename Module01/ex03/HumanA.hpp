#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"


class HumanA
{
private:
	std::string name;
	Weapon &typeREF;
public:
	HumanA(std::string n, Weapon &tref);
	~HumanA();
	void	setName(std::string n);
	void	attack();
};


#endif