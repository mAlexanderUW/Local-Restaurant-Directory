#pragma once
#include "food.h"
class korean : public food
{
public:
	korean();
	korean(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getSubcategories();

};

