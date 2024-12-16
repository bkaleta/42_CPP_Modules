#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string zombie_name;
public:
	Zombie();
	~Zombie();
	void	set_name(std::string name);
	void	announce();
};

Zombie* zombieHorde( int N, std::string name );

#endif