#pragma once
#include "beverage.h"

class nonalcoholic : public beverage
{
public:
	nonalcoholic();
	nonalcoholic(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();
};

