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

//顺序表测试
void SqListTest() {
	//初始化
	SequenceList* list = InitializeSqList(3);
	//插入0到9
	for(size_t i = 0;i < 10;++i)
		InsertSqList(list, i, i);
	//第8号位置插入999
	InsertSqList(list,8,999);
	//打印所有元素
	for (size_t i = 0; i < SizeSqList(list); ++i)
		printf("%lld ", *AtSqList(list, i));
	puts("");
	//删除第3个位置开始的5个元素
	for (size_t i = 0; i < 5; ++i)
		EraseSqList(list, 3);
	//遍历打印元素
	ForeachSqList(list, print);
	puts("");
	//查找值为999元素
	printf("%lld", FindSqList(list, 999, equal));
	puts("");
	//非法位置操作
	printf("%d\n", InsertSqList(list, SizeSqList(list) + 1, 999));
	printf("%d\n", InsertSqList(list, -1, 999));
	printf("%d\n", EraseSqList(list, SizeSqList(list)));
	printf("%d\n", EraseSqList(list, -1));
	printf("%lld\n", FindSqList(list,7,equal));
	printf("%p\n", AtSqList(list, SizeSqList(list)));
	printf("%p\n", AtSqList(list, -1));
	printf("%d\n", InsertSqList(NULL,0,0));
	printf("%d\n", EraseSqList(NULL,0));
	printf("%lld\n", FindSqList(NULL,0,NULL));
	printf("%p\n", AtSqList(NULL,0));
	ForeachSqList(list, print);
	puts("");
	//清空元素
	ClearSqList(list);
	ForeachSqList(list, print);
	//释放内存
	FreeSqList(list);
}

void LinkListTest() {
	//初始化
	LinkedList* list = InitializeLinkList();
	//插入0到9
	for (size_t i = 0; i < 10; ++i)
		InsertLinkList(list, i, i);
	//第8号位置插入999
	InsertLinkList(list, 8, 999);
	//打印所有元素
	for (size_t i = 0; i < SizeLinkList(list); ++i)
		printf("%lld ", *AtLinkList(list, i));
	puts("");
	//删除第3个位置开始的5个元素
	for (size_t i = 0; i < 5; ++i)
		EraseLinkList(list, 3);
	//遍历打印元素
	ForeachLinkList(list, print);
	puts("");
	//查找值为999元素
	printf("%lld", FindLinkList(list, 999, equal));
	puts("");
	//非法位置操作
	printf("%d\n", InsertLinkList(list, SizeLinkList(list) + 1, 999));
	printf("%d\n", InsertLinkList(list, -1, 999));
	printf("%d\n", EraseLinkList(list, SizeLinkList(list)));
	printf("%d\n", EraseLinkList(list, -1));
	printf("%lld\n", FindLinkList(list, 7, equal));
	printf("%p\n", AtLinkList(list, SizeLinkList(list)));
	printf("%p\n", AtLinkList(list, -1));
	printf("%d\n", InsertLinkList(NULL, 0, 0));
	printf("%d\n", EraseLinkList(NULL, 0));
	printf("%lld\n", FindLinkList(NULL, 0, NULL));
	printf("%p\n", AtLinkList(NULL, 0));
	ForeachLinkList(list, print);
	puts("");
	//清空元素
	ClearLinkList(list);
	ForeachLinkList(list, print);
	//释放内存
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
	LinkListTest();
	return 0;
}