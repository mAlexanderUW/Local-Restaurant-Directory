#include "korean.h"

korean::korean()
{
}

korean::korean(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	korean::subcategory = subcategory;
	korean::restaurantName = restaurantName;
	korean::menuLink = menuLink;
	korean::imgName = imgName;
	korean::recDish = recDish;
}

std::vector<std::string> korean::getSubcategories()
{
	std::vector <std::string> subcategories = { "BBQ", "Burger" };

	return subcategories;
}

