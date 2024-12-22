#include "loser.hpp"

int main(int ac, char **av)
{
	std::string	original_file;
	std::string	copied_file;
	std::string	s1;
	std::string	s2;

	if (ac != 4)
		return (0);
	original_file 	= av[1];
	copied_file 	= "modified.txt";
	s1 				= av[2];
	s2 				= av[3];
	
	replaceAndWrite(original_file, copied_file, s1, s2);

    std::cout << "Original File before changes: " << original_file << std::endl;
    std::cout << "Finished processing the file. Check " << copied_file << " for results." << std::endl;
    return (0);
}