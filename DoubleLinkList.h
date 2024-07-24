#pragma once

typedef long long int DLL_DataType;

typedef struct DNode {
	DLL_DataType _data;
	struct DNode* _prev;
	struct DNode* _next;
}DNode,DoubleLinkList;

#ifdef bool
//˫�������ʼ��
DoubleLinkList* InitializeDLList();
//˫�������С
size_t SizeDLList(const DoubleLinkList* list);
//˫���������Ԫ��
DLL_DataType* AtDLList(const DoubleLinkList* list, size_t pos);
//˫���������Ԫ��
bool InsertDLList(DoubleLinkList* list,size_t pos,DLL_DataType value);
//˫������ɾ��Ԫ��
bool EraseDLList(DoubleLinkList* list,size_t pos);
//˫���������Ԫ��
size_t FindDLList(const DoubleLinkList* list,DLL_DataType value,bool(equal)(DLL_DataType,DLL_DataType));
//˫���������Ԫ��
bool ForeachDLList(const DoubleLinkList* list,void(*foreach)(DLL_DataType*));
//˫���������Ԫ��
bool ClearDLList(DoubleLinkList* list);
//˫�������ͷ��ڴ�
bool FreeDLList(DoubleLinkList* list);
#endif