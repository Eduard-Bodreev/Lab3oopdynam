#pragma once

#ifndef STATICARRAY_H
#define STATICARRAY_H

#include <stdexcept>

class StaticArray {
private:
    char *arr = new char[0];
	size_t arrSize = 0;
public:
	StaticArray();
	StaticArray(const StaticArray& other);
    StaticArray(StaticArray&& sa);
    StaticArray& operator =(StaticArray&& sa);
    
	~StaticArray();

	bool resize(size_t newSize);
	bool push_back(char c);
	bool set_value(size_t index, char c);

	size_t size() const;
	char get_value(size_t index) const;
	int find(char c) const;

	StaticArray& operator=(const StaticArray& other);
	char& operator[](size_t ind);
    
    
};

//#include "StaticArray.cpp"

#endif
