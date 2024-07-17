#pragma once
#include<stddef.h>
#include<malloc.h>
#include<stdbool.h>

typedef long long int LinkL_DataType;

typedef struct Node {
	LinkL_DataType _data;
	struct Node* _next;
}Node,LinkedList;

LinkedList* InitializeLinkList();
size_t SizeLinkList(const LinkedList* list);
LinkL_DataType* AtLinkList(const LinkedList* list, size_t pos);
bool InsertLinkList(LinkedList* list, size_t pos, LinkL_DataType value);
bool EraseLinkList(LinkedList* list, size_t pos);
size_t FindLinkList(const LinkedList* list, LinkL_DataType value, bool(*equal)(LinkL_DataType, LinkL_DataType));
bool ForeachLinkList(const LinkedList* list, void(*foreach)(LinkL_DataType*));
bool ClearLinkList(LinkedList* list);
bool FreeLinkList(LinkedList* list);