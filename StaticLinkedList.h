#pragma once
#include<stddef.h>
#include<stdbool.h>

typedef long long int SLL_DataType;

typedef struct{
	SLL_DataType _data;
	size_t _next;
}SNode;

typedef struct {
	SNode* _arr;
	size_t _capacity;
}StaticLinkedList;

//静态链表初始化
StaticLinkedList* InitializeSLinkList(size_t capacity);
//静态链表获取大小
size_t SizeSLinkList(const StaticLinkedList* list);
//静态链表操作元素
SLL_DataType* AtSLinkList(const StaticLinkedList* list, size_t pos);
//静态链表插入元素
bool InsertSLinkList(StaticLinkedList* list, size_t pos, SLL_DataType value);
//静态链表删除
bool EraseSLinkList(StaticLinkedList* list, size_t pos);
//静态链表查找元素
size_t FindSLinkList(const StaticLinkedList* list, SLL_DataType value, bool(*equal)(SLL_DataType, SLL_DataType));
//静态链表遍历元素
bool ForeachSLinkList(const StaticLinkedList* list, void(*foreach)(SLL_DataType*));
//静态链表清空元素
bool ClearSLinkList(StaticLinkedList* list);
//静态链表释放内存
bool FreeSLinkList(StaticLinkedList* list);