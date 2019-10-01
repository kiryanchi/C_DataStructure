/*
 1. Project
	[COME331006] DataStructure Homework #1

 2. Name
	node.h

 3. Purpose
	1. To define NODE using linked list

 4. Creator
	2017112387 Park Ki hyun ( ¹Ú±âÇö )
 */

typedef struct node
{
	void* dataPtr;
	struct node* link;
} NODE;

NODE* createNode(void* itemPtr)
{
	NODE* nodePtr = NULL;
	nodePtr = (NODE*)malloc(sizeof(NODE));
	nodePtr->dataPtr = itemPtr;
	nodePtr->link = NULL;

	return nodePtr;
}   // createNode