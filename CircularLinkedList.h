#pragma once
#include<stdbool.h>

typedef long long int CLL_DataType;

typedef struct CNode {
	CLL_DataType _data;
	struct CNode* _next;
}CNode,CircularLinkedList;

//循环链表初始化
CircularLinkedList* InitializeCLList();
//循环链表获取大小
size_t SizeCLList(const CircularLinkedList* list);
//循环链表操作元素
CLL_DataType* AtCLList(const CircularLinkedList* list,size_t pos);
//循环链表插入元素
bool InsertCLList(CircularLinkedList* list, size_t pos, CLL_DataType value);
//循环链表删除元素
bool EraseCLList(CircularLinkedList* list, size_t pos);
//循环链表查找元素
size_t FindCLList(const CircularLinkedList* list, CLL_DataType value, bool(*epual)(CLL_DataType, CLL_DataType));
//循环链表遍历元素
bool ForeachCLList(const CircularLinkedList* list, void(*foreach)(CLL_DataType*));
//循环链表清空元素
bool ClearCLList(CircularLinkedList* list);
//循环链表释放内存
bool FreeCLList(CircularLinkedList* list);