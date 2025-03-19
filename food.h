#pragma once
#include "restaurant.h"

class food : public restaurant
{
public:
	food();
	food(std::string restaurantName, std::string menuLink,
		std::string imgName, std::string recDish);
	food(std::string category, std::string subcategory, std::string restaurantName,
		std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getCategories();
};

