//链表操作中间元素
#include"SinglyLinkedList.h"
SLL_DataType* MidSLList(SinglyLinkedList* list) {
	Node* fast = list->_next, * mid = list->_next;
	while (fast->_next) {
		fast = fast->_next->_next;
		mid = mid->_next;
	}
	return &mid->_data;
}