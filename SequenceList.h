#include<stdbool.h>
#include<malloc.h>
#include<stddef.h>

typedef int SqL_DataType;

typedef struct {
	SqL_DataType* _data;
	size_t _size;
	size_t _capacity;
}SequenceList;

SequenceList* InitializeSqList(size_t capacity);
size_t SizeSqList(const SequenceList*list);
SqL_DataType* AtSqList(const SequenceList*list,size_t pos);
bool InsertSqList(SequenceList* list,size_t pos,SqL_DataType value);
bool EraseSqList(SequenceList* list,size_t pos);
size_t FindSqList(const SequenceList* list,SqL_DataType value, bool(*equal)(SqL_DataType,SqL_DataType));
bool ForeachSqList(const SequenceList* list, void(*foreach)(SqL_DataType*element));
bool ClearSqList(SequenceList* list);
bool FreeSqList(SequenceList* list);