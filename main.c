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

//˳������
void SqListTest() {
	//��ʼ��
	SequenceList* list = InitializeSqList(3);
	//����0��9
	for(size_t i = 0;i < 10;++i)
		InsertSqList(list, i, i);
	//��8��λ�ò���999
	InsertSqList(list,8,999);
	//��ӡ����Ԫ��
	for (size_t i = 0; i < SizeSqList(list); ++i)
		printf("%lld ", *AtSqList(list, i));
	puts("");
	//ɾ����3��λ�ÿ�ʼ��5��Ԫ��
	for (size_t i = 0; i < 5; ++i)
		EraseSqList(list, 3);
	//������ӡԪ��
	ForeachSqList(list, print);
	puts("");
	//����ֵΪ999Ԫ��
	printf("%lld", FindSqList(list, 999, equal));
	puts("");
	//�Ƿ�λ�ò���
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
	//���Ԫ��
	ClearSqList(list);
	ForeachSqList(list, print);
	puts("");
	//�ͷ��ڴ�
	FreeSqList(list);
}

void LinkListTest() {
	//��ʼ��
	LinkedList* list = InitializeLinkList();
	//����0��9
	for (size_t i = 0; i < 10; ++i)
		InsertLinkList(list, i, i);
	//��8��λ�ò���999
	InsertLinkList(list, 8, 999);
	//��ӡ����Ԫ��
	for (size_t i = 0; i < SizeLinkList(list); ++i)
		printf("%lld ", *AtLinkList(list, i));
	puts("");
	//ɾ����3��λ�ÿ�ʼ��5��Ԫ��
	for (size_t i = 0; i < 5; ++i)
		EraseLinkList(list, 3);
	//������ӡԪ��
	ForeachLinkList(list, print);
	puts("");
	//����ֵΪ999Ԫ��
	printf("%lld", FindLinkList(list, 999, equal));
	puts("");
	//�Ƿ�λ�ò���
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
	//���Ԫ��
	ClearLinkList(list);
	ForeachLinkList(list, print);
	puts("");
	//�ͷ��ڴ�
	FreeLinkList(list);
}

void StaticLinkedListTest() {
	//��ʼ��
	StaticLinkedList* list = InitializeSLinkList(30);
	//����0��9
	for (size_t i = 0; i < 10; ++i)
		InsertSLinkList(list, i, i);
	//��8��λ�ò���999
	InsertSLinkList(list, 8, 999);
	//��ӡ����Ԫ��
	for (size_t i = 0; i < SizeSLinkList(list); ++i)
		printf("%lld ", *AtSLinkList(list, i));
	puts("");
	//ɾ����3��λ�ÿ�ʼ��5��Ԫ��
	for (size_t i = 0; i < 5; ++i)
		EraseSLinkList(list, 3);
	//������ӡԪ��
	ForeachSLinkList(list, print);
	puts("");
	//����ֵΪ999Ԫ��
	printf("%lld", FindSLinkList(list, 999, equal));
	puts("");
	//�Ƿ�λ�ò���
	printf("%d\n", InsertSLinkList(list, SizeSLinkList(list) + 1, 999));
	printf("%d\n", InsertSLinkList(list, -1, 999));
	printf("%d\n", EraseSLinkList(list, SizeSLinkList(list)));
	printf("%d\n", EraseSLinkList(list, -1));
	printf("%lld\n", FindSLinkList(list, 7, equal));
	printf("%p\n", AtSLinkList(list, SizeSLinkList(list)));
	printf("%p\n", AtSLinkList(list, -1));
	printf("%d\n", InsertSLinkList(NULL, 0, 0));
	printf("%d\n", EraseSLinkList(NULL, 0));
	printf("%lld\n", FindSLinkList(NULL, 0, NULL));
	printf("%p\n", AtSLinkList(NULL, 0));
	ForeachSLinkList(list, print);
	puts("");
	//���Ԫ��
	ClearSLinkList(list);
	ForeachSLinkList(list, print);
	puts("");
	//�ͷ��ڴ�
	FreeSLinkList(list);
}

int main(void) {
	SqListTest();
	StaticLinkedListTest();
	return 0;
}