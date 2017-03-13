#include "linkedListFuncs.h"
#include "moreLinkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {
  //Test your deleteNodeRecursively and deleteNodeIteratively functions
  //Test your code extensively
  //assertTrue(false);
  
	int nums[8]={1,2,3,2,1,4,5,4};
	int empty[0]={};

	LinkedList *list = arrayToLinkedList(nums,8);
	LinkedList *list2 = arrayToLinkedList(nums,8);
	LinkedList *list3 = arrayToLinkedList(empty,0);

	// iterative testing
	cout << "*** BEGINNING ITERATIVE TESTING ***" << endl;

	ASSERT_EQUALS( "[1]->[2]->[3]->[2]->[1]->[4]->[5]->[4]->null", linkedListToString(list));

	// tests to make sure nothing is deleted from a LL that doesn't have the target value
	deleteNodeIteratively(list,6);
	ASSERT_EQUALS( "[1]->[2]->[3]->[2]->[1]->[4]->[5]->[4]->null", linkedListToString(list));
	ASSERT_TRUE(list->head->data == 1);
	ASSERT_TRUE(list->tail->data == 4);

	// deleting a Node from the beginning and middle of a LL
	deleteNodeIteratively(list,1);
	ASSERT_EQUALS( "[2]->[3]->[2]->[4]->[5]->[4]->null", linkedListToString(list));
	ASSERT_TRUE(list->head->data == 2);
	ASSERT_TRUE(list->tail->data == 4);

	addIntToEndOfList(list,6);

	// deleting from the middle, checking to make sure add to end works
	deleteNodeIteratively(list,3);
	ASSERT_EQUALS( "[2]->[2]->[4]->[5]->[4]->[6]->null", linkedListToString(list));
	ASSERT_TRUE(list->head->data == 2);
	ASSERT_TRUE(list->tail->data == 6);

	addIntToStartOfList(list,7);

	// adding to the front, deleting the last Node
	deleteNodeIteratively(list,4);
	deleteNodeIteratively(list,6);
	ASSERT_EQUALS( "[7]->[2]->[2]->[5]->null", linkedListToString(list));
	ASSERT_TRUE(list->head->data == 7);
	ASSERT_TRUE(list->tail->data == 5);

	// deleting multiple nodes in a row and making sure the link stays
	deleteNodeIteratively(list,2);
	ASSERT_EQUALS( "[7]->[5]->null", linkedListToString(list));
	ASSERT_TRUE(list->head->data == 7);
	ASSERT_TRUE(list->tail->data == 5);

	cout << "*** FINISHED ITERATIVE TESTING ***" << endl;

	// recursive testing

	cout << "*\n";
	cout << "*\n";
	cout << "*\n";

	cout << "*** BEGINNING RECURSIVE TESTING ***" << endl;

	ASSERT_EQUALS( "[1]->[2]->[3]->[2]->[1]->[4]->[5]->[4]->null", linkedListToString(list2));

	//deleteNodeRecursively(list3,1);
	//ASSERT_TRUE(list3->head == NULL);
	//ASSERT_TRUE(list3->tail == NULL);

	// tests to make sure nothing is deleted from a LL that doesn't have the target value
	deleteNodeRecursively(list2,6);
	ASSERT_EQUALS( "[1]->[2]->[3]->[2]->[1]->[4]->[5]->[4]->null", linkedListToString(list2));
	ASSERT_TRUE(list2->head->data == 1);
	ASSERT_TRUE(list2->tail->data == 4);

	// deleting a Node from the beginning and middle of a LL
	deleteNodeRecursively(list2,1);
	ASSERT_EQUALS( "[2]->[3]->[2]->[4]->[5]->[4]->null", linkedListToString(list2));
	ASSERT_TRUE(list2->head->data == 2);
	ASSERT_TRUE(list2->tail->data == 4);

	addIntToEndOfList(list2,6);

	// deleting from the middle, checking to make sure add to end works
	deleteNodeRecursively(list2,3);
	ASSERT_EQUALS( "[2]->[2]->[4]->[5]->[4]->[6]->null", linkedListToString(list2));
	ASSERT_TRUE(list2->head->data == 2);
	ASSERT_TRUE(list2->tail->data == 6);

	addIntToStartOfList(list2,7);

	// adding to the front, deleting the last Node
	deleteNodeRecursively(list2,4);
	deleteNodeRecursively(list2,6);
	ASSERT_EQUALS( "[7]->[2]->[2]->[5]->null", linkedListToString(list2));
	ASSERT_TRUE(list2->head->data == 7);
	ASSERT_TRUE(list2->tail->data == 5);

	// deleting multiple nodes in a row and making sure the link stays
	deleteNodeRecursively(list2,2);
	ASSERT_EQUALS( "[7]->[5]->null", linkedListToString(list2));
	ASSERT_TRUE(list2->head->data == 7);
	ASSERT_TRUE(list2->tail->data == 5);

	cout << "*** FINISHED RECURSIVE TESTING ***" << endl;

	freeLinkedList(list);
	freeLinkedList(list2);

	return 0;
}

