#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

struct directory
{
	std::string category;
	std::string subcategory;
	std::string restaurantName;
	std::string menuLink;
	std::string imgName;
	std::string recDish;
};

std::vector<directory> loadRestarautsDirectory(std::string fileName);