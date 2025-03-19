#include "american.h"

american::american()
{
}

american::american(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	american::subcategory = subcategory;
	american::restaurantName = restaurantName;
	american::menuLink = menuLink;
	american::imgName = imgName;
	american::recDish = recDish;
}

std::vector<std::string> american::getSubcategories()
{
	std::vector <std::string> subcategories = {"BBQ", "Burger"};

	return subcategories;
}
