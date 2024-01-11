#ifndef TARR_TAD
#define TARR_TAD

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template <typename T>
struct Array
{
   int len;
   int cap;
   int curr;
   T* arr;
};

template <typename T>
Array<T> array()
{
   Array<T> a;

   a.arr = new T[1];
   a.len = 0;
   a.cap = 1;
   a.curr = 0;
   return a;
}

// Add an element to the end of the array
template <typename T>
int arrayAdd(Array<T>& a, T t)
{
   a.len++;
   return add<T>(a.arr,a.len,t);
}

// Gets the element at position p
template <typename T>
T* arrayGet(Array<T> a, int p)
{
   T* d = &a.arr[p];

   return d;
}

// Sets the value of the element at position p
template <typename T>
void arraySet(Array<T>& a, int p, T t)
{
   remove<T>(a.arr,a.len,p);
   insert<T>(a.arr,a.len,t,p);

}

// Inserts an element at position p
template <typename T>
void arrayInsert(Array<T>& a, T t, int p)
{
   a.len++;
   insert<T>(a.arr,a.len,t,p);
}

// Returns the size of the array
template <typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

// Delete the element at position p
template <typename T>
T arrayRemove(Array<T>& a, int p)
{
   a.len--;
   return remove<T>(a.arr,a.len,p);
}

// Remove all elements from the array
template <typename T>
void arrayRemoveAll(Array<T>& a)
{
   a.len = 0;
}

// Search for an element in the array
template <typename T, typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T, K))
{
   return find<T>(a.arr,a.len,k,cmpTK);
}

// Insert an element into the array in an orderly manner
template <typename T>
int arrayOrderedInsert(Array<T>& a, T t, int cmpTT(T, T))
{
   a.len++;
   return orderedInsert<T>(a.arr,a.len,t,cmpTT);
}

// Sort the array
template <typename T>
void arraySort(Array<T>& a, int cmpTT(T, T))
{
   sort<T>(a.arr,a.len,cmpTT);
}

// Searches for an element in the array and if it is not found, adds it to the end
template <typename T>
T* arrayDiscover(Array<T>& a, T t, int (*cmpTT)(T, T)) {
    for (int i = 0; i < a.len; i++) {
        if (cmpTT(a.arr[i], t) == 0) {
            return &a.arr[i];
        }
    }
    // If the element is not found, it is added to the end of the array.
    a.len++;
    a.arr = (T*)realloc(a.arr, a.len * sizeof(T));
    a.arr[a.len - 1] = t;
    return &a.arr[a.len - 1];
}



#endif
