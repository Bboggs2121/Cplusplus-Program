#include "Grocery.h"
#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cctype>
using namespace std;

string formatString(size_t n, char c)
{
	return string(n, c);
}

bool icompare_pred(unsigned char a, unsigned char b) { // Will take first character of the string and set to lower
	return tolower(a) == tolower(b);
}

bool icompare(string const& a, string const& b) { // Function to compare string length and set up non case sensitive searching
	if (a.length() == b.length()) {
		return equal(b.begin(), b.end(), a.begin(), icompare_pred);
	}
	else {
		return false;
	}
}

void DisplayMenu() {
	cout << setw(31);
	cout << "Grocery Sales By Product Menu" << endl;
	cout << formatString(31,'=') << endl;
	cout << "1: Search for an item" << endl;
	cout << "2: Display all frequencies" << endl;
	cout << "3: Print histogram" << endl;
	cout << "4: Exit Program" << endl;
	cout << formatString(31, '=') << endl;
	cout << endl;
}

void PrintGraph(const map<string, int>& productMap) { // Method to display histogram
	cout << "Histogram" << endl;
	cout << formatString(15, '-') << endl;
	// Loop through the map passed by reference and return the key then the value as '*'
	for (const auto& entry : productMap) {
		cout << entry.first;
		for (int i = 0; i < entry.second; ++i) {
			cout << '*';
		}
		cout << endl;
	}
	cout << formatString(15, '-') << endl;
}

void ReadInputFile(map<string, int> &productMap)
{
	ifstream productFS;
	string productName;
	string currProduct;

	productFS.open("CS210_Project_Three_Input_File.txt");

	if (!productFS.is_open()) {
		cout << "Unable to open file" << endl;
	}

	while (productFS >> productName) {
		if (productMap.count(productName)) {
			productMap[productName]++;
		}
		else {
			productMap.emplace(productName, 1);
		}
	}
}

void OutputFile(const map<string, int>& productMap)
{
	ofstream outFS;
	string productName;

	outFS.open("frequency.dat");

	if (!outFS.is_open()) {
		cout << "Unable to open out file" << endl;
		return;
	}

	for (const auto& product : productMap) {
		outFS << product.first << " " << product.second << endl;
	}
	outFS.close();
}

void GetProductInfo(const map<string, int>& productMap) {	// Function to search for the name of a product, menu option 1 handler
	string userProduct;

	cout << "Please enter the name of the product you would like to search." << endl;
	cin >> userProduct;

	// Use the map function find to locate the product
	auto it = std::find_if(productMap.begin(), productMap.end(),
		[&userProduct](const std::pair<string, int>& pair) {
			return icompare(userProduct, pair.first);
		});	// Returns the name of the product and becomes case insensitive
	
	// If the iterator does not equal end, the product was found
	if (it != productMap.end()) {
		cout << it->first << " " << it->second << endl;  // Display the original product name from the map
	}
	else {
		cout << userProduct << " was not found." << endl;
	}
} 

void GetProductList(const map<string, int>& productMap) {	// Menu option two handler, returns the list of products and counts
	cout << "Product List" << endl;
	cout << formatString(15, '-') << endl;
	for (const auto& entry : productMap) {
		cout << entry.first << " " << entry.second << endl;
	}
	cout << formatString(15, '-') << endl;
	cout << endl;
}



int main() {
	map<string, int> productMap;
	string product;
	int userChoice;
	bool exit = false;

	ReadInputFile(productMap);
	OutputFile(productMap);

	DisplayMenu();
	while (!exit) {
		cout << "Please enter a number 1 - 4 from the menu selections to select your desired option." << endl;

		// Obtain user input from menu choice
		cin >> userChoice;

		// Check for non-integer inputs first
		if (cin.fail()) {
			cin.clear();               // Clear the error state
			cin.ignore(INT_MAX, '\n'); // Discard invalid characters from the input buffer
			cout << "Your input was not recognized, please enter a number 1-4 from the menu options." << endl;
			continue; // Go to the next iteration of the loop
		}
		try {
		
			if (userChoice < 1 || userChoice > 4) {
				throw runtime_error("Invalid Input. Enter a number 1-4 from the menu options.");
				cin.clear();
				cin >> userChoice;
			}

			else if (userChoice == 1) {
				GetProductInfo(productMap);
			}

			else if (userChoice == 2) {
				GetProductList(productMap);
			}

			else if (userChoice == 3) {
				PrintGraph(productMap);
			}

			else if (userChoice == 4) {
				exit = true;
				cout << "You are now exiting the program." << endl;
				break;
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
		}
		
	}
	



	
	return 0;
}