#pragma once

typedef long long int DLL_DataType;

typedef struct DNode {
	DLL_DataType _data;
	struct DNode* _prev;
	struct DNode* _next;
}DNode,DoubleLinkList;

#ifdef bool
//双向链表初始化
DoubleLinkList* InitializeDLList();
//双向链表大小
size_t SizeDLList(const DoubleLinkList* list);
//双向链表操作元素
DLL_DataType* AtDLList(const DoubleLinkList* list, size_t pos);
//双向链表插入元素
bool InsertDLList(DoubleLinkList* list,size_t pos,DLL_DataType value);
//双向链表删除元素
bool EraseDLList(DoubleLinkList* list,size_t pos);
//双向链表查找元素
size_t FindDLList(const DoubleLinkList* list,DLL_DataType value,bool(equal)(DLL_DataType,DLL_DataType));
//双向链表遍历元素
bool ForeachDLList(const DoubleLinkList* list,void(*foreach)(DLL_DataType*));
//双向链表清空元素
bool ClearDLList(DoubleLinkList* list);
//双向链表释放内存
bool FreeDLList(DoubleLinkList* list);
#endif