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

   //new arr= direcci�n otorgada por la UC
   a.arr = new T[1];
   a.len = 0;
   a.cap = 1;
   a.curr = 0;
   return a;
}

// Agrega un elemento al final del array
template <typename T>
int arrayAdd(Array<T>& a, T t)
{
   a.len++;
   return add<T>(a.arr,a.len,t);
}

// Obtiene el elemento en la posici�n p
template <typename T>
T* arrayGet(Array<T> a, int p)
{
   T* d = &a.arr[p];

   return d;
}

// Establece el valor del elemento en la posici�n p
template <typename T>
void arraySet(Array<T>& a, int p, T t)
{
   remove<T>(a.arr,a.len,p);
   insert<T>(a.arr,a.len,t,p);

}

// Inserta un elemento en la posici�n p
template <typename T>
void arrayInsert(Array<T>& a, T t, int p)
{
   a.len++;
   insert<T>(a.arr,a.len,t,p);
}

// Devuelve el tama�o del array
template <typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

// Elimina el elemento en la posici�n p
template <typename T>
T arrayRemove(Array<T>& a, int p)
{
   a.len--;
   return remove<T>(a.arr,a.len,p);
}

// Elimina todos los elementos del array
template <typename T>
void arrayRemoveAll(Array<T>& a)
{
   a.len = 0;
}

// Busca un elemento en el array
template <typename T, typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T, K))
{
   return find<T>(a.arr,a.len,k,cmpTK);
}

// Inserta un elemento en el array de forma ordenada
template <typename T>
int arrayOrderedInsert(Array<T>& a, T t, int cmpTT(T, T))
{
   a.len++;
   return orderedInsert<T>(a.arr,a.len,t,cmpTT);
}

// Ordena el array
template <typename T>
void arraySort(Array<T>& a, int cmpTT(T, T))
{
   sort<T>(a.arr,a.len,cmpTT);
}

// Busca un elemento en el array y si no lo encuentra lo agrega al final
template <typename T>
T* arrayDiscover(Array<T>& a, T t, int (*cmpTT)(T, T)) {
    for (int i = 0; i < a.len; i++) {
        if (cmpTT(a.arr[i], t) == 0) {
            return &a.arr[i];
        }
    }
    // Si no se encuentra el elemento, se agrega al final del array.
    a.len++;
    a.arr = (T*)realloc(a.arr, a.len * sizeof(T));
    a.arr[a.len - 1] = t;
    return &a.arr[a.len - 1];
}



#endif
