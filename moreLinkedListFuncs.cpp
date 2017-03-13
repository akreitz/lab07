#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element  
// If more than one element has largest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node * pointerToMax(LinkedList *list) {

	// Code may assume that these assertions are true;
	//  so does not need to do error checking for these conditions.
	assert(list!=NULL);
	assert(list->head != NULL);

	Node *p, *max;
	int maxVal;

	p = list->head;
	max = p;
	maxVal = p->data;
	while (p != NULL) {
		if (p->data > maxVal) {
			max = p;
			maxVal = p->data;
		}
		p = p->next;
	}
	// TODO: Insert code here to calculate and return
	//   value of pointer to max element (first one if ties.)

	return max; // STUB!  Replace this line with correct code
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the smallest value.  
// You may assume list has at least one element
// If more than one element has smallest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head


Node * pointerToMin(LinkedList *list) {

	// Code may assume that these assertions are true;
	//  so does not need to do error checking for these conditions.

	assert(list!=NULL);
	assert(list->head != NULL);

	Node *p, *min;
	int minVal;

	p = list->head;
	min = p;
	minVal = p->data;
	while (p != NULL) {
		if (p->data < minVal) {
			min = p;
			minVal = p->data;
		}
		p = p->next;
	}


	// TODO: Insert code here to calculate and return
	//   value of pointer to min element 
	//   (first one such value that occurs if there are ties.)

	return min; // STUB!  Replace this line with correct code

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list) {

	// Code may assume that these assertions are true;
	//  so does not need to do error checking for these conditions.

	assert(list!=NULL);
	assert(list->head != NULL);

	Node *p, *max;
	int maxVal;

	p = list->head;
	max = p;
	maxVal = p->data;
	while (p != NULL) {
		if (p->data > maxVal) {
			max = p;
			maxVal = p->data;
		}
		p = p->next;
	}


	// TODO: Insert code here to calculate and return
	//   largest value in list (which may not be unique).

	return maxVal; // STUB!  Replace this line with correct code

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list) {
	// Code may assume that these assertions are true;
	//  so does not need to do error checking for these conditions.

	assert(list!=NULL);
	assert(list->head != NULL);

	Node *p, *min;
	int minVal;

	p = list->head;
	min = p;
	minVal = p->data;
	while (p != NULL) {
		if (p->data < minVal) {
			min = p;
			minVal = p->data;
		}
		p = p->next;
	}


	// TODO: Insert code here to calculate and return
	//   smallest value in list (which may not be unique).

	return minVal; // STUB!  Replace this line with correct code

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not NULL
// However, the list may be empty (i.e. list->head may be NULL)
//  in which case your code should return 0.

int sum(LinkedList * list) {
	// Code may assume that these assertions are true;
	//  so does not need to do error checking for these conditions.

	assert(list!=NULL);

	Node *p;
	int sum(0);

	p = list->head;
	while (p != NULL) {
		sum += p->data;
		p = p->next;
	}

	// TODO: Insert code here to calculate and return
	//   sum of all values in list (0 if there are none).

	return sum; // STUB!  Replace this line with correct code

}

void deleteNodeIteratively(LinkedList *list, int value) {
	assert(list!=NULL);

	Node *p, *q;
	p = list->head;
	q = p;
	for (; p != NULL; p = p->next) {
		if (p->data == value) {
			if (p == list->head) {
				list->head = p->next;
				delete p;
			}
			else if (p->next != NULL) {
				q->next = p->next;
				delete p;
			}
			else if (p->next == NULL) {
				list->tail = q;
				q->next = NULL;
				delete p;
			}
		}
		else {
			q = p;
		}
	}
	return;
}

void deleteNodeRecursively(LinkedList *list, int value) {
	deleteNodeRecursivelyHelper(list->head,value);
}


Node* deleteNodeRecursivelyHelper(Node *head, int value) {
	
	Node *p, *link;

	if (head == NULL) {
		return NULL;
	}

	else if (head->data == value) {
		// case for list of 1
		if (head->next == NULL) {
			delete head;
			return NULL;
		}
		else{
			link = head->next;
			deleteNodeRecursivelyHelper(head->next,value);
			delete head;
		}
		//deleteNodeRecursivelyHelper(head,value);
	}

	else if (head->data != value) {
		deleteNodeRecursivelyHelper(head->next,value);
	}
}


