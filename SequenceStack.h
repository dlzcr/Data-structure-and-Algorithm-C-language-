#pragma once

typedef long long int SS_DataType;

typedef struct {
	SS_DataType* _top;
	SS_DataType* _base;
	size_t _capacity;
}SequenceStack;

#ifdef bool
SequenceStack* InitializeSStack(size_t capacity);
bool PushSStack(SequenceStack* stack, SS_DataType value);
SS_DataType PopStack(SequenceStack* stack);
bool FreeSStack(SequenceStack* stack);
#endif