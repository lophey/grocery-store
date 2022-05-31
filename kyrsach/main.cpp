#include <Windows.h>
#include <string>
#include <conio.h>
#include "shop_classes.h"

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void ConsoleCursorVisible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

int main()
{
    system("title Goods store");
    ConsoleCursorVisible(false , 100);
    int expd{}, expm{}, expy{};
    int d{}, m{}, y{};
    
    std::string yogname, yogfilling;
    int yogweight{}, yogkcal{}, yogfatcont{};

    std::string milkname, milkpackagetype;
    int milkweight{}, milkkcal{}, milkfatcont{};

    Yogurt yogurt;
    Milk milk;
    Shelf shelf;

    /////////////////////////////////////////////// Yogurt Block
    
    
    std::cout << "Enter yogurt name:" << std::endl;
    std::cin >> yogname;
    yogurt.SetName(yogname);
    
    std::cout << "Enter yogurt release date(yy/mm/dd):" << std::endl;
    std::cin >> y >> m >> d;
    date YogReleaseDate(y, m, d);
    yogurt.SetReleaseDate(YogReleaseDate);
    
    std::cout << "Enter yogurt weight:" << std::endl;
    std::cin >> yogweight;
    yogurt.SetWeight(yogweight);
    
    std::cout << "Enter yogurt kcal:" << std::endl;
    std::cin >> yogkcal;
    yogurt.SetYogKcal(yogkcal);
    
    std::cout << "Enter yogurt filling:" << std::endl;
    std::cin >> yogfilling;
    yogurt.SetYogFilling(yogfilling);
    
    std::cout << "Enter yogurt fat content:" << std::endl;
    std::cin >> yogfatcont;
    yogurt.SetYogFatConent(yogfatcont);
    
    std::cout << "Enter yogurt expiring date(yy/mm/dd):" << std::endl;
    std::cin >> expy >> expm >> expd;
    date YogExpDate(expy, expm, expd);
    yogurt.SetYogExpDate(YogExpDate);


    shelf.AddFoodGoods(yogurt);
    shelf.SetGoodsAmount(yogurt, 5);
    std::cout << shelf.GetGoodsAmount();
    /////////////////////////////////////////////// Yogurt Block
    std::cout << std::endl;
    /////////////////////////////////////////////// Milk Block
    std::cout << "Enter milk name:" << std::endl;
    std::cin >> milkname;
    milk.SetName(milkname);

    std::cout << "Enter milk release date(yy/mm/dd):" << std::endl;
    std::cin >> y >> m >> d;
    date MilkReleaseDate(y, m, d);
    milk.SetReleaseDate(MilkReleaseDate);
    
    std::cout << "Enter milk weight:" << std::endl;
    std::cin >> milkweight;
    milk.SetWeight(milkweight);
    
    std::cout << "Enter milk kcal:" << std::endl;
    std::cin >> milkkcal;
    milk.SetMilkKcal(milkkcal);
    
    std::cout << "Enter milk package type:" << std::endl;
    std::cin >> milkpackagetype;
    milk.SetMilkPackageType(milkpackagetype);
    
    std::cout << "Enter milk fat content:" << std::endl;
    std::cin >> milkfatcont;
    milk.SetMilkFatConent(milkfatcont);
    
    std::cout << "Enter milk expiring date(yy/mm/dd):" << std::endl;
    std::cin >> expy >> expm >> expd;
    date MilkExpDate(expy, expm, expd);
    milk.SetMilkExpDate(MilkExpDate);

 
    shelf.AddFoodGoods(milk);
    shelf.SetGoodsAmount(milk, 10);
    std::cout << shelf.GetGoodsAmount();
    /////////////////////////////////////////////// Milk Block

    std::cout << std::endl << "Yogurt info: " << std::endl << yogurt.Info() << std::endl << yogurt.exp_date_checker() << std::endl << std::endl;
    std::cout << "Milk info: " << std::endl << milk.Info() << std::endl << milk.exp_date_checker();
}
