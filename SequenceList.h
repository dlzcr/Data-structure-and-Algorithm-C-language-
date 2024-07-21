#pragma once
#include<stdbool.h>
#include<malloc.h>
#include<stddef.h>

typedef long long int SL_DataType;

typedef struct {
	SL_DataType* _data;
	size_t _size;
	size_t _capacity;
}SequenceList;

//˳����ʼ��
SequenceList* InitializeSList(size_t capacity);
//˳����ȡ��С
inline size_t SizeSList(const SequenceList* list) {
	return list ? list->_size : 0;
}
//˳������Ԫ��
inline SL_DataType* AtSList(const SequenceList* list, size_t pos) {
	return list && pos < list->_size ? list->_data + pos : NULL;
}
//˳������Ԫ��
bool InsertSList(SequenceList* list,size_t pos,SL_DataType value);
//˳���ɾ��Ԫ��
bool EraseSList(SequenceList* list,size_t pos);
//˳������Ԫ��
size_t FindSList(const SequenceList* list,SL_DataType value, bool(*equal)(SL_DataType,SL_DataType));
//˳������Ԫ��
bool ForeachSList(const SequenceList* list, void(*foreach)(SL_DataType*element));
//˳������Ԫ��
inline bool ClearSList(SequenceList* list) {
	return list ? list->_size = 0, true : false;
}
//˳����ͷ��ڴ�
bool FreeSList(SequenceList* list);