#include "nonalcoholic.h"

nonalcoholic::nonalcoholic()
{
}
nonalcoholic::nonalcoholic(std::string subcategory, std::string restaurantName, std::string menuLink, std::string imgName, std::string recDish)
{
	nonalcoholic::subcategory = subcategory;
	nonalcoholic::restaurantName = restaurantName;
	nonalcoholic::menuLink = menuLink;
	nonalcoholic::imgName = imgName;
	nonalcoholic::recDish = recDish;
}
//returns subcategoryList
std::vector<std::string> nonalcoholic::getSubcategories()
{
	std::vector <std::string> subcategories = {"Bubble Tea", "Coffee", "Milkshake"};

	return subcategories;
}

