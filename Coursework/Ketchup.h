#pragma once
#include "Food_goods.h"
class Ketchup : public Food_goods
{
public:
	Ketchup();
	Ketchup(std::string Name, boost::gregorian::date Reldate, boost::gregorian::date Expdate, int Weight, int Kcal, std::string Packagetype, int Fatcont, int Price);
	std::string Type() const override { return "Ketchup"; }
	std::string Info() const override;
private:
	std::string package_type;
	int fat_content;
};

