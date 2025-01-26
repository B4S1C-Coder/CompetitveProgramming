// ========== [ LAB ASSIGNMENT - 3 ] ==========
// +--------------------------+
// |  Name: SAKSHAM MITTAL    |
// |  Roll Number: 102319061  |
// +--------------------------+
// ============================================
// IMPORTANT
// --------------------------------------------
// Each function of the form:     void container_ass3_quesN() { ... }
// is to be treated as an isolated container for Assignment - 3, Question - N.
// --------------------------------------------
// COMPILATION
// --------------------------------------------
// This code has been developed and tested with the following gcc version:
// gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
// --------------------------------------------
// COMMAND USED FOR COMPILATION (Make sure you have created a directory named bin before compiling)
// --------------------------------------------
// gcc -Wall labass3_102319061.c -O3 -o ./bin/labass3 && ./bin/labass3
// --------------------------------------------
// The platform on which the code has been developed and tested:
// Linux 5.15.153.1-microsoft-standard-WSL2 #1 SMP Fri Mar 29 23:14:13 UTC 2024 x86_64 x86_64 x86_64 GNU/Linux

// Used for compilation: gcc -Wall labass3_102319061.c -O3 -o ./bin/labass3 && ./bin/labass3

#include <stdio.h>
#include <stdlib.h>

// ################# SINGLY LINKED LIST #################

typedef struct singlyLinkedNode {
	struct singlyLinkedNode* next;
	int data;
} singlyLinkedNode;

typedef struct singlyLinkedList {
	struct singlyLinkedNode* first;
	int numNodes;
} singlyLinkedList;

singlyLinkedNode* singlyLinked_createNode() {
	singlyLinkedNode* node = (singlyLinkedNode*)malloc(sizeof(singlyLinkedNode));
	node->next = NULL;
	return node;
}

singlyLinkedList* singlyLinked_createList() {
	singlyLinkedList* list = (singlyLinkedList*)malloc(sizeof(singlyLinkedList));
	list->first = NULL;
	list->numNodes = 0;
	return list;
}

void singlyLinked_addNodeToTail(singlyLinkedList* list, singlyLinkedNode* node) {
	// If list is empty
	if ((list->first == NULL)||(list->numNodes == 0)) {
		list->first = node;
		list->numNodes++;
		return;
	}

	singlyLinkedNode* nodeUnderConsideration = list->first;

	while (1) {
		if (nodeUnderConsideration->next == NULL) {
			// This is the last node
			nodeUnderConsideration->next = node;
			break;
		} else {
			nodeUnderConsideration = nodeUnderConsideration->next;
		}
	}

	list->numNodes++;
}

void singlyLinked_addNodeToHead(singlyLinkedList* list, singlyLinkedNode* node) {
	node->next = list->first;
	list->first = node;
	list->numNodes++;
}

void singlyLinked_popNodeFromHead(singlyLinkedList* list) {
	// The removed node can be freed from the heap for now this has been skipped.
	// Leaving it to the user to decide whether they use the removed node in a
	// different list or free() it.
	list->first = list->first->next;
	list->numNodes--;
}

void singlyLinked_popNodeFromTail(singlyLinkedList* list) {
	// Do nothing if the list is already empty
	if ((list->first == NULL)||(list->numNodes == 0)) {
		return;
	}

	// If list contains only one node
	if (list->first->next == NULL) {
		list->first = NULL;
		list->numNodes--;
		return;
	}

	singlyLinkedNode* nodeUnderConsideration = list->first;
	singlyLinkedNode* prevNode = NULL;

	while (1) {
		if (nodeUnderConsideration->next == NULL) {
			// Reached last node
			prevNode->next = NULL;
			list->numNodes--;
			break;
		} else {
			prevNode = nodeUnderConsideration;
			nodeUnderConsideration = nodeUnderConsideration->next;
		}
	}
}

void singlyLinked_printList(singlyLinkedList* list) {
	printf("-------------------------------\n");
	printf("Singly Linked List: %d nodes\n", list->numNodes);

	if ((list->first == NULL)||(list->numNodes == 0)) { return; }
	
	singlyLinkedNode* nodeUnderConsideration = list->first;

	while (1) {
		if (nodeUnderConsideration->next == NULL) {
			printf("%d\n", nodeUnderConsideration->data);
			printf("-------------------------------\n");
			break;
		} else {
			printf("%d -> ", nodeUnderConsideration->data);
			nodeUnderConsideration = nodeUnderConsideration->next;
		}
	}
}

