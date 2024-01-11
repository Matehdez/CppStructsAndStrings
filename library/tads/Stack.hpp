#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Stack
{
   T info;
   Stack* sig;
   int len;
   int curr;
};

template <typename T>
Stack<T> stack()
{
   Stack<T> st = new Stack<T>;
   st->info = T(); // Valor por defecto de T
   st->sig = NULL;
   st->len = 0;
   st->curr = 0;
   return st;
}

// Funci�n para agregar un elemento a la pila
template <typename T>
T* stackPush(Stack<T>& st, T e)
{
   st->len++;
   return addFirst(st,e);
}

// Funci�n para eliminar un elemento de la pila
template <typename T>
T stackPop(Stack<T>& st)
{
   T t;
   st->len--;
   return removeFirst(st);
}

// Funci�n para verificar si la pila est� vac�a
template <typename T>
bool stackIsEmpty(Stack<T> st)
{
   return isEmpty(st);
}

// Funci�n para obtener el tama�o de la pila
template <typename T>
int stackSize(Stack<T> st)
{
   int i = 0;
   Stack<T>* aux = st;
   while( aux!=NULL )
   {
      i++;
      aux = aux->sig;
   }
   return i;
}

#endif
