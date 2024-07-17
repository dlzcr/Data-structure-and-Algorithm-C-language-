#include "LinkedList.h"
#include <malloc.h>
#include <stdint.h>

//链表初始化
LinkedList* InitializeLinkList(){
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	if (!list)
		return NULL;
	list->_next = NULL;
	return list;
}

//链表获取大小
size_t SizeLinkList(const LinkedList* list){
	if (!list)
		return 0;
	size_t count = 0;
	for (Node* index = list->_next; index != NULL; index = index->_next)
		++count;
	return count;
}

//链表操作元素
LinkL_DataType* AtLinkList(const LinkedList* list, size_t pos){
	if (!list)
		return NULL;
	Node* index = list->_next;
	for (size_t i = 0; i < pos && index; ++i)
		index = index->_next;
	if (!index)
		return NULL;
	return &index->_data;
}

//链表插入元素
bool InsertLinkList(LinkedList* list, size_t pos, LinkL_DataType value){
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

//链表删除元素
bool EraseLinkList(LinkedList* list, size_t pos){
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

//链表查找元素
size_t FindLinkList(const LinkedList* list, LinkL_DataType value, bool(*equal)(LinkL_DataType, LinkL_DataType)){
	if (!list)
		return SIZE_MAX;
	Node* index = list->_next;
	int i;
	for (i = 0; index; ++i,index = index->_next)
		if (equal(index->_data, value))
			return i;
	return i;
}

//链表遍历元素
bool ForeachLinkList(const LinkedList* list, void(*foreach)(LinkL_DataType*)){
	if (!list)
		return false;
	for (Node* index = list->_next; index; index = index->_next)
		foreach(&index->_data);
	return true;
}

//链表清空元素
bool ClearLinkList(LinkedList* list){
	bool state = FreeLinkList(list->_next);
	list->_next = NULL;
	return state;
}

//链表释放内存
bool FreeLinkList(LinkedList* list){
	if (!list)
		return false;
	FreeLinkList(list->_next);
	free(list);
	return true;
}
