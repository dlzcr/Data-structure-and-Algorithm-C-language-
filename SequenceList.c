#include"SequenceList.h"
#include <stdint.h>
//˳����ʼ��
SequenceList* InitializeSqList(size_t capacity) {
	SequenceList* newList = (SequenceList*)malloc(sizeof(SequenceList));
	if (!newList)
		return NULL;
	newList->_capacity = capacity;
	newList->_size = 0;
	newList->_data = (SqL_DataType*)malloc(sizeof(SqL_DataType) * capacity);
	if (!newList->_data) {
		free(newList);
		return NULL;
	}
	return newList;
}
//˳������Ԫ��
bool InsertSqList(SequenceList* list, size_t pos, SqL_DataType value) {
	if (!list || pos > list->_size)
		return false;
	if (list->_size == list->_capacity)
		list->_data = (SqL_DataType*)realloc(list->_data, sizeof(SqL_DataType) * (list->_capacity *= 2));
	if (!list->_data)
		return false;
	for (size_t i = list->_size; i > pos; --i)
		list->_data[i] = list->_data[i - 1];
	list->_data[pos] = value;
	++list->_size;
	return true;
}
//˳���ɾ��Ԫ��
bool EraseSqList(SequenceList* list, size_t pos) {
	if (!list || pos >= list->_size)
		return false;
	for (size_t i = pos + 1; i < list->_size; ++i)
		list->_data[i - 1] = list->_data[i];
	--list->_size;
	return true;
}
//˳������Ԫ��
size_t FindSqList(const SequenceList* list, SqL_DataType value, bool(* equal)( SqL_DataType,  SqL_DataType)) {
	if (!list)
		return SIZE_MAX;
	for (size_t i = 0; i < list->_size; ++i)
		if (equal(list->_data[i], value))
			return i;
	return list->_size;
}
//˳������Ԫ��
bool ForeachSqList(const SequenceList*  list, void(* foreach)(SqL_DataType* element)) {
	if (!list || !foreach)
		return false;
	for (size_t i = 0; i < list->_size; ++i)
		foreach(list->_data + i);
	return true;
}
//˳����ͷ��ڴ�
bool FreeSqList(SequenceList* list) {
	if (!list || !list->_data)
		return false;
	free(list->_data);
	free(list);
	return true;
}