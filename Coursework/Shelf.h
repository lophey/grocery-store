#pragma once
#include "FoodShop.h"
class Shelf : public FoodShop
{
public:
	Shelf();
	size_t GetShelfSpace() const { return shelfSpace; }
	void SetShelfSpace(int ShelfSpace) { shelfSpace = ShelfSpace; }
	void AddFoodGoods(const Food_goods* foodGoods, int amount);
	void AddFoodGoods(const Food_goods& foodGoods, int amount);
	const std::vector<const Food_goods*>& GetFoodGoods() const { return foodGoodsShelf; }
	void ShelfInfo();
protected:
	int shelfSpace;
};

