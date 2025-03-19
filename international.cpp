#include "international.h"

international::international()
{
}

international::international(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	international::subcategory = subcategory;
	international::restaurantName = restaurantName;
	international::menuLink = menuLink;
	international::imgName = imgName;
	international::recDish = recDish;
}

std::vector<std::string> international::getSubcategories()
{
	std::vector <std::string> subcategories = { "Fusion" };

	return subcategories;
}