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
   nuevoNodo->sig = p; // le asigno la direccion hacia p
   p = nuevoNodo; // cambio p para que comience apuntando a nuevoNodo
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
         if( prev==NULL ) // Si es el primer nodo
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
   return NULL; // Si no se encuentra el elemento, devuelve NULL
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T e, int cmpTT(T, T))
{
   Node<T>* nuevoNodo = new Node<T>;
   nuevoNodo->info = e;
   nuevoNodo->sig = NULL;

   if( p==NULL||cmpTT(p->info,e)>0 )
   {
      // Insertar al principio de la lista
      nuevoNodo->sig = p;
      p = nuevoNodo;
   }
   else
   {
      // Insertar en medio o al final de la lista
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
   if (q == NULL) // Si la cola está vacía, no podemos desencolar nada
   {
      std::cout << "La cola está vacía, no se puede desencolar." << std::endl;
      return T(); // Devuelve un valor por defecto de T
   }

   Node<T>* temp = q->sig; // Nodo a desencolar (primer nodo en la cola)
   T t = temp->info; // Valor a devolver

   if (q->sig == q) // Si solo hay un nodo en la cola
   {
      q = NULL; // La cola se vuelve NULL después de desencolar el último nodo
   }
   else
   {
      q->sig = temp->sig; // El siguiente nodo del último nodo (q) se convierte en el primer nodo en la cola
   }

   delete temp; // Elimina el nodo desencolado
   return t; // Devuelve el valor desencolado
}

#endif
