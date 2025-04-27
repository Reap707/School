#ifndef ITEMINDEX_H
#define ITEMINDEX_H
using namespace std;


#include <map>
#include <string>

class ItemIndex {
private:
	map<string, int> itemFrequency; // Map to store item frequencies
	void LoadItemsFromFile(const string& filename); // Function to load items from a file
    string ToUpper(const string& str); // Function to convert a string to Uppercase
	
public:
    ItemIndex(const string& inputFile); 
    int GetItem(const string& itemName); 
    void Print();
    void PrintHistogram();
    void WriteToFile(const string& outputFile);

 
};

#endif
