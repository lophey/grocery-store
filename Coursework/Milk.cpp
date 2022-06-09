#include "Milk.h"
Milk::Milk()
{
	package_type = "unknown";
	fat_content = 0;
}

Milk::Milk(std::string Name, boost::gregorian::date Reldate, boost::gregorian::date Expdate, int Weight, int Kcal, std::string Packagetype, int Fatcont, int Price) {
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
	if (Weight > 2500 || Weight < 1) {
		system("cls");
		throw std::exception("Weight of milk cannot be less than 1g or more than 2500g!");
	}
	if (Kcal > 1000 || Kcal < 1) {
		system("cls");
		throw std::exception("Kcal of milk cannot be less than 1 or more than 1000!");
	}
	if (Fatcont > 10 || Fatcont < 0) {
		system("cls");
		throw std::exception("Fat content of milk cannot be less than 0% or more than 10%!");
	}
	if (price < 0 || price == 0) {
		system("cls");
		throw std::exception("Price of milk cannot be less or equal 0 UAH!");
	}
}

std::string Milk::Info() const {
	std::ostringstream out;
	out << "Name: " << name << "\n" << "Type: Milk" << "\n" << "Release date: " << release_date << "\n" << "Expiring date: " << expiring_date << "\n" << "Weight: " << weight << "g\n"
		<< kcal << " kcal\n" << "Package type: " << package_type << "\n" << "Fat content: " << fat_content <<"%\n" << "Price: " << price << " UAH\n";
	return out.str();
}