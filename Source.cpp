/*
This is a simple C++ program that splits a bill.

There's an episode of Parks and Rec in which the gang goes 
out to dinner and Ann complains to the camera that she hates 
when the bill for a group meal inevitably ends up being split evenly, 
leaving inexpensive-meal-orderers like her to cover for the 
expensive-meal-orderers (i.e. Tom).

This is definitely a real life college kid problem. My roommate 
once spent 20 minutes trying to divide up tax and tip proportionally 
after a 12-person birthday party dinner.

But now we just have to open this program, type in everyone's meal cost, and voila !
*/



#include<iostream>
#include<string>
using namespace std;



class Diner
{
public:
	void setName(string name) {
		m_name = name;
	}
	void setPrice(double price) {
		m_price = price;
	}
	string getName() {
		return m_name;
	}
	double getPrice() {
		return m_price;
	}
private:	
	double m_price;
	string m_name;
};


int main()
{
	double total;
	int ndiners;
	Diner *dinerPtr;
	double subtotal = 0;
	double taxAndTip;


	cout << "Please enter number of diners: ";
	cin >> ndiners;
	cin.ignore(10000, '\n');

	dinerPtr = new Diner[ndiners];

	cout << "Enter bill total: $";
	cin >> total;
	cin.ignore(1000, '\n');

	//get each diner's name and meal price and calculate subtotal
	for (int i = 0; i < ndiners; i++) {
		cout << "Enter name for diner " << (i + 1) << ": ";
		string name;
		getline(cin, name);

		cout << "Enter meal price for diner " << (i + 1) << ": $";
		double price;
		cin >> price;
		std::cin.ignore(10000, '\n');

		subtotal += price;

		dinerPtr[i].setName(name);
		dinerPtr[i].setPrice(price);
	}

	taxAndTip = total - subtotal;

	//calculate and set the cost of a person's meal as a percent of total cost
	for (int i = 0; i < ndiners; i++) {
		double price = dinerPtr[i].getPrice();
		double percent = price/subtotal;

		double dinersCost = price + (percent * taxAndTip);

		cout.setf(ios::fixed);
		cout.precision(2);
		cout << dinerPtr[i].getName() << "'s cost is $" << dinersCost << endl;
	}

	delete[] dinerPtr;

}
