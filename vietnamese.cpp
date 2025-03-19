#include "vietnamese.h"

vietnamese::vietnamese()
{
}

vietnamese::vietnamese(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	vietnamese::subcategory = subcategory;
	vietnamese::restaurantName = restaurantName;
	vietnamese::menuLink = menuLink;
	vietnamese::imgName = imgName;
	vietnamese::recDish = recDish;
}

std::vector<std::string> vietnamese::getSubcategories()
{
	std::vector <std::string> subcategories = { "Banh Mi", "Pho" };

	return subcategories;
}

