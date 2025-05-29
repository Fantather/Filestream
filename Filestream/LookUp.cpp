#include "LookUp.h"
#include <fstream>
#include <string>

bool LookUp::saveToFile(std::ostream& os) const
{
	os << name_ << "\n"
		<< owner_ << "\n"
		<< number_ << "\n"
		<< adress_ << "\n"
		<< business_activity_ << "\n";

	return bool(os);
}

bool LookUp::loadFromFile(std::istream& is)
{
	// Read in local variables so that with an error not to spoil the object
	std::string name, owner, number, adress, activity;

	if (!getline(is, name) ||
		!getline(is, owner) ||
		!getline(is, number) ||
		!getline(is, adress) ||
		!getline(is, activity))

	{
		return false;
	}

	name_ = name;
	owner_ = owner;
	number_ = number;
	adress_ = adress;
	business_activity_ = activity;
	return true;
}
