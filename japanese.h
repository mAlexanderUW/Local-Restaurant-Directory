#pragma once
#include "food.h"
class japanese : public food
{
public:
	japanese();
	japanese(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();;
};

