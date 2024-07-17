#pragma once
#include<stdbool.h>
#include<malloc.h>
#include<stddef.h>

typedef long long int SqL_DataType;

typedef struct {
	SqL_DataType* _data;
	size_t _size;
	size_t _capacity;
}SequenceList;

//˳����ʼ��
SequenceList* InitializeSqList(size_t capacity);
//˳����ȡ��С
inline size_t SizeSqList(const SequenceList* list) {
	return list ? list->_size : 0;
}
//˳������Ԫ��
inline SqL_DataType* AtSqList(const SequenceList* list, size_t pos) {
	return list && pos < list->_size ? list->_data + pos : NULL;
}
//˳������Ԫ��
bool InsertSqList(SequenceList* list,size_t pos,SqL_DataType value);
//˳���ɾ��Ԫ��
bool EraseSqList(SequenceList* list,size_t pos);
//˳������Ԫ��
size_t FindSqList(const SequenceList* list,SqL_DataType value, bool(*equal)(SqL_DataType,SqL_DataType));
//˳������Ԫ��
bool ForeachSqList(const SequenceList* list, void(*foreach)(SqL_DataType*element));
//˳������Ԫ��
inline bool ClearSqList(SequenceList* list) {
	return list ? list->_size = 0, true : false;
}
//˳����ͷ��ڴ�
bool FreeSqList(SequenceList* list);