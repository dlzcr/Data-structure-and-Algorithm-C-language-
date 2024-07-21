#include"CircularLinkedList.h"
#include"malloc.h"
#include <stdint.h>

//循环链表初始化
CircularLinkedList* InitializeCLList() {
	CircularLinkedList* newList = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
	if (!newList)
		return NULL;
	newList->_next = newList;
	return newList;
}
//循环链表获取大小
size_t SizeCLList(const CircularLinkedList* list) {
	if (!list)
		return 0;
	size_t counst = 0;
	for (CNode* index = list->_next; index != list; index = index->_next)
		++counst;
	return counst;
}
//循环链表操作元素
CLL_DataType* AtCLList(const CircularLinkedList* list,size_t pos) {
	if (!list)
		return NULL;
	CNode* index = list->_next;
	for (size_t i = 0; i < pos && index != list; ++i)
		index = index->_next;
	if (index == list)
		return NULL;
	return &index->_data;
}
//循环链表插入元素
bool InsertCLList(CircularLinkedList* list, size_t pos, CLL_DataType value) {
	if (!list)
		return false;
	CNode* indexPrev = list;
	for (size_t i = 0; i < pos && (indexPrev != list || i==0); ++i)
		indexPrev = indexPrev->_next;
	if (indexPrev == list && pos != 0)
		return false;
	CNode* newNode = (CNode*)malloc(sizeof(CNode));
	if (!newNode)
		return false;
	newNode->_next = indexPrev->_next;
	indexPrev->_next = newNode;
	newNode->_data = value;
	return true;
}
//循环链表删除元素
bool EraseCLList(CircularLinkedList* list, size_t pos) {
	if (!list)
		return false;
	CNode* indexPrev = list;
	for (size_t i = 0; i < pos && indexPrev->_next != list; ++i)
		indexPrev = indexPrev->_next;
	if (indexPrev->_next == list)
		return false;
	CNode* to_delete = indexPrev->_next;
	indexPrev->_next = to_delete->_next;
	free(to_delete);
	return true;
}
//循环链表查找元素
size_t FindCLList(const CircularLinkedList* list, CLL_DataType value, bool(*epual)(CLL_DataType, CLL_DataType)) {
	if (!list)
		return SIZE_MAX;
	CNode* index = list->_next;
	size_t i = 0;
	while (index != list){
		if (epual(index->_data, value))
			return i;
		index = index->_next;
		++i;
	}
	return i;
}
//循环链表遍历元素
bool ForeachCLList(const CircularLinkedList* list, void(*foreach)(CLL_DataType*)) {
	if (!list || !foreach)
		return false;
	for (CNode* index = list->_next; index != list; index = index->_next)
		foreach(&index->_data);
	return true;
}
//循环链表清空元素
bool ClearCLList(CircularLinkedList* list) {
	if (!list)
		return false;
	FreeCLList(list->_next);
	list->_next = list;
	return true;
}
//循环链表释放内存
bool FreeCLList(CircularLinkedList* list) {
	if (list)
		return false;
	const CNode* const head = list;
	CNode* temp;
	while (list != head) {
		temp = list->_next;
		free(list);
		list = temp;
	}
	return true;
}