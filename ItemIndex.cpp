#include "ItemIndex.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor: Loads items from file and writes initial frequency data to "frequency.dat"
ItemIndex::ItemIndex(const string& inputFile) {
    LoadItemsFromFile(inputFile);                  // Load item data from input file
    WriteToFile("frequency.dat");       // Save frequencies to backup file
}

// Converts only the first letter of a string to uppercase
string ItemIndex::ToUpper(const string& str) {
    if (str.empty()) return str;                  // Return as-is if empty

    string result = str;
    result[0] = toupper(static_cast<unsigned char>(result[0]));  // Capitalize first character only
    return result;
}

// Reads items from the input file and updates their frequency count
void ItemIndex::LoadItemsFromFile(const string& filename) {
    ifstream inFile(filename);                     // Open input file
    string item;
    while (inFile >> item) {
        item = ToUpper(item);                      // Normalize item to Uppercase
        ++itemFrequency[item];                     // Increment item count in the map
    }
    inFile.close();                                // Close input file
}

// Returns the frequency of a specific item (case-insensitive)
int ItemIndex::GetItem(const string& itemName) {
    string UpperItem = ToUpper(itemName);          // Normalize input for case-insensitive search
    if (itemFrequency.find(UpperItem) != itemFrequency.end()) {
        return itemFrequency[UpperItem];           // Return frequency if item exists
    }
    return 0;                                       // Return 0 if item is not found
}

// Prints each item and its corresponding frequency to the console
void ItemIndex::Print() {
    for (const auto& pair : itemFrequency) {
        cout << left << setw(12) << pair.first      // Align item name
            << " " << pair.second << endl;         // Print item frequency
    }
}

// Prints a histogram of item frequencies using asterisks
void ItemIndex::PrintHistogram() {
    for (const auto& pair : itemFrequency) {
        cout << left << setw(12) << pair.first << " ";  // Print item name
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";                                 // Print asterisk per frequency count
        }
        cout << endl;
    }
}

// Writes the frequency data to an output file for backup
void ItemIndex::WriteToFile(const string& outputFile) {
    ofstream outFile(outputFile);                    // Open output file
    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;  // Write each item and frequency
    }
    outFile.close();                                 // Close output file
}