#pragma once
//wxWidgets
#include <wx/wx.h>
#include <wx/hyperlink.h>
#include <wx/generic/statbmpg.h>
#include <wx/srchctrl.h>
#include <wx/treectrl.h>
//restaurant directory
#include "restaurantlistbuilder.h"
#include "fileHandler.h"
//base restaurant class
#include "restaurant.h"
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
#include "pizza.h"
#include "burgerk.h"
#include "kbbq.h"
#include "burrito.h"
#include "fastfood.h"
#include "central.h"
#include "isan.h"
#include "banhmi.h"
#include "pho.h"


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private:
	//creates window and bind quit button if lists are empty
	void createExit();
	void bindQuit();
	//builds windows/list/controls if lists arent empty
	void createControls();
	void createLists();
	void createSizers();
	void bindEvents();
	//events to bind to controls
	void QuitButtonClicked(wxCommandEvent& evt);
	void selectedRoot(wxCommandEvent& evt);
	void selectedCategory(wxCommandEvent& evt);
	void selectedSubCategory(wxCommandEvent& evt);
	void selectedRestaurant(wxCommandEvent& evt);
	//populates info in the restraunt display area
	void changeRecDisplay();
	void displayDefault();
	//passes vector to change to a wxArrrayString to be inserted into a listbox
	wxArrayString vectorToArray(std::vector<std::string>);
	//Breaks down a restaurant to it string arrays for its different fields
	void restaurantToArray(std::vector<restaurant>);

	//wxWidget controls that make up the window and controls
	wxPanel* panel;
	wxStaticText* titleText;
	wxStaticText* mainText;
	wxListBox* listBoxMain;
	wxStaticText* textCategory;	
	wxListBox * listBoxCategory;
	wxListBox* listBoxSubCategory;
	wxStaticText* textSubCategory;
	wxListBox* listBoxRestaurant;
	wxButton* quitButton;
	//wxWidget data fields for the restaurant
	wxStaticText* textRestaurant;
	wxHyperlinkCtrl* menuLink;
	wxStaticText* recText;
	wxGenericStaticBitmap* recImage;
	//Sizers for organize the layout of the window
	wxBoxSizer* mainSizer;
	wxBoxSizer* horzSizer;
	wxBoxSizer* vertLeftSizer;
	wxBoxSizer* vertMiddleSizer;
	wxBoxSizer* vertRightSizer;
	wxGridSizer* outerBorder;
	//for passing the selected index into the events
	int selectedIdx;
	//directory compontent to be populated when a sub category is picked
	wxArrayString restaurantNameArray;
	wxArrayString menuLinkArray;
	wxArrayString imgNameArray;
	wxArrayString recDishArray;
	//creates and stores the lists of restaurants
	restaurantlistbuilder builder;
	
};

