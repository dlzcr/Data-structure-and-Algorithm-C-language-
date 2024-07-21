#include "SinglyLinkedList.h"
#include <malloc.h>
#include <stdint.h>

//�����ʼ��
SinglyLinkedList* InitializeSLList(){
	SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
	if (!list)
		return NULL;
	list->_next = NULL;
	return list;
}

//�����ȡ��С
size_t SizeSLList(const SinglyLinkedList* list){
	if (!list)
		return 0;
	size_t count = 0;
	for (Node* index = list->_next; index; index = index->_next)
		++count;
	return count;
}

//�������Ԫ��
SLL_DataType* AtSLList(const SinglyLinkedList* list, size_t pos){
	if (!list)
		return NULL;
	Node* index = list->_next;
	for (size_t i = 0; i < pos && index; ++i)
		index = index->_next;
	if (!index)
		return NULL;
	return &index->_data;
}

//�������Ԫ��
bool InsertSLList(SinglyLinkedList* list, size_t pos, SLL_DataType value){
	if (!list)
		return false;
	Node* indexPrev = list;
	for (size_t i = 0; i < pos && indexPrev; ++i)
		indexPrev = indexPrev->_next;
	if (!indexPrev)
		return false;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode || !indexPrev)
		return false;
	newNode->_next = indexPrev->_next;
	indexPrev->_next = newNode;
	newNode->_data = value;
	return true;
}

//����ɾ��Ԫ��
bool EraseSLList(SinglyLinkedList* list, size_t pos){
	if (!list)
		return false;
	Node* indexPrev = list;
	for (size_t i = 0; i < pos && indexPrev->_next; ++i)
		indexPrev = indexPrev->_next;
	if (!indexPrev->_next)
		return NULL;
	Node* to_delete = indexPrev->_next;
	indexPrev->_next = to_delete->_next;
	free(to_delete);
	return false;
}

//�������Ԫ��
size_t FindSLList(const SinglyLinkedList* list, SLL_DataType value, bool(*equal)(SLL_DataType, SLL_DataType)){
	if (!list)
		return SIZE_MAX;
	Node* index = list->_next;
	int i;
	for (i = 0; index; ++i,index = index->_next)
		if (equal(index->_data, value))
			return i;
	return i;
}

//�������Ԫ��
bool ForeachSLList(const SinglyLinkedList* list, void(*foreach)(SLL_DataType*)){
	if (!list)
		return false;
	for (Node* index = list->_next; index; index = index->_next)
		foreach(&index->_data);
	return true;
}

//�������Ԫ��
bool ClearSLList(SinglyLinkedList* list){
	bool state = FreeSLList(list->_next);
	list->_next = NULL;
	return state;
}

//�����ͷ��ڴ�
bool FreeSLList(SinglyLinkedList* list){
	if (!list)
		return false;
	FreeSLList(list->_next);
	free(list);
	return true;
}
