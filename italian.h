#pragma once
#include "food.h"
class italian : public food
{
public:
	italian();
	italian(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();
};


