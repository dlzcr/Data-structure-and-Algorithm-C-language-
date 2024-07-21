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

//顺序表初始化
SequenceList* InitializeSList(size_t capacity);
//顺序表获取大小
inline size_t SizeSList(const SequenceList* list) {
	return list ? list->_size : 0;
}
//顺序表操作元素
inline SL_DataType* AtSList(const SequenceList* list, size_t pos) {
	return list && pos < list->_size ? list->_data + pos : NULL;
}
//顺序表插入元素
bool InsertSList(SequenceList* list,size_t pos,SL_DataType value);
//顺序表删除元素
bool EraseSList(SequenceList* list,size_t pos);
//顺序表查找元素
size_t FindSList(const SequenceList* list,SL_DataType value, bool(*equal)(SL_DataType,SL_DataType));
//顺序表遍历元素
bool ForeachSList(const SequenceList* list, void(*foreach)(SL_DataType*element));
//顺序表清空元素
inline bool ClearSList(SequenceList* list) {
	return list ? list->_size = 0, true : false;
}
//顺序表释放内存
bool FreeSList(SequenceList* list);