#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Queue
{
   Node<T>* que;
   int len;
};

template <typename T>
Queue<T> queue()
{
   Queue<T> q;
   q.que = NULL;
   q.len = 0;
   return q;
}

// Adds an element
template <typename T>
T* queueEnqueue(Queue<T>& q, T e)
{
   q.len++;
   return &enqueue(q.que,e)->info;
}

 // Deletes an element
template <typename T>
T queueDequeue(Queue<T>& q)
{
   q.len--;
   return dequeue(q.que);
}

// Checks if the List is empty
template <typename T>
bool queueIsEmpty(Queue<T> q)
{
   return isEmpty(q.que);
}

// Gets List´s size
template <typename T>
int queueSize(Queue<T> q)
{
   int i = 0;
   Queue<T>* aux = q.que;
   while( aux!=NULL )
   {
      i++;
      aux = aux->sig;
   }
   return q.len = i;
}

#endif
