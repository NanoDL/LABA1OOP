#include "iterator.h"

template<typename T> 
bool ArrayListIt<T>::operator<(const ArrayListIt<T>& it) {
	return ukaz < it.ukaz;
}

template<typename T>
T ArrayListIt<T>::operator*() {
	return *ukaz;
}

template<typename T>
ArrayListIt<T> ArrayListIt<T>::operator++() {
	return ++ukaz;
}

template<typename T>
ArrayListIt<T> ArrayListIt<T>::operator++(int) {
	ArrayListIt<T> copy{*this};
	++(this->ukaz);
	return copy;
}