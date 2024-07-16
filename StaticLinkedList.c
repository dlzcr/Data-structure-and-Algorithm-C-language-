#include "StaticLinkedList.h"
#include<malloc.h>
#include <stdint.h>

StaticLinkedList* InitializeSLinkList(size_t capacity){
    StaticLinkedList* newList = (StaticLinkedList*)malloc(sizeof(StaticLinkedList));
    if (!newList)
        return NULL;
    newList->_arr = (SNode*)malloc(sizeof(SNode) * (newList->_capacity = capacity));
    if (!newList->_arr)
        return NULL;
    for (size_t i = 0; i < newList->_capacity - 1; ++i)
        newList->_arr[i]._next = i + 1;
    newList->_arr[capacity - 1]._next = 0;
    newList->_size = 0;
}

size_t Malloc_SLL(StaticLinkedList* list) {
    size_t i = list->_arr[0]._next;
    if (i)
        list->_arr[0]._next = list->_arr[i]._next;
    return i;
}

bool InsertSLinkList(StaticLinkedList* list, size_t pos, SLL_DataType value){
    if (!list || pos > list->_size)
        return false;
    size_t newNode = Malloc_SLL(list);
    if (!newNode)
        return false;
    size_t prevIndex = list->_capacity - 1;
    for (size_t i = 0; i < pos; ++i)
        prevIndex = list->_arr[prevIndex]._next;
    list->_arr[newNode]._next = list->_arr[prevIndex]._next;
    list->_arr[prevIndex]._next = newNode;
    list->_arr[newNode]._data = value;
    ++list->_size;
}

SLL_DataType* AtSLinkList(const StaticLinkedList* list, size_t pos){
    if (!list || pos >= list->_size)
        return NULL;
    size_t index = list->_arr[list->_capacity - 1]._next;
    for (size_t i = 0; i < pos; ++i)
        index = list->_arr[index]._next;
    return &list->_arr[index]._data;
}

void Free_SLL(StaticLinkedList* list, size_t pos) {
    if (!list || pos >= list->_size)
        return;
    list->_arr[pos]._next = list->_arr[0]._next;
    list->_arr[0]._next = pos;
}

bool EraseSLinkList(StaticLinkedList* list, size_t pos) {
    if (!list || pos >= list->_size)
        return false;
    size_t prevIndex = list->_capacity - 1;
    for (size_t i = 0; i < pos; ++i)
        prevIndex = list->_arr[prevIndex]._next;
    size_t to_delete = list->_arr[prevIndex]._next;
    list->_arr[prevIndex]._next = list->_arr[to_delete]._next;
    Free_SLL(list,to_delete);
    --list->_size;
}

bool ForeachSLinkList(const StaticLinkedList* list, void(*foreach)(SLL_DataType*)){
    if (!list || !foreach)
        return false;
    size_t index = list->_arr[list->_capacity - 1]._next;
    for (size_t i = 0; i < list->_size; ++i, index = list->_arr[index]._next)
        foreach(&list->_arr[index]._data);
    return true;
}

size_t FindSLinkList(const StaticLinkedList* list, SLL_DataType value, bool(*equal)(SLL_DataType, SLL_DataType)){
    if (!list || !equal)
        return SIZE_MAX;
    size_t index = list->_arr[list->_capacity - 1]._next;
    for (size_t i = 0; i < list->_size; ++i, index = list->_arr[index]._next)
        if (equal(list->_arr[index]._data, value))
            return i;
    return list->_size;
}

bool ClearSLinkList(StaticLinkedList* list){
    if (!list)
        return false;
    for (size_t i = 0; i < list->_capacity - 1; ++i)
        list->_arr[i]._next = i + 1;
    list->_arr[list->_capacity]._next = 0;
    list->_size = 0;
    return true;
}

bool FreeSLinkList(StaticLinkedList* list){
    if (!list)
        return false;
    free(list->_arr);
    free(list);
    return true;
}