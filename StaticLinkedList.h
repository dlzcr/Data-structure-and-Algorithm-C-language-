#pragma once

typedef long long int SSLL_DataType;

typedef struct{
	SSLL_DataType _data;
	size_t _next;
}SNode;

typedef struct {
	SNode* _arr;
	size_t _capacity;
}StaticLinkedList;

#ifdef bool
//静态链表初始化
StaticLinkedList* InitializeSSLList(size_t capacity);
//静态链表获取大小
size_t SizeSSLList(const StaticLinkedList* list);
//静态链表操作元素
SSLL_DataType* AtSSLList(const StaticLinkedList* list, size_t pos);
//静态链表插入元素
bool InsertSSLList(StaticLinkedList* list, size_t pos, SSLL_DataType value);
//静态链表删除
bool EraseSSLList(StaticLinkedList* list, size_t pos);
//静态链表查找元素
size_t FindSSLList(const StaticLinkedList* list, SSLL_DataType value, bool(*equal)(SSLL_DataType, SSLL_DataType));
//静态链表遍历元素
bool ForeachSSLList(const StaticLinkedList* list, void(*foreach)(SSLL_DataType*));
//静态链表清空元素
bool ClearSSLList(StaticLinkedList* list);
//静态链表释放内存
bool FreeSSLList(StaticLinkedList* list);
#endif