#pragma once
#include <boost/date_time.hpp>

class Goods {
public:
	int GetPrice() const { return price; }
	std::string GetName() const { return name; }
protected:
	Goods();
	int price;
	int weight;
	std::string name;
	boost::gregorian::date release_date;
	boost::gregorian::date curr_time = boost::gregorian::day_clock::local_day();
};
