#include<stdbool.h>
#include<stddef.h>
#include<malloc.h>
#include<stdint.h>
#include"DoubleLinkList.h"

//˫�������ʼ��
DoubleLinkList* InitializeDLList() {
	DoubleLinkList* newList = (DoubleLinkList*)malloc(sizeof(DoubleLinkList));
	if (!newList)
		return NULL;
	newList->_next = NULL;
	newList->_prev = NULL;
	return newList;
}
//˫�������С
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
//˫���������Ԫ��
DLL_DataType* AtDLList(const DoubleLinkList* list,size_t pos) {
	if (!list)
		return NULL;
	DNode* index = list->_next;
	for (size_t i = 0; i < pos; ++i)
		index = index->_next;
	return &index->_data;
}
//˫���������Ԫ��
bool InsertDLList(DoubleLinkList* list, size_t pos, DLL_DataType value) {
	//�жϿ�ָ��
	if (!list)
		return false;
	//��ǰ��ָ��
	DNode* indexPrev = list;
	for (size_t i = 0; i < pos && indexPrev; ++i)
		indexPrev = indexPrev->_next;
	if (!indexPrev)
		return false;
	//�����½ڵ�
	DNode* newList = (DNode*)malloc(sizeof(DNode));
	if (!newList)
		return false;
	//������ϵ
	newList->_next = indexPrev->_next;
	newList->_prev = indexPrev;
	newList->_prev->_next = newList;
	newList->_next->_prev = newList;
	return true;
}
//˫������ɾ��Ԫ��
bool EraseDLList(DoubleLinkList* list, size_t pos) {
	//�жϿ�ָ��
	if (!list)
		return false;
	//��ǰ��ָ��
	DNode* indexPrev = list;
	for (size_t i = 0; i < pos && indexPrev->_next; ++i)
		indexPrev = indexPrev->_next;
	if (!indexPrev->_next)
		return false;
	//ɾ���ڵ�
	DNode* to_delete = indexPrev->_next;//��ɾ�ڵ�
	to_delete->_prev->_next = to_delete->_next;
	to_delete->_next->_prev = to_delete->_prev;
	free(to_delete);
	return true;
}
//˫���������Ԫ��
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
//˫���������Ԫ��
bool ForeachDLList(const DoubleLinkList* list, void(*foreach)(DLL_DataType*)) {
	if (!list || !foreach)
		return false;
	for (DNode* index = list->_next; index; index = index->_next)
		foreach(index->_data);
	return true;
}
//˫���������Ԫ��
bool ClearDLList(DoubleLinkList* list) {
	if (!list)
		return false;
	FreeDLList(list->_next);
	list->_next = NULL;
	return true;
}
//˫�������ͷ��ڴ�
bool FreeDLList(DoubleLinkList* list) {
	if (!list)
		return false;
	FreeDLList(list);
	free(list);
	return true;
}