void singlyLinked_insertNodeAtIndex(singlyLinkedList* list, singlyLinkedNode* node, int toInsertIndex) {
	// empty list
	if ((list->first == NULL)||(list->numNodes == 0)) {
		list->first = node;
		list->numNodes++;
		return;
	}

	// invalid index, exit silently
	// this check can be removed if you want to strictly not use list->numNodes
	if (toInsertIndex >= list->numNodes) { return; }

	singlyLinkedNode* nodeUnderConsideration = list->first;
	int index = 0;

	while (index < toInsertIndex - 1) {
		nodeUnderConsideration = nodeUnderConsideration->next;
		index++;
	}

	node->next = nodeUnderConsideration->next;
	nodeUnderConsideration->next = node;
	list->numNodes++;
}

void singlyLinked_popNodeAtIndex(singlyLinkedList* list, int toRemoveIndex) {
	// empty list
	if ((list->first == NULL)||(list->numNodes == 0)) { return; }

	// invalid index, exit silently
	// this check can be removed if you want to strictly not use list->numNodes
	if (toRemoveIndex >= list->numNodes) { return; }

	singlyLinkedNode* nodeUnderConsideration = list->first;
	singlyLinkedNode* prevNode = NULL;
	int index = 0;

	while (index < toRemoveIndex) {
		prevNode = nodeUnderConsideration;
		nodeUnderConsideration = nodeUnderConsideration->next;
		index++;
	}

	prevNode->next = nodeUnderConsideration->next;
	list->numNodes--;

	free(nodeUnderConsideration);
}

// Element found: index (node count starts from 0), Element not found: -1
int singlyLinked_linearSearch(singlyLinkedList* list, int toSearch) {
	if ((list->first == NULL)||(list->numNodes == 0)) { return -1; }

	singlyLinkedNode* nodeUnderConsideration = list->first;
	int index = 0, returnIndex = -1;

	while (nodeUnderConsideration->next != NULL) {
		if (nodeUnderConsideration->data == toSearch) {
			returnIndex = index;
			break;
		} else {
			nodeUnderConsideration = nodeUnderConsideration->next;
			index++;
		}
	}

	return returnIndex;
}

// ################# DOUBLE LINKED LIST #################

typedef struct doublyLinkedNode {
	struct doublyLinkedNode* prev;
	struct doublyLinkedNode* next;
	int data;
} doublyLinkedNode;

typedef struct doublyLinkedList {
	struct doublyLinkedNode* first;
	struct doublyLinkedNode* last;
	int numNodes;
} doublyLinkedList;

