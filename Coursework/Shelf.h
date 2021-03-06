#pragma once
#include "FoodShop.h"
class Shelf : public FoodShop
{
public:
	Shelf();
	size_t GetShelfSpace() const { return shelfSpace; }
	void SetShelfSpace(int ShelfSpace);
	void AddFoodGoods(const Food_goods* foodGoods, int amount);
	void AddFoodGoods(const Food_goods& foodGoods, int amount);
	//const std::vector<const Food_goods*>& GetFoodGoods() const { return foodGoodsShelf; }
	void ShelfSort();
	void ShelfInfo();
protected:
	int shelfSpace;
};