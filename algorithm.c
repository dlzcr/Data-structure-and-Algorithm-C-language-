#include<stdbool.h>
#include<stddef.h>
#include<stdio.h>
#include<malloc.h>
#include"SinglyLinkedList.h"
#include"CircularLinkedList.h"
#include "algorithm.h"

//用于测试
#ifndef NDEBUG
void print(long long int* const element);
#define PRINT(list) ForeachCLList(index, print)
#endif

//链表操作中间元素
SLL_DataType* MidSLList(SinglyLinkedList* list) {
	Node* fast = list->_next, * mid = list->_next;
	while (fast->_next) {
		fast = fast->_next->_next;
		mid = mid->_next;
	}
	return &mid->_data;
}

//约瑟夫问题
void Joseph(size_t size,CLL_DataType arr[]) {
	CircularLinkedList list;
	list._next = &list;

	CNode* index = &list;
	for (size_t i = 0; i < size; ++i) {
		CNode* newList = (CNode*)malloc(sizeof(CNode));
		if (!newList) {
			perror("error");
			return;
		}
		newList->_data = i + 1;
		newList->_next = index->_next;
		index->_next = newList;
		index = index->_next;
	}

	index->_next = list._next;

	unsigned int counst = 0;
	while (true) {
		index = index->_next->_next;
		CNode* to_delete = index->_next;
		index->_next = to_delete->_next;
		arr[counst++] = to_delete->_data;
		free(to_delete);
		if (index == to_delete)
			break;
	}
}

//拼接循环链表
void ConcatenateCLList(CircularLinkedList* list_1, CircularLinkedList* list_2) {
	//找list_1的尾
	CNode* list_1_back = list_1;
	while (list_1_back->_next != list_1)
		list_1_back = list_1_back->_next;
	//找list_2的尾
	CNode* list_2_back = list_2;
	while (list_2_back->_next != list_2)
		list_2_back = list_2_back->_next;
	//连接
	list_1_back->_next = list_2->_next;
	list_2_back->_next = list_1;
}

//判断链表是否有环
bool is_Circular(SinglyLinkedList* list){
	Node *fast = list->_next, *slow = list->_next;
	while(fast) {
		fast = fast->_next->_next;
		slow = slow->_next->_next;
		if (fast == slow)
			return true;
	}
	return false;
}
