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
SS_DataType PopSStack(SequenceStack* stack);
bool FreeSStack(SequenceStack* stack);
inline size_t SizeSStack(const SequenceStack* stack) {
	return stack->_top - stack->_base;
}
#endif