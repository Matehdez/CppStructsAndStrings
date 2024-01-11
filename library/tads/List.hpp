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

// Crea una nueva lista
template <typename T>
List<T>* list()
{
   List<T>* lst = new List<T>;
   lst->info = T(); // Valor por defecto de T
   lst->sig = NULL;
   lst->len = 0;
   lst->curr = 0;

   return lst;
}

// Agrega un elemento al final de la lista
template <typename T>
T* listAdd(List<T>& lst, T e)
{
   lst->len++;
   return add<T>(lst,e);
}

// Agrega un elemento al inicio de la lista
template <typename T>
T* listAddFirst(List<T>& lst, T e)
{
   lst->len++;
   return addFirst<T>(lst,e);
}

// Elimina un elemento de la lista basado en una clave
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

// Elimina el primer elemento de la lista
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

// Busca un elemento en la lista basado en una clave
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

// Verifica si la lista est� vac�a
template <typename T>
bool listIsEmpty(List<T> lst)
{
   return isEmpty<T>(lst);
}

// Devuelve el tama�o de la lista
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

// Libera la memoria ocupada por la lista
template <typename T>
void listFree(List<T>& lst)
{
   lst->len = 0;
   free<T>(lst);
}

//descubre e inserta si no est�
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
   // Si no se encuentra el elemento, se agrega al final del array.
   lst->len++;
   return listAdd(lst,t);
}

// Inserta un elemento en la lista de forma ordenada
template <typename T>
T* listOrderedInsert(List<T>& lst, T t, int cmpTT(T, T))
{
   lst->len++;
   return orderedInsert<T>(lst,t,cmpTT);
}


// Ordena la lista
template <typename T>
void listSort(List<T>& lst, int cmpTT(T, T))
{
   sort<T>(lst,cmpTT);
}

// Reinicia la posici�n actual de la lista al inicio
template <typename T>
void listReset(List<T>& lst)
{
   lst.curr = 0;
}

// Verifica si hay un siguiente elemento en la lista
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

// Avanza a la siguiente posici�n en la lista y devuelve el elemento en esa posici�n
template <typename T>
T* listNext(List<T>& lst)
{
   lst = lst.sig;
   return lst;
}

// Avanza a la siguiente posici�n en la lista y devuelve el elemento en esa posici�n. Tambi�n establece una bandera si se ha llegado al final de la lista.
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