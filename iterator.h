#pragma once
template<typename T>
class ArrayListIt
{
public:
	T* ukaz;

public:
	ArrayListIt(T* first);

	bool operator<(const ArrayListIt<T>& it);
	bool operator>(const ArrayListIt<T>& it);
	T operator*();
	ArrayListIt operator++();
	ArrayListIt operator++(int);
};

