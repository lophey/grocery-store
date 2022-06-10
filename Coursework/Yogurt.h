#pragma once
#include "Food_goods.h"
class Yogurt : public Food_goods
{
public:
	Yogurt();
	Yogurt(std::string Name, boost::gregorian::date Reldate, boost::gregorian::date Expdate, int Weight, int Kcal, std::string Yogfilling, int Fatcont, int Price);
	std::string Type() const override { return "Yogurt"; }
	std::string Info() const override;
private:
	std::string filling;
	int fat_content;
};
