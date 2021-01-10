//This is the theater seating programming assignment
//C++ Target Practice --> Arrays and 2D Arrays
//January 8th 2021   GeolUread 

#include<iomanip>
#include<iostream>
using namespace std;

//Function prototype
const int ROWS = 15; const int COLUMNS = 30;
//Initializing the 2D array and price array -- If the array below is commented out it is because I have initialized an array below without user input
char theater[ROWS][COLUMNS];	//float price[ROWS];

void theaterSetup(char array[][COLUMNS], int row, int col);	
void theaterDisplay(char array[][COLUMNS], int row, int col);		//d
void theaterPurchase(char array[][COLUMNS], float price[]);		//t
void theaterTicketsSold();														//s
int seatAvailable();																//a
int seatAvailableRow(char array[][COLUMNS], int row); 			//r



int main()
{
	std::cout << "Theater Seat Assignment - Chapter 7 Group Project\n" << std::endl;
	theaterSetup(theater, ROWS, COLUMNS);

	//Character input variable		//Row number input variable
	char command;					int rowNumber;
		
	//Flag indicator
	bool finish = false;

	//We are going to input the price of each row into the array price, if you want to skip user input then you can easily use the premade list
	float price[ROWS] = { 15.00, 14.50, 14.00, 13.00, 12.00, 11.00, 10.00, 9.50, 8.00, 7.50, 7.00, 6.50, 6.00, 5.00, 2.00 };

	//cout << "Please enter the Price of Each the Rows" << endl;
	//cout << "Please note that Row 15 is the back and Row 1 is the front\n" << endl;
	//for (int i = 0; i < ROWS; i++)
	//{
	//	cout << "The Price for Row " << i + 1 << " is: "; cin >> price[i]; cout << endl;
	//	while (price[i] < 0)
	//	{
	//		cout << "Please enter a Valid Price: "; cin >> price[i];
	//	}
	//}
	//cout << endl;
	//theaterDisplay(theater, ROWS, COLUMNS);
	//cout << endl;

	while(!finish)
	{
		cout << "Please Enter a Command:" << endl;
		cout << "Display Seating Chart (d)" << endl;
		cout << "Purchase Ticket/Tickets (t)" << endl;
		cout << "Display Total Ticket Sold and the Total (s)" << endl;
		cout << "Display Total Total Seats Avaliable (a)" << endl;
		cout << "Display Total Seat Available in Row X (r)" << endl;
		cout << "Quit (q)\n" << endl;
		cout << "Your command is: "; cin >> command; cout << endl;
		
		if (command == 'd') { theaterDisplay(theater, ROWS, COLUMNS); }
		else if (command == 't') { theaterPurchase(theater, price); }
		else if (command == 's') { theaterTicketsSold(); }
		else if (command == 'a') { cout << "There are " << seatAvailable() <<" seats available"<< endl; }
		else if(command == 'r')
		{
			cout << "Enter Row Number: "; cin >> rowNumber; cout << endl;
			while (rowNumber < 1 || rowNumber > 15)
			{
				cout << "Please Enter a Valid Row Number: "; cin >> rowNumber; cout << endl;
			}
			cout << "There are " << seatAvailableRow(theater, rowNumber) << " seats available in row " << rowNumber << endl;
		}
		else if (command == 'q') { finish = true;  }
		else
		{
			cout << command << " is an Invalid Command. Please Enter a Valid Command "<< endl;
		}
		cout << endl;
		cout << endl;
	}

	cout << "The Program has Ended!" << endl;
	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}