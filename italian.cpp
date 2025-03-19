#include "italian.h"

italian::italian()
{
}

italian::italian(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	italian::subcategory = subcategory;
	italian::restaurantName = restaurantName;
	italian::menuLink = menuLink;
	italian::imgName = imgName;
	italian::recDish = recDish;
}

std::vector<std::string> italian::getSubcategories()
{
	std::vector <std::string> subcategories = { "Pasta", "Pizza" };

	return subcategories;
}
