#include "japanese.h"

japanese::japanese()
{
}

japanese::japanese(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	japanese::subcategory = subcategory;
	japanese::restaurantName = restaurantName;
	japanese::menuLink = menuLink;
	japanese::imgName = imgName;
	japanese::recDish = recDish;
}

std::vector<std::string> japanese::getSubcategories()
{
	std::vector <std::string> subcategories = { "Burger", "Ramen", "Sushi"};

	return subcategories;
}
