#include "Zombie.hpp"

int	main()
{
	Zombie *horde;
	int		N = 10, i = 0;

	horde = zombieHorde(N, "Legion");
	if (horde)
	{
		while (i < N)
		{
			horde[i].announce();
			i++;
		}
		delete [] horde;
	}
	return (0);
}