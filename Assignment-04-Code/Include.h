#pragma once
#include "Node.cpp"
#include "BagInterface.h"

class LinkedBag : public BagInterface<ItemType> {

	/*--------------------------CSC340-------------------------------------*/
public:
	bool removeSecondNode340();
	bool addEnd340(const ItemType&);
	int getCurrentSize340Iterative() const;
	int getCurrentSize340Recursive() const;
	int getCurrentSize340RecursiveNoHelper() const;
	int getFrequencyOf340Recursive(const ItemType&) const;
	int getFrequencyOf340RecursiveNoHelper(const ItemType&) const;
	ItemType removeRandom340();
private:
	int getCurrentSize340RecursiveHelper(Node<ItemType>*) const; // if needed
	int getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType&) const; // if needed
	/*----------------------------------------------------------------------*/