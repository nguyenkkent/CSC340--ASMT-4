#include "LinkedBag.h"
using namespace std;
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
	if (itemCount < 2) {
		return false;
	}
	//assertion: there is atleast 2 items in the bag
	Node<ItemType>* currentNodePtr = headPtr->getNext();
	headPtr->setNext(currentNodePtr->getNext());
	currentNodePtr->setNext(nullptr);
	delete currentNodePtr;
	currentNodePtr = nullptr;
	itemCount--;
	return true;
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& item) {
	Node<ItemType>* currentNodePtr = headPtr;
	while (currentNodePtr->getNext() != nullptr) {
		currentNodePtr = currentNodePtr->getNext();
	}
	//currentNodePtr->setNext(new Node<ItemType>(item));
	unique_ptr<Node<ItemType>> newNodePtr = make_unique<Node<ItemType>>(item);//newly added code
	currentNodePtr->setNext(newNodePtr.release());//newly added code
	itemCount++;
	return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
	int counter = 0;
	auto* currentNodePtr = headPtr;
	while (currentNodePtr != nullptr) {
		counter++;
		currentNodePtr = currentNodePtr->getNext();
	}
	return counter;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
	int counter = 1;
	return (counter + getCurrentSize340RecursiveHelper(headPtr->getNext() ));
}
//helper
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* currentNodePtr) const {
	if (currentNodePtr->getNext() == nullptr) {
		return 1;
	}
	else {
		return (1 + getCurrentSize340RecursiveHelper(currentNodePtr->getNext()));
	}
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
	static Node<ItemType>* currentNodePtr = headPtr; //the use of static allows for var to be shared across all recursive calls
	if (currentNodePtr->getNext() == nullptr) {
		return 1;
	}
	else {
		currentNodePtr = currentNodePtr->getNext();
		return (1 + getCurrentSize340RecursiveNoHelper());
	}
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& item) const {
	return getFrequencyOf340RecursiveHelper(headPtr, item);
}
//helper
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* currentNodePtr, const ItemType& item) const {
	int result = 0;
	if (currentNodePtr->getItem() == item) {
		result = 1;
	}
	if (currentNodePtr->getNext() == nullptr) {
		return result;
	}
	else {
		return (result + getFrequencyOf340RecursiveHelper(currentNodePtr->getNext(), item));
	}
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& item) const {
	int result = 0;
	static Node<ItemType>* currentNodePtr = headPtr;
	if (currentNodePtr->getItem() == item) {
		result = 1;
	}
	if (currentNodePtr->getNext() == nullptr) {
		currentNodePtr = headPtr; //currentNodePtr seems to stay in memory after the method call is completed and carries into the next instance of that method if not reset at end of recursion
		return result;
	}
	else {
		currentNodePtr = currentNodePtr->getNext();
		return (result + getFrequencyOf340RecursiveNoHelper(item));
	}
}

//function will generate a random number between zero and itemCount-1. If head node is selected then the head node is deleted. Otherwise value of the randomly selected
//node will be overwritten with the current value of the headPtr. headPtr will be deleted afterwards.
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
	ItemType itemToBeRemoved = "";
	//for some reason this produces the same numbers everytime without srand()
	srand((unsigned int)time(NULL));
	int randomIndexToBeRemoved = rand() % itemCount;

	if (randomIndexToBeRemoved == 0) {//if head is selected
		auto* nodeToBeDeleted = headPtr;
		itemToBeRemoved = nodeToBeDeleted->getItem();
		headPtr = headPtr->getNext();
		nodeToBeDeleted->setNext(nullptr);
		delete nodeToBeDeleted;
		nodeToBeDeleted = nullptr;
		itemCount--;
	}
	else {//non-head nodes
		Node<ItemType>* nodeToBeDeleted = headPtr;
		while (randomIndexToBeRemoved != 0) {
			nodeToBeDeleted = nodeToBeDeleted->getNext();
			randomIndexToBeRemoved--;
		}
		itemToBeRemoved = nodeToBeDeleted->getItem();
		nodeToBeDeleted->setItem(headPtr->getItem());//replace target node value with value from headPtr
		nodeToBeDeleted = headPtr;//reset the pointer
		headPtr = headPtr->getNext();//set new head
		nodeToBeDeleted->setNext(nullptr);//delete old head
		delete nodeToBeDeleted;
		nodeToBeDeleted = nullptr;
		itemCount--;
	}
	return itemToBeRemoved;
}


