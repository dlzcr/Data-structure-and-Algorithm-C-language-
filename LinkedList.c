#include "LinkedList.h"
#include <malloc.h>
#include <stdint.h>

LinkedList* InitializeLinkList(){
	LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
	if (!newList)
		return NULL;
	newList->_size = 0;
	newList->_head = (Node*)malloc(sizeof(Node));
	if (!newList->_head)
		return NULL;
	newList->_head->_next = NULL;
	return newList;
}

size_t SizeLinkList(const LinkedList* list){
	return list ? list->_size : 0;
}

LinkL_DataType* AtLinkList(const LinkedList* list, size_t pos){
	if (!list || pos>=list->_size)
		return NULL;
	Node* index = list->_head->_next;
	for (size_t i = 0; i < pos; ++i)
		index = index->_next;
	return &index->_data;
}

bool InsertLinkList(LinkedList* list, size_t pos, LinkL_DataType value) {
	if (!list || pos > list->_size)
		return false;

	Node* prevIndex = list->_head;
	for (size_t i = 0; i < pos; ++i)
		prevIndex = prevIndex->_next;

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode)
		return false;
	newNode->_data = value;
	newNode->_next = prevIndex->_next;
	prevIndex->_next = newNode;

	++list->_size;
}

bool EraseLinkList(LinkedList* list, size_t pos){
	if (!list || pos >= list->_size)
		return false;

	Node* prevIndex = list->_head;
	for (size_t i = 0; i < pos; ++i)
		prevIndex = prevIndex->_next;

	Node* toDelete = prevIndex->_next;
	prevIndex->_next = prevIndex->_next->_next;
	free(toDelete);
	--list->_size;
}

size_t FindLinkList(const LinkedList* list, LinkL_DataType value, bool(*equal)(LinkL_DataType, LinkL_DataType)){
	if (!list || !equal)
		return SIZE_MAX;
	Node* index = list->_head->_next;
	for (size_t i = 0; i < list->_size; ++i,index = index->_next)
		if (equal(index->_data, value))
			return i;
	return list->_size;
}

bool ForeachLinkList(const LinkedList* list, void(*foreach)(LinkL_DataType*)){
	if (!list || !foreach)
		return false;
	Node* index = list->_head->_next;
	for (size_t i = 0; i < list->_size; ++i,index = index->_next)
		foreach(&index->_data);
	return true;
}

void clearL(Node* node) {
	if (!node)
		return
	free(node);
	clearL(node->_next);
}

bool ClearLinkList(LinkedList* list){
	if (!list)
		return false;
	clearL(list->_head->_next);
	list->_size = 0;
	list->_head->_next = NULL;
	return true;
}

bool FreeLinkList(LinkedList* list){
	if (!list)
		return false;
	ClearLinkList(list);
	free(list->_head);
	free (list);
	return true;
}