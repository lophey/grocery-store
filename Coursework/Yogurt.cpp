#include "Yogurt.h"
Yogurt::Yogurt()
{
	filling = "none";
	fat_content = 0;
}

Yogurt::Yogurt(std::string Name, boost::gregorian::date Reldate, boost::gregorian::date Expdate, int Weight, int Kcal, std::string Yogfilling, int Fatcont, int Price) {
	name = Name;
	release_date = Reldate;
	expiring_date = Expdate;
	weight = Weight;
	kcal = Kcal;
	filling = Yogfilling;
	fat_content = Fatcont;
	price = Price;
}

std::string Yogurt::Info() const {
	std::ostringstream out;
	out << "Name: " << name << "\n" <<"Type: Yogurt" << "\n" << "Release date: " << release_date << "\n" << "Expiring date: " << expiring_date << "\n" << "Weight: " << weight << "g\n"
		<< kcal << " kcal\n" << "Filling: " << filling << "\n" << "Fat content: " << fat_content << "%\n" << "Price: " << price << " UAH\n";
	return out.str();
}

