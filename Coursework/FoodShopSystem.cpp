#include "FoodShopSystem.h"
#include <cstdlib>
#include <Windows.h>
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void FoodShopSystem::ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
void FoodShopSystem::menu() {
	char number;
	char number1;
	int amount, price, shelfspace, weight, kcal, fatcont, quantity;
	std::string name, yogfilling, milkpackagetype, ketchuppackagetype;
	std::string reldate, expdate;
	bool ex = false;
	
	Yogurt *yogurt;
	Milk *milk;
	Ketchup *ketchup;
	Shelf shelf;
	system("title Grocery store");
	ConsoleCursorVisible(true, 100);
	do {
		std::cout << "|------------------------------------|\n"
					 "|           Grocery Store            |\n"
					 "|------------------------------------|\n"
					 "|1. Add Yogurt                       |\n"
					 "|2. Add Milk                         |\n"
					 "|3. Add Ketchup                      |\n"
					 "|4. Set shelf size(30 - default)     |\n"
					 "|5. Check on expired goods           |\n"
					 "|6. Buy products                     |\n"
					 "|7. Revenue                          |\n"
					 "|8. Show me products on the shelf    |\n"
					 "|------------------------------------|\n"
					 "|0. Exit                             |\n"
					 "|------------------------------------|\n";
		//std::cout << "||" << std::endl;
		std::cin >> number;
		try {
			switch (number) {
			case '1':
				system("cls");
				std::cout << "Enter yogurt name:\n";
				std::cin >> name;
				std::cout << "Enter yogurt release date(yy/mm/dd):\n";
				std::cin >> reldate;
				std::cout << "Enter yogurt expiring date(yy/mm/dd):\n";
				std::cin >> expdate;
				std::cout << "Enter yogurt weight(g):\n";
				std::cin >> weight;
				std::cout << "Enter yogurt kcal:\n";
				std::cin >> kcal;
				std::cout << "Enter yogurt filling:\n";
				std::cin >> yogfilling;
				std::cout << "Enter yogurt fat content(%):\n";
				std::cin >> fatcont;
				std::cout << "Enter yogurt amount:\n";
				std::cin >> amount;
				std::cout << "Enter yogurt price(UAH):\n";
				std::cin >> price;
				yogurt = new Yogurt(name, boost::gregorian::from_string(reldate), boost::gregorian::from_string(expdate), weight, kcal, yogfilling, fatcont, price);
				shelf.AddFoodGoods(yogurt, amount);
				shelf.GetFoodGoods();
				std::cout    << "-----------------------------------------------\n"
								"You added yogurt to the shelf in size of " << amount << "!\n"
								"-----------------------------------------------\n";
				system("pause");
				system("cls");
				break;
			case '2':
				system("cls");
				std::cout << "Enter milk name:\n";
				std::cin >> name;
				std::cout << "Enter milk release date(yy/mm/dd):\n";
				std::cin >> reldate;
				std::cout << "Enter milk expiring date(yy/mm/dd):\n";
				std::cin >> expdate;
				std::cout << "Enter milk weight(g):\n";
				std::cin >> weight;
				std::cout << "Enter milk kcal:\n";
				std::cin >> kcal;
				std::cout << "Enter milk package type:\n";
				std::cin >> milkpackagetype;
				std::cout << "Enter milk fat content(%):\n";
				std::cin >> fatcont;
				std::cout << "Enter milk amount:\n";
				std::cin >> amount;
				std::cout << "Enter milk price(UAH):\n";
				std::cin >> price;
				milk = new Milk(name, boost::gregorian::from_string(reldate), boost::gregorian::from_string(expdate), weight, kcal, milkpackagetype, fatcont, price);
				shelf.AddFoodGoods(milk, amount);
				std::cout    << "-----------------------------------------------\n"
								"You added milk to the shelf in size of " << amount << "!\n"
								"-----------------------------------------------\n";
				system("pause");
				system("cls");
				break;
			case '3':
				system("cls");
				std::cout << "Enter ketchup name:\n";
				std::cin >> name;
				std::cout << "Enter ketchup release date(yy/mm/dd):\n";
				std::cin >> reldate;
				std::cout << "Enter ketchup expiring date(yy/mm/dd):\n";
				std::cin >> expdate;
				std::cout << "Enter ketchup weight(g):\n";
				std::cin >> weight;
				std::cout << "Enter ketchup kcal:\n";
				std::cin >> kcal;
				std::cout << "Enter ketchup package type:\n";
				std::cin >> ketchuppackagetype;
				std::cout << "Enter ketchup fat content(%):\n";
				std::cin >> fatcont;
				std::cout << "Enter ketchup amount:\n";
				std::cin >> amount;
				std::cout << "Enter ketchup price(UAH):\n";
				std::cin >> price;
				ketchup = new Ketchup(name, boost::gregorian::from_string(reldate), boost::gregorian::from_string(expdate), weight, kcal, ketchuppackagetype, fatcont, price);
				shelf.AddFoodGoods(ketchup, amount);
				std::cout    << "-----------------------------------------------\n"
								"You added ketchup to the shelf in size of " << amount << "!\n"
								"-----------------------------------------------\n";
				system("pause");
				system("cls");
				break;
			case '4':
				system("cls");
				std::cout << "Enter desired shelf size:\n";
				std::cin >> shelfspace;
				shelf.SetShelfSpace(shelfspace);
				std::cout    << "-----------------------------------------------\n"
								"You have successfully set the shelf size of " << shelf.GetShelfSpace() << "!\n"
								"-----------------------------------------------\n";
				system("pause");
				system("cls");
				break;
			case '5':
				system("cls");
				do {
					std::cout << "|----------------------------------|\n"
								 "|What product do you want to check?|\n"
								 "|----------------------------------|\n"
								 "|1. Check for expired by name      |\n"
								 "|0. Back to the grocery store      |\n"
								 "|----------------------------------|\n";
					std::cin >> number1;
					switch (number1) {
					case '1':
						system("cls");
						std::cout << "Enter name of product:\n";
						std::cin >> name;
						shelf.CheckExpiredGoods(name);
						system("pause");
						system("cls");
						break;
					case '0':
						system("cls");
						std::cout << "|----------------------------------|\n"
									 "|Going back to the grocery store...|\n"
									 "|----------------------------------|\n";
						system("pause");
						system("cls");
						break;
					default:
						std::cerr << "Oops!... You made a wrong choice!\n";
						system("pause");
						system("cls");
					}
				} while (number1 !='0');
				break;
			case '6':
				system("cls");
				std::cout << "Enter name of product you want to buy: \n";
				std::cin >> name;
				std::cout << "Enter quantity of product you want to buy: \n";
				std::cin >> quantity;
				shelf.BuyGoods(name, quantity);
				std::cout << "Successfully bought " << quantity << " products!\n";
				system("pause");
				system("cls");
				break;
			case '7':
				system("cls");
				std::cout << "Your revenue is: " << shelf.GetRevenue() << " UAH\n";
				system("pause");
				system("cls");
				break;
			case '8':
				system("cls");
				shelf.ShelfInfo();
				system("pause");
				system("cls");
				break;
			case '0':
				system("cls");
				do {
					std::cout << "|------------------------------------|\n"
								 "|        Do you want to exit?        |\n"
								 "|------------------------------------|\n"
								 "|1. Yes                              |\n"
								 "|2. No                               |\n"
								 "|------------------------------------|\n";
					std::cin >> number1;
					switch (number1) {
					case '1':
						std::cout << "|----------------|\n"
									 "|Have a nice day!|\n"
									 "|----------------|\n";
						exit(0);
						break;
					case '2':
						std::cout << "|----------------------------------|\n"
									 "|Going back to the grocery store...|\n"
									 "|----------------------------------|\n";
						system("pause");
						system("cls");
						break;
					default:
						std::cerr << "Oops!... You made a wrong choice!\n";
						system("pause");
						system("cls");
					}
				} while (number1 != '2');
			default:
				std::cerr << "Oops!... You made a wrong choice!\n";
				system("pause");
				system("cls");
			}
		}
		catch (const std::exception& ex) { std::cerr << ex.what() << "\n"; }
	} while (number != 0);
}

/*void Food_shop::DeleteExpiredGoods(const std::string Name) { //Проверяем и удаляем товары с истекшим сроком годности
	for (std::vector<const Food_goods*>::iterator i = foodGoodsShelf.begin(); i != foodGoodsShelf.end();) {
		const Goods* goods = *i;
		boost::gregorian::date expdt = goods->GetExpDate();
		if (goods->GetName() == Name) {
			if (curr_time > expdt) {
				i = foodGoodsShelf.erase(i);
			}
			if (curr_time == expdt) {
				std::cout << "Today is the last day\n";
				i++;
			}
			if (goods->GetName() != Name) {
				throw std::exception("No such product!");
			}
		}
	}
}*/

