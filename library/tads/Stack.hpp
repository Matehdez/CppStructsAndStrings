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
   st->info = T(); 
   st->sig = NULL;
   st->len = 0;
   st->curr = 0;
   return st;
}

// Function to add an element to the stack
template <typename T>
T* stackPush(Stack<T>& st, T e)
{
   st->len++;
   return addFirst(st,e);
}

// Function to remove an element from the stack
template <typename T>
T stackPop(Stack<T>& st)
{
   T t;
   st->len--;
   return removeFirst(st);
}

// Function to check if the stack is empty
template <typename T>
bool stackIsEmpty(Stack<T> st)
{
   return isEmpty(st);
}

// Function to get stack size
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
