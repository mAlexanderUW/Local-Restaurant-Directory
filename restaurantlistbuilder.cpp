#include "restaurantlistbuilder.h"
#include <iostream>

void restaurantlistbuilder::buildBeverageRestaurants()
{
	//gets the cuisine category lists
	beverage drinks;
	beverageCategoryList = drinks.getCategories();
	//loads drinks.txt to build a list a restaurants
	std::string fileName = "resources/drinks.txt";
	directoryList = loadRestarautsDirectory(fileName);
	beverageListEmpty = directoryList.empty();
	//gets the subcategory lists
	alcoholic alcoholicDrinks;
	alcoholicSubcategoryList = alcoholicDrinks.getSubcategories();
	nonalcoholic nonalcoholicDrinks;
	nonalcoholicSubcategoryList = nonalcoholicDrinks.getSubcategories();
	//intializing idx for the switches as restaurts are sorted into the category then subcategory
	int idx;

	for (const directory directoryList : directoryList)
	{
		std::string temp = directoryList.category;

		//find the index of the category for the switch 
		idx = 0;
		for (std::string beverageCategoryList : beverageCategoryList)
		{
			if (beverageCategoryList == temp)
			{
				break;
			}

			else
			{
				idx++;
			}
		}
		switch (idx)
		{
		case 0:
			//Alcoholic list
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string alcoholicSubcategoryList : alcoholicSubcategoryList)
			{
				if (alcoholicSubcategoryList == temp)
				{
					break;
				}

				{
					idx++;
				}
			}
			//Alcoholic switch based on subcategory
				switch (idx)
				{
				case 0:
					//Cocktail
					cocktailList.push_back(cocktail(directoryList.restaurantName,
						directoryList.menuLink, directoryList.imgName, directoryList.recDish));
					break;
				case 1:
					//Milkshake
					milkshakeshotList.push_back(milkshakeshot(directoryList.restaurantName,
						directoryList.menuLink, directoryList.imgName, directoryList.recDish));
					break;
				}
			break;

		case 1:
			//Non-alcoholic list
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string nonalcoholicSubcategoryList : nonalcoholicSubcategoryList)
			{
				if (nonalcoholicSubcategoryList == temp)
				{
					break;
				}

				else
				{
					idx++;
				}
			}
			//Non-alcoholic switch based on subcategory
				switch (idx)
				{
				case 0:
					//Bubble Tea
					bubbleteaList.push_back(bubbletea{directoryList.restaurantName, directoryList.menuLink,
						directoryList.imgName, directoryList.recDish});
					break;
				case 1:
					//Coffee
					coffeeList.push_back(coffee{directoryList.restaurantName, directoryList.menuLink,
						directoryList.imgName, directoryList.recDish});
					break;
				case 2:
					//Milkshake;
					milkshakeList.push_back(milkshake{directoryList.restaurantName, directoryList.menuLink,
						directoryList.imgName, directoryList.recDish});
					break;
				}
			break;

		}

	}
}

