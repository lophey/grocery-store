#pragma once
#include "Goods.h"
class Food_goods : public Goods
{
public:
	virtual std::string Info() const;
	boost::gregorian::date GetExpDate() const { return expiring_date; }
protected:
	Food_goods();
	int kcal;
	boost::gregorian::date expiring_date;
};