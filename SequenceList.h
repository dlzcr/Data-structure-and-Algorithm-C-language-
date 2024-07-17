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

//顺序表初始化
SequenceList* InitializeSqList(size_t capacity);
//顺序表获取大小
inline size_t SizeSqList(const SequenceList* list) {
	return list ? list->_size : 0;
}
//顺序表操作元素
inline SqL_DataType* AtSqList(const SequenceList* list, size_t pos) {
	return list && pos < list->_size ? list->_data + pos : NULL;
}
//顺序表插入元素
bool InsertSqList(SequenceList* list,size_t pos,SqL_DataType value);
//顺序表删除元素
bool EraseSqList(SequenceList* list,size_t pos);
//顺序表查找元素
size_t FindSqList(const SequenceList* list,SqL_DataType value, bool(*equal)(SqL_DataType,SqL_DataType));
//顺序表遍历元素
bool ForeachSqList(const SequenceList* list, void(*foreach)(SqL_DataType*element));
//顺序表清空元素
inline bool ClearSqList(SequenceList* list) {
	return list ? list->_size = 0, true : false;
}
//顺序表释放内存
bool FreeSqList(SequenceList* list);