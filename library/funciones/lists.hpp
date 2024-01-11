#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T info;
   Node<T>* sig;
};

int cmpInt(int a, int b)
{
   return a-b;
}

template <typename T>
void show(Node<T>*& p)
{
   Node<T>* aux = p;
   while( aux!=NULL )
   {
      cout<<aux->info<<"";
      aux = aux->sig;
   }
}

template <typename T>
Node<T>* add(Node<T>*& p, T e)
{
   Node<T>* nuevoNodo = new Node<T>;
   nuevoNodo->info = e;
   nuevoNodo->sig = NULL;

   if( p!=NULL )
   {
      Node<T>* aux = p;
      while( aux->sig!=NULL )
      {
         aux = aux->sig;
      }
      aux->sig = nuevoNodo;
   }
   else
   {
      p = nuevoNodo;
   }

   return nuevoNodo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p, T e)
{
   Node<T>* nuevoNodo = new Node<T>;
   nuevoNodo->info = e;
   nuevoNodo->sig = p; 
   p = nuevoNodo; 
   return nuevoNodo;
}

template <typename T, typename K>
T remove(Node<T>*& p, K k, int cmpTK(T, K))
{
   Node<T>* aux = p;
   Node<T>* prev = NULL;
   while( aux!=NULL )
   {
      if( cmpTK(aux->info,k)==0 )
      {
         if( prev==NULL ) // If it is the first node
         {
            p = aux->sig;
         }
         else
         {
            prev->sig = aux->sig;
         }
         T t = aux->info;
         delete aux;
         return t;
      }
      prev = aux;
      aux = aux->sig;
   }
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   Node<T>* aux = p;
   p = aux->sig;
   T t = aux->info;
   delete aux;
   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p, K k, int cmpTK(T, K))
{
   Node<T>* aux = p;
   while( aux!=NULL )
   {
      if( cmpTK(aux->info,k)==0 )
      {
         return aux;
      }
      aux = aux->sig;
   }
   return NULL; // If the element is not found, returns NULL
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T e, int cmpTT(T, T))
{
   Node<T>* nuevoNodo = new Node<T>;
   nuevoNodo->info = e;
   nuevoNodo->sig = NULL;

   if( p==NULL||cmpTT(p->info,e)>0 )
   {
      // Insert to top of list
      nuevoNodo->sig = p;
      p = nuevoNodo;
   }
   else
   {
      // Insert in the middle or at the end of the list
      Node<T>* aux = p;
      while( aux->sig!=NULL&&cmpTT(aux->sig->info,e)<0 )
      {
         aux = aux->sig;
      }
      nuevoNodo->sig = aux->sig;
      aux->sig = nuevoNodo;
   }

   return nuevoNodo;
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p, T e, bool& enc, int cmpTT(T, T))
{
   Node<T>* encontrado = find(p,e,cmpTT);
   if( encontrado!=NULL )
   {
      enc = true;
      return encontrado;
   }
   else
   {
      enc = false;
      return orderedInsert(p,e,cmpTT);
   }
}

template <typename T>
void sort(Node<T>*& p, int (*cmpTT)(T, T))
{
   if( p==NULL||p->sig==NULL )
   {
      return;
   }

   Node<T>* end = NULL;
   bool swapped;

   do
   {
      swapped = false;
      Node<T>* aux = p;

      while( aux->sig!=end )
      {
         if( cmpTT(aux->info,aux->sig->info)>0 )
         {
            T temp = aux->info;
            aux->info = aux->sig->info;
            aux->sig->info = temp;
            swapped = true;
         }
         aux = aux->sig;
      }
      end = aux;
   }
   while( swapped );
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   if( p==NULL||p->sig==NULL )
   {
      return true;
   }
   return false;
}

template <typename T>
void free(Node<T>*& p)
{
   while( p!=NULL )
   {
      Node<T>* aux = p->sig;
      delete p;
      p = aux;
   }
}

template <typename T>
Node<T>* push(Node<T>*& p, T e)
{

   return addFirst(p,e);
}

template <typename T> T pop(Node<T>*& p)
{
   return removeFirst(p);
}

template <typename T>
Node<T>* enqueue(Node<T>*& p, Node<T>*& q, T e)
{
   return add(q,e);
}

template <typename T>
Node<T>* enqueue(Node<T>*& q, T e) //sobrecarga
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   if( q!=NULL )
   {
      nuevo->sig = q->sig;
      q->sig = nuevo;
   }
   else
   {
      nuevo->sig = nuevo;
   }
   q = nuevo;
   return nuevo;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t;
   return removeFirst(p);
}

template <typename T>
T dequeue(Node<T>*& q)
{
   if (q == NULL) // If the queue is empty, we cannot unqueue anything
   {
      std::cout << "The queue is empty, it cannot be dequeued." << std::endl;
      return T(); // Returns a default value of T
   }

   Node<T>* temp = q->sig; // Node to dequeue (first node in queue)
   T t = temp->info; // Value to return

   if (q->sig == q) // If there is only one node in the queue
   {
      q = NULL; // Queue becomes NULL after dequeuing last node
   }
   else
   {
      q->sig = temp->sig; // The next node from the last node (q) becomes the first node in the queue
   }

   delete temp; // Delete the dequeued node
   return t; // Returns the dequeued value
}

#endif
