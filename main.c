#include<stdio.h>
#include<stdbool.h>
#include<stddef.h>
#include"SequenceList.h"
#include"SinglyLinkedList.h"
#include"StaticLinkedList.h"
#include"CircularLinkedList.h"
#include"algorithm.h"
#include"DoubleLinkList.h"
#include"SequenceStack.h"
#include"LinkedStack.h"

//顺序表测试
void SListTest();
//链表测试
void SLListTest();
//静态链表测试
void SSLListTest();
//循环链表测试
void CLListTest();
//双链表测试
void DLListTest();
//算法测试
void algorithmTest();
//顺序栈测试
void SStackTest();
//链式栈测试
void LStackTest();

int main(void) {
	//SListTest();
	//SLListTest();
	//SSLListTest();
	//CLListTest();
	//CLListTest();
	//algorithmTest();
	//SStackTest();
	LStackTest();
	return 0;
}

void print(long long int* const element) {
	printf("%lld ", *element);
}

bool equal(const long long int a, const long long int b) {
	return a == b;
}

//顺序表测试
void SListTest() {
	//初始化
	SequenceList* list = InitializeSList(3);
	//插入0到9
	for (size_t i = 0; i < 10; ++i)
		InsertSList(list, i, i);
	//第8号位置插入999
	InsertSList(list, 8, 999);
	//打印所有元素
	for (size_t i = 0; i < SizeSList(list); ++i)
		printf("%lld ", *AtSList(list, i));
	puts("");
	//删除第3个位置开始的5个元素
	for (size_t i = 0; i < 5; ++i)
		EraseSList(list, 3);
	//遍历打印元素
	ForeachSList(list, print);
	puts("");
	//查找值为999元素
	printf("%lld", FindSList(list, 999, equal));
	puts("");
	//非法位置操作
	printf("%d\n", InsertSList(list, SizeSList(list) + 1, 999));
	printf("%d\n", InsertSList(list, -1, 999));
	printf("%d\n", EraseSList(list, SizeSList(list)));
	printf("%d\n", EraseSList(list, -1));
	printf("%lld\n", FindSList(list, 7, equal));
	printf("%p\n", AtSList(list, SizeSList(list)));
	printf("%p\n", AtSList(list, -1));
	printf("%d\n", InsertSList(NULL, 0, 0));
	printf("%d\n", EraseSList(NULL, 0));
	printf("%lld\n", FindSList(NULL, 0, NULL));
	printf("%p\n", AtSList(NULL, 0));
	ForeachSList(list, print);
	puts("");
	//清空元素
	ClearSList(list);
	ForeachSList(list, print);
	puts("");
	//释放内存
	FreeSList(list);
}

//链表测试
void SLListTest() {
	//初始化
	SinglyLinkedList* list = InitializeSLList();
	//插入0到9
	for (size_t i = 0; i < 10; ++i)
		InsertSLList(list, i, i);
	//第8号位置插入999
	InsertSLList(list, 8, 999);
	//打印所有元素
	for (size_t i = 0; i < SizeSLList(list); ++i)
		printf("%lld ", *AtSLList(list, i));
	puts("");
	//删除第3个位置开始的5个元素
	for (size_t i = 0; i < 5; ++i)
		EraseSLList(list, 3);
	//遍历打印元素
	ForeachSLList(list, print);
	puts("");
	//查找值为999元素
	printf("%lld", FindSLList(list, 999, equal));
	puts("");
	//非法位置操作
	printf("%d\n", InsertSLList(list, SizeSLList(list) + 1, 999));
	printf("%d\n", InsertSLList(list, -1, 999));
	printf("%d\n", EraseSLList(list, SizeSLList(list)));
	printf("%d\n", EraseSLList(list, -1));
	printf("%lld\n", FindSLList(list, 7, equal));
	printf("%p\n", AtSLList(list, SizeSLList(list)));
	printf("%p\n", AtSLList(list, -1));
	printf("%d\n", InsertSLList(NULL, 0, 0));
	printf("%d\n", EraseSLList(NULL, 0));
	printf("%lld\n", FindSLList(NULL, 0, NULL));
	printf("%p\n", AtSLList(NULL, 0));
	ForeachSLList(list, print);
	puts("");
	//清空元素
	ClearSLList(list);
	ForeachSLList(list, print);
	puts("");
	//释放内存
	FreeSLList(list);
}

//静态链表测试
void SSLListTest() {
	//初始化
	StaticLinkedList* list = InitializeSSLList(30);
	//插入0到9
	for (size_t i = 0; i < 10; ++i)
		InsertSSLList(list, i, i);
	//第8号位置插入999
	InsertSSLList(list, 8, 999);
	//打印所有元素
	for (size_t i = 0; i < SizeSSLList(list); ++i)
		printf("%lld ", *AtSSLList(list, i));
	puts("");
	//删除第3个位置开始的5个元素
	for (size_t i = 0; i < 5; ++i)
		EraseSSLList(list, 3);
	//遍历打印元素
	ForeachSSLList(list, print);
	puts("");
	//查找值为999元素
	printf("%lld", FindSSLList(list, 999, equal));
	puts("");
	//非法位置操作
	printf("%d\n", InsertSSLList(list, SizeSSLList(list) + 1, 999));
	printf("%d\n", InsertSSLList(list, -1, 999));
	printf("%d\n", EraseSSLList(list, SizeSSLList(list)));
	printf("%d\n", EraseSSLList(list, -1));
	printf("%lld\n", FindSSLList(list, 7, equal));
	printf("%p\n", AtSSLList(list, SizeSSLList(list)));
	printf("%p\n", AtSSLList(list, -1));
	printf("%d\n", InsertSSLList(NULL, 0, 0));
	printf("%d\n", EraseSSLList(NULL, 0));
	printf("%lld\n", FindSSLList(NULL, 0, NULL));
	printf("%p\n", AtSSLList(NULL, 0));
	ForeachSSLList(list, print);
	puts("");
	//清空元素
	ClearSSLList(list);
	ForeachSSLList(list, print);
	puts("");
	//释放内存
	FreeSSLList(list);
}