doublyLinkedNode* doublyLinked_createNode(int data) {
	doublyLinkedNode* node = (doublyLinkedNode*)malloc(sizeof(doublyLinkedNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = data;
	return node;
}

doublyLinkedList* doublyLinked_createList() {
	doublyLinkedList* list = (doublyLinkedList*)malloc(sizeof(doublyLinkedList));
	list->first = NULL;
	list->last = NULL;
	list->numNodes = 0;
	return list;
}

void doublyLinked_pushBack(doublyLinkedList* list, int data) {
	doublyLinkedNode* node = doublyLinked_createNode(data);

	if ((list->first == NULL)||(list->numNodes == 0)||(list->last == NULL)) {
		list->first = node;
		list->last = node;
		list->numNodes++;
		return;
	}

	list->last->next = node;
	node->prev = list->last;
	list->last = node;
	list->numNodes++;
}

void doublyLinked_popBack(doublyLinkedList* list) {
	// list is empty, nothing to do
	if ((list->first == NULL)||(list->numNodes == 0)||(list->last == NULL)) { return; }

	list->last->prev->next = NULL;
	list->last = list->last->prev;
	list->numNodes--;
}

void doublyLinked_pushFront(doublyLinkedList* list, int data) {
	doublyLinkedNode* node = doublyLinked_createNode(data);

	if ((list->first == NULL)||(list->numNodes == 0)||(list->last == NULL)) {
		list->first = node;
		list->last = node;
		list->numNodes++;
		return;
	}

	list->first->prev = node;
	node->next = list->first;
	list->first = node;
	list->numNodes++;
}

void doublyLinked_popFront(doublyLinkedList* list) {
	// list is empty, nothing to do
	if ((list->first == NULL)||(list->numNodes == 0)||(list->last == NULL)) { return; }

	list->first->next->prev = NULL;
	list->first = list->first->next;
	list->numNodes--;
}

void doublyLinked_insertAtIndex(doublyLinkedList* list, int data, int toInsertIndex) {
	// invalid index
	if (toInsertIndex >= list->numNodes) { return; }

	doublyLinkedNode* node = doublyLinked_createNode(data);

	if ((list->first == NULL)||(list->numNodes == 0)||(list->last == NULL)) {
		list->first = node;
		list->last = node;
		list->numNodes++;
		return;
	}

	int index = 0;
	doublyLinkedNode* nodeUnderConsideration = list->first;

	while (index < toInsertIndex - 1) {
		nodeUnderConsideration = nodeUnderConsideration->next;
		index++;
	}

	node->next = nodeUnderConsideration->next;
	nodeUnderConsideration->next->prev = node;

	nodeUnderConsideration->next = node;
	node->prev = nodeUnderConsideration;

	list->numNodes++;	

}

void doublyLinked_popAtIndex(doublyLinkedList* list, int toRemoveIndex) {
	// list is empty, nothing to do
	if ((list->first == NULL)||(list->numNodes == 0)||(list->last == NULL)) { return; }
	// invalid index
	if (toRemoveIndex >= list->numNodes) { return; }

	int index = 0;
	doublyLinkedNode* nodeUnderConsideration = list->first;

	while (index < toRemoveIndex) {
		nodeUnderConsideration = nodeUnderConsideration->next;
		index++;
	}

	nodeUnderConsideration->prev->next = nodeUnderConsideration->next;
	nodeUnderConsideration->next->prev = nodeUnderConsideration->prev;

	list->numNodes--;

	free(nodeUnderConsideration);
}

void doublyLinked_printList(doublyLinkedList* list) {
	printf("-------------------------------\n");
	printf("Doubly Linked List: %d nodes | first: %p last: %p\n", list->numNodes, list->first, list->last);

	if ((list->first == NULL)||(list->numNodes == 0)||(list->last == NULL)) {
		printf("-------------------------------\n");
		return;
	}

	doublyLinkedNode* nodeUnderConsideration = list->first;

	while (nodeUnderConsideration->next != NULL) {
		printf("%d <-> ", nodeUnderConsideration->data);
		nodeUnderConsideration = nodeUnderConsideration->next;
	}

	printf("%d\n", nodeUnderConsideration->data);
	printf("-------------------------------\n");
}

// ################# CIRCULAR DOUBLE LINKED LIST #################

typedef struct circularDoublyLinkedNode {
	struct circularDoublyLinkedNode* prev;
	struct circularDoublyLinkedNode* next;
	int data;
} circularDoublyLinkedNode;

typedef struct circularDoublyLinkedList {
	struct circularDoublyLinkedNode* first;
	struct circularDoublyLinkedNode* last;
	int numNodes;
} circularDoublyLinkedList;

circularDoublyLinkedNode* circular_createNode(int data) {
	circularDoublyLinkedNode* node = (circularDoublyLinkedNode*)malloc(sizeof(circularDoublyLinkedNode));
	node->prev = NULL;
	node->next = NULL;
	node->data = data;
	return node;
}

circularDoublyLinkedList* circular_createList() {
	circularDoublyLinkedList* list = (circularDoublyLinkedList*)malloc(sizeof(circularDoublyLinkedList));
	list->first = NULL;
	list->last = NULL;
	list->numNodes = 0;
	return list;
}

void circular_pushBack(circularDoublyLinkedList* list, int data) {
	circularDoublyLinkedNode* node = circular_createNode(data);

	// Empty List
	if ((list->first == NULL)||(list->last == NULL)||(list->numNodes == 0)) {
		list->first = node;
		list->last = node;

		node->next = node;
		node->prev = node;

		list->numNodes++;
		return;
	}

	list->last->next = node;
	node->prev = list->last;

	list->last = node;

	node->next = list->first;
	list->first->prev = node;

	list->numNodes++;
}

void circular_popBack(circularDoublyLinkedList* list) {
	// Empty List
	if ((list->first == NULL)||(list->last == NULL)||(list->numNodes == 0)) { return; }
	// List has only one element
	if ((list->first == list->last)||(list->numNodes == 1)) {
		list->first = NULL;
		list->last = NULL;
		list->numNodes = 0;
		return;
	}

	list->last->prev->next = list->first;
	list->first->prev = list->last->prev;

	list->last = list->last->prev;

	list->numNodes--;
	return;
}

void circular_pushFront(circularDoublyLinkedList* list, int data) {
	circularDoublyLinkedNode* node = circular_createNode(data);

	// Empty List
	if ((list->first == NULL)||(list->last == NULL)||(list->numNodes == 0)) {
		list->first = node;
		list->last = node;

		node->next = node;
		node->prev = node;

		list->numNodes++;
		return;
	}

	list->last->next = node;
	node->prev = list->last;

	node->next = list->first;
	list->first->prev = node;

	list->first = node;
	list->numNodes++;
}

void circular_popFront(circularDoublyLinkedList* list) {
	// Empty List
	if ((list->first == NULL)||(list->last == NULL)||(list->numNodes == 0)) { return; }
	// List has only one element
	if ((list->first == list->last)||(list->numNodes == 1)) {
		list->first = NULL;
		list->last = NULL;
		list->numNodes = 0;
		return;
	}

	list->last->next = list->first->next;
	list->first->next->prev = list->last;

	list->first = list->first->next;

	list->numNodes--;
}

void circular_insertAtIndex(circularDoublyLinkedList* list, int data, int toInsertIndex) {
	
	// Resolve index
	while (toInsertIndex >= list->numNodes) {
		toInsertIndex = toInsertIndex - list->numNodes;
	}

	circularDoublyLinkedNode* node = circular_createNode(data);

	// Empty List
	if ((list->first == NULL)||(list->last == NULL)||(list->numNodes == 0)) {
		list->first = node;
		list->last = node;

		node->next = node;
		node->prev = node;

		list->numNodes++;
		return;
	}

	int index = 0;
	circularDoublyLinkedNode* nodeUnderConsideration = list->first;

	while (index < toInsertIndex - 1) {
		nodeUnderConsideration = nodeUnderConsideration->next;
		index++;
	}

	node->next = nodeUnderConsideration->next;
	nodeUnderConsideration->next->prev = node;

	nodeUnderConsideration->next = node;
	node->prev = nodeUnderConsideration;

	list->numNodes++;
}

void circular_popAtIndex(circularDoublyLinkedList* list, int toRemoveIndex) {
	// Resolve index
	while (toRemoveIndex >= list->numNodes) {
		toRemoveIndex = toRemoveIndex - list->numNodes;
	}
	// Empty List
	if ((list->first == NULL)||(list->last == NULL)||(list->numNodes == 0)) { return; }

	int index = 0;
	circularDoublyLinkedNode* nodeUnderConsideration = list->first;

	while (index < toRemoveIndex + 1) {
		nodeUnderConsideration = nodeUnderConsideration->next;
		index++;
	}

	nodeUnderConsideration->prev->next = nodeUnderConsideration->next;
	nodeUnderConsideration->next->prev = nodeUnderConsideration->prev;

	list->numNodes--;

	free(nodeUnderConsideration);
}

void circular_printList(circularDoublyLinkedList* list) {
	printf("-------------------------------\n");
	printf("Circular Doubly Linked List: %d nodes | first: %p last: %p\n", list->numNodes, list->first, list->last);

	if ((list->first == NULL)||(list->last == NULL)||(list->numNodes == 0)) { return; }

	circularDoublyLinkedNode* nodeUnderConsideration = list->first;

	printf("... -> ");

	while (nodeUnderConsideration->next != list->first) {
		printf("%d <-> ", nodeUnderConsideration->data);
		nodeUnderConsideration = nodeUnderConsideration->next;
	}

	printf("%d <- ...\n", nodeUnderConsideration->data);
	printf("-------------------------------\n");
}

// ################# USAGE #################

void container_ass3_ques1() {
	printf("Question - 1, SINGLY LINKED LIST\n");
	printf("-------------------------------\n");
	printf("Initial Singly Linked List (nodes added to tail):\n");
	singlyLinkedList* list = singlyLinked_createList();

	for (int i = 0; i < 10; i++) {
		singlyLinkedNode* node = singlyLinked_createNode();
		node->data = i + 100;
		singlyLinked_addNodeToTail(list, node);
	}

	singlyLinked_printList(list);

	printf("Adding a node at the head.\n");

	singlyLinkedNode* myHeadNode = singlyLinked_createNode();
	myHeadNode->data = 69;

	singlyLinked_addNodeToHead(list, myHeadNode);
	singlyLinked_printList(list);

	printf("Removing a node from the tail.\n");

	singlyLinked_popNodeFromTail(list);
	singlyLinked_printList(list);

	printf("Removing a node from the head.\n");

	singlyLinked_popNodeFromHead(list);
	singlyLinked_printList(list);

	printf("Inserting a node after 6 nodes.\n");

	singlyLinkedNode* myOtherNode = singlyLinked_createNode();
	myOtherNode->data = 42;

	singlyLinked_insertNodeAtIndex(list, myOtherNode, 6);
	singlyLinked_printList(list);

	printf("Performing linear search for node with data = 42\n");
	int foundIndex = singlyLinked_linearSearch(list, 42);

	if (foundIndex == -1) {
		printf("No such node found.\n");
	} else {
		printf("Node found at index: %d i.e. (%d-th node)\n", foundIndex, foundIndex + 1);
	}

	printf("-------------------------------\n");

	printf("Removing the above mentioned node.\n");

	singlyLinked_popNodeAtIndex(list, 6);
	singlyLinked_printList(list);
}

void container_ass3_ques2() {
	printf("Question - 2, DOUBLY LINKED LIST\n");
	printf("-------------------------------\n");
	printf("Initial Doubly Linked List (nodes added to tail):\n");
	doublyLinkedList* list = doublyLinked_createList();

	for (int i = 0; i < 10; i++) {
		doublyLinked_pushBack(list, 100 + i);
	}

	doublyLinked_printList(list);

	printf("Adding a node at the head.\n");

	doublyLinked_pushFront(list, 42);
	doublyLinked_printList(list);

	printf("Removing a node from the tail.\n");

	doublyLinked_popBack(list);
	doublyLinked_printList(list);

	printf("Removing a node from the head.\n");

	doublyLinked_popFront(list);
	doublyLinked_printList(list);

	printf("Inserting a node after 6 nodes.\n");

	doublyLinked_insertAtIndex(list, 69, 6);
	doublyLinked_printList(list);

	printf("Removing the above mentioned node.\n");

	doublyLinked_popAtIndex(list, 6);
	doublyLinked_printList(list);
}

void container_ass3_ques3() {
	printf("Question - 3, CIRCULAR DOUBLY LINKED LIST\n");
	printf("-------------------------------\n");
	printf("Initial Circular Doubly Linked List (nodes added to tail):\n");
	circularDoublyLinkedList* list = circular_createList();

	for (int i = 0; i < 10; i++) {
		circular_pushBack(list, 100 + i);
	}

	circular_printList(list);

	printf("Adding a node at the head.\n");

	circular_pushFront(list, 42);
	circular_printList(list);

	printf("Removing a node from the tail.\n");

	circular_popBack(list);
	circular_printList(list);

	printf("Removing a node from the head.\n");

	circular_popFront(list);
	circular_printList(list);

	printf("Inserting a node after 6 nodes.\n");

	circular_insertAtIndex(list, 69, 6);
	circular_printList(list);

	printf("Inserting a node after 14 nodes.(More than one round around the list)\n");

	circular_insertAtIndex(list, 53, 14);
	circular_printList(list);	

	printf("Removing the above mentioned node.\n");

	circular_popAtIndex(list, 14);
	circular_printList(list);
}

int main() {
	printf("========= [ SAKSHAM MITTAL - 102319061 ] =========\n");
	container_ass3_ques3();

	return 0;
}