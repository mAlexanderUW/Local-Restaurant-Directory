#include "food.h"

food::food()
{
}

food::food(std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	food::restaurantName = restaurantName;
	food::menuLink = menuLink;
	food::imgName = imgName;
	food::recDish = recDish;
}

food::food(std::string category, std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	food::category = category;
	food::subcategory = subcategory;
	food::restaurantName = restaurantName;
	food::menuLink = menuLink;
	food::imgName = imgName;
	food::recDish = recDish;
}

std::vector<std::string> food::getCategories()
{
	std::vector<std::string> categoryList = { "American", "Desserts", "International", "Italian", "Japanese", "Korean", "Mexican", "Thai", "Vietnamese" };

	return categoryList;
}

