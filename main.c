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

//˳������
void SListTest();
//�������
void SLListTest();
//��̬�������
void SSLListTest();
//ѭ���������
void CLListTest();
//˫�������
void DLListTest();
//�㷨����
void algorithmTest();
//˳��ջ����
void SStackTest();
//��ʽջ����
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

//˳������
void SListTest() {
	//��ʼ��
	SequenceList* list = InitializeSList(3);
	//����0��9
	for (size_t i = 0; i < 10; ++i)
		InsertSList(list, i, i);
	//��8��λ�ò���999
	InsertSList(list, 8, 999);
	//��ӡ����Ԫ��
	for (size_t i = 0; i < SizeSList(list); ++i)
		printf("%lld ", *AtSList(list, i));
	puts("");
	//ɾ����3��λ�ÿ�ʼ��5��Ԫ��
	for (size_t i = 0; i < 5; ++i)
		EraseSList(list, 3);
	//������ӡԪ��
	ForeachSList(list, print);
	puts("");
	//����ֵΪ999Ԫ��
	printf("%lld", FindSList(list, 999, equal));
	puts("");
	//�Ƿ�λ�ò���
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
	//���Ԫ��
	ClearSList(list);
	ForeachSList(list, print);
	puts("");
	//�ͷ��ڴ�
	FreeSList(list);
}

//�������
void SLListTest() {
	//��ʼ��
	SinglyLinkedList* list = InitializeSLList();
	//����0��9
	for (size_t i = 0; i < 10; ++i)
		InsertSLList(list, i, i);
	//��8��λ�ò���999
	InsertSLList(list, 8, 999);
	//��ӡ����Ԫ��
	for (size_t i = 0; i < SizeSLList(list); ++i)
		printf("%lld ", *AtSLList(list, i));
	puts("");
	//ɾ����3��λ�ÿ�ʼ��5��Ԫ��
	for (size_t i = 0; i < 5; ++i)
		EraseSLList(list, 3);
	//������ӡԪ��
	ForeachSLList(list, print);
	puts("");
	//����ֵΪ999Ԫ��
	printf("%lld", FindSLList(list, 999, equal));
	puts("");
	//�Ƿ�λ�ò���
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
	//���Ԫ��
	ClearSLList(list);
	ForeachSLList(list, print);
	puts("");
	//�ͷ��ڴ�
	FreeSLList(list);
}

//��̬�������
void SSLListTest() {
	//��ʼ��
	StaticLinkedList* list = InitializeSSLList(30);
	//����0��9
	for (size_t i = 0; i < 10; ++i)
		InsertSSLList(list, i, i);
	//��8��λ�ò���999
	InsertSSLList(list, 8, 999);
	//��ӡ����Ԫ��
	for (size_t i = 0; i < SizeSSLList(list); ++i)
		printf("%lld ", *AtSSLList(list, i));
	puts("");
	//ɾ����3��λ�ÿ�ʼ��5��Ԫ��
	for (size_t i = 0; i < 5; ++i)
		EraseSSLList(list, 3);
	//������ӡԪ��
	ForeachSSLList(list, print);
	puts("");
	//����ֵΪ999Ԫ��
	printf("%lld", FindSSLList(list, 999, equal));
	puts("");
	//�Ƿ�λ�ò���
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
	//���Ԫ��
	ClearSSLList(list);
	ForeachSSLList(list, print);
	puts("");
	//�ͷ��ڴ�
	FreeSSLList(list);
}

void CLListTest()
{
	//��ʼ��
	CircularLinkedList* list = InitializeCLList();
	//����0��9
	for (size_t i = 0; i < 10; ++i)
		InsertCLList(list, i, i);
	//��8��λ�ò���999
	InsertCLList(list, 8, 999);
	//��ӡ����Ԫ��
	for (size_t i = 0; i < SizeCLList(list); ++i)
		printf("%lld ", *AtCLList(list, i));
	puts("");
	//ɾ����3��λ�ÿ�ʼ��5��Ԫ��
	for (size_t i = 0; i < 5; ++i)
		EraseCLList(list, 3);
	//������ӡԪ��
	ForeachCLList(list, print);
	puts("");
	//����ֵΪ999Ԫ��
	printf("%lld", FindCLList(list, 999, equal));
	puts("");
	//�Ƿ�λ�ò���
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
	//���Ԫ��
	ClearCLList(list);
	ForeachCLList(list, print);
	puts("");
	//�ͷ��ڴ�
	FreeCLList(list);
}

void DLListTest(){
	//��ʼ��
	CircularLinkedList* list = InitializeCLList();
	//����0��9
	for (size_t i = 0; i < 10; ++i)
		InsertCLList(list, i, i);
	//��8��λ�ò���999
	InsertCLList(list, 8, 999);
	//��ӡ����Ԫ��
	for (size_t i = 0; i < SizeCLList(list); ++i)
		printf("%lld ", *AtCLList(list, i));
	puts("");
	//ɾ����3��λ�ÿ�ʼ��5��Ԫ��
	for (size_t i = 0; i < 5; ++i)
		EraseCLList(list, 3);
	//������ӡԪ��
	ForeachCLList(list, print);
	puts("");
	//����ֵΪ999Ԫ��
	printf("%lld", FindCLList(list, 999, equal));
	puts("");
	//�Ƿ�λ�ò���
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
	//���Ԫ��
	ClearCLList(list);
	ForeachCLList(list, print);
	puts("");
	//�ͷ��ڴ�
	FreeCLList(list);
}

void algorithmTest() {
	//MidSLList����
	SinglyLinkedList* list = InitializeSLList();
	for (size_t i = 0; i < 11; ++i)
		InsertSLList(list, i, i);
	ForeachSLList(list, print);
	puts("");
	printf("%lld", *MidSLList(list));
	puts("");
	//Joseph����
	DLL_DataType arr[41];
	Joseph(41,arr);
	for (size_t i = 0; i < 41; ++i)
		printf("%lld ", arr[i]);
	puts("");
	//concatenateCLList����
	CircularLinkedList* list1 = InitializeCLList();
	for (size_t i = 0; i < 10; ++i)
		InsertCLList(list1, i, i + 1);
	CircularLinkedList* list2 = InitializeCLList();
	for (size_t i = 0; i < 10; ++i)
		InsertCLList(list2, i, i + 11);
	ConcatenateCLList(list1, list2);
	puts("");
	ForeachCLList(list1, print);
	//����is_Circualar
	//��д......
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
