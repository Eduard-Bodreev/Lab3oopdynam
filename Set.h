#ifndef SET_H
#define SET_H
#pragma once

#include <string>
#include <iostream>

#include "StaticArray.h"

class Set {
private:
	StaticArray arr;
public:
	Set(size_t power=1);
	Set(std::string str);
	Set(const Set &other);
	~Set();

	bool insert(char c);

	Set Union(const Set& other) const;

	Set interection(const Set& other) const;

	Set exception(const Set& other) const;

	bool is_exists(char c) const;

	size_t power() const;
	void print() const;
	char get_value(size_t ind) const;

	Set& operator=(const Set& other);

	friend Set operator+(const Set& left, const Set& right); // UNION
	friend Set operator-(const Set& left, const Set& right);
    friend std::ostream& operator <<(std::ostream&, const StaticArray&);// EXCEPTION
};

//#include "Set.cpp"

#endif
