#include"SequenceList.h"
#include <stdint.h>
#include <malloc.h>
#include<stdbool.h>
//顺序表初始化
SequenceList* InitializeSList(size_t capacity) {
	SequenceList* newList = (SequenceList*)malloc(sizeof(SequenceList));
	if (!newList)
		return NULL;
	newList->_capacity = capacity;
	newList->_size = 0;
	newList->_data = (SL_DataType*)malloc(sizeof(SL_DataType) * capacity);
	if (!newList->_data) {
		free(newList);
		return NULL;
	}
	return newList;
}
//顺序表插入元素
bool InsertSList(SequenceList* list, size_t pos, SL_DataType value) {
	if (!list || pos > list->_size)
		return false;
	if (list->_size == list->_capacity)
		list->_data = (SL_DataType*)realloc(list->_data, sizeof(SL_DataType) * (list->_capacity *= 2));
	if (!list->_data)
		return false;
	for (size_t i = list->_size; i > pos; --i)
		list->_data[i] = list->_data[i - 1];
	list->_data[pos] = value;
	++list->_size;
	return true;
}
//顺序表删除元素
bool EraseSList(SequenceList* list, size_t pos) {
	if (!list || pos >= list->_size)
		return false;
	for (size_t i = pos + 1; i < list->_size; ++i)
		list->_data[i - 1] = list->_data[i];
	--list->_size;
	return true;
}
//顺序表查找元素
size_t FindSList(const SequenceList* list, SL_DataType value, bool(* equal)( SL_DataType,  SL_DataType)) {
	if (!list)
		return SIZE_MAX;
	for (size_t i = 0; i < list->_size; ++i)
		if (equal(list->_data[i], value))
			return i;
	return list->_size;
}
//顺序表遍历元素
bool ForeachSList(const SequenceList*  list, void(* foreach)(SL_DataType* element)) {
	if (!list || !foreach)
		return false;
	for (size_t i = 0; i < list->_size; ++i)
		foreach(list->_data + i);
	return true;
}
//顺序表释放内存
bool FreeSList(SequenceList* list) {
	if (!list || !list->_data)
		return false;
	free(list->_data);
	free(list);
	return true;
}