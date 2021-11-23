#ifndef SET_CPP
#define SET_CPP

#include "Set.h"

Set::Set(size_t power) {
	for (size_t i = 0; i < power; i++)
		arr.push_back(' ' + (char)i);
}

Set::Set(std::string str) {
	int n = str.size();
	for (int i = 0; i < n; i++)
		arr.push_back(str[i]);
}

Set::Set(const Set &other) {
	arr = other.arr;
}

Set::~Set() {}

bool Set::insert(char c) {
	if (arr.find(c) == -1) {
		return arr.push_back(c);
	}
	return false;
}

Set Set::Union(const Set& other) const {
	Set result(0);
	for (size_t i = 0; i < power(); i++) {
		result.insert(arr.get_value(i));
	}
	for (size_t i = 0; i < other.power(); i++) {
		result.insert(other.arr.get_value(i));
	}
	return result;
}

Set Set::interection(const Set& other) const {
	Set result(0);
	for (size_t i = 0; i < other.power(); i++) {
		char other_val = other.arr.get_value(i);
		if (arr.find(other_val) != -1)
			result.insert(other_val);
	}
	return result;
}

Set Set::exception(const Set& other) const {
	Set result(0);
	for (size_t i = 0; i < power(); i++) {
		char val = arr.get_value(i);
		if (other.arr.find(val) == -1)
			result.insert(val);
	}

	for (size_t i = 0; i < other.power(); i++) {
		char other_val = other.arr.get_value(i);
		if (arr.find(other_val) == -1)
			result.insert(other_val);
	}
	return result;
}

bool Set::is_exists(char c) const {
	return arr.find(c) != -1;
}

size_t Set::power() const {
	return arr.size();
}

void Set::print() const {
	std::cout << "Set is '";
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr.get_value(i);
	std::cout << "'" << std::endl;
}

char Set::get_value(size_t ind) const {
	return arr.get_value(ind);
}


Set& Set::operator=(const Set& other) {
	if (this == &other)
		return *this;

	arr = other.arr;
	
	return *this;
}


Set operator+(const Set& left, const Set& right) {
	return left.Union(right);
}

Set operator-(const Set& left, const Set& right) {
	return left.exception(right);
    
}

std::ostream& operator <<(std::ostream& s, const StaticArray& arr)
{
    s << "Set is '";
    for (size_t i = 0; i < arr.size(); i++)
        s << arr.get_value(i);
    s << "'" << std::endl;
    return s;
}


#endif
