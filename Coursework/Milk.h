#pragma once
#include "Food_goods.h"
class Milk : public Food_goods
{
public:
	Milk();
	Milk(std::string Name, boost::gregorian::date Reldate, boost::gregorian::date Expdate, int Weight, int Kcal, std::string Packagetype, int Fatcont, int Price);
	//void SetMilkKcal(int MilkKcal) { kcal = MilkKcal; }
	//void SetMilkExpDate(boost::gregorian::date MilkExpDate) { expiring_date = MilkExpDate; }
	//void SetMilkPackageType(std::string pack_type) { package_type = pack_type; }
	//void SetMilkFatConent(int MilkFatContent) { fat_content = MilkFatContent; }
	std::string Info() const override;
private:
	std::string package_type;
	int fat_content;
};

