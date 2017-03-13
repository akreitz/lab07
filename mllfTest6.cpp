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
	int a[1]={1};

	LinkedList *list = arrayToLinkedList(nums,8);
	LinkedList *list0 = arrayToLinkedList(a,1);

	// iterative testing
	cout << "*** BEGINNING ITERATIVE TESTING ***" << endl;

	ASSERT_EQUALS( "[1]->[2]->[3]->[2]->[1]->[4]->[5]->[4]->null", linkedListToString(list));

	deleteNodeIteratively(list0,1);
	ASSERT_EQUALS( "null", linkedListToString(list0));
	ASSERT_TRUE(list->head->data == NULL);
	ASSERT_TRUE(list->tail->data == NULL);


	

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

	int empty[0]={};
	int one[1]={1};
	int two[2]={1,2};
	int three[3]={1,2,3};
	int four[4]={1,2,2,3};
	int five[5]={1,2,2,3,4};

	LinkedList *list2 = arrayToLinkedList(nums,8);
	LinkedList *list3 = arrayToLinkedList(empty,0);
	LinkedList *list4 = arrayToLinkedList(one,1);
	LinkedList *list5 = arrayToLinkedList(two,2);
	LinkedList *list6 = arrayToLinkedList(three,3);
	LinkedList *list7 = arrayToLinkedList(four,4);
	LinkedList *list8 = arrayToLinkedList(five,5);

	ASSERT_EQUALS( "[1]->[2]->[3]->[2]->[1]->[4]->[5]->[4]->null", linkedListToString(list2));

	cout << "deleteNodeRecursively(list3,1);" << endl;
	deleteNodeRecursively(list3,1);
	ASSERT_EQUALS( "null", linkedListToString(list3));	
	ASSERT_TRUE(list3->head == NULL);
	ASSERT_TRUE(list3->tail == NULL);
//HERE
	cout << "deleteNodeRecursively(list4,1);" << endl;
	cout << linkedListToString(list4) << endl;
	cout << list4->head->data << endl;
	cout << list4->head->next << endl;
	deleteNodeRecursively(list4,1);
	ASSERT_EQUALS( "null", linkedListToString(list4));	
	ASSERT_TRUE(list4->head == NULL);
	ASSERT_TRUE(list4->tail == NULL);
//
	cout << "deleteNodeRecursively(list5,1);" << endl;
	deleteNodeRecursively(list5,1);
	ASSERT_EQUALS( "[2]->null", linkedListToString(list5));	
	ASSERT_TRUE(list5->head->data == 2);
	ASSERT_TRUE(list5->tail->data == 2);

	cout << "deleteNodeRecursively(list6,1);" << endl;
	deleteNodeRecursively(list6,1);
	ASSERT_EQUALS( "[2]->[3]->null", linkedListToString(list6));	
	ASSERT_TRUE(list6->head->data == 2);
	ASSERT_TRUE(list6->tail->data == 3);

	cout << "deleteNodeRecursively(list7,2);" << endl;
	deleteNodeRecursively(list7,2);
	ASSERT_EQUALS( "[1]->[3]->null", linkedListToString(list7));
	ASSERT_TRUE(list7->head->data == 1);
	ASSERT_TRUE(list7->head->next->data == 3);



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
	
	cout << "addIntToStartOfList(list2,7);" << endl;
	addIntToStartOfList(list2,7);

	// adding to the front, deleting the last Node
	cout << list2->tail->data << endl;
	deleteNodeRecursively(list2,4);
	deleteNodeRecursively(list2,6);
	ASSERT_EQUALS( "[7]->[2]->[2]->[5]->null", linkedListToString(list2));
	ASSERT_TRUE(list2->head->data == 7);
	ASSERT_TRUE(list2->tail->data == 5);
	cout << list2->head->data << endl;
	cout << list2->head->next->data << endl;
	cout << list2->head->next->next->data << endl;
	cout << list2->head->next->next->next->data << endl;
	cout << list2->head->next->next->next->next->data << endl;

	cout << list2->tail->data << endl;

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

