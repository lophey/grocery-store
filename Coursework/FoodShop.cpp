#include "FoodShop.h"
FoodShop::FoodShop() {
	revenue = 0;
}
void FoodShop::CheckExpiredGoods(const std::string Name) {

	//if (curr_time < expdt) { std::cout << "Not expired yet!\n"; }
	//if (curr_time == expdt) { std::cout << "Today is the last day!\n"; }
	for (auto i = foodGoodsShelf.begin(); i != foodGoodsShelf.end();i++) {
		const Goods* goods = *i;
			if (goods->GetName() == Name) {
				while (curr_time > goods->GetExpDate()) {
					i = foodGoodsShelf.erase(i);
					std::cout << "Deleted!\n";
				}
			}
			//else { throw std::exception("No such product"); }
			if (goods->GetName() == Name) {
				while (curr_time < goods->GetExpDate()) { 
					std::cout << "Not expired yet!\n";
				}
			}
			if (goods->GetName() == Name) {
				while (curr_time == goods->GetExpDate()) { 
					std::cout << "Today is the last day!\n";
				}
			}
	}
	if (foodGoodsShelf.empty()) { throw std::exception("The shelf is empty!"); }
	//if (goods->GetName() != Name) { throw std::exception("No such product!"); }
}
void FoodShop::BuyGoods(const std::string& Name, int quantity) {
	if (foodGoodsShelf.empty()) { throw std::exception("The shelf is empty!"); }
	for (auto i = foodGoodsShelf.begin(); i != foodGoodsShelf.end(); i++) {
		const Goods* goods = *i;
		if (goods->GetName() == Name) {
			while (quantity > 0) {
				i = foodGoodsShelf.erase(i);
				Revenue(goods->GetPrice());
				quantity--;
			}
		
		}

	}
}