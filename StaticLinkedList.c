#include "StaticLinkedList.h"
#include <malloc.h>
#include <stdint.h>

//��̬�����ʼ��
StaticLinkedList* InitializeSLinkList(size_t capacity) {
	//������̬����
	StaticLinkedList* newList = (StaticLinkedList*)malloc(sizeof(StaticLinkedList));
	if (!newList)
		return NULL;
	//���侲̬����Ԫ�ص��ڴ�
	newList->_arr = (SNode*)malloc(sizeof(SNode) * (newList->_capacity = capacity + 2));
	if (!newList->_arr) {
		free(newList);
		return NULL;
	}
	//���ó�ʼ�α��ָ��
	for (size_t i = 0; i < newList->_capacity - 1; ++i)
		newList->_arr[i]._next = i + 1;
	newList->_arr[newList->_capacity - 1]._next = 0;
	//���ؾ�̬����
	return newList;
}
//��̬�����ȡ��С
size_t SizeSLinkList(const StaticLinkedList* list) {
	//�жϿ�ָ��
	if (!list)
		return 0;
	//���㾲̬����Ĵ�С
	size_t count = 0;
	for (size_t index = list->_arr[list->_capacity - 1]._next; index; index = list->_arr[index]._next)
		++count;
	//���ش�С
	return count;
}
//��̬�������Ԫ��
SLL_DataType* AtSLinkList(const StaticLinkedList* list, size_t pos) {
	//�жϿ�ָ��
	if (!list)
		return NULL;
	//Ѱ��λ��
	size_t index = list->_arr[list->_capacity - 1]._next;
	for (size_t i = 0; i < pos && index; ++i)
		index = list->_arr[index]._next;
	//�ж�pos�Ƿ�Խ��
	if (!index)
		return NULL;
	//����Ԫ��
	return &list->_arr[index]._data;
}
//�����ڴ�
size_t malloc_SLL(StaticLinkedList* list) {
	//����ڴ��Ƿ�����
	if (list->_arr[0]._next == list->_capacity - 1)
		return 0;
	//�����¿ռ�
	size_t newIndex = list->_arr[0]._next;
	list->_arr[0]._next = list->_arr[newIndex]._next;
	return newIndex;
}
//��̬�������Ԫ��
bool InsertSLinkList(StaticLinkedList* list, size_t pos, SLL_DataType value) {
	//�жϿ�ָ��
	if (!list)
		return false;
	//Ѱ��λ��
	size_t indexPrev = list->_capacity - 1;
	for (size_t i = 0; i < pos && indexPrev; ++i)
		indexPrev = list->_arr[indexPrev]._next;
	//�ж�pos�Ƿ�Խ��
	if (!indexPrev)
		return false;
	//������Ԫ��
	size_t newNode = malloc_SLL(list);
	list->_arr[newNode]._data = value;
	//������ϵ
	list->_arr[newNode]._next = list->_arr[indexPrev]._next;
	list->_arr[indexPrev]._next = newNode;
	return true;
}
//�ͷ��ڴ�
void free_SLL(StaticLinkedList* list, size_t pos) {
	list->_arr[pos]._next = list->_arr[0]._next;
	list->_arr[0]._next = pos;
}
//��̬����ɾ��
bool EraseSLinkList(StaticLinkedList* list, size_t pos) {
	//�жϿ�ָ��
	if (!list)
		return false;
	//Ѱ��λ��
	size_t indexPrev = list->_capacity - 1;
	for (size_t i = 0; i < pos && list->_arr[indexPrev]._next; i++)
		indexPrev = list->_arr[indexPrev]._next;
	//�ж�pos�Ƿ�Խ��
	if (!list->_arr[indexPrev]._next)
		return false;
	//������ϵ
	size_t to_delete = list->_arr[indexPrev]._next;
	list->_arr[indexPrev]._next = list->_arr[to_delete]._next;
	free_SLL(list,to_delete);
	return true;
}
//��̬�������Ԫ��
size_t FindSLinkList(const StaticLinkedList* list, SLL_DataType value, bool(*equal)(SLL_DataType, SLL_DataType)) {
	//�жϿ�ָ��
	if (!list)
		return SIZE_MAX;
	size_t i = 0;
	for (size_t index = list->_arr[list->_capacity - 1]._next; index; index = list->_arr[index]._next, ++i)
		if (equal(list->_arr[index]._data, value))
			return i;
	return i;
}
//��̬�������Ԫ��
bool ForeachSLinkList(const StaticLinkedList* list, void(*foreach)(SLL_DataType*)) {
	//�жϿ�ָ��
	if (!list)
		return false;
	for (size_t index = list->_arr[list->_capacity - 1]._next; index; index = list->_arr[index]._next)
		foreach(&list->_arr[index]._data);
	return true;
}
//��̬�������Ԫ��
bool ClearSLinkList(StaticLinkedList* list) {
	if (!list)
		return false;
	for (size_t i = 0; i < list->_capacity - 1; ++i)
		list->_arr[i]._next = i + 1;
	list->_arr[list->_capacity - 1]._next = 0;
	return true;
}
//��̬�����ͷ��ڴ�
bool FreeSLinkList(StaticLinkedList* list) {
	if (!list || !list->_arr)
		return false;
	free(list->_arr);
	free(list);
	return true;
}