#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *newBornZombie;
	newBornZombie = new Zombie;
	newBornZombie->set_name(name);
	return (newBornZombie);
}