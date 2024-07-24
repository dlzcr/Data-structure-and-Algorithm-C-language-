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
//��̬�����ʼ��
StaticLinkedList* InitializeSSLList(size_t capacity);
//��̬�����ȡ��С
size_t SizeSSLList(const StaticLinkedList* list);
//��̬�������Ԫ��
SSLL_DataType* AtSSLList(const StaticLinkedList* list, size_t pos);
//��̬�������Ԫ��
bool InsertSSLList(StaticLinkedList* list, size_t pos, SSLL_DataType value);
//��̬����ɾ��
bool EraseSSLList(StaticLinkedList* list, size_t pos);
//��̬�������Ԫ��
size_t FindSSLList(const StaticLinkedList* list, SSLL_DataType value, bool(*equal)(SSLL_DataType, SSLL_DataType));
//��̬�������Ԫ��
bool ForeachSSLList(const StaticLinkedList* list, void(*foreach)(SSLL_DataType*));
//��̬�������Ԫ��
bool ClearSSLList(StaticLinkedList* list);
//��̬�����ͷ��ڴ�
bool FreeSSLList(StaticLinkedList* list);
#endif