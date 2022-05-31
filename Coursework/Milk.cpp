#include "Milk.h"
Milk::Milk()
{
	package_type = "unknown";
	fat_content = 0;
}

std::string Milk::Info() const {
	std::ostringstream out;
	out << "Name: " << name << std::endl << "Release date: " << release_date << std::endl << "Weight: " << weight << std::endl << kcal << " kcal"
		<< std::endl << "Package type: " << package_type << std::endl << "Fat content: " << fat_content << std::endl << "Expiring date: " << expiring_date;
	return out.str();
}