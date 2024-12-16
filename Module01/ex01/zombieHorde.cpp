#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *newHorde;
	int		i;
	if (N <= 0)
		return (nullptr);
	i = 0;
	newHorde = new Zombie[N];
	while (i < N)
	{
		newHorde[i].set_name(name);
		i++;
	}
	return (newHorde);
}