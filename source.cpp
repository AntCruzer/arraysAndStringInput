// INCLUDES
#include <iostream>
#include <sstream>



// OMIT 'std::'
using namespace std;



// FUNCTION PROTOTYPES (OK)
int dayToIndex(string input_day);
double calculateCostOfRoom(const double roomRates[], int check_in_day, int check_out_day);



int main()
{
	// declare constants
	const int NUM_RATES = 6;
	const int NUM_ATTEND = 4;

	// initialize counters
	int i = 0;
	int j = 0;

	// initialize strings
	string name;
	string first_day;
	string last_day;

	// declare array of rates (prices)
	const double roomRates[NUM_RATES] = {127.50, 128.25, 130.50, 150, 150, 162.50};

	// initialize variables
	int first_index = 0;
	int second_index = 0;
	double cost = 0.00;
    double final_sum = 0.00;

	// prompt for each attendee
	for (i = 0; i < NUM_ATTEND; i++)
	{
		// prompt to input name
		cout << "Enter name: ";

		// obtain name
		getline(cin, name);

		// if no name provided by user...
		if (name == "" || name == " ")
		{
			cout << "Error: missing name. Skipping check-in process for " << name << endl;
			continue;
		}

		// prompt for check-in day
		cout << "Enter check-in day: ";
		getline(cin, first_day);

		// function call
		first_index = dayToIndex(first_day);
		
		// output if input was invalid
		if (first_index == -1)
		{
			cout << "Error: Invalid input. Skipping check-in process for " << name << endl;
			continue;
		}

		// if they are checking in late
		if (first_day == "fri" || first_day == "sat")
		{
			cout << "Error: Late check-in day. " << name << " missed the meeting." << endl;
			continue;
		}

		// prompt for check-out day
		cout << "Enter day are they checking out: ";
		getline(cin, last_day);

		// function call
		second_index = dayToIndex(last_day);

		// output if input was invalid
		if (second_index == -1)
		{
			cout << "Error: Invalid input. Skipping check-out process for " << name << endl;
			continue;
		}

		// if they are checking out early
		if (last_day == "sun" || last_day == "mon" || last_day == "tue" || last_day == "wed")
		{
			cout << "Error: " << name << " will miss the meeting. Skipping check out process." << endl;
			continue;
		}

		// if they are checking in and out the same day
		if (first_day == last_day)
		{
			cout << name << " cannot check in and out the same day" << endl;
			continue;
		}
		
		// function call
		cost = calculateCostOfRoom(roomRates, first_index, second_index);
    
		// display name and total room cost
		cout << name << " has to pay " << cost << " for their stay." << endl;

        final_sum += cost;
	}

    // display total cost
    printf("Total costs for the entire group: $%.2f.", final_sum);

    return 0;
}



/*
*   Function:       dayToIndex()
*   Parameters:     string input_day: contains first 3 letters of a day of the week
*   Returns:        int index: array index corresponding to day of the week or -1 if string day invalid
*   Description:    This function converts day given by the user and convert it to an array index
*/
int dayToIndex(string input_day)
{
	// initialize variables
	int i = 0;
	const int NUM_ELEM = 7;
	const string days[] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat" };
	int index = -1;

	// validate in input matches on of the array elements
	for (i = 0; i < NUM_ELEM; i++)
	{
		if (input_day == days[i])
		{
			index = i;
			break;
		}
	}
	return index;
}



/*
*   Function:       calculateCostOfRoom()
*   Parameters:     double roomRates: array of doubles containing rates
*                   int check_in_day: the day of check-in as an index into the array
*				    int check_out_day: the day of check-out, as an index into the array
*   Returns:        double cost : cost for stay, sum of array elements excluding last day
*   Description:    This function calculates and returns the total cost for the attendee's stay
*/
double calculateCostOfRoom(const double array[], int check_in_day, int check_out_day)
{
	double cost = 0;
	int i = 0;

	for (i = check_in_day; i < check_out_day; i++)
	{
		cost += array[i];
	}
	return cost;
}