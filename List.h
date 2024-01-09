#pragma once
template<typename T>
class List
{public:
	int sizeArr;
	virtual void push_back(const T&) {

	}
	virtual void insert(){}
	virtual void erase(const int&){}
	int size() { return sizeArr; }
};
