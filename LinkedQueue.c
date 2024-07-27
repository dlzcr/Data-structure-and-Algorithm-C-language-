#include<stdbool.h>
#include<malloc.h>
#include<stddef.h>
#include<stdint.h>
#include"LinkedQueue.h"

LinkedQueue* InitializeLQueue() {
	LinkedQueue* newQueue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if (!newQueue)
		return NULL;
	newQueue->_rear = newQueue->_front = (QNode*)malloc(sizeof(QNode));
	if (!newQueue->_rear)
		return NULL;
	newQueue->_rear->_next = NULL;
	return newQueue;
}

bool InsertLQueue(LinkedQueue* queue, LQ_DataType value) {
	if (!queue)
		return false;
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (!newNode)
		return false;
	newNode->_data = value;
	newNode->_next = NULL;
	queue->_rear->_next = newNode;
	queue->_rear = queue->_rear->_next;
	return false;
}

LQ_DataType DeleteLQueue(LinkedQueue* queue) {
	if (!queue || queue->_front == queue->_rear)
		return false;
	QNode* to_delete = queue->_front->_next;
	LQ_DataType data = to_delete->_data;
	queue->_front->_next = to_delete->_next;
	free(to_delete);
	return data;
}

bool FreeLQueue(LinkedQueue* queue){
	if (!queue)
		return false;
	QNode* index = queue->_front;
	QNode* temp;
	while (index) {
		temp = index->_next;
		free(index);
		index = temp;
	}
}

size_t SizeLQueue(const LinkedQueue* queue)
{
	if (!queue)
		return SIZE_MAX;
	QNode* index = queue->_front->_next;
	size_t counst = 0;
	while (index) {
		++counst;
		index = index->_next;
	}
	return index;
}
