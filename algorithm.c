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
void Joseph(size_t size){
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
	while (true) {
		index = index->_next->_next;
		CNode* to_delete = index->_next;
		index->_next = to_delete->_next;
		printf("%lld ", to_delete->_data);
		free(to_delete);
		if (index == to_delete)
			break;
	}
}
