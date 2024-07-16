#include<stdio.h>
#include"SequenceList.h"
#include"LinkedList.h"
#include"StaticLinkedList.h"
#include <assert.h>

void print(long long int* const element) {
	printf("%lld ", *element);
}

bool equal(const long long int a, const long long int b) {
	return a == b;
}

//À≥–Ú±Ì≤‚ ‘
void SqListTest() {
	SequenceList* list = InitializeSqList(3);
	for(size_t i = 0;i < 10;++i)
		InsertSqList(list, i, i);
	InsertSqList(list,8,999);
	for (size_t i = 0; i < SizeSqList(list); ++i)
		printf("%lld ", *AtSqList(list, i));
	puts("");
	for (size_t i = 0; i < 5; ++i)
		EraseSqList(list, 3);
	ForeachSqList(list, print);
	puts("");
	printf("%lld", FindSqList(list, 999, equal));
	puts("");
	ClearSqList(list);
	ForeachSqList(list, print);
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
	StaticLinkedList* list = InitializeSLinkList(20);
	for (size_t i = 0; i < 10; ++i)
		InsertSLinkList(list, i, i);
	InsertSLinkList(list, 3, 999);
	for (size_t i = 0; i < SizeSLinkList(list); ++i)
		printf("%lld ", *AtSLinkList(list, i));
	puts("");
	for (size_t i = 0; i < 2; ++i)
		EraseSLinkList(list, 4);
	ForeachSLinkList(list, print);
	InsertSLinkList(list, 5, 999);
	puts("");
	ForeachSLinkList(list, print);
	puts("");
	printf("%lld", FindSLinkList(list, 6, equal));
	FreeSLinkList(list);
}

int main(void) {
	SqListTest();
	return 0;
}