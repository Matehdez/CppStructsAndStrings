#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct List
{
   T info;
   List* sig;
   int len;
   int curr;
};

// Create a new list
template <typename T>
List<T>* list()
{
   List<T>* lst = new List<T>;
   lst->info = T(); 
   lst->sig = NULL;
   lst->len = 0;
   lst->curr = 0;

   return lst;
}

// Add an element to the end of the list
template <typename T>
T* listAdd(List<T>& lst, T e)
{
   lst->len++;
   return add<T>(lst,e);
}

// Add an item to the top of the list
template <typename T>
T* listAddFirst(List<T>& lst, T e)
{
   lst->len++;
   return addFirst<T>(lst,e);
}

// Remove an item from the list based on a key
template <typename T, typename K>
T listRemove(List<T>& lst, K k, int cmpTK(T, K))
{
   T t;
   {
      if( lst==NULL )
      {
         std::cout<<"List is empty and cannot be deleted"<<std::endl;
         return T(); // Devuelve un valor por defecto de T
      }
      else
      {
         lst->len--;
         return remove<T>(lst,k,cmpTK);
      }
   }
}

// Delete the first item in the list
template <typename T>
T listRemoveFirst(List<T>& lst)
{
   T t;
   if( lst->sig==NULL )
   {
      std::cout<<"List is empty, first elemente cannot be deleted"<<std::endl;
      return T(); // Devuelve un valor por defecto de T
   }
   else
   {
      lst->len--;
      return removeFirst<T>(lst);
   }
}

// Search for an item in the list based on a key
template <typename T, typename K>
T* listFind(List<T> lst, K k, int cmpTK(T, K))
{
   if( lst==NULL )
   {
      std::cout<<"List is empty, cannot find any element"<<std::endl;
      return NULL;
   }
   else
   {
      return find<T>(lst,k,cmpTK);
   }
}

// Check if the list is empty
template <typename T>
bool listIsEmpty(List<T> lst)
{
   return isEmpty<T>(lst);
}

// Returns the size of the list
template <typename T>
int listSize(List<T>* lst)
{
   int i = 0;
   List<T>* aux = lst;
   while( aux!=NULL )
   {
      i++;
      aux = aux->sig;
   }

   return lst->len = i;
}

// Release the memory occupied by the list
template <typename T>
void listFree(List<T>& lst)
{
   lst->len = 0;
   free<T>(lst);
}

//discover and insert if not present
template <typename T>
T* listDiscover(List<T>& lst, T t, int cmpTT(T, T))
{
   List<T>* aux = lst;
   while( aux!=NULL )
   {
      if( cmpTT(aux->info,t)==0 )
      {
         return aux->info;
      }
      aux = lst->sig;
   }
   // If the element is not found, it is added to the end of the array.
   lst->len++;
   return listAdd(lst,t);
}

// Insert an element into the list in order
template <typename T>
T* listOrderedInsert(List<T>& lst, T t, int cmpTT(T, T))
{
   lst->len++;
   return orderedInsert<T>(lst,t,cmpTT);
}


// Sort the list
template <typename T>
void listSort(List<T>& lst, int cmpTT(T, T))
{
   sort<T>(lst,cmpTT);
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
   if( lst.sig==NULL )
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
   lst = lst.sig;
   return lst;
}

// Moves to the next position in the list and returns the element at that position. It also sets a flag if the end of the list has been reached.
template <typename T>
T* listNext(List<T>*& lst, bool& endOfList)
{
   if( lst->sig==NULL )
   {
      endOfList = true;
      return NULL;
   }
   else
   {
      endOfList = false;
      lst = lst->sig;
      return &(lst->info);
   }
}

#endif
