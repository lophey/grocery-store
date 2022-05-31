#include "Yogurt.h"
Yogurt::Yogurt()
{
	filling = "none";
	fat_content = 0;
}

std::string Yogurt::Info() const {
	std::ostringstream out;
	out << "Name: " << name << std::endl << "Release date: " << release_date << std::endl << "Weight: " << weight << std::endl << kcal << " kcal"
		<< std::endl << "Filling: " << filling << std::endl << "Fat content: " << fat_content << std::endl << "Expiring date: " << expiring_date;
	return out.str();
}