#include "MainFrame.h"

//create id numbers for the main controls
enum IDs
{
	LISTBOX_ID = 3,
	LISTBOX2_ID,
	LISTBOX3_ID,
	LISTBOX4_ID,
	QUITBUTTON_ID,
};
//calls all the creation of the window
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	createLists();
	//some check needs to be here for missing file?
	if (builder.getBeverageListEmpty() && builder.getFoodListEmpty())
	{
		createExit();
		bindQuit();
	}
	else {
		createControls();
		createSizers();
		bindEvents();
	}
	
}
//Creatation of exit screen if lists are empty
void MainFrame::createExit()
{
	SetIcon(wxIcon("FOOD_ICON"));
	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxWANTS_CHARS);

	titleText = new wxStaticText(panel, wxID_ANY, "No directory file found, please exit check the resources folder for \"food.txt\" and \"drinks.txt\"");
	quitButton = new wxButton(panel, QUITBUTTON_ID, "Quit",
		wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);

	mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(titleText, wxSizerFlags().CenterHorizontal().Border(wxALL,25));
	mainSizer->Add(quitButton, wxSizerFlags().Right().Border(wxALL, 25));

	panel->SetSizer(mainSizer);
	mainSizer->SetSizeHints(this);
}
//bind quit for createExit()
void MainFrame::bindQuit()
{
	quitButton->Bind(wxEVT_BUTTON, &MainFrame::QuitButtonClicked, this);
	quitButton->Bind(wxEVT_TEXT_ENTER, &MainFrame::QuitButtonClicked, this);
}
//Creates the window and controls
void MainFrame::createControls()
{
	//sets icon for window
	SetIcon(wxIcon("FOOD_ICON"));
	//creation of two main fonts
	wxFont titleFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));
	//creates the panel that the controls will be on
	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxWANTS_CHARS);
	panel->SetFont(mainFont);
	//creation of the titles and subtitles on the panel
	titleText = new wxStaticText(panel, wxID_ANY, "Food Options");
	titleText->SetFont(titleFont);
	mainText = new wxStaticText(panel, wxID_ANY, "Food or Drink?");
	textCategory = new wxStaticText(panel, wxID_ANY, "Category");
	textSubCategory = new wxStaticText(panel, wxID_ANY, "SubCategory");
	textRestaurant = new wxStaticText(panel, wxID_ANY, "Restaurant");
	//creation of listboxes
	listBoxMain = new wxListBox(panel, LISTBOX_ID, wxDefaultPosition, wxDefaultSize, { "Food", "Drinks" });
	listBoxCategory = new wxListBox(panel, LISTBOX2_ID);
	listBoxSubCategory = new wxListBox(panel, LISTBOX3_ID);
	listBoxRestaurant = new wxListBox(panel, LISTBOX4_ID);
	//creation of the display area for the recommended restaurant
	recImage = new wxGenericStaticBitmap(panel, wxID_ANY, wxBitmap("MENU_BITMAP"));
	menuLink = new wxHyperlinkCtrl(panel, wxID_ANY, wxT("Link To Recommend Restraunt's Menu here"),
		wxT("https://www.konamisushi.com/menus"));
	recText = new wxStaticText(panel, wxID_ANY, "Recommendation: Dish Name will be displayed here.");
	//quit button
	quitButton = new wxButton(panel, QUITBUTTON_ID, "Quit",
		wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
}
//Creation of all of the food & drink lists
void MainFrame::createLists()
{
	builder.buildBeverageRestaurants();
	builder.buildFoodRestaurants();
}
//Creation of sizers for the layout of the window
void MainFrame::createSizers()
{
	mainSizer = new wxBoxSizer(wxVERTICAL);
	horzSizer = new wxBoxSizer(wxHORIZONTAL);
	vertLeftSizer = new wxBoxSizer(wxVERTICAL);
	vertMiddleSizer = new wxBoxSizer(wxVERTICAL);
	vertRightSizer = new wxBoxSizer(wxVERTICAL);

	mainSizer->Add(titleText, wxSizerFlags().CenterHorizontal());
	mainSizer->AddSpacer(25);

	horzSizer->Add(vertLeftSizer, wxSizerFlags().Expand().Proportion(1));
	vertLeftSizer->Add(mainText, wxSizerFlags().CenterHorizontal());
	vertLeftSizer->Add(listBoxMain, wxSizerFlags().Expand());
	vertLeftSizer->AddSpacer(5);
	vertLeftSizer->Add(textCategory, wxSizerFlags().CenterHorizontal());
	vertLeftSizer->Add(listBoxCategory, wxSizerFlags().Expand().Proportion(1));
	vertLeftSizer->AddSpacer(5);
	vertLeftSizer->Add(textSubCategory, wxSizerFlags().CenterHorizontal());
	vertLeftSizer->Add(listBoxSubCategory, wxSizerFlags().Expand().Proportion(1));

	horzSizer->AddSpacer(5);

	horzSizer->Add(vertMiddleSizer, wxSizerFlags().Expand().Proportion(1));
	vertMiddleSizer->Add(textRestaurant, wxSizerFlags().CenterHorizontal());
	vertMiddleSizer->Add(listBoxRestaurant, wxSizerFlags().Expand().Proportion(1));

	horzSizer->AddSpacer(5);

	horzSizer->Add(vertRightSizer, wxSizerFlags().Expand().Proportion(1));
	vertRightSizer->Add(menuLink, wxSizerFlags().CenterHorizontal());
	vertRightSizer->AddSpacer(5);
	vertRightSizer->Add(recImage, wxSizerFlags().CenterHorizontal().Proportion(1));
	vertRightSizer->AddSpacer(5);
	vertRightSizer->Add(recText, wxSizerFlags().CenterHorizontal());
	horzSizer->AddSpacer(5);

	mainSizer->Add(horzSizer, wxSizerFlags().Expand().Proportion(1));
	mainSizer->AddSpacer(15);
	mainSizer->Add(quitButton, wxSizerFlags().Right());

	outerBorder = new wxGridSizer(1);
	outerBorder->Add(mainSizer, wxSizerFlags().Border(wxALL, 25).Expand());

	panel->SetSizer(outerBorder);
	outerBorder->SetSizeHints(this);
}
//binds events to the controls
void MainFrame::bindEvents()
{
	listBoxMain->Bind(wxEVT_LISTBOX, &MainFrame::selectedRoot, this);
	listBoxCategory->Bind(wxEVT_LISTBOX, &MainFrame::selectedCategory, this);
	listBoxSubCategory->Bind(wxEVT_LISTBOX, &MainFrame::selectedSubCategory, this);
	listBoxRestaurant->Bind(wxEVT_LISTBOX, &MainFrame::selectedRestaurant, this);
	quitButton->Bind(wxEVT_BUTTON, &MainFrame::QuitButtonClicked, this);
	quitButton->Bind(wxEVT_TEXT_ENTER, &MainFrame::QuitButtonClicked, this);
}
//Clicking the close button close the window and stops the app
void MainFrame::QuitButtonClicked(wxCommandEvent& evt)
{
	Close(true);
}
//handles event when the mainlist box is clicked and generates category list based on user's interaction
void MainFrame::selectedRoot(wxCommandEvent& evt)
{
	int temp = listBoxMain->GetSelection();
	//clear old selections data from listboxes
	listBoxCategory->Clear();
	listBoxSubCategory->Clear();
	listBoxRestaurant->Clear();
	//displays default info on the right instead of last restaunt selected
	displayDefault();

	switch (temp)
	{
	case 0:
		//food
		listBoxCategory->InsertItems(vectorToArray(builder.getFoodCategoryList()), 0);
		break;

	case 1:
		//drinks
		listBoxCategory->InsertItems(vectorToArray(builder.getBeverageCategoryList()), 0);
		break;
	}
}
//handles event when the category list box is clicked and generates subcategory list based on user's interaction
void MainFrame::selectedCategory(wxCommandEvent& evt)
{
	int temp = listBoxMain->GetSelection();
	//clear old selections data from listboxes
	listBoxSubCategory->Clear();
	listBoxRestaurant->Clear();
	//displays default info on the right instead of last restaunt selected
	displayDefault();

	switch (temp)
	{
	case 0:
		//food
		temp = listBoxCategory->GetSelection();
		switch (temp)
		{
		case 0:
			//american
			listBoxSubCategory->InsertItems(vectorToArray(builder.getAmericanSubcategoryList()), 0);
			break;
		case 1:
			//dessert
			listBoxSubCategory->InsertItems(vectorToArray(builder.getDessertSubcategoryList()), 0);
			break;
		case 2:
			//international
			listBoxSubCategory->InsertItems(vectorToArray(builder.getInternationalSubcategoryList()), 0);
			break;
		case 3:
			//italian
			listBoxSubCategory->InsertItems(vectorToArray(builder.getItalianSubcategoryList()), 0);
			break;
		case 4:
			//japanese
			listBoxSubCategory->InsertItems(vectorToArray(builder.getJapaneseSubcategoryList()), 0);
			break;
		case 5:
			//korean
			listBoxSubCategory->InsertItems(vectorToArray(builder.getKoreanSubcategoryList()), 0);
			break;
		case 6:
			//mexican
			listBoxSubCategory->InsertItems(vectorToArray(builder.getMexicanSubcategoryList()), 0);
			break;
		case 7:
			//thai
			listBoxSubCategory->InsertItems(vectorToArray(builder.getThaiSubcategoryList()), 0);
			break;
		case 8:
			//vietnamese
			listBoxSubCategory->InsertItems(vectorToArray(builder.getVietnameseSubcategoryList()), 0);
			break;
		}
		break;
	

	case 1:
		//drinks
		temp = listBoxCategory->GetSelection();
		switch (temp)
		{
		case 0:
			//alcoholic
			listBoxSubCategory->InsertItems(vectorToArray(builder.getAlcoholicSubcategoryList()), 0);
			break;
		case 1:
			//nonalcoholic
			listBoxSubCategory->InsertItems(vectorToArray(builder.getNonalcoholicSubcategoryList()), 0);
			break;
		
		}
		break;
	}
}
//handles event when the subcategory list box is clicked and generates restaurant list based on user's interaction
void MainFrame::selectedSubCategory(wxCommandEvent& evt)
{
	int temp = listBoxMain->GetSelection();
	//clear old restaunt selections from listbox
	listBoxRestaurant->Clear();

	switch (temp)
	{
	case 0:
		//food
		temp = listBoxCategory->GetSelection();
		switch (temp)
		{
		case 0:
			//american
			temp = listBoxSubCategory->GetSelection();
			switch (temp)
			{
			case 0:
				restaurantToArray(builder.getbbqList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;

			case 1:
				restaurantToArray(builder.getburgerUSAList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			}
			break;
		case 1:
			//dessert
			temp = listBoxSubCategory->GetSelection();
			switch (temp)
			{
			case 0:
				restaurantToArray(builder.getcookiesList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;

			case 1:
				restaurantToArray(builder.geticecreamList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			case 2:
				restaurantToArray(builder.getpastriesList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			}
			break;
		case 2:
			//international
			restaurantToArray(builder.getfusionList());
			listBoxRestaurant->InsertItems(restaurantNameArray, 0);
			break;
		case 3:
			//italian
			temp = listBoxSubCategory->GetSelection();
			switch (temp)
			{
			case 0:
				restaurantToArray(builder.getpastaList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;

			case 1:
				restaurantToArray(builder.getpizzaList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			}
			break;
		case 4:
			//japanese
			temp = listBoxSubCategory->GetSelection();
			switch (temp)
			{
			case 0:
				restaurantToArray(builder.getburgerJList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;

			case 1:
				restaurantToArray(builder.getramenList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			case 2:
				restaurantToArray(builder.getsushiList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			}
			break;
		case 5:
			//korean
			temp = listBoxSubCategory->GetSelection();
			switch (temp)
			{
			case 0:
				restaurantToArray(builder.getburgerKList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;

			case 1:
				restaurantToArray(builder.getkbbqList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			}
			break;
		case 6:
			//mexican;
			temp = listBoxSubCategory->GetSelection();
			switch (temp)
			{
			case 0:
				restaurantToArray(builder.getburritoList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;

			case 1:
				restaurantToArray(builder.getfastfoodList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			}
			break;
		case 7:
			//thai
			temp = listBoxSubCategory->GetSelection();
			switch (temp)
			{
			case 0:
				restaurantToArray(builder.getcentralList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;

			case 1:
				restaurantToArray(builder.getisanList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			}
			break;
		case 8:
			//vietnamese
			temp = listBoxSubCategory->GetSelection();
			switch (temp)
			{
			case 0:
				restaurantToArray(builder.getbanhmiList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;

			case 1:
				restaurantToArray(builder.getphoList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			}
			break;
		}
		break;

	case 1:
		//drinks
		temp = listBoxCategory->GetSelection();
		switch (temp)
		{
		case 0:
			//alcoholic
			temp = listBoxSubCategory->GetSelection();
			switch (temp)
			{
			case 0:
				restaurantToArray(builder.getcocktailList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;

			case 1:
				restaurantToArray(builder.getmilkshakeshotList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			}
			break;
		case 1:
			//nonalcoholic
			temp = listBoxSubCategory->GetSelection();
			switch (temp)
			{
			case 0:
				restaurantToArray(builder.getbubbleteaList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;

			case 1:
				restaurantToArray(builder.getcoffeeList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			case 2:
				restaurantToArray(builder.getmilkshakeList());
				listBoxRestaurant->InsertItems(restaurantNameArray, 0);
				break;
			}
			break;

		}
		break;
	}
}
//handles event when the restaurant list box is clicked and generates restaurant information on user's interaction
void MainFrame::selectedRestaurant(wxCommandEvent& evt)
{
	selectedIdx = listBoxRestaurant->GetSelection();
	changeRecDisplay();
}
//changes the information of the dispayed restraunt from the selectedRestaurant event
void MainFrame::changeRecDisplay()
{
	directory tempRes; //= directoryList.at(selectedIdx);
	menuLink->SetLabel("Menu for: " + restaurantNameArray[selectedIdx]);
	menuLink->SetURL(menuLinkArray[selectedIdx]);
	recImage->SetBitmap(wxBitmap(imgNameArray[selectedIdx]));
	recText->SetLabel("Recommended dish: " + recDishArray[selectedIdx]);
	outerBorder->SetSizeHints(this);

}
//changes the information of the restraunt display area back to default if no restaurant is selected
void MainFrame::displayDefault()
{
	menuLink->SetLabel("Link To Recommend Restraunt's Menu here");
	menuLink->SetURL("https://www.google.com/search?q=restaurants+near+me");
	recImage->SetBitmap(wxBitmap("MENU_BITMAP"));
	recText->SetLabel("Recommendation: Dish Name will be displayed here.");
	outerBorder-> SetSizeHints(this);
}
//passed vector to be made into arraysting to be inserted into a listbox
wxArrayString MainFrame::vectorToArray(std::vector<std::string> vectorString)
{
	wxArrayString tempArray;

	for (std::string vectorString : vectorString)
	{
		tempArray.Add(vectorString);
	}
	return tempArray;
}
//use the base class to accept any food or drink to populate arrays for the recommendtion pannel
void MainFrame::restaurantToArray(std::vector<restaurant> restaurantInfo)
{
	//clears last subcategory's list of restaurants info out
	restaurantNameArray.Clear();
	menuLinkArray.Clear();
	imgNameArray.Clear();
	recDishArray.Clear();

	//populates array with current selected subcategory's data
	for (restaurant restaurantInfo : restaurantInfo)
	{
		restaurantNameArray.Add(restaurantInfo.getRestaurantName());
		menuLinkArray.Add(restaurantInfo.getMenuLink());
		imgNameArray.Add(restaurantInfo.getImgName());
		recDishArray.Add(restaurantInfo.getRecDish());
	}
}

