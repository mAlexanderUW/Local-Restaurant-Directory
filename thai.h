#pragma once
#include "food.h"
class thai : public food
{
public:
	thai();
	thai(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();
};

