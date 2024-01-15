#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Stack
{
   Node<T>* sta;
   int len;
};

template <typename T>
Stack<T> stack()
{
   Stack<T> st;
   st.sta = NULL;
   st.len = 0;
   return st;
}

// Adds an element
template <typename T>
T* stackPush(Stack<T>& st, T e)
{
   st.len++;
   return &push(st.sta,e)->info;
}

// Deletes an element
template <typename T>
T stackPop(Stack<T>& st)
{
   st.len--;
   return removeFirst(st.sta);
}

// Checks if the List is empty
template <typename T>
bool stackIsEmpty(Stack<T> st)
{
   return isEmpty(st.sta);
}

// Obtains List´s size
template <typename T>
int stackSize(Stack<T> st)
{
   int i = 0;
   Stack<T>* aux = st.sta;
   while( aux!=NULL )
   {
      i++;
      aux = aux->sig;
   }
   return st.len = i;
}

#endif
