#include "thai.h"

thai::thai()
{
}

thai::thai(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	thai::subcategory = subcategory;
	thai::restaurantName = restaurantName;
	thai::menuLink = menuLink;
	thai::imgName = imgName;
	thai::recDish = recDish;
}

std::vector<std::string> thai::getSubcategories()
{
	std::vector <std::string> subcategories = { "Central Style", "Isan" };

	return subcategories;
}

