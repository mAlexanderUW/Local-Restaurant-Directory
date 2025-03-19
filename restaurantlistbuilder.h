#pragma once
#include "fileHandler.h"
//drinks
#include "beverage.h"
#include "alcoholic.h"
#include "cocktail.h"
#include "milkshakeshot.h"
#include "nonalcoholic.h"
#include "milkshake.h"
#include "bubbletea.h"
#include "coffee.h"
//food
#include "food.h"
#include "bbq.h"
#include "burgerUSA.h"
#include "cookies.h"
#include "icecream.h"
#include "pastries.h"
#include "burgerJ.h"
#include "ramen.h"
#include "sushi.h"
#include "fusion.h"
#include "pasta.h"
#include "pizza.h"
#include "burgerk.h"
#include "kbbq.h"
#include "burrito.h"
#include "fastfood.h"
#include "central.h"
#include "isan.h"
#include "banhmi.h"
#include "pho.h"


class restaurantlistbuilder
{
public:
	void buildBeverageRestaurants();
	void buildFoodRestaurants();
	//get functions for booleans on if lists built
	bool getBeverageListEmpty();
	bool getFoodListEmpty();
	//get functions for category Lists
	std::vector<std::string> getBeverageCategoryList();
	std::vector<std::string> getFoodCategoryList();
	//get functions for Beverage Subcategory lists
	std::vector<std::string> getAlcoholicSubcategoryList();
	std::vector<std::string> getNonalcoholicSubcategoryList();
	//get functions for Food Subcategory lists
	std::vector<std::string> getAmericanSubcategoryList();
	std::vector<std::string> getDessertSubcategoryList();
	std::vector<std::string> getInternationalSubcategoryList();
	std::vector<std::string> getItalianSubcategoryList();
	std::vector<std::string> getJapaneseSubcategoryList();
	std::vector<std::string> getKoreanSubcategoryList();
	std::vector<std::string> getMexicanSubcategoryList();
	std::vector<std::string> getThaiSubcategoryList();
	std::vector<std::string> getVietnameseSubcategoryList();
	//get functions for the vectors storing beverages
	std::vector<restaurant> getcocktailList();
	std::vector<restaurant> getmilkshakeshotList();
	std::vector<restaurant> getmilkshakeList();
	std::vector<restaurant> getbubbleteaList();
	std::vector<restaurant> getcoffeeList();
	//get functions for the vectors storing cuisines
	std::vector<restaurant> getbbqList();
	std::vector<restaurant> getburgerUSAList();
	std::vector<restaurant> getcookiesList();
	std::vector<restaurant> geticecreamList();
	std::vector<restaurant> getpastriesList();
	std::vector<restaurant> getburgerJList();
	std::vector<restaurant> getramenList();
	std::vector<restaurant> getsushiList();
	std::vector<restaurant> getfusionList();
	std::vector<restaurant> getpastaList();
	std::vector<restaurant> getpizzaList();
	std::vector<restaurant> getburgerKList();
	std::vector<restaurant> getkbbqList();
	std::vector<restaurant> getburritoList();
	std::vector<restaurant> getfastfoodList();
	std::vector<restaurant> getcentralList();
	std::vector<restaurant> getisanList();
	std::vector<restaurant> getbanhmiList();
	std::vector<restaurant> getphoList();

private:
	bool beverageListEmpty;
	bool foodListEmpty;
	//Category Lists
	std::vector<std::string> beverageCategoryList;
	std::vector<std::string> foodCategoryList;
	//Beverage Subcategory lists
	std::vector<std::string> alcoholicSubcategoryList;
	std::vector<std::string> nonalcoholicSubcategoryList;
	//Food Subcategory lists
	std::vector<std::string> americanSubcategoryList;
	std::vector<std::string> dessertSubcategoryList;
	std::vector<std::string> internationalSubcategoryList;
	std::vector<std::string> italianSubcategoryList;
	std::vector<std::string> japaneseSubcategoryList;
	std::vector<std::string> koreanSubcategoryList;
	std::vector<std::string> mexicanSubcategoryList;
	std::vector<std::string> thaiSubcategoryList;
	std::vector<std::string> vietnameseSubcategoryList;
	//vector of data from filehandler
	std::vector<directory> directoryList;
	//vector storing beverage related restaurants
	std::vector<restaurant> cocktailList;
	std::vector<restaurant> milkshakeshotList;
	std::vector<restaurant> milkshakeList;
	std::vector<restaurant> bubbleteaList;
	std::vector<restaurant> coffeeList;
	//vector storing food related restaurants
	std::vector<restaurant> bbqList;
	std::vector<restaurant> burgerUSAList;
	std::vector<restaurant> cookiesList;
	std::vector<restaurant> icecreamList;
	std::vector<restaurant> pastriesList;
	std::vector<restaurant> burgerJList;
	std::vector<restaurant> ramenList;
	std::vector<restaurant> sushiList;
	std::vector<restaurant> fusionList;
	std::vector<restaurant> pastaList;
	std::vector<restaurant> pizzaList;
	std::vector<restaurant> burgerKList;
	std::vector<restaurant> kbbqList;
	std::vector<restaurant> burritoList;
	std::vector<restaurant> fastfoodList;
	std::vector<restaurant> centralList;
	std::vector<restaurant> isanList;
	std::vector<restaurant> banhmiList;
	std::vector<restaurant> phoList;
};