void restaurantlistbuilder::buildFoodRestaurants()
{
	//gets the cuisine category lists
	food cuisine;
	foodCategoryList = cuisine.getCategories(); 

	//loads food.txt to build a list a restaurants
	std::string fileName = "resources/food.txt";
	directoryList = loadRestarautsDirectory(fileName);
	foodListEmpty = directoryList.empty();
	//gets the subcategory lists
	american americanFood;
	americanSubcategoryList = americanFood.getSubcategories();

	dessert dessertFood;
	dessertSubcategoryList = dessertFood.getSubcategories();

	international internationalFood;
	internationalSubcategoryList = internationalFood.getSubcategories();

	italian italianFood;
	italianSubcategoryList = italianFood.getSubcategories();

	japanese japaneseFood;
	japaneseSubcategoryList = japaneseFood.getSubcategories();

	korean koreanFood;
	koreanSubcategoryList = koreanFood.getSubcategories();

	mexican mexicanFood;
	mexicanSubcategoryList = mexicanFood.getSubcategories();

	thai thaiFood;
	thaiSubcategoryList = thaiFood.getSubcategories();

	vietnamese vietnameseFood;
	vietnameseSubcategoryList = vietnameseFood.getSubcategories();
	
	//intializing idx for the switches as restaurts are sorted into the category then subcategory
	int idx;

	for (const directory directoryList : directoryList)
	{
		std::string temp = directoryList.category;

		//find the index of the category for the switch 
		idx = 0;
		for (std::string foodCategoryList : foodCategoryList)
		{
			if (foodCategoryList == temp)
			{
				break;
			}

			else
			{
				idx++;
			}
		}
		switch (idx)
		{
		case 0:
			//american list
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string americanSubcategoryList : americanSubcategoryList)
			{
				if (americanSubcategoryList == temp)
				{
					break;
				}

				else
				{
					idx++;
				}
			}
			//american switch based on subcategory
			switch (idx)
			{
			case 0:
				//bbq
				bbqList.push_back(bbq(directoryList.restaurantName, directoryList.menuLink,
					directoryList.imgName, directoryList.recDish));
				break;
			case 1:
				//burger
				burgerUSAList.push_back(burgerUSA(directoryList.restaurantName, directoryList.menuLink,
					directoryList.imgName, directoryList.recDish));
				break;
			}
			break;

		case 1:
			//Dessert list
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string dessertSubcategoryList : dessertSubcategoryList)
			{
				if (dessertSubcategoryList == temp)
				{
					break;
				}

				else
				{
					idx++;
				}
			}
			//dessert switch based on subcategory
			switch (idx)
			{
			case 0:
				//Cookies
				cookiesList.push_back(cookies(directoryList.restaurantName, directoryList.menuLink,
					directoryList.imgName, directoryList.recDish));
				break;
			case 1:
				//Ice Cream
				icecreamList.push_back(icecream(directoryList.restaurantName, directoryList.menuLink,
					directoryList.imgName, directoryList.recDish));
				break;
			case 2:
				//Pastries
				pastriesList.push_back(pastries(directoryList.restaurantName, directoryList.menuLink,
					directoryList.imgName, directoryList.recDish));
				break;
			}
			break;

		case 2:
			//International list
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string internationalSubcategoryList : internationalSubcategoryList)
			{
				if (internationalSubcategoryList == temp)
				{
					break;
				}

				{
					idx++;
				}
			}
			//International switch based on subcategory
			switch (idx)
			{
			case 0:
				//fusion
				fusionList.push_back(fusion(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			}
			break;

		case 3:
			//Italian list
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string italianSubcategoryList : italianSubcategoryList)
			{

				if (italianSubcategoryList == temp)
				{
					break;
				}

				else
				{
					idx++;
				}
			}
			//italian switch based on subcategory
			switch (idx)
			{
			case 0:
				//pasta
				pastaList.push_back(pasta(directoryList.restaurantName, directoryList.menuLink,
					directoryList.imgName, directoryList.recDish));
				break;
			case 1:
				//pizza
				pizzaList.push_back(pizza(directoryList.restaurantName, directoryList.menuLink,
					directoryList.imgName, directoryList.recDish));
				break;
			}
			break;

		case 4:
			//Japanese list
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string japaneseSubcategoryList : japaneseSubcategoryList)
			{
				if (japaneseSubcategoryList == temp)
				{
					break;
				}

				{
					idx++;
				}
			}
			//Japanese switch based on subcategory
			switch (idx)
			{
			case 0:
				//Burger
				burgerJList.push_back(burgerJ(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			case 1:
				//Ramen
				ramenList.push_back(ramen(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			case 2:
				//Sushi
				sushiList.push_back(sushi(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			}
			break;

		case 5:
			//Korean list
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string koreanSubcategoryList : koreanSubcategoryList)
			{
				if (koreanSubcategoryList == temp)
				{
					break;
				}

				{
					idx++;
				}
			}
			//Korean switch based on subcategory
			switch (idx)
			{
			case 0:
				//Burger
				burgerKList.push_back(burgerK(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			case 1:
				//KBBQ
				kbbqList.push_back(kbbq(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			}
			break;

		case 6:
			//Mexican list
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string mexicanSubcategoryList : mexicanSubcategoryList)
			{
				if (mexicanSubcategoryList == temp)
				{
					break;
				}

				{
					idx++;
				}
			}
			//Mexican switch based on subcategory
			switch (idx)
			{
			case 0:
				//Burrito
				burritoList.push_back(burrito(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			case 1:
				//Fast Food
				fastfoodList.push_back(fastfood(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			}
			break;

		case 7:
			//Thai list
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string thaiSubcategoryList : thaiSubcategoryList)
			{
				if (thaiSubcategoryList == temp)
				{
					break;
				}

				{
					idx++;
				}
			}
			//Alcoholic switch based on subcategory
			switch (idx)
			{
			case 0:
				//Central
				centralList.push_back(central(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			case 1:
				//Isan
				isanList.push_back(isan(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			}
			break;

		case 8:
			//Vietnamese list 
			idx = 0;
			temp = directoryList.subcategory;
			for (std::string vietnameseSubcategoryList : vietnameseSubcategoryList)
			{
				if (vietnameseSubcategoryList == temp)
				{
					break;
				}

				{
					idx++;
				}
			}
			//Vietnamese switch based on subcategory
			switch (idx)
			{
			case 0:
				//Banh mi
				banhmiList.push_back(banhmi(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			case 1:
				//Pho
				phoList.push_back(pho(directoryList.restaurantName,
					directoryList.menuLink, directoryList.imgName, directoryList.recDish));
				break;
			}
			break;
		}

	}
}

//get functions for booleans on if lists built
bool restaurantlistbuilder::getBeverageListEmpty()
{
	return beverageListEmpty;
}
bool restaurantlistbuilder::getFoodListEmpty()
{
	return foodListEmpty;
}

//get functions for category Lists
std::vector<std::string> restaurantlistbuilder::getBeverageCategoryList()
{
	return beverageCategoryList;
}
std::vector<std::string> restaurantlistbuilder::getFoodCategoryList()
{
	return foodCategoryList;
}

//get functions for Beverage Subcategory lists
std::vector<std::string> restaurantlistbuilder::getAlcoholicSubcategoryList()
{
	return alcoholicSubcategoryList;
}
std::vector<std::string> restaurantlistbuilder::getNonalcoholicSubcategoryList()
{
	return nonalcoholicSubcategoryList;
}

//get functions for Food Subcategory lists
std::vector<std::string> restaurantlistbuilder::getAmericanSubcategoryList()
{
	return americanSubcategoryList;
}
std::vector<std::string> restaurantlistbuilder::getDessertSubcategoryList()
{
	return dessertSubcategoryList;
}
std::vector<std::string> restaurantlistbuilder::getInternationalSubcategoryList()
{
	return internationalSubcategoryList;
}
std::vector<std::string> restaurantlistbuilder::getItalianSubcategoryList()
{
	return italianSubcategoryList;
}
std::vector<std::string> restaurantlistbuilder::getJapaneseSubcategoryList()
{
	return japaneseSubcategoryList;
}
std::vector<std::string> restaurantlistbuilder::getKoreanSubcategoryList()
{
	return koreanSubcategoryList;
}
std::vector<std::string> restaurantlistbuilder::getMexicanSubcategoryList()
{
	return mexicanSubcategoryList;
}
std::vector<std::string> restaurantlistbuilder::getThaiSubcategoryList()
{
	return thaiSubcategoryList;
}
std::vector<std::string> restaurantlistbuilder::getVietnameseSubcategoryList()
{
	return vietnameseSubcategoryList;
}

//drinks get calls
std::vector<restaurant> restaurantlistbuilder::getcocktailList()
{
	return cocktailList;
}

std::vector<restaurant> restaurantlistbuilder::getmilkshakeshotList()
{
	return milkshakeshotList;
}

std::vector<restaurant> restaurantlistbuilder::getmilkshakeList()
{
	return milkshakeList;
}

std::vector<restaurant> restaurantlistbuilder::getbubbleteaList()
{
	return bubbleteaList;
}

std::vector<restaurant> restaurantlistbuilder::getcoffeeList()
{
	return coffeeList;
}

//food get calls
std::vector<restaurant> restaurantlistbuilder::getbbqList()
{
	return bbqList;
}

std::vector<restaurant> restaurantlistbuilder::getburgerUSAList()
{
	return burgerUSAList;
}

std::vector<restaurant> restaurantlistbuilder::getcookiesList()
{
	return cookiesList;
}

std::vector<restaurant> restaurantlistbuilder::geticecreamList()
{
	return icecreamList;
}

std::vector<restaurant> restaurantlistbuilder::getpastriesList()
{
	return pastriesList;
}

std::vector<restaurant> restaurantlistbuilder::getburgerJList()
{
	return burgerJList;
}

std::vector<restaurant> restaurantlistbuilder::getramenList()
{
	return ramenList;
}

std::vector<restaurant> restaurantlistbuilder::getsushiList()
{
	return sushiList;
}

std::vector<restaurant> restaurantlistbuilder::getfusionList()
{
	return fusionList;
}

std::vector<restaurant> restaurantlistbuilder::getpastaList()
{
	return pastaList;
}

std::vector<restaurant> restaurantlistbuilder::getpizzaList()
{
	return pizzaList;
}

std::vector<restaurant> restaurantlistbuilder::getburgerKList()
{
	return burgerKList;
}

std::vector<restaurant> restaurantlistbuilder::getkbbqList()
{
	return kbbqList;
}

std::vector<restaurant> restaurantlistbuilder::getburritoList()
{
	return burritoList;
}

std::vector<restaurant> restaurantlistbuilder::getfastfoodList()
{
	return fastfoodList;
}

std::vector<restaurant> restaurantlistbuilder::getcentralList()
{
	return centralList;
}

std::vector<restaurant> restaurantlistbuilder::getisanList()
{
	return isanList;
}

std::vector<restaurant> restaurantlistbuilder::getbanhmiList()
{
	return banhmiList;
}

std::vector<restaurant> restaurantlistbuilder::getphoList()
{
	return phoList;
}
