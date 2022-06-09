#include "Shelf.h"
Shelf::Shelf()
{
	shelfSpace = 30;
}
void Shelf::ShelfInfo() {
	if (foodGoodsShelf.empty()) {
		throw std::exception("The shelf is empty!");
	}
	for (auto foodGoods : foodGoodsShelf) {
		std::cout << foodGoods->Info() << "\n";
	}
}
void Shelf ::AddFoodGoods(const Food_goods* foodGoods, int amount) { //ƒобавл€ем продукт на полку в каком-то количестве
	size_t ShelfSpace = GetShelfSpace();
	for (int i = 1; i <= amount; i++) {
		while (amount > 0) {
			foodGoodsShelf.push_back(foodGoods); 
			amount--;
			if (foodGoodsShelf.size() >= ShelfSpace) { throw std::length_error("No place for goods!"); }
		}
	}
}
void Shelf::AddFoodGoods(const Food_goods& foodGoods, int amount) {
	AddFoodGoods(&foodGoods, amount);
}
void Shelf::SetShelfSpace(int ShelfSpace){
	shelfSpace = ShelfSpace;
	if (ShelfSpace > 99) { throw std::exception("Shelf size cannot be more than 99!"); }
}