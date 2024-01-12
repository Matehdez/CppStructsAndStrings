#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Stack
{
   Node<T> *p; // primer Nodo
   int pos;    // posicion actual
   int length;
};

template <typename T>
Stack<T> stack()
{
   Stack<T> st;
   st.p = NULL;
   st.pos = 0;
   st.length = 0;
   return st;
}
/*push Retorna: Node<T>* – Dirección del nodo que contiene al elemento que se agregó.
 */
/*Retorna: T* – Dirección de memoria del elemento que se apiló.
 */
template <typename T>
Node<T> *stackPush(Stack<T> &st, T e)
{
   st.length++;
   return push<T>(st.p, e);
}

template <typename T>
T stackPop(Stack<T> &st)
{
   T t = pop<T>(st.p);
   st.length--;
   return t;
}

template <typename T>
bool stackIsEmpty(Stack<T> st)
{
   return st.p == NULL;
}

template <typename T>
int stackSize(Stack<T> st)
{
   return st.length;
}

#endif
