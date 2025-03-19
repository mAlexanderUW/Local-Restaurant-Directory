#include "alcoholic.h"
#include <iostream>

alcoholic::alcoholic()
{
}

alcoholic::alcoholic(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	alcoholic::subcategory = subcategory;
	alcoholic::restaurantName = restaurantName;
	alcoholic::menuLink = menuLink;
	alcoholic::imgName = imgName;
	alcoholic::recDish = recDish;
}
//returns subcategoryList
std::vector<std::string> alcoholic::getSubcategories()
{
	std::vector <std::string> subcategories = {"Cocktail", "Milkshake"};

	return subcategories;
}
