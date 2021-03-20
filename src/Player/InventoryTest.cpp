#include <iostream>
#include "Inventory.hpp"
#include <vector>z
using namespace std;

int main() {
	Inventory<int> ints;
	ints.addToInventory(1);
	ints.addToInventory(3);
	ints.addToInventory(5);
	ints.addToInventory(7);
	ints.addToInventory(9);
	ints.printInventory();
	int counter = ints.countItemInInventory();
	cout << "counter: " << counter << endl;
	int var = ints.searchIndexItemInInventory(9);
	cout << var << endl;
	ints.removeFromInventory(7);
	ints.printInventory();

	return 0;
}