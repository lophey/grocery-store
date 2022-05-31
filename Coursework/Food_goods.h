#pragma once
#include "Goods.h"

class Food_goods : public Goods
{
public:
	virtual std::string Info() const;
	std::string exp_date_checker() const;
protected:
	Food_goods();
	int kcal;
	boost::gregorian::date expiring_date;
	boost::gregorian::date curr_time = boost::gregorian::day_clock::local_day();
};

