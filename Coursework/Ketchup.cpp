#include "Ketchup.h"
Ketchup::Ketchup()
{
	package_type = "unknown";
	fat_content = 0;
}

Ketchup::Ketchup(std::string Name, boost::gregorian::date Reldate, boost::gregorian::date Expdate, int Weight, int Kcal, std::string Packagetype, int Fatcont, int Price) {
	name = Name;
	release_date = Reldate;
	expiring_date = Expdate;
	weight = Weight;
	kcal = Kcal;
	package_type = Packagetype;
	fat_content = Fatcont;
	price = Price;
}

std::string Ketchup::Info() const {
	std::ostringstream out;
	out << "Name: " << name << "\n" << "Type: Ketchup" << "\n" << "Release date: " << release_date << "\n" << "Expiring date: " << expiring_date << "\n" << "Weight: " << weight << "g\n"
		<< kcal << " kcal\n" << "Package type: " << package_type << "\n" << "Fat content: " << fat_content << "%\n" << "Price: " << price << " UAH\n";
	return out.str();
}