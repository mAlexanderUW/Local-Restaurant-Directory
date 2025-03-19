#include "dessert.h"

dessert::dessert()
{
}

dessert::dessert(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	dessert::subcategory = subcategory;
	dessert::restaurantName = restaurantName;
	dessert::menuLink = menuLink;
	dessert::imgName = imgName;
	dessert::recDish = recDish;
}

std::vector<std::string> dessert::getSubcategories()
{
	std::vector <std::string> subcategories = { "Cookies", "Ice Cream", "Pastries" };

	return subcategories;
}
