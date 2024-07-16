#pragma once
#include<stddef.h>
#include<stdbool.h>

typedef int SLL_DataType;

typedef struct{
	SLL_DataType _data;
	size_t _next;
}SNode;

typedef struct {
	SNode* _arr;
	size_t _size;
	size_t _capacity;
}StaticLinkedList;

StaticLinkedList* InitializeSLinkList(size_t capacity);
bool InsertSLinkList(StaticLinkedList* list, size_t pos, SLL_DataType value);
SLL_DataType* AtSLinkList(const StaticLinkedList* list, size_t pos);
bool EraseSLinkList(StaticLinkedList* list, size_t pos);
inline size_t SizeSLinkList(const StaticLinkedList* list) {
	return list ? list->_size : 0;
}
bool ForeachSLinkList(const StaticLinkedList* list, void(*foreach)(SLL_DataType*));
size_t FindSLinkList(const StaticLinkedList* list, SLL_DataType value, bool(*equal)(SLL_DataType, SLL_DataType));
bool ClearSLinkList(StaticLinkedList* list);
bool FreeSLinkList(StaticLinkedList* list);