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

//��̬�����ʼ��
StaticLinkedList* InitializeSLinkList(size_t capacity);
//��̬�����ȡ��С
size_t SizeSLinkList(const StaticLinkedList* list);
//��̬�������Ԫ��
SLL_DataType* AtSLinkList(const StaticLinkedList* list, size_t pos);
//��̬�������Ԫ��
bool InsertSLinkList(StaticLinkedList* list, size_t pos, SLL_DataType value);
//��̬����ɾ��
bool EraseSLinkList(StaticLinkedList* list, size_t pos);
//��̬�������Ԫ��
size_t FindSLinkList(const StaticLinkedList* list, SLL_DataType value, bool(*equal)(SLL_DataType, SLL_DataType));
//��̬�������Ԫ��
bool ForeachSLinkList(const StaticLinkedList* list, void(*foreach)(SLL_DataType*));
//��̬�������Ԫ��
bool ClearSLinkList(StaticLinkedList* list);
//��̬�����ͷ��ڴ�
bool FreeSLinkList(StaticLinkedList* list);