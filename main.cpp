#include <iostream>
#include <string>
#include "ItemIndex.h"

using namespace std;

// Displays the main menu options to the user
void DisplayMenu() {
    cout << "\n====== Corner Grocer Menu ======" << endl;
    cout << "1. Search for item frequency" << endl;         // Option to look up a specific item's frequency
    cout << "2. Display all item frequencies" << endl;     // Option to list all items with purchase counts
    cout << "3. Display item histogram" << endl;           // Option to display a visual histogram
    cout << "4. Exit" << endl;                             // Option to quit the program
    cout << "Choose an option: ";
}

int main() {
    // Create ItemIndex object with input file containing grocery transactions
    ItemIndex tracker("CS210_Project_Three_Input_File.txt");

    int choice = 0; // Variable to hold user’s menu selection

    // Keep looping until the user chooses to exit
    while (choice != 4) {
        DisplayMenu();  // Show the menu options
        cin >> choice;  // Get user input

        // Input validation: handle non-numeric input
        if (cin.fail()) {
            cin.clear();                // Clear error flag
            cin.ignore(10000, '\n');    // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        // Process user choice
        switch (choice) {
        case 1: {
            // Prompt user to enter an item name to search
            string item;
            cout << "Enter item name: ";
            cin >> item;

            // Retrieve and display frequency of the item
            int freq = tracker.GetItem(item);
            cout << item << " was purchased " << freq << " time(s)." << endl;
            break;
        }
        case 2:
            // Print list of all items and their frequencies
            cout << "\nItem Frequencies:\n";
            tracker.Print();
            break;

        case 3:
            // Print histogram of all items with asterisks
            cout << "\nItem Histogram:\n";
            tracker.PrintHistogram();
            break;

        case 4:
            // Exit message
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            // Handle menu input outside 1-4 range
            cout << "Invalid option. Try again." << endl;
        }
    }

    return 0; // Successful exit
}
