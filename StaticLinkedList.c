#include "StaticLinkedList.h"
#include <malloc.h>
#include <stdint.h>

//静态链表初始化
StaticLinkedList* InitializeSLinkList(size_t capacity) {
	//创建静态链表
	StaticLinkedList* newList = (StaticLinkedList*)malloc(sizeof(StaticLinkedList));
	if (!newList)
		return NULL;
	//分配静态链表元素的内存
	newList->_arr = (SNode*)malloc(sizeof(SNode) * (newList->_capacity = capacity + 2));
	if (!newList->_arr) {
		free(newList);
		return NULL;
	}
	//设置初始游标的指向
	for (size_t i = 0; i < newList->_capacity - 1; ++i)
		newList->_arr[i]._next = i + 1;
	newList->_arr[newList->_capacity - 1]._next = 0;
	//返回静态链表
	return newList;
}
//静态链表获取大小
size_t SizeSLinkList(const StaticLinkedList* list) {
	//判断空指针
	if (!list)
		return 0;
	//计算静态链表的大小
	size_t count = 0;
	for (size_t index = list->_arr[list->_capacity - 1]._next; index; index = list->_arr[index]._next)
		++count;
	//返回大小
	return count;
}
//静态链表操作元素
SLL_DataType* AtSLinkList(const StaticLinkedList* list, size_t pos) {
	//判断空指针
	if (!list)
		return NULL;
	//寻找位置
	size_t index = list->_arr[list->_capacity - 1]._next;
	for (size_t i = 0; i < pos && index; ++i)
		index = list->_arr[index]._next;
	//判断pos是否越界
	if (!index)
		return NULL;
	//返回元素
	return &list->_arr[index]._data;
}
//申请内存
size_t malloc_SLL(StaticLinkedList* list) {
	//检查内存是否以满
	if (list->_arr[0]._next == list->_capacity - 1)
		return 0;
	//分配新空间
	size_t newIndex = list->_arr[0]._next;
	list->_arr[0]._next = list->_arr[newIndex]._next;
	return newIndex;
}
//静态链表插入元素
bool InsertSLinkList(StaticLinkedList* list, size_t pos, SLL_DataType value) {
	//判断空指针
	if (!list)
		return false;
	//寻找位置
	size_t indexPrev = list->_capacity - 1;
	for (size_t i = 0; i < pos && indexPrev; ++i)
		indexPrev = list->_arr[indexPrev]._next;
	//判断pos是否越界
	if (!indexPrev)
		return false;
	//创建新元素
	size_t newNode = malloc_SLL(list);
	list->_arr[newNode]._data = value;
	//建立关系
	list->_arr[newNode]._next = list->_arr[indexPrev]._next;
	list->_arr[indexPrev]._next = newNode;
	return true;
}
//释放内存
void free_SLL(StaticLinkedList* list, size_t pos) {
	list->_arr[pos]._next = list->_arr[0]._next;
	list->_arr[0]._next = pos;
}
//静态链表删除
bool EraseSLinkList(StaticLinkedList* list, size_t pos) {
	//判断空指针
	if (!list)
		return false;
	//寻找位置
	size_t indexPrev = list->_capacity - 1;
	for (size_t i = 0; i < pos && list->_arr[indexPrev]._next; i++)
		indexPrev = list->_arr[indexPrev]._next;
	//判断pos是否越界
	if (!list->_arr[indexPrev]._next)
		return false;
	//建立关系
	size_t to_delete = list->_arr[indexPrev]._next;
	list->_arr[indexPrev]._next = list->_arr[to_delete]._next;
	free_SLL(list,to_delete);
	return true;
}
//静态链表查找元素
size_t FindSLinkList(const StaticLinkedList* list, SLL_DataType value, bool(*equal)(SLL_DataType, SLL_DataType)) {
	//判断空指针
	if (!list)
		return SIZE_MAX;
	size_t i = 0;
	for (size_t index = list->_arr[list->_capacity - 1]._next; index; index = list->_arr[index]._next, ++i)
		if (equal(list->_arr[index]._data, value))
			return i;
	return i;
}
//静态链表遍历元素
bool ForeachSLinkList(const StaticLinkedList* list, void(*foreach)(SLL_DataType*)) {
	//判断空指针
	if (!list)
		return false;
	for (size_t index = list->_arr[list->_capacity - 1]._next; index; index = list->_arr[index]._next)
		foreach(&list->_arr[index]._data);
	return true;
}
//静态链表清空元素
bool ClearSLinkList(StaticLinkedList* list) {
	if (!list)
		return false;
	for (size_t i = 0; i < list->_capacity - 1; ++i)
		list->_arr[i]._next = i + 1;
	list->_arr[list->_capacity - 1]._next = 0;
	return true;
}
//静态链表释放内存
bool FreeSLinkList(StaticLinkedList* list) {
	if (!list || !list->_arr)
		return false;
	free(list->_arr);
	free(list);
	return true;
}