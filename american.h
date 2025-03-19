#pragma once
#include "food.h"
class american : public food
{
public:
	american();
	american(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();
};

