#include<iostream>
#include<iomanip>
using namespace std;
//Variables
const int COLUMNS = 30; const int ROWS = 15; 

float overallTotal = 0.00;
int ticket = 0; 

//This will set up the theater with the # "avaliable" characters
void theaterSetup(char array[][COLUMNS], int r, int c)
{ 
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			array[i][j] = '#';
		}
	}
}

//This will display the thater whenever it is called
void theaterDisplay(char array[][COLUMNS], int r, int c)
{
	cout << "Avaliable Seats = # & Taken Seats = *" << endl;
	cout << setw(52) << "SEATS" << endl;
	cout << "	1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30" << endl;
	for (int i = 0; i < r; i++)
	{
		cout << "Row " << i + 1 << "	";
		for (int j = 0; j < c; j++)
		{
			cout << array[i][j] << "  ";
		}
		cout << endl;
	}
}

//This will take care of the transactions
void theaterPurchase(char array[][COLUMNS], float priceArray[])
{
	int rowChoice, seatChoice; float yourTotal = 0.00; char answer; bool again = false;

	//This will repeat the question until the user says no
	while (!again)
	{
		cout << "What Row would you Choose? "; cin >> rowChoice; cout << endl;
		while (rowChoice < 1 || rowChoice > 15)
		{
			cout << "That Row does not Exist. Please Make Another Choice "; cin >> rowChoice; cout << endl;
		}
		cout << "What Seat Number would you Choose? "; cin >> seatChoice; cout << endl;
		while (seatChoice < 1 || seatChoice > 30)
		{
			cout << "That Seat Choice does not Exist. Please Make Another Choice "; cin >> seatChoice; cout << endl;
		}

		rowChoice -= 1; seatChoice -= 1;

		if (array[rowChoice][seatChoice] == '*')
		{
			cout << "Your Seat Selection is Unavaliable!\n" << endl;
		}
		else
		{
			//Set the seat location to unavaliable
			array[rowChoice][seatChoice] = '*';
			//Add the price to the overall total
			overallTotal = overallTotal + priceArray[rowChoice];
			//Increment the number of tickets sold
			ticket++;

			yourTotal = yourTotal + priceArray[rowChoice];
		}

		//Ask if the user will purchase another seat to handle all the transactions at once
		cout << "Will you Purchase another Seat? "; cin >> answer; cout << endl;
		while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
		{
			cout << "Please Input a Valid Response. Y for yes or N for no: "; cin >> answer; cout << endl;
		}

		if (answer == 'N' || answer == 'n')
		{
			again = true;
		}
	}
	cout << "The total is $" << setprecision(2) << fixed<< yourTotal << endl;
}

//This will display how many tickets have been sold and the overall total of the purchases
void theaterTicketsSold()
{
	cout << "You have sold " << ticket << " tickets. Overall you have made $" << setprecision(2)<< fixed << overallTotal << endl;
}

int seatAvailable()
{
	int available = (ROWS * COLUMNS) - ticket;
	return available;
}

int seatAvailableRow(char array[][COLUMNS], int r)
{
	int x = 0; 

	//You must take away 1, since row 1 is actually row 0
	r -= 1;
	for (int i = 0; i < COLUMNS; i++)
	{
		if (array[r][i] == '#')
		{
			x++;
		}
	}
	return x;
}
