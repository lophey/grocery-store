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

/*std::string Food_goods::exp_date_checker() const {
	if (curr_time < expiring_date) {
		return "Not expired yet";
	}
	if (curr_time > expiring_date) {
		return "Already expired";
	}
	if (curr_time == expiring_date) {
		return "Today is the last day";
	}
}*/