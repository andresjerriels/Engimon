#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_
#include <iostream>
using namespace std;
#include <vector>
#include "../Utility.h"
template<class T>
class Inventory
{
protected:
	std::vector<T> container;
	
public:
	Inventory() {
		container = vector<T>();
	}

	//getter
	vector<T> getContainer() const {
		return this->container;
	}

	void addToInventory(T item) { //menambahkan item (enigmon / skill item) ke dalam container
		container.push_back(item);
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

	void removeFromInventory(T item) {
		int index = searchIndexItemInInventory(item);
		typename std::vector<T>::iterator it;
		it = container.begin();
		for (int i = 0; i < index; i++) {
			it++;
		}

		container.erase(it);
	}

	void removeByindex(int idx) {
		if (0 <= idx && idx < container.size())
		{
			typename std::vector<T>::iterator it;
			it = container.begin() + idx;
			container.erase(it);
		} else {
			throw "Invalid index";
		}
	}

	void printInventory() {
		typename std::vector<T>::const_iterator iterator;
		if(container.begin() == container.end()) Util::printFormatKiri("Empty");
		else {
			for (iterator = container.begin(); 
			iterator != container.end(); iterator++) {
				cout << "* ";
				cout << iterator - container.begin() + 1 << ". " << *iterator << endl;
			}
		}
	}

	T& operator[](int i) { //operator overloading elemen inventory
		return container[i];
	}
	
};


#endif