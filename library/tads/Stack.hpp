#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
   Node<T>* p;
   int cant;
};

template<typename T>
Stack<T> stack()
{
   Stack<T> st;
   st.p = NULL;
   st.cant = 0;
   return st;
}

// Pushes an element to the Stack
template<typename T>
T* stackPush(Stack<T>& st,T e)
{
   Node<T>* aux = push<T>(st.p,e);
   st.cant++;
   return &(aux->info);
}

// Pops an element from the Stack
template<typename T>
T stackPop(Stack<T>& st)
{
   T t = pop<T>(st.p);
   st.cant--;
   return t;
}

// Checks if the Stack is empty
template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return isEmpty<T>(st.p);
}

// Returns the size of the Stack
template<typename T>
int stackSize(Stack<T> st)
{
   return st.cant;
}

// Displays all elements in the Stack
template <typename T>
void stackDisplay(Queue<T> st)
{
   display(st.p);
}

#endif
