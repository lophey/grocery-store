#pragma once
#include <boost/date_time.hpp>

class Goods {
public:
	int GetPrice() const { return price; }
	std::string GetName() const { return name; }
	boost::gregorian::date GetExpDate() const { return expiring_date; }
	//void SetName(std::string Name) { name = Name; }
	//void SetWeight(int Weight) { weight = Weight; }
	//void SetReleaseDate(boost::gregorian::date rel_d) { release_date = rel_d; }
	//void SetPrice(int Price) { price = Price; }

protected:
	Goods();
	int price;
	int weight;
	std::string name;
	boost::gregorian::date release_date;
	boost::gregorian::date expiring_date;
	boost::gregorian::date curr_time = boost::gregorian::day_clock::local_day();
};