void CLListTest()
{
	//初始化
	CircularLinkedList* list = InitializeCLList();
	//插入0到9
	for (size_t i = 0; i < 10; ++i)
		InsertCLList(list, i, i);
	//第8号位置插入999
	InsertCLList(list, 8, 999);
	//打印所有元素
	for (size_t i = 0; i < SizeCLList(list); ++i)
		printf("%lld ", *AtCLList(list, i));
	puts("");
	//删除第3个位置开始的5个元素
	for (size_t i = 0; i < 5; ++i)
		EraseCLList(list, 3);
	//遍历打印元素
	ForeachCLList(list, print);
	puts("");
	//查找值为999元素
	printf("%lld", FindCLList(list, 999, equal));
	puts("");
	//非法位置操作
	printf("%d\n", InsertCLList(list, SizeCLList(list) + 1, 999));
	printf("%d\n", InsertCLList(list, -1, 999));
	printf("%d\n", EraseCLList(list, SizeCLList(list)));
	printf("%d\n", EraseCLList(list, -1));
	printf("%lld\n", FindCLList(list, 7, equal));
	printf("%p\n", AtCLList(list, SizeCLList(list)));
	printf("%p\n", AtCLList(list, -1));
	printf("%d\n", InsertCLList(NULL, 0, 0));
	printf("%d\n", EraseCLList(NULL, 0));
	printf("%lld\n", FindCLList(NULL, 0, NULL));
	printf("%p\n", AtCLList(NULL, 0));
	ForeachCLList(list, print);
	puts("");
	//清空元素
	ClearCLList(list);
	ForeachCLList(list, print);
	puts("");
	//释放内存
	FreeCLList(list);
}

void DLListTest(){
	//初始化
	CircularLinkedList* list = InitializeCLList();
	//插入0到9
	for (size_t i = 0; i < 10; ++i)
		InsertCLList(list, i, i);
	//第8号位置插入999
	InsertCLList(list, 8, 999);
	//打印所有元素
	for (size_t i = 0; i < SizeCLList(list); ++i)
		printf("%lld ", *AtCLList(list, i));
	puts("");
	//删除第3个位置开始的5个元素
	for (size_t i = 0; i < 5; ++i)
		EraseCLList(list, 3);
	//遍历打印元素
	ForeachCLList(list, print);
	puts("");
	//查找值为999元素
	printf("%lld", FindCLList(list, 999, equal));
	puts("");
	//非法位置操作
	printf("%d\n", InsertCLList(list, SizeCLList(list) + 1, 999));
	printf("%d\n", InsertCLList(list, -1, 999));
	printf("%d\n", EraseCLList(list, SizeCLList(list)));
	printf("%d\n", EraseCLList(list, -1));
	printf("%lld\n", FindCLList(list, 7, equal));
	printf("%p\n", AtCLList(list, SizeCLList(list)));
	printf("%p\n", AtCLList(list, -1));
	printf("%d\n", InsertCLList(NULL, 0, 0));
	printf("%d\n", EraseCLList(NULL, 0));
	printf("%lld\n", FindCLList(NULL, 0, NULL));
	printf("%p\n", AtCLList(NULL, 0));
	ForeachCLList(list, print);
	puts("");
	//清空元素
	ClearCLList(list);
	ForeachCLList(list, print);
	puts("");
	//释放内存
	FreeCLList(list);
}

void algorithmTest() {
	//MidSLList测试
	SinglyLinkedList* list = InitializeSLList();
	for (size_t i = 0; i < 11; ++i)
		InsertSLList(list, i, i);
	ForeachSLList(list, print);
	puts("");
	printf("%lld", *MidSLList(list));
	puts("");
	//Joseph测试
	DLL_DataType arr[41];
	Joseph(41,arr);
	for (size_t i = 0; i < 41; ++i)
		printf("%lld ", arr[i]);
	puts("");
	//concatenateCLList测试
	CircularLinkedList* list1 = InitializeCLList();
	for (size_t i = 0; i < 10; ++i)
		InsertCLList(list1, i, i + 1);
	CircularLinkedList* list2 = InitializeCLList();
	for (size_t i = 0; i < 10; ++i)
		InsertCLList(list2, i, i + 11);
	ConcatenateCLList(list1, list2);
	puts("");
	ForeachCLList(list1, print);
	//测试is_Circualar
	//待写......
}

void SStackTest(){
	SequenceStack* stack = InitializeSStack(3);
	for (size_t i = 0; i < 10; ++i)
		PushSStack(stack, i);
	printf("%lld", SizeSStack(stack));
	puts("");
	for (size_t i = 0; i < 10; ++i)
		printf("%lld ",PopSStack(stack));
	FreeSStack(stack);
	puts("");
}

void LStackTest(){
	LinkedStack* stack = InitializeLStack(3);
	for (size_t i = 0; i < 10; ++i)
		PushLStack(stack, i);
	printf("%lld", SizeLStack(stack));
	puts("");
	for (size_t i = 0; i < 10; ++i)
		printf("%lld ",PopLStack(stack));
	FreeLStack(stack);
	puts("");
}
