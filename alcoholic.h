#pragma once
#include "beverage.h"

class alcoholic : public beverage
{
public:
	alcoholic();
	alcoholic(std::string subcategory,std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();
};

