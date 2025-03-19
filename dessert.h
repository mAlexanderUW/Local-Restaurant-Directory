#pragma once
#include "food.h"
class dessert : public food
{
public:
	dessert();
	dessert(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();
};

