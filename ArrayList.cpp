#include "ArrayList.h"
//#include "Line.h"
//#include "Explosion.h"
template<typename T>
ArrayList<T>::ArrayList() {
	container = new T * [1];
			sizeArr = 0;
		capacity = 1;

}




template<typename T>
void ArrayList<T>::push_back(const T& value) {
	if (capacity == sizeArr) {
		recreate();
	}	
	container[sizeArr]=value;
	sizeArr++;
};

template<typename T>
ArrayList<T>::ArrayList(const int& n) {
	if (n != 0) {
		container = new T * [n * 2];
		sizeArr = 0;
		capacity = n * 2;
	}
}

template<typename T>
void ArrayList<T>::insert(const int& pos, const T& value) {
	if (pos >= 0 && pos <= capacity) {
		if (capacity == sizeArr) {
			recreate();
		}

		T* temp = new T * [capacity	];

		for(int i = 0;i<=pos;i++){
			if (i == pos) {
				temp[i] = value;
			}
			else {
				temp[i] = container[i];
			}
		}
		
		for (int i = pos; i < sizeArr; i++)
		{
			temp[i+1] = container[i];
		}
		container = temp;
		delete temp;
		sizeArr++;
	}
	else {
		throw "Вылетел за края";
	}
}

template<typename T>
ArrayListIt<T> ArrayList<T>::begin()
{
	ArrayListIt<T> it(container);
	return it;
}

template<typename T>
ArrayListIt<T> ArrayList<T>::end() {
	ArrayListIt<T> it(container + sizeArr);
	return it;
}

template<typename T>
void ArrayList<T>::erase(const int& pos) {
	if (pos >= 0 && pos <= sizeArr) {
		T* temp = new T * [capacity];

		for (int i = 0; i < pos; i++) {
			if (i != pos) {
				temp[i] = container[i];
			}

		}
		for (int i = pos; i < sizeArr - 1; i++)
		{
			temp[i] = container[i + 1];
		}

		sizeArr--;

		container = temp;
		delete temp;
	}
	else {
		throw "Вылетел за края!";
	}
}

//template<typename T>
//ArrayListIt<T> ArrayList<T>::erase(const ArrayListIt<T>& it) {
//	int pos = it.ukaz - container;
//	if (pos >= 0 && pos <= sizeArr) {
//		T* temp = new T * [capacity];
//
//		for (int i = 0; i < pos; i++) {
//			if (i != pos) {
//				temp[i] = container[i];
//			}
//
//		}
//		for (int i = pos; i < sizeArr - 1; i++)
//		{
//			temp[i] = container[i + 1];
//		}
//
//		sizeArr--;
//
//		container = temp;
//		delete temp;
//		return ArrayListIt(container + (pos - 1));
//	}
//	else {
//		throw "Вылетел за края!";
//	}
//}

template<typename T>
void ArrayList<T>::recreate() {
	T* temp = new T * [capacity * 2];
	for (int i = 0; i < capacity; i++) {
		temp[i] = container[i];
	}
	delete container;
	capacity *= 2;
	container = temp;
}

template<typename T>
bool ArrayList<T>::empty() {
	return sizeArr == 0;
}

