#ifndef STATICARRAY_CPP
#define STATICARRAY_CPP

#include "StaticArray.h"

StaticArray::StaticArray() {}

StaticArray::StaticArray(const StaticArray &sa) {
    arrSize = sa.arrSize;
    arr = new char[sa.arrSize];
    for (int i = 0; i < sa.arrSize; i++)
        this->arr[i] = sa.arr[i];
}

StaticArray::~StaticArray() {
    delete[] arr;
}

StaticArray::StaticArray(StaticArray&& sa) :arrSize(sa.arrSize), arr(sa.arr) // move constructor
{
    sa.arrSize = 0;
    sa.arr = nullptr;
}

StaticArray& StaticArray::operator =(StaticArray&& sa) // move operator =
{
    if (this != &sa) {
        size_t tmp = arrSize;
        arrSize = sa.arrSize;
        sa.arrSize= tmp;
        char* ptr = arr;
        arr = sa.arr;
        sa.arr = ptr;
    }
    return *this;
}



bool StaticArray::resize(size_t newSize) {
    char *new_arr = new char[newSize];
    wmemcpy(new_arr, arr, arrSize * sizeof(char));
    arrSize = newSize;
    delete[] arr;
    arr = new_arr;
    return true;
}

bool StaticArray::push_back(char c) {
	if (resize(this->size() + 1) == false)
		return false;
	set_value(size() - 1, c);
	return true;
}

bool StaticArray::set_value(size_t ind, char c) {
    if (ind < arrSize) {
		arr[ind] = c;
		return true;
	}
    return false;
}

size_t StaticArray::size() const {
	return arrSize;
}

char StaticArray::get_value(size_t ind) const {
    if (ind < arrSize)
        return arr[ind];
    return '\0';
}

int StaticArray::find(char c) const {
	for (size_t i = 0; i < size(); i++) {
		if (arr[i] == c)
			return i;
	}
	return -1;
}

StaticArray& StaticArray::operator=(const StaticArray& other) {
	if (this == &other)
		return *this;

	if (size() != other.size()) {         // resource in *this cannot be reused
		resize(0);
		for (size_t i = 0; i < other.size(); i++)
			push_back(other.get_value(i));
    }
	return *this;
}

char& StaticArray::operator[](size_t ind) {
	return arr[ind];
}

#endif
