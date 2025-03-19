#include "beverage.h"

beverage::beverage()
{
}

beverage::beverage(std::string category, std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	beverage::category = category;
	beverage::subcategory = subcategory;
	beverage::restaurantName = restaurantName;
	beverage::menuLink = menuLink;
	beverage::imgName = imgName;
	beverage::recDish = recDish;
}

//returns categoryList
std::vector<std::string> beverage::getCategories()
{
	std::vector<std::string> categoryList = {"Alcoholic", "Non-Alcoholic"};

	return categoryList;
}

