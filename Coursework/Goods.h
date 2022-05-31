#pragma once
//#include "Date.h"
#include <boost/date_time.hpp>

class Goods {
public:
	void SetName(std::string Name) { name = Name; }
	void SetWeight(int Weight) { weight = Weight; }
	void SetReleaseDate(boost::gregorian::date rel_d) { release_date = rel_d; }
	void SetPrice(int Price) { price = Price; }
protected:
	Goods();
	std::string name;
	int weight;
	boost::gregorian::date release_date;
	int price;
};
