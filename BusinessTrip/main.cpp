/**
* GeoulRead January 4. 2021
* This program will calculate and display the total travel expenses of a business
* person on a business trip and return the values calculated
*/
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
using namespace std;

void firstDayMeal(int, int, int, string);
void lastDayMeal(int, int, int, string);
void foodOne();
void foods();
void totalCost(int, float, float, float, float, float, float, float);

int main()
{
	char answer, ch;
	bool repeat = false;
	int timeDhour, timeAhour, timeDmin, timeAmin, days;
	float airfareCost, carMiles, parkingFee, taxiFee, conRegFee, hotelFee, rentalFee;
	string depMid, arrMid;

	//Ask if trip expenses is to be calculated
	cout << "C++ Business Trip Program\n\n";

	cout << "Would You Like Your Trip Expenses to be Calculated? Enter Y for Yes and N for No: "; cin >> answer; cout << endl;

	//Checks if the answer is a yes or no and if not repeats the question
	while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
	{
		cout << "Please Enter A Y or N. Would You Like Your Trip Expenses to be Calculated? "; cin >> answer; cout << endl;
	}

	if (answer == 'n' || answer == 'N')
	{
		cout << "Please Enjoy the Rest of Your Day!\n" << endl;
	}
	else
	{
		//This is the outcome if the answer is a yes
		cout << "What is the Total Number of Days of the Business Trip? ";  cin >> days; cout << endl;
		while (days < 1)
		{
			cout << "Please Enter a Value Greater Than 1!: ";  cin >> days; cout << endl;
		}

		//Depature
		//This will check the depature time and validate the input 
		cout << "Please Enter the Time of Depature. Please Input As (HH:MM): ";  cin >> timeDhour >> ch >> timeDmin; cout << endl;
		while (timeDmin < 0 || timeDmin > 60 || timeDhour < 0 || timeDhour > 12 || ch != ':')
		{
			cout << "Please Enter a Valid Time in the HH:MM Format! Enter Time of Depature: "; cin >> timeDhour >> ch >> timeDmin; cout << endl;
		}
		//This will check and validate the time abberviation for the depature
		cout << "If it was AM Please Type AM. If it is PM Please Type PM: "; cin >> depMid; cout << endl;
		while (depMid != "AM" && depMid != "am" && depMid != "PM" && depMid != "pm")
		{
			cout << "Please Enter a Valid Midday Abbreviation for Depature: "; cin >> depMid; cout << endl;
		}

		firstDayMeal(days, timeDhour, timeDmin, depMid);
		cout << endl;
		cout << endl;

		//Arrival
		//This will check the arrival time and validate the input 
		cout << "Please Enter the Time of Arrival. Please Input As (HH:MM): ";  cin >> timeAhour >> ch >> timeAmin; cout << endl;
		while (timeAmin < 0 || timeAmin > 60 || timeAhour < 0 || timeAhour > 12 || ch != ':')
		{
			cout << "Please Enter a Valid Time in the HH:MM Format! Enter Time of Depature: "; cin >> timeAhour >> ch >> timeAmin; cout << endl;
		}

		//This will check and validate the time abbreviation for arrival 
		cout << "If it was AM Please Type AM. If it is PM Please Type PM: "; cin >> arrMid; cout << endl;
		while (arrMid != "am" && arrMid != "AM" && arrMid != "pm" && arrMid != "PM")
		{
			cout << "Please Enter a Valid Midday Abbreviation for Arrival: "; cin >> arrMid; cout << endl;
		}

		lastDayMeal(days, timeAhour, timeAmin, arrMid);
		cout << endl;
		cout << endl;

		//This will ask for airfare information
		cout << "Please Input the Rountrip Airfare Cost: "; cin >> airfareCost; cout << endl;
		while (airfareCost < 0)
		{
			cout << "Please Input a Value Zero or Greater: "; cin >> airfareCost; cout << endl;
		}

		cout << "Did you Drive your own Personal Vehicle? Enter Y for Yes or N for No: "; cin >> answer; cout << endl;
		while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
		{
			cout << "Please Enter A Y or N. Did you Drive Your Personal Vehicle? "; cin >> answer; cout << endl;
		}
		if (answer == 'Y' || answer == 'y')
		{
			cout << "How Many Miles Did you Travel? "; cin >> carMiles; cout << endl;
			//Validating the car miles
			while (carMiles < 0)
			{
				cout << "Please Input Zero or a Value Greater than 0: "; cin >> carMiles; cout << endl;
			}
		}
		else
		{
			carMiles = 0;
		}
		//Ask car rental information
		cout << "If you Used a Car Rental, Please Input Cost:  "; cin >> rentalFee; cout << endl;

		cout << "If you Used Parking, Please Enter the Total Parking Fees: "; cin >> parkingFee; cout << endl;
		cout << "If you used a Taxi, Please Input the fee: "; cin >> taxiFee; cout << endl;
		cout << "Please Input any Conference or Registration Fee: "; cin >> conRegFee; cout << endl;

		//This is if the person decides to stay in the hotel within a one day trip
		if (days == 1)
		{
			if (timeDhour > 7 && timeAhour > 7 && depMid == "pm" || depMid == "PM")
			{
				cout << "Will you be staying at a hotel temporarily? Input a Y for yes and N for no: "; cin >> answer; cout << endl;
				while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
				{
					cout << "Please Enter A Y or N: "; cin >> answer; cout << endl;
				}
				if (answer == 'Y' || answer == 'y')
				{
					cout << "Please Input your Hotel Expense per Night: "; cin >> hotelFee; cout << endl;
				}
				else
				{
					hotelFee = 0.00;
				}
			}
			else
			{
				hotelFee = 0.00;
			}
			foodOne();
		}
		else
		{
			cout << "Please Input your Hotel Expense per Night: "; cin >> hotelFee; cout << endl;
			foods();
		}
		cout << "--------------------------------------------------------------------------------------" << endl;

		totalCost(days, airfareCost, carMiles, rentalFee, parkingFee, taxiFee, conRegFee, hotelFee);
	}
	system("pause");
	return 0;
}
