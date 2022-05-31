#pragma once
#include "Food_goods.h"
class Shelf
{
public:
	Shelf();
	int GetGoodsAmount() const { return goods_amount; }

	void SetGoodsAmount(Food_goods, int GoodsAmount) {
		if (goods_amount >= max_amount) {
			throw std::length_error("No place for goods!");
		}
		goods_amount = GoodsAmount;
	}

	const std::vector<const Food_goods*>& GetFoodGoods() const { return m_foodGoods; }

	void AddFoodGoods(const Food_goods* foodGoods) {
		if (m_foodGoods.size() > GetGoodsAmount()) {
			throw std::length_error("No place for goods!");
		}
		else m_foodGoods.push_back(foodGoods);
	}

	void AddFoodGoods(const Food_goods& foodGoods) { AddFoodGoods(&foodGoods); }

private:
	int max_amount;
	int goods_amount;
	std::vector<const Food_goods*> m_foodGoods;
};

