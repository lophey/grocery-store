#include "FoodShop.h"
FoodShop::FoodShop() {
	revenue = 0;
}
void FoodShop::CheckExpiredGoods(const std::string Name) {
	if (foodGoodsShelf.empty()) { throw std::exception("The shelf is empty!"); }
	std::vector<const Food_goods*>::iterator i = foodGoodsShelf.begin();
	/*const Food_goods* goods = *i;
	if (goods->GetName() != Name) { throw std::exception("No such poducts!"); }*/
	for (i; i != foodGoodsShelf.end();) {
		const Food_goods* goods = *i;
		if (goods->GetName() == Name) {
			if (curr_time > goods->GetExpDate()) {
				i = foodGoodsShelf.erase(i);
				std::cout << "Expired! Deleted!\n";
			}
			if (curr_time < goods->GetExpDate()) { std::cout << "Not expired yet!\n"; i++; }
			if (curr_time == goods->GetExpDate()) { std::cout << "Today is the last day!\n"; i++; }
		}else { i++; }
	}
}
void FoodShop::BuyGoods(const std::string& Name, int quantity) {
	if (foodGoodsShelf.empty()) { throw std::exception("The shelf is empty!"); }
	std::vector<const Food_goods*>::iterator i = foodGoodsShelf.begin();
	/*const Food_goods* goods = *i;
	if (goods->GetName() != Name) { throw std::exception("No such poducts!"); }*/
	for (i; i != foodGoodsShelf.end();) {
		const Food_goods* goods = *i;
		if (goods->GetName() == Name) {
			while (quantity > 0) {
				i = foodGoodsShelf.erase(i);
				Revenue(goods->GetPrice());
				quantity--;
			}
		}
		else { i++; }
	}
}