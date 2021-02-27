/**
* geolUread
* February 25. 2021
* Weather Statistics
* Create a structure of weather. Include the rainfall, high, low temperature, and average temperature
**/

#include<iostream>
using namespace std;

//A weather structure
struct Weather
{
	float totalRainfall;
	float highTemp;
	float lowTemp;
	float avgTemp;
};

float totalRainfall(Weather x[], int);
void highTempMonth(Weather x[], int);
void lowTempMonth(Weather x[], int);
float annualAverage(Weather x[], int);

int main()
{
	cout << "Weather Statistics - Problem #4\n\n" << endl;

	Weather months[2];	//An array of 12 weather data structure

	for (int i = 0; i < 2; i++)
	{
		cout << "For month " << i + 1 << " enter the total rainfall: "; cin >> months[i].totalRainfall; 
		cout << "For month " << i + 1 << " enter the highest temperature: "; cin >> months[i].highTemp;
		while(months[i].highTemp < -100 || months[i].highTemp > 140)
		{	
			cout << "Please enter a temperature between -100 and 140: "; cin >> months[i].highTemp;
		}
		cout << "For month " << i + 1 << " enter the lowest temperature: "; cin >> months[i].lowTemp;
		while(months[i].lowTemp < -100 || months[i].lowTemp > 140)
		{
			cout << "Please enter a temperature between -100 and 140: "; cin >> months[i].lowTemp;
		}
		cout << endl;
		months[i].avgTemp = (months[i].highTemp + months[i].lowTemp) / 2;
	}

	cout << "The annual total rainfall is " << totalRainfall(months, 2) <<"\n"<< endl;
	highTempMonth(months, 2);
	lowTempMonth(months, 2);
	cout << "The annual average temperature is " << annualAverage(months, 2) << endl <<endl;
	cout << endl;
	system("pause");
	return 0;
}

//A function to calculate and display the average monthly rainfall

//A function to calculate the total rainfall
float totalRainfall(Weather list[], int size)
{
	float total = 0;
	for (int i = 0; i < size; i++)
	{	
		total = total + list[i].totalRainfall;
	}
	return total;
}

//A function to find the highest temperature and months it occured in
void highTempMonth(Weather list[], int size)
{	
	string MONTH[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	
	float highValue = list[0].highTemp;		int highIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i].highTemp > highValue)
		{	
			highValue = list[i].highTemp;
			highIndex = i;
		}
	}

	cout << "The Month with the Highest Temperature is " << MONTH[highIndex] << " with the Temperature at " << highValue; cout << "\n" << endl;

}


//A function to find the lowest temperature and months it occured in
void lowTempMonth(Weather list[], int size)
{
	string MONTH[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	float lowValue = list[0].lowTemp;		int lowIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i].lowTemp < lowValue)
		{
			lowValue = list[i].lowTemp;
			lowIndex = i;
		}
	}

	cout << "The Month with the Lowest Temperature is " << MONTH[lowIndex] << " with the Temperature at " << lowValue; cout << "\n" << endl;

}


float annualAverage(Weather list[], int size)
{	
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + list[i].avgTemp;
	}

	float total = sum / size;
	return total;
}