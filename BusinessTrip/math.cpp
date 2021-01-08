#include<iostream>
#include<iomanip>
using namespace std;

//These are the fees allowed by the company
const int BREAKFAST = 9;
const int LUNCH = 12;
const int DINNER = 16;
const float MILES = 0.27;
const int PARKING = 6;
const int TAXI = 10;
const int HOTEL = 90;


//Calculate the first day meal costs
float firstDayMealCost = 0.00; int firstDayAllowable = 0.00;
float firstDayB = 0.00, firstDayL = 0.00, firstDayD = 0.00;
//------------------------------------------------------
void firstDayMeal(int days, int departHour, int departMin, string mid)
{
	float mealCost;

	if (days == 1)
	{
		return;
	}

	//If you depart before 7am you get breakfast, lunch, and dinner
	if (mid == "AM" || mid == "am" && departHour < 7)
	{
		cout << "On your first day, how much was your breakfast meal? "; cin >> firstDayB; cout << endl;
		cout << "On your first day, how much was your lunch meal? "; cin >> firstDayL; cout << endl;
		cout << "On your first day, how much was your dinner meal? "; cin >> firstDayD; cout << endl;
		firstDayMealCost = firstDayB + firstDayL + firstDayD;
		firstDayAllowable = BREAKFAST + LUNCH + DINNER;
	}
	//If you depart after 7 and before 12 then you get lunch and dinner
	else if (mid == "AM" || mid == "am" && departHour > 7 && departHour < 12)
	{
		cout << "On your first day, how much was your lunch meal? "; cin >> firstDayL; cout << endl;
		cout << "On your first day, how much was your dinner meal? "; cin >> firstDayD; cout << endl;
		firstDayMealCost = firstDayL + firstDayD;
		firstDayAllowable = LUNCH + DINNER;
	}
	//If you depart after 12 pm you only get dinner
	else if (mid == "PM" || mid == "pm" && departHour <= 12 && departMin > 0)
	{
		cout << "On your first day, how much was your dinner meal? "; cin >> firstDayD; cout << endl;
		firstDayMealCost = firstDayD;
		firstDayAllowable = DINNER;
	}
}

//Calculate the last day meal cost
float lastDayMealCost =0.00; int lastDayAllowable = 0.00;
float lastDayB = 0.00, lastDayL = 0.00, lastDayD = 0.00;
//---------------------------------------------------
void lastDayMeal(int days, int arriveHour, int arriveMin, string mid)
{
	float mealCost;

	if (days == 1)
	{
		return;
	}

	if (mid == "AM" || mid == "am" && arriveHour >= 8 && arriveMin > 0)
	{
		cout << "On the last day, how much was your breakfast? "; cin >> lastDayB; cout << endl;
		lastDayMealCost = lastDayB;
		lastDayAllowable = BREAKFAST;
	}
	else if (mid == "PM" || mid == "pm" && arriveHour >= 1 && arriveHour <= 7)
	{
		cout << "On  your last day, how much was your breakfast? "; cin >> lastDayB; cout << endl;
		cout << "On your last day, how much was your lunch? "; cin >> lastDayL; cout << endl;
		lastDayMealCost = lastDayB + lastDayL;
		lastDayAllowable = BREAKFAST + LUNCH;
	}
	else if (mid == "PM" || mid == "pm" && arriveHour >= 7 && arriveMin > 0)
	{
		cout << "On your last day, how much was your breakfast? "; cin >> lastDayB; cout << endl;
		cout << "On your last day, how much was your lunch? "; cin >> lastDayL; cout << endl;
		cout << "On your last day, how much was your dinner? "; cin >> lastDayD; cout << endl;
		lastDayMealCost = lastDayB + lastDayL + lastDayD;
		lastDayAllowable = BREAKFAST + LUNCH + DINNER;
	}
}

float breakfast = 0.00; float lunch = 0.00; float dinner = 0.00;
void foodOne()
{
	//This function will only occur if days equals one; I have decided to just allow the person the full breakfast, lunch and dinner expenses 
	cout << "How much was your breakfast? "; cin >> firstDayB; cout << endl;
	cout << "How much was your lunch? "; cin >> firstDayL; cout << endl;
	cout << "How much was your dinner? "; cin >> firstDayD; cout << endl;

	firstDayMealCost = firstDayB + firstDayL + firstDayD;
	firstDayAllowable = BREAKFAST + LUNCH + DINNER;
}

void foods()
{
	cout << "Excluding your first and last day, What is your total expenses for your breakfast meal? "; cin >> breakfast; cout << endl;
	cout << "Excluding your first and last day, What is your total expenses for your lunch meal? "; cin >> lunch; cout << endl;
	cout << "Excluding your first and last day, what is your total expenses for your dinner meal? "; cin >> dinner; cout << endl;
}

float hotelExpenses, taxiExpenses, parkingExpenses, foodExpenses;
void totalCost(int days, float airfareCost, float carMiles, float carRentals, float parkingFee, float taxiFee, float conRegFee, float hotelFee)
{
	//Get the total of the food cost and the amount company can pay for
	float food = firstDayMealCost + breakfast + lunch + dinner + lastDayMealCost;
	foodExpenses = firstDayAllowable + lastDayAllowable + (days - 2) * BREAKFAST + (days - 2) * LUNCH + (days - 2) * DINNER;

	//Get hotel total and the amount the company allows for
	float hotel = hotelFee * (days - 1);
	hotelExpenses = HOTEL * (days - 1);

	//Get the total for the car miles
	float car = carMiles * MILES;

	float parkingExpenses = PARKING * days;
	float taxiExpenses = TAXI * days;

	//The overall total expense
	float total = food + hotel + parkingFee + taxiFee + airfareCost + conRegFee + carRentals + car;
	//The company overall total expense
	float companyTotal = foodExpenses + hotelExpenses + parkingExpenses + taxiExpenses + airfareCost + conRegFee + carRentals + car;

	cout << "On this trip, you've spent $" << setprecision(2) << fixed << total << endl;
	cout << "On this trip, the company will pay for $" << setprecision(2) << fixed << companyTotal << endl;

	float check = total - companyTotal;
	if (check > 0)
	{
		check = total - companyTotal;
		cout << "You have to pay $" << setprecision(2) << fixed << check << " out-of-pocket." << endl;
	}
	else if (check < 0)
	{
		check = companyTotal - total;
		cout << "You have saved a total of $" << setprecision(2) << fixed << check <<"\n"<< endl;
	}
}
