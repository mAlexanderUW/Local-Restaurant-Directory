#pragma once
#include "restaurant.h"

class beverage : public restaurant
{
public:
	beverage();
	beverage(std::string category, std::string subcategory, std::string restaurantName,
		std::string menuLink, std::string imgName, std::string recDish);
	std::vector<std::string> getCategories();
};
