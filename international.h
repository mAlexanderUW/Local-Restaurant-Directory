#pragma once
#include "food.h"
class international : public food
{
public:
	international();
	international(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();
};

