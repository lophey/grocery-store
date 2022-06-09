#include "Food_goods.h"
Food_goods::Food_goods()
{
	kcal = 0;
}
std::string Food_goods::Info() const {
	std::ostringstream out;
	out << kcal << " kcal\n";
	return out.str();
}