#pragma once
#include "Food_goods.h"
class Ketchup : public Food_goods
{
public:
	Ketchup();
	Ketchup(std::string Name, boost::gregorian::date Reldate, boost::gregorian::date Expdate, int Weight, int Kcal, std::string Packagetype, int Fatcont, int Price);
	//void SetKetchupKcal(int KetchupKcal) { kcal = KetchupKcal; }
	//void SetKetchupExpDate(boost::gregorian::date KetchupExpDate) { expiring_date = KetchupExpDate; }
	//void SetKetchupPackageType(std::string package_type) { package_type = package_type; }
	//void SetKetchupFatConent(int KetchupFatContent) { fat_content = KetchupFatContent; }
	std::string Info() const override;
private:
	std::string package_type;
	int fat_content;
};

