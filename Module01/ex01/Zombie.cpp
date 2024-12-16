#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << zombie_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	zombie_name = "";
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << zombie_name << " died!" << std::endl;
}

void Zombie::set_name(std::string name)
{
	zombie_name = name;
}