#include "stdafx.h"
#include "math.h"
#include "iostream"
#include "string"
using namespace std;

//Global Variables
int i = 0, max = 0;
float fi = 0;
float TimeToCreateInSec1 = 0, TimeToCreateInSec2 = 0, ItemsProduced = 1, ItemsRequired = 1, CraftingSpeed1 = 1, CraftingSpeed2 = 1, IngredientsMachines = 0, RequiredMachines = 0, RatioMulti = 0, WholeCheck = 0, IngredientRatio = 0, ProductRatio = 0;
bool isEQ = false, isIngredientMore = false, isRequiredMore = false, isEqual = false;

void Number() {
	if (isIngredientMore == true) { cout << RatioMulti << " times more crafting machines creating the product."; }
	if (isRequiredMore == true) { cout << RatioMulti << " times more crafting machines creating the ingredient."; }
	if (isEqual == true) { cout << "equal amount of crafting machines creating the ingredient and the product."; }
}
//Not used to avoid confusion.
/*void Ratio() {
	if (isIngredientMore == true) { cout << "Ratio:   " << ProductRatio << ":" << IngredientRatio; }
	if (isRequiredMore == true) { cout << "Ratio:     " << IngredientRatio << ":" << ProductRatio; }
}*/

int main()
{
	cout << "Enter raw time to complete for the ingredient in seconds: "; cin >> TimeToCreateInSec1;
	cout << endl << "Enter number of produced ingredients in one recipe: "; cin >> ItemsProduced;
	cout << endl << "Enter crafting speed of the machine producing the ingredients: "; cin >> CraftingSpeed1;
	cout << endl << "Enter raw time to complete for the product in seconds: "; cin >> TimeToCreateInSec2;
	cout << endl << "Enter number of required ingredients in one recipe: "; cin >> ItemsRequired;
	cout << endl << "Enter crafting speed of the machine producing the Product: "; cin >> CraftingSpeed2;
	float IngredientTimePerRecipeInSec = (TimeToCreateInSec1 / CraftingSpeed1);
	float RequiredTimePerRecipeInSec = (TimeToCreateInSec2 / CraftingSpeed2);
	float IngredientTimesPerMinute = (60 / IngredientTimePerRecipeInSec);
	float RequiredTimesPerMinute = (60 / RequiredTimePerRecipeInSec);
	float IngredientPerMinute = (IngredientTimesPerMinute * ItemsProduced);
	float RequiredPerMinute = (RequiredTimesPerMinute * ItemsRequired);
	cout << endl << endl << "Ingredients produced per minute by one crafting machine: " << IngredientPerMinute;
	cout << endl << "Required ingredients per minute by one crafting machine: " << RequiredPerMinute;
	if (IngredientPerMinute > RequiredPerMinute && IngredientPerMinute != RequiredPerMinute) {
		RatioMulti = (IngredientPerMinute / RequiredPerMinute); isIngredientMore = true; }
	if (IngredientPerMinute < RequiredPerMinute && IngredientPerMinute != RequiredPerMinute) {
		RatioMulti = (RequiredPerMinute / IngredientPerMinute); isRequiredMore = true; }
	if (IngredientPerMinute == RequiredPerMinute) {
		RatioMulti = (RequiredPerMinute / RequiredPerMinute); isEqual = true; }
	cout << endl << endl << "Ratio Multiplier: " << RatioMulti;
	cout << endl << "Which means you need "; Number();
	int iIngredientPerMinute = int(IngredientPerMinute);
	int iRequiredPerMinute = int(RequiredPerMinute);
	max = (iIngredientPerMinute > iRequiredPerMinute) ? iIngredientPerMinute : iRequiredPerMinute;
	do {
		if (max % iIngredientPerMinute == 0 && max % iRequiredPerMinute == 0) {
			//cout << endl << "LCM = " << max;
			break;
		}
		else
			++max;
	} while (true);
	IngredientRatio = max / iIngredientPerMinute;
	ProductRatio = max / iRequiredPerMinute;
	cout << endl << endl << "Actual ratio output only works perfectly if both per minute numbers are whole numbers." << endl;
	//Ratio();
	cout << "Ratio:     " << IngredientRatio << ":" << ProductRatio;
	cout << endl << "((Ingredient:Product) in number of crafting machines.)";
	//Not used to avoid confusion.
	/*if (isRequiredMore == true) cout << endl << "((Ingredient:Product) in number of crafting machines.)";
	if (isIngredientMore == true) cout << endl << "((Product:Ingredient) in number of crafting machines.)";*/
	//experimental
	while (isEQ!=true) {
		i++;
		RatioMulti = RatioMulti*i;
		if(ceilf(RatioMulti)==RatioMulti) isEQ=true;
	}
	cout << endl << endl << endl << "~~~~~DEBUG~~~~~";
	cout << endl << isEqual << isRequiredMore << isIngredientMore;
	cout << endl << "LCM: " << max;
	cout << endl << "RatioMulti: " << RatioMulti;
	cout << endl << "Times multiplied: " << i;
	cout << endl;
	system("pause");
	return 0;
}

