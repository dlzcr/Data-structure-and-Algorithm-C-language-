#pragma once
#include<stddef.h>
#include<malloc.h>
#include<stdbool.h>

typedef long long int SLL_DataType;

typedef struct Node {
	SLL_DataType _data;
	struct Node* _next;
}Node,SinglyLinkedList;

//链表初始化
SinglyLinkedList* InitializeSLList();
//链表获取大小
size_t SizeSLList(const SinglyLinkedList* list);
//链表操作元素
SLL_DataType* AtSLList(const SinglyLinkedList* list, size_t pos);
//链表插入元素
bool InsertSLList(SinglyLinkedList* list, size_t pos, SLL_DataType value);
//链表删除元素
bool EraseSLList(SinglyLinkedList* list, size_t pos);
//链表查找元素
size_t FindSLList(const SinglyLinkedList* list, SLL_DataType value, bool(*equal)(SLL_DataType, SLL_DataType));
//链表遍历元素
bool ForeachSLList(const SinglyLinkedList* list, void(*foreach)(SLL_DataType*));
//链表清空元素
bool ClearSLList(SinglyLinkedList* list);
//链表释放内存
bool FreeSLList(SinglyLinkedList* list);
