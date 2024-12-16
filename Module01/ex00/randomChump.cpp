#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie	random_zombie;
	random_zombie.set_name(name);
	random_zombie.announce();
}