#pragma once
#include "Food_goods.h"
class Yogurt : public Food_goods
{
public:
	Yogurt();
	void SetYogKcal(int YogKcal) { kcal = YogKcal; }
	void SetYogExpDate(boost::gregorian::date YogExpDate) { expiring_date = YogExpDate; }
	void SetYogFilling(std::string yog_filling) { filling = yog_filling; }
	void SetYogFatConent(int YogFatContent) { fat_content = YogFatContent; }
	std::string Info() const override;
private:
	std::string filling;
	int fat_content;
};
