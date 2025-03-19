#pragma once
#include "food.h"
class mexican : public food
{
public:
	mexican();
	mexican(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();
};

