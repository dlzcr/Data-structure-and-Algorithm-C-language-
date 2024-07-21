#pragma once
#include<stddef.h>
#include<malloc.h>
#include<stdbool.h>

typedef long long int SLL_DataType;

typedef struct Node {
	SLL_DataType _data;
	struct Node* _next;
}Node,SinglyLinkedList;

//�����ʼ��
SinglyLinkedList* InitializeSLList();
//�����ȡ��С
size_t SizeSLList(const SinglyLinkedList* list);
//�������Ԫ��
SLL_DataType* AtSLList(const SinglyLinkedList* list, size_t pos);
//�������Ԫ��
bool InsertSLList(SinglyLinkedList* list, size_t pos, SLL_DataType value);
//����ɾ��Ԫ��
bool EraseSLList(SinglyLinkedList* list, size_t pos);
//�������Ԫ��
size_t FindSLList(const SinglyLinkedList* list, SLL_DataType value, bool(*equal)(SLL_DataType, SLL_DataType));
//�������Ԫ��
bool ForeachSLList(const SinglyLinkedList* list, void(*foreach)(SLL_DataType*));
//�������Ԫ��
bool ClearSLList(SinglyLinkedList* list);
//�����ͷ��ڴ�
bool FreeSLList(SinglyLinkedList* list);
