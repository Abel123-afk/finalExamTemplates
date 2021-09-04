#pragma once
#include<iostream>
using namespace std;
template<class T>
class CVector {
    int n;
    T* arr;
public:
    CVector() {
        n = 0;
        arr = new T[n];
    }
    ~CVector() {}
    void insert(T nuevo, int pos)
    {
        T* aux = new T[n + 1];
        for (int i = 0; i < n; i++)
        {
            if (i < pos)
                aux[i] = arr[i];
            else
                aux[i + 1] = arr[i];
        }
        delete arr[];
        arr = aux;
        aux = nullptr;
        delete aux;
        n++;
    }
    void erase(int pos)
    {
        T* aux = new T[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            if (i < pos)
                aux[i] = arr[i];
            else
                aux[i] = arr[i+1];
        }
        delete []arr;
        arr = aux;
        aux = nullptr;
        delete aux;
        n--;
    }
    void pop_back()
    {
        T* aux = new T[n - 1];
        for (int i = 0; i < n - 1; i++)
            aux[i] = arr[i];
        delete[]arr;
        arr = aux;
        aux = nullptr;
        delete aux;
        n--;
    }
    T at(int pos) {
        return arr[pos];
    }
    int size() {
        return n;
    }
    void push_back(T nuevo)
    {
        T* aux = new T[n + 1];
        for (int i = 0; i < n; i++)
            aux[i] = arr[i];
        aux[n] = nuevo;
        delete[]arr;
        arr = aux;
        aux = nullptr;
        delete aux;
        n++;
    }
};