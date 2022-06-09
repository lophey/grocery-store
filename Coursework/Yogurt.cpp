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
	if (Reldate > Expdate) {
		system("cls");
		throw std::exception("Release date cannot be later than expiring date!");
	}
	if (Weight > 1000 || Weight < 1) {
		system("cls");
		throw std::exception("Weight of yogurt cannot be less than 1g or more than 1000g!");
	}
	if (Kcal > 1000 || Kcal < 1) {
		system("cls");
		throw std::exception("Kcal of yogurt cannot be less than 1 or more than 1000!");
	}
	if (Fatcont > 15 || Fatcont < 0) {
		system("cls");
		throw std::exception("Fat content of yogurt cannot be less than 0% or more than 15%!");
	}
	if (price < 0 || price == 0) {
		system("cls");
		throw std::exception("Price of yogurt cannot be less or equal 0 UAH!");
	}

}

std::string Yogurt::Info() const {
	std::ostringstream out;
	out << "Name: " << name << "\n" <<"Type: Yogurt" << "\n" << "Release date: " << release_date << "\n" << "Expiring date: " << expiring_date << "\n" << "Weight: " << weight << "g\n"
		<< kcal << " kcal\n" << "Filling: " << filling << "\n" << "Fat content: " << fat_content << "%\n" << "Price: " << price << " UAH\n";
	return out.str();
}

