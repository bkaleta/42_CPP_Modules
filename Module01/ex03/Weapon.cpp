#include "Weapon.cpp"

Weapon::Weapon(void) : type("Unknown")
{
	std::cout << "Weapon with default type: Unknown created" << std::endl;
}
Weapon::Weapon(const std::string &initWep) : type(initWep)
{
	std::cout << "Weapon created with type: " << type << std::endl;
}
Weapon::~Weapon()
{
	std::cout << "Weapon of type " << type << " destroyed" << std::endl;

}
const	std::string &getType() const;
{
	return type;
}
void	setType(const std::string &newType)
{
	type = newType;
	std::cout << "Weapon set to: " << type << std::endl;
}