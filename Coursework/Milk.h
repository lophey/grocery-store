#pragma once
#include "Food_goods.h"
class Milk : public Food_goods
{
public:
	Milk();
	void SetMilkKcal(int MilkKcal) { kcal = MilkKcal; }
	void SetMilkExpDate(boost::gregorian::date MilkExpDate) { expiring_date = MilkExpDate; }
	void SetMilkPackageType(std::string pack_type) { package_type = pack_type; }
	void SetMilkFatConent(int MilkFatContent) { fat_content = MilkFatContent; }
	std::string Info() const override;
private:
	std::string package_type;
	int fat_content;
};

