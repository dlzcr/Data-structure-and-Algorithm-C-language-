#pragma once
#include<stddef.h>
#include<malloc.h>
#include<stdbool.h>

typedef long long int LinkL_DataType;

typedef struct Node {
	LinkL_DataType _data;
	struct Node* _next;
}Node,LinkedList;

//�����ʼ��
LinkedList* InitializeLinkList();
//�����ȡ��С
size_t SizeLinkList(const LinkedList* list);
//�������Ԫ��
LinkL_DataType* AtLinkList(const LinkedList* list, size_t pos);
//�������Ԫ��
bool InsertLinkList(LinkedList* list, size_t pos, LinkL_DataType value);
//����ɾ��Ԫ��
bool EraseLinkList(LinkedList* list, size_t pos);
//�������Ԫ��
size_t FindLinkList(const LinkedList* list, LinkL_DataType value, bool(*equal)(LinkL_DataType, LinkL_DataType));
//�������Ԫ��
bool ForeachLinkList(const LinkedList* list, void(*foreach)(LinkL_DataType*));
//�������Ԫ��
bool ClearLinkList(LinkedList* list);
//�����ͷ��ڴ�
bool FreeLinkList(LinkedList* list);