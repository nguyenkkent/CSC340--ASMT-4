using namespace std;
#include <string>
#include <vector>
#include "LinkedBag.cpp"
#include "LinkedBag340.cpp"



//template<typename ItemType>
//class LinkedBag : public BagInterface<ItemType> {
//
//
//public:
//	bool removeSecondNode340();
//	bool addEnd340(const ItemType&);
//	int getCurrentSize340Iterative() const;
//	int getCurrentSize340Recursive() const;
//	int getCurrentSize340RecursiveNoHelper() const;
//	int getFrequencyOf340Recursive(const ItemType&) const;
//	int getFrequencyOf340RecursiveNoHelper(const ItemType&) const;
//	ItemType removeRandom340();
//private:
//	int getCurrentSize340RecursiveHelper(Node<ItemType>*) const; // if needed
//	int getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType&) const; // if needed
//	/*----------------------------------------------------------------------*/
//
//
//private:
//	Node<ItemType>* headPtr{ nullptr }; // Pointer to first node
//	int itemCount{ 0 };					// Current count of bag items
//
//
//};