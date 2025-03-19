#pragma once
#include "food.h"
class vietnamese : public food
{
public:
	vietnamese();
	vietnamese(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();
};
