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
	if (Reldate > Expdate) {
		system("cls");
		throw std::exception("Release date cannot be later than expiring date!");
	}
	if (Weight > 500 || Weight < 1) {
		system("cls");
		throw std::exception("Weight of ketchup cannot be less than 1g or more than 500g!");
	}
	if (Kcal > 560 || Kcal < 1) {
		system("cls");
		throw std::exception("Kcal of ketchup cannot be less than 1 or more than 560!");
	}
	if (Fatcont > 7 || Fatcont < 0) {
		system("cls");
		throw std::exception("Fat content of ketchup cannot be less than 0% or more than 7%!");
	}
	if (price < 0 || price == 0) {
		system("cls");
		throw std::exception("Price of ketchup cannot be less or equal 0 UAH!");
	}
}

std::string Ketchup::Info() const {
	std::ostringstream out;
	out << "Name: " << name << "\n" << "Type: Ketchup" << "\n" << "Release date: " << release_date << "\n" << "Expiring date: " << expiring_date << "\n" << "Weight: " << weight << "g\n"
		<< kcal << " kcal\n" << "Package type: " << package_type << "\n" << "Fat content: " << fat_content << "%\n" << "Price: " << price << " UAH\n";
	return out.str();
}