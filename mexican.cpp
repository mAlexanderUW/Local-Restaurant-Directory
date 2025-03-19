#include "mexican.h"

mexican::mexican()
{
}

mexican::mexican(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	mexican::subcategory = subcategory;
	mexican::restaurantName = restaurantName;
	mexican::menuLink = menuLink;
	mexican::imgName = imgName;
	mexican::recDish = recDish;
}

std::vector<std::string> mexican::getSubcategories()
{
	std::vector <std::string> subcategories = { "Burrito", "Fast Food" };

	return subcategories;
}

