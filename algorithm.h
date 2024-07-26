#pragma once
#ifdef bool
//链表操作中间元素
SLL_DataType* MidSLList(SinglyLinkedList* list);
//约瑟夫问题
void Joseph(size_t size, CLL_DataType arr[]);
//拼接循环链表
void ConcatenateCLList(CircularLinkedList* list_1,CircularLinkedList* list_2);
//是否有环
bool is_Circular(SinglyLinkedList* list);
#endif