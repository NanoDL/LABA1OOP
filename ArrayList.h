#pragma once
#include "List.h"
//#include "iterator.h"

template<typename T>
class ArrayList : public List<T>{
private:
    T* container;
    //int List<T>::sizeArr;
    int capacity;
    //friend class ArrayListIt<T>;
    void recreate() {
        T* temp = new T [capacity * 2];
        for (int i = 0; i < capacity; i++) {
            temp[i] = container[i];
        }
        delete container;
        capacity *= 2;
        container = temp;
    };
public:
    ArrayList() {
        container = new T [1];
        List<T>::sizeArr = 0;
        capacity = 1;
    };
    ArrayList(const int& n) {
        if (n != 0) {
            container = new T [n * 2];
            List<T>::sizeArr = 0;
            capacity = n * 2;
        }
    }
    void push_back(const T& value) override {
        if (capacity == List<T>::sizeArr) {
            recreate();
        }
        container[List<T>::sizeArr] = value;
        List<T>::sizeArr++;
    };
    
    void erase(const int& pos) override {
        if (pos >= 0 && pos < List<T>::sizeArr) {
            /*T* temp = new T [capacity];

            for (int i = 0; i < pos; i++) {
                if (i != pos) {
                    temp[i] = container[i];
                }

            }*/
            for (int i = pos; i < List<T>::sizeArr - 1; i++)
            {
                container[i] = container[i + 1];
            }
            container[List<T>::sizeArr - 1] = 0;
            List<T>::sizeArr--;

            //container = temp;
            //delete temp;
        }
        else {
            throw "Вылетел за края!";
        }
    };
    /*ArrayListIt<T> erase(const ArrayListIt<T>& it) {
        int pos = it.ukaz - container;
        if (pos >= 0 && pos <= List<T>::sizeArr) {
            T* temp = new T [capacity];

            for (int i = 0; i < pos; i++) {
                if (i != pos) {
                    temp[i] = container[i];
                }

            }
            for (int i = pos; i < List<T>::sizeArr - 1; i++)
            {
                temp[i] = container[i + 1];
            }

            List<T>::sizeArr--;

            container = temp;
            delete temp;
        }
        else {
            throw "Вылетел за края!";
        }
    };*/
    void insert(const int& pos, const T& value) {
        if (pos >= 0 && pos <= capacity) {
            if (capacity == List<T>::sizeArr) {
                recreate();
            }

            T* temp = new T [capacity];

            for (int i = 0; i <= pos; i++) {
                if (i == pos) {
                    temp[i] = value;
                }
                else {
                    temp[i] = container[i];
                }
            }

            for (int i = pos; i < List<T>::sizeArr; i++)
            {
                temp[i + 1] = container[i];
            }
            container = temp;
            delete temp;
            List<T>::sizeArr++;
        }
        else {
            throw "Вылетел за края";
        }
    };
    

    bool empty() {
        return List<T>::sizeArr == 0;
    };


    T& begin() {
        return *container;
    };
    T& end() {
        return container[List<T>::sizeArr];
    };

    T& operator[](const int& i) {
        return container[i];
    }



};


