#pragma once
#pragma once
#include <string>
#include <vector>

class restaurant
{
public:
	restaurant();
	std::string getCategory();
	std::string getSubcategory();
	std::string getRestaurantName();
	std::string getMenuLink();
	std::string getImgName();
	std::string getRecDish();

protected:
	std::string category;
	std::string subcategory;
	std::string restaurantName;
	std::string menuLink;
	std::string imgName;
	std::string recDish;
};
