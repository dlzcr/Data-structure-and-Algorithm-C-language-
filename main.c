#include<stdio.h>
#include"SequenceList.h"
#include"LinkedList.h"
#include"StaticLinkedList.h"

void print(SqL_DataType* const element) {
	printf("%d ", *element);
}

bool equal(const SqL_DataType a, const SqL_DataType b) {
	return a == b;
}

void SqListTest() {
	SequenceList* list = InitializeSqList(10);
	for(size_t i = 0;i < 10;++i)
		InsertSqList(list, i, i);
	for (size_t i = 0; i < SizeSqList(list); ++i)
		printf("%d ", *AtSqList(list,i));
	puts("");
	for (size_t i = 0; i < 5; ++i)
		EraseSqList(list, i);
	ForeachSqList(list, print);
	puts("");
	printf("%lld",FindSqList(list, 7, equal));
	ClearSqList(list);
	FreeSqList(list);
}

void LinkListTest() {
	LinkedList* list = InitializeLinkList();
	for (size_t i = 0; i < 10; ++i)
		InsertLinkList(list, i, i);
	for (size_t i = 0; i < SizeLinkList(list); ++i)
		printf("%d ", *AtLinkList(list, i));
	puts("");
	for (size_t i = 0; i < 5; ++i)
		EraseLinkList(list, i);
	ForeachLinkList(list, print);
	puts("");
	printf("%lld", FindLinkList(list, 7, equal));
	ClearLinkList(list);
	FreeLinkList(list);
}

void StaticLinkedListTest() {
	StaticLinkedList* list = InitializeSLinkList(256);
	for (size_t i = 0; i < 10; ++i)
		InsertSLinkList(list, i, i);
	InsertSLinkList(list, 3, 999);
	for (size_t i = 0; i < 11; ++i)
		printf("%d ", *AtSLinkList(list, i));
	puts("");
	for (size_t i = 0; i < SizeSLinkList(list); ++i)
		EraseSLinkList(list, 1);
	for (size_t i = 0; i < SizeSLinkList(list); ++i)
		printf("%d ", *AtSLinkList(list, i));
}

int main(void) {
	StaticLinkedListTest();
	return 0;
}