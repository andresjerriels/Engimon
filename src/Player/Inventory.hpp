#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_
#include <iostream>
using namespace std;
#include <vector>

template<class T>
class Inventory
{
protected:
	std::vector<T> container;
	
public:
	Inventory() {
		container = vector<T>();
	}

	void addToInventory(T item) { //menambahkan item (enigmon / skill item) ke dalam container
		container.push_back(item);z
	}

	int countItemInInventory() {
		typename std::vector<T>::iterator it;
		it = container.begin();
		int counter = 0;
		while (it != container.end()) {
			counter++;
			it++;
		}
		return counter;
	}

	int searchIndexItemInInventory(T item) {
		typename std::vector<T>::iterator it;
		it = container.begin();
		bool found = false;
		int i = 0;

		while (!found && it != container.end()) {
			if (item == container[i]) {
				found = true;
			}

			else {
				it++;
				i++;
			}
		}
			// cout << i << endl;
		if (found) {
			return i;
		} else {
			return -1; //kalo gaada returnnya -1
		}
	}

	T itemInIventory(int index) {
		return container[index];
	}

	void removeFromInventory(T item) {
		int index = searchIndexItemInInventory(item);
		typename std::vector<T>::iterator it;
		it = container.begin();
		for (int i = 0; i < index; i++) {
			it++;
		}

		container.erase(it);

	}

	void printInventory() {
		typename std::vector<T>::const_iterator iterator;
		for (iterator = container.begin(); 
			iterator != container.end(); iterator++) {
			cout << iterator << ' ';
		}
		cout << endl;
	}
	
};


#endif