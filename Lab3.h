
#ifndef LAB3_H
#define LAB3_H
#pragma once

#include <iostream>
#include <algorithm>
#include <exception>
#include <limits>
#include <ios>

#include "Set.h"

namespace Input {
	template <typename T>
	T read();
	template <typename T>
	T getNumber(T min, T max);
	int getInt(int min = INT_MIN, int max = INT_MAX);
	int getPositiveInt(int max = INT_MAX);
	std::string getString();
	char getChar();
	int dialog(const char* msgs[], int n);
}

namespace Program {
	Set InputPowerSet();
	Set InputStringSet();
	Set CreateSet();
	void PrintSet(Set& set);
	void Union(Set& set);
	void Add(Set& set);
	void Intersection(Set& set);
	void Exception(Set& set);
	void IsExist(Set& set);
}

#include "Lab3.h"

#endif