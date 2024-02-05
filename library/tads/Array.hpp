#ifndef TARR_TAD
#define TARR_TAD

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array
{
   T* arr;
   int len;
   int cap;
};

template<typename T>
Array<T> array()
{
   Array<T> a;
   T* p = new T[20];
   a.arr = p;
   a.len=0;
   a.cap=20;
   return a;
}

//Redimentions array in order to manipulate it dynamically
template<typename T>
void arrayRedimention(Array<T>& a)
{
   T* nuevoArr = new T[a.cap+1];
   for(int i=0;i<a.len;i++)
   {
      nuevoArr[i]=a.arr[i];
   }
   delete a.arr;
   a.arr = nuevoArr;
   a.cap++;   
}

// Adds an element to the array, expanding its capacity if necessary
template<typename T>
int arrayAdd(Array<T>& a,T t)
{
   if(a.len==a.cap)
   {
      arrayRedimention<T>(a);
   }
   add<T>(a.arr,a.len,t);
   return a.len-1;
}

// Returns a pointer to the element at the specified position in the array
template<typename T>
T* arrayGet(Array<T> a,int p)
{
   return &a.arr[p];
}

// Sets the value of the element at the specified position in the array
template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   T* e = arrayGet<T>(a,p);
   *e = t;
}

// Inserts an element at the specified position in the array, expanding its capacity if necessary
template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   if(a.len==a.cap)
   {
      arrayRedimention<T>(a);
   }
   insert<T>(a.arr,a.len,t,p);
}

// Returns the size of the array
template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

// Removes and returns the element at the specified position in the array
template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   T t = remove<T>(a.arr,a.len,p);
   return t;
}

// Removes all elements from the array
template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   a.len=0;
}

// Finds and returns the position of the first element that matches the specified key
template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   return find<T,K>(a.arr,a.len,k,cmpTK);
}

// Inserts an element in the array in a sorted order, expanding its capacity if necessary
template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   if(a.len==a.cap)
   {
      arrayRedimention<T>(a);
   }
   return orderedInsert<T>(a.arr,a.len,t,cmpTT);
}

// Returns a pointer to the element if it exists, otherwise adds the element to the array and returns a pointer to it
template<typename T>
T* arrayDiscover(Array<T>& a,T t,int cmpTT(T,T))
{
   int pos = arrayFind<T,T>(a,t,cmpTT);
   if(pos<0)
   {
      pos = arrayAdd<T>(a,t);
   }
   return arrayGet<T>(a,pos);
}

// Sorts the array in place according to the specified comparison function
template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort<T>(a.arr,a.len,cmpTT);
}

// Displays all elements in the array
template <typename T>
void arrayDisplay(Array<T> arr)
{
    T* x = NULL;

    for(int i = 0; i<arraySize<T>(arr);i++)
    {
        x = arrayGet<T>(arr,i);
        cout << *x << endl;
    }
}

#endif
