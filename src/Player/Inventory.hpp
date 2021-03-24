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
		if(container.begin() == container.end()) cout << "Empty\n";
		else {
			for (iterator = container.begin(); 
			iterator != container.end(); iterator++) {
				cout << *iterator << endl;
			}
		}
		cout << endl;
	}

	T& operator[](int i) { //operator overloading elemen inventory
		return container[i];
	}

	void openEngimonInventory(){
		string cmd;
		do{
			cout << "Your Engimon(s):\n";
			printInventory();
			cout << "- To see an engimon's detail, select a number\n";
			cout << "- To close inventory, select 'c'\n\n";
			cout << "What do you want to do?\n\n";
			cin >> cmd;

			if(cmd != "c"){
				int i = stoi(cmd);
				if(i < container.size()) container[i-1].printInfo();
				else cout << "Number invalid" << endl;
			}
		} while (cmd != "c");

	}

	void openSkillInventory(){
		string cmd;
		do{
			cout << "Your Skill(s):\n";
			printInventory();
			cout << "- To use a skill, select a number\n";
			cout << "- To close inventory, select 'c'\n\n";
			cout << "What do you want to do?\n\n";
			cin >> cmd;

			if(cmd != "c"){
				int i = stoi(cmd);
				if(i < container.size()) cout << "using skill..\n";
				else cout << "Number invalid" << endl;
			}
		} while (cmd != "c");

	}
	
};


#endif