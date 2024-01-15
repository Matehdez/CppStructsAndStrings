#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct List
{
   Node<T>* nodo;
   int len;
   int curr;
};

// Create a new list
template <typename T>
List<T> list()
{
   List<T> lst;
   lst.nodo = NULL;
   lst.len = 0;
   lst.curr = 0;

   return lst;
}

template <typename T>
void listDisplay(List<T> lst)
{
   display(lst.nodo);
}

// Add an element to the end of the list
template <typename T>
T* listAdd(List<T>& lst, T e)
{
   lst.len++;
   return &add<T>(lst.nodo,e)->info; // returns the element contained in that node
}

// Add an item to the top of the list
template <typename T>
T* listAddFirst(List<T>& lst, T e)
{
   lst.len++;
   return &addFirst<T>(lst.nodo,e)->info;
}

// Remove an item from the list based on a key
template <typename T, typename K>
T listRemove(List<T>& lst, K k, int cmpTK(T, K))
{
   return remove<T>(lst.nodo,k,cmpTK);
}

// Delete the first item in the list
template <typename T>
T listRemoveFirst(List<T>& lst)
{
   return removeFirst<T>(lst.nodo);
}

// Search for an item in the list based on a key
template <typename T, typename K>
T* listFind(List<T> lst, K k, int cmpTK(T, K))
{
   return &find<T>(lst.nodo,k,cmpTK)->info;
}

// Check if the list is empty
template <typename T>
bool listIsEmpty(List<T> lst)
{
   return isEmpty<T>(lst.nodo);
}

// Returns the size of the list
template <typename T>
int listSize(List<T>* lst)
{
   int i = 0;
   List<T>* aux = lst.nodo;
   while( aux!=NULL )
   {
      i++;
      aux = aux->sig;
   }

   return lst.len = i;
}

// Release the memory occupied by the list
template <typename T>
void listFree(List<T>& lst)
{
   lst.len = 0;
   free<T>(lst.nodo);
}

//discover and insert if not present
template <typename T>
T* listDiscover(List<T>& lst, T t, int cmpTT(T, T))
{
   List<T>* aux = lst.nodo;
   while( aux!=NULL )
   {
      if( cmpTT(aux->info,t)==0 )
      {
         return aux->info;
      }
      aux = lst.nodo->sig;
   }
   // If the element is not found, it is added to the end of the array.
   lst.len++;
   return listAdd(lst.nodo,t);
}

// Insert an element into the list in order
template <typename T>
T* listOrderedInsert(List<T>& lst, T t, int cmpTT(T, T))
{
   lst.len++;
   return &orderedInsert<T>(lst.nodo,t,cmpTT)->info;
}

// Sort the list
template <typename T>
void listSort(List<T>& lst, int cmpTT(T, T))
{
   sort<T>(lst.nodo,cmpTT);
}

// Resets the current position of the list to the beginning
template <typename T>
void listReset(List<T>& lst)
{
   lst.curr = 0;
}

// Check if there is a next item in the list
template <typename T>
bool listHasNext(List<T> lst)
{
   bool next;
   if( lst.len==lst.curr )
   {
      return next = false;
   }
   else
   {
      return next = true;
   }
}

// Moves to the next position in the list and returns the element at that position
template <typename T>
T* listNext(List<T>& lst)
{
   Node<T>* aux = lst.nodo;
   for( int i = 0; i<lst.curr; i++ )
   {
      aux = aux->sig;
   }
   lst.curr++;
   return &aux->info;
}

// Moves to the next position in the list and returns the element at that position. It also sets a flag if the end of the list has been reached.
template <typename T>
T* listNext(List<T>& lst, bool& endOfList)
{
   T* t = listNext<T>(lst);
   endOfList=listHasNext<T>(lst);
   return t;
}

#endif
