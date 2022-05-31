#include <iostream>
#include <sstream>
#include <vector>

#include <boost/date_time.hpp>
using namespace boost::gregorian;
date curr_time = day_clock::local_day();

class Food_shop {
public:

private:

};

class Goods {
public:
	void SetName(std::string Name) {
		name = Name;
	}
	void SetWeight(int Weight) {
		weight = Weight;
	}
	void SetReleaseDate(date rel_d) {
		release_date = rel_d;
	}
	void SetPrice(int Price) {
		price = Price;
	}
protected:
	Goods()
	{
		name = "unknown";
		weight = 0;
	}
	std::string name;
	int weight;
	date release_date;
	int price;
};

class Food_goods : public Goods {
public:
	virtual std::string Info() const {
		std::ostringstream out;
		out << kcal << " kcal" << std::endl << expiring_date;
		return out.str();
	}
	
	std::string exp_date_checker() const {
		if (curr_time < expiring_date) {
			return "Not expired yet";
		}
		if (curr_time > expiring_date) {
			return "Already expired";
		}
		if (curr_time == expiring_date) {
			return "Today is the last day";
		}
	}
protected:
	Food_goods()
	{
		kcal = 0;
	}
	int kcal;
	date expiring_date;
};

class Yogurt : public Food_goods {
public:
	Yogurt()
	{
		filling = "none";
		fat_content = 0;
	}
	void SetYogKcal(int YogKcal) {
		kcal = YogKcal;
	}
	void SetYogExpDate(date YogExpDate) {
		expiring_date = YogExpDate;
	}
	void SetYogFilling(std::string yog_filling) {
		filling = yog_filling;
	}
	void SetYogFatConent(int YogFatContent) {
		fat_content = YogFatContent;
	}
	std::string Info() const override {
		std::ostringstream out;
		out << "Name: " << name << std::endl << "Release date: " << release_date << std::endl << "Weight: " << weight << std::endl << kcal << " kcal" 
			<< std::endl << "Filling: " << filling << std::endl << "Fat content: " << fat_content << std::endl << "Expiring date: " << expiring_date;
		return out.str();
	}
private:
	std::string filling;
	int fat_content;
};

class Milk : public Food_goods {
public:
	Milk()
	{
		package_type = "unknown";
		fat_content = 0;
	}
	void SetMilkKcal(int MilkKcal) {
		kcal = MilkKcal;
	}
	void SetMilkExpDate(date MilkExpDate) {
		expiring_date = MilkExpDate;
	}
	void SetMilkPackageType(std::string pack_type) {
		package_type = pack_type;
	}
	void SetMilkFatConent(int MilkFatContent) {
		fat_content = MilkFatContent;
	}
	std::string Info() const override {
		std::ostringstream out;
		out << "Name: " << name << std::endl << "Release date: " << release_date << std::endl << "Weight: " << weight << std::endl << kcal << " kcal" 
			<< std::endl << "Package type: " << package_type << std::endl << "Fat content: " << fat_content << std::endl << "Expiring date: " << expiring_date;
		return out.str();
	}
private:

	std::string package_type;
	int fat_content;
};

class Water : public Food_goods {
public:
	Water()
	{
		
	}

private:
	std::string water_type;
};

class Shelf {
public:
	Shelf()
	{
		max_amount = 30;
		goods_amount = 0;
	}
	int GetGoodsAmount() const {
		return goods_amount;
	}
	void SetGoodsAmount(Food_goods, int GoodsAmount) {
		if (goods_amount >= max_amount) {
			throw std::length_error("No place for goods!");
		}
		goods_amount = GoodsAmount;
	}
	const std::vector<const Food_goods*>& GetFoodGoods() const {
		return m_foodGoods;
	}
	void AddFoodGoods(const Food_goods* foodGoods) {
		if (m_foodGoods.size() > GetGoodsAmount()) {
			throw std::length_error("No place for goods!");
		}
		else m_foodGoods.push_back(foodGoods);
	}
	void AddFoodGoods(const Food_goods& foodGoods) {
		AddFoodGoods(&foodGoods);
	}
private:
	int max_amount;
	int goods_amount;
	std::vector<const Food_goods*> m_foodGoods;
};