#include<stdbool.h>
#include<stddef.h>
#include<malloc.h>
#include<stdint.h>
#include"DoubleLinkList.h"

//双向链表初始化
DoubleLinkList* InitializeDLList() {
	DoubleLinkList* newList = (DoubleLinkList*)malloc(sizeof(DoubleLinkList));
	if (!newList)
		return NULL;
	newList->_next = NULL;
	newList->_prev = NULL;
	return newList;
}
//双向链表大小
size_t SizeDLList(const DoubleLinkList* list) {
	if (!list)
		return SIZE_MAX;
	DNode* index = list->_next;
	size_t counst = 0;
	while (index) {
		++counst;
		index = index->_next;
	}
	return counst;
}
//双向链表操作元素
DLL_DataType* AtDLList(const DoubleLinkList* list,size_t pos) {
	if (!list)
		return NULL;
	DNode* index = list->_next;
	for (size_t i = 0; i < pos; ++i)
		index = index->_next;
	return &index->_data;
}
//双向链表插入元素
bool InsertDLList(DoubleLinkList* list, size_t pos, DLL_DataType value) {
	//判断空指针
	if (!list)
		return false;
	//找前驱指针
	DNode* indexPrev = list;
	for (size_t i = 0; i < pos && indexPrev; ++i)
		indexPrev = indexPrev->_next;
	if (!indexPrev)
		return false;
	//创建新节点
	DNode* newList = (DNode*)malloc(sizeof(DNode));
	if (!newList)
		return false;
	//建立关系
	newList->_next = indexPrev->_next;
	newList->_prev = indexPrev;
	newList->_prev->_next = newList;
	newList->_next->_prev = newList;
	return true;
}
//双向链表删除元素
bool EraseDLList(DoubleLinkList* list, size_t pos) {
	//判断空指针
	if (!list)
		return false;
	//找前驱指针
	DNode* indexPrev = list;
	for (size_t i = 0; i < pos && indexPrev->_next; ++i)
		indexPrev = indexPrev->_next;
	if (!indexPrev->_next)
		return false;
	//删除节点
	DNode* to_delete = indexPrev->_next;//待删节点
	to_delete->_prev->_next = to_delete->_next;
	to_delete->_next->_prev = to_delete->_prev;
	free(to_delete);
	return true;
}
//双向链表查找元素
size_t FindDLList(const DoubleLinkList* list, DLL_DataType value, bool(equal)(DLL_DataType, DLL_DataType)) {
	if (!list || !equal)
		return SIZE_MAX;
	DNode* index = list->_next;
	size_t counst = 0;
	while (index) {
		if (equal(index->_data, value))
			return counst;
		++counst;
		index = index->_next;
	}
	return counst;
}
//双向链表遍历元素
bool ForeachDLList(const DoubleLinkList* list, void(*foreach)(DLL_DataType*)) {
	if (!list || !foreach)
		return false;
	for (DNode* index = list->_next; index; index = index->_next)
		foreach(index->_data);
	return true;
}
//双向链表清空元素
bool ClearDLList(DoubleLinkList* list) {
	if (!list)
		return false;
	FreeDLList(list->_next);
	list->_next = NULL;
	return true;
}
//双向链表释放内存
bool FreeDLList(DoubleLinkList* list) {
	if (!list)
		return false;
	FreeDLList(list);
	free(list);
	return true;
}