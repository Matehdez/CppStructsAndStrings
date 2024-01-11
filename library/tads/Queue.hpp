#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Queue
{
   T info;
   Queue* sig;
   int len;
   int curr;
};

template <typename T>
Queue<T> queue()
{
   Queue<T>* q = new Queue<T>;
   q->info = T(); // Valor por defecto de T
   q->sig = NULL;
   q->len = 0;
   q->curr = 0;
   return q;
}

// Función para agregar un elemento a la cola
template <typename T>
T* queueEnqueue(Queue<T>& q, T e)
{
   q->len++;
   return enqueue(q,e);
}

// Función para eliminar un elemento de la cola
template <typename T>
T queueDequeue(Queue<T>& q)
{
   T t;
   q->len--;
   return dequeue(q);
}

// Función para verificar si la cola está vacía
template <typename T>
bool queueIsEmpty(Queue<T> q)
{
   return isEmpty(q);
}

// Función para obtener el tamaño de la cola
template <typename T>
int queueSize(Queue<T> q)
{
   int i = 0;
   Queue<T>* aux = q;
   while( aux!=NULL )
   {
      i++;
      aux = aux->sig;
   }
   return i;
}

#endif
