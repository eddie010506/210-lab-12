#include <iostream>
#include <array>
#include <fstream>
#include <numeric> // for std::accumulate
#include <algorithm> // for std::for_each, std::max_element, std::min_element
#include <stdexcept> 

using namespace std;

//  constant for the inventory size. 
const size_t INVENTORY_SIZE = 30;

// helper function to print the contents of the array
void printInventory(const array<int, INVENTORY_SIZE>& arr, const string& title) {
    cout << "\n--- " << title << " ---\n";
    cout << "Book ID | Stock\n";
    cout << "----------------\n";
    int id = 0;
    for (const auto& stock : arr) {
        cout << "  " << id++ << "\t|   " << stock << "\n";
    }
    cout << "----------------\n";
}

int main() {
    //declare a std::array to hold the book inventory.
    array<int, INVENTORY_SIZE> inventory;

    // read from the external data file into the array.
    ifstream inputFile("inventory.txt");
    if (!inputFile) {
        cout << "Error: Could not open inventory.txt" << endl;
        return 1;
    }

    