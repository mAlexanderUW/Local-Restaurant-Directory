#include "fileHandler.h"

std::vector<directory> loadRestarautsDirectory(std::string fileName)
{
	if (!std::filesystem::exists(fileName))
	{
		return std::vector<directory>();
	}

	std::vector<directory> directoryList;
	std::ifstream istream(fileName);

	int n;
	istream >> n;

	for (int i = 0; i < n; i++)
	{
		std::string category, subcategory, restaurantName, menuLink, imgName, recDish;

		istream >>  category >> subcategory >> restaurantName >> menuLink >> imgName >> recDish;

		std::replace(subcategory.begin(), subcategory.end(), '_', ' ');
		std::replace(restaurantName.begin(), restaurantName.end(), '_', ' ');
		std::replace(recDish.begin(), recDish.end(), '_', ' ');

		directoryList.push_back(directory{ category, subcategory, restaurantName, menuLink, imgName, recDish });
	}

	return directoryList;
}
