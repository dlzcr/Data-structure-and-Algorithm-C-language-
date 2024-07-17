#pragma once
#include<stddef.h>
#include<malloc.h>
#include<stdbool.h>

typedef long long int LinkL_DataType;

typedef struct Node {
	LinkL_DataType _data;
	struct Node* _next;
}Node,LinkedList;

//链表初始化
LinkedList* InitializeLinkList();
//链表获取大小
size_t SizeLinkList(const LinkedList* list);
//链表操作元素
LinkL_DataType* AtLinkList(const LinkedList* list, size_t pos);
//链表插入元素
bool InsertLinkList(LinkedList* list, size_t pos, LinkL_DataType value);
//链表删除元素
bool EraseLinkList(LinkedList* list, size_t pos);
//链表查找元素
size_t FindLinkList(const LinkedList* list, LinkL_DataType value, bool(*equal)(LinkL_DataType, LinkL_DataType));
//链表遍历元素
bool ForeachLinkList(const LinkedList* list, void(*foreach)(LinkL_DataType*));
//链表清空元素
bool ClearLinkList(LinkedList* list);
//链表释放内存
bool FreeLinkList(LinkedList* list);