#pragma once
#include <boost/date_time.hpp>
#include "Food_goods.h"
#include "Yogurt.h"
#include "Milk.h"
#include "Ketchup.h"
class FoodShop
{
public:
	FoodShop();
	void CheckExpiredGoods(const std::string Name);
	void BuyGoods(const std::string& Name, int quantity);
	void Revenue(int ProductPrice) {
		revenue += ProductPrice;
	}
	int  GetRevenue() { return revenue; }
	//void DeleteExpiredGoods(const std::string Name);
protected:
	int revenue;
	std::vector<const Food_goods*> foodGoodsShelf;
	boost::gregorian::date curr_time = boost::gregorian::day_clock::local_day();
};

