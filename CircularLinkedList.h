#pragma once
#include<stdbool.h>

typedef long long int CLL_DataType;

typedef struct CNode {
	CLL_DataType _data;
	struct CNode* _next;
}CNode,CircularLinkedList;

//ѭ�������ʼ��
CircularLinkedList* InitializeCLList();
//ѭ�������ȡ��С
size_t SizeCLList(const CircularLinkedList* list);
//ѭ���������Ԫ��
CLL_DataType* AtCLList(const CircularLinkedList* list,size_t pos);
//ѭ���������Ԫ��
bool InsertCLList(CircularLinkedList* list, size_t pos, CLL_DataType value);
//ѭ������ɾ��Ԫ��
bool EraseCLList(CircularLinkedList* list, size_t pos);
//ѭ���������Ԫ��
size_t FindCLList(const CircularLinkedList* list, CLL_DataType value, bool(*epual)(CLL_DataType, CLL_DataType));
//ѭ���������Ԫ��
bool ForeachCLList(const CircularLinkedList* list, void(*foreach)(CLL_DataType*));
//ѭ���������Ԫ��
bool ClearCLList(CircularLinkedList* list);
//ѭ�������ͷ��ڴ�
bool FreeCLList(CircularLinkedList* list);