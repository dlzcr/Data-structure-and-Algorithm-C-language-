#pragma once

typedef long long int LQ_DataType;

typedef struct QNode {
	LQ_DataType _data;
	struct QNode* _next;
}QNode;

typedef struct {
	QNode* _front;
	QNode* _rear;
}LinkedQueue;

#ifdef bool
LinkedQueue* InitializeLQueue();
bool InsertLQueue(LinkedQueue* queue, LQ_DataType value);
LQ_DataType DeleteLQueue(LinkedQueue* queue);
bool FreeLQueue(LinkedQueue* queue);
size_t SizeLQueue(const LinkedQueue* queue);
#endif