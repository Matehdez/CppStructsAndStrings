#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template <typename K, typename V>
struct Map
{
   Array<K> ke; //keys
   Array<V> va; //values
   int num;
   int cap;
};

template <typename K, typename V>
Map<K, V> map()
{
   Map<K, V> m;
   m.ke = array<K>();
   m.va = array<V>();
   m.num = 0;
   m.cap = 0;

   return m;
}

// Devuelve un puntero al valor asociado con la clave en el mapa.
template <typename K, typename V>
V* mapGet(Map<K, V> m, K k)
{
   V* dir = NULL;
   for( int i = 0; i<arraySize<K>(m.ke); i++ )
   {
      if( k==m.ke.arr[i] )
      {
         dir = &(m.va.arr[i]);
      }
   }

   return dir;
}

// Inserta un par clave-valor en el mapa. Si la clave ya existe en el mapa, actualiza su valor.
template <typename K, typename V>
V* mapPut(Map<K, V>& m, K k, V v)
{
   V* dir = NULL;
   bool keyFound = false;

   // Si el mapa no está vacío
   if( m.ke.len!=0 )
   {
      // Buscar la clave en el mapa
      for( int i = 0; i<arraySize<K>(m.ke); i++ )
      {
         // Si la clave se encuentra en el mapa
         if( k==m.ke.arr[i] )
         {
            // Actualizar el valor asociado a la clave
            arraySet<V>(m.va,i,v);
            dir = &(m.va.arr[i]);
            keyFound = true;
            break;
         }
      }
   }

   // Si la clave no se encuentra en el mapa
   if( !keyFound )
   {
      // Añadir la nueva clave y valor al mapa
      int add = arrayAdd<K>(m.ke,k);
      arrayAdd<V>(m.va,v);
      dir = &(m.va.arr[add]);
   }

   return dir;
}

// Comprueba si una clave está presente en el mapa.
template <typename K, typename V>
bool mapContains(Map<K, V> m, K k)
{
   for( int i = 0; i<arraySize<K>(m.ke); i++ )
   {
      if( k==m.ke.arr[i] )
      {
         return true;
      }
   }
   return false;
}

// Elimina una clave y su valor asociado del mapa.
template <typename K, typename V>
V mapRemove(Map<K, V>& m, K k)
{
   V v;
   bool found = false;
   for( int i = 0; i<arraySize<K>(m.ke); i++ )
   {
      if( k==m.ke.arr[i] )
      {
         v = arrayRemove(m.va,i);
         arrayRemove(m.ke,i);
         found = true;
         break;
      }
   }

   if( !found )
   {
      throw std::invalid_argument("Key not found in map");
   }

   return v;
}

// Elimina todas las claves y valores del mapa.
template <typename K, typename V>
void mapRemoveAll(Map<K, V>& m)
{
   arrayRemoveAll<K>(m.ke);
   arrayRemoveAll<V>(m.va);
}

// Devuelve el número de elementos en el mapa.
template <typename K, typename V>
int mapSize(Map<K, V> m)
{
   return arraySize<V>(m.va);
}

// Comprueba si hay más elementos en el mapa para iterar.
template <typename K, typename V>
bool mapHasNext(Map<K, V> m)
{
   return m.num<arraySize(m.va);
}

// Devuelve la siguiente clave en la iteración del mapa.
template <typename K, typename V>
K mapNextKey(Map<K, V>& m)
{
   if (m.ke.curr >= arraySize<K>(m.ke)) {
       throw std::out_of_range("No more keys in map");
   }
   K* k;
   k = arrayGet<K>(m.ke, m.ke.curr++);
   return *k;
}

// Devuelve el siguiente valor en la iteración del mapa.
template <typename K, typename V>
V* mapNextValue(Map<K, V>& m)
{
   if( !mapHasNext<K, V>(m) )
   {
      return nullptr;
   }
   V* dir = arrayGet<V>(m.va,m.va.curr++);
   return dir;
}

// Reinicia la iteración del mapa al principio.
template <typename K, typename V>
void mapReset(Map<K, V>& m)
{
   m.num = 0;
}



// Ordena los elementos del mapa por sus claves utilizando una función de comparación proporcionada.
template <typename K, typename V>
void mapSortByKeys(Map<K, V>& m, int cmpKK(K, K))
{
   Array<K> kAux = array<K>();
   Array<V> vAux = array<V>();
   while( arraySize<K>(m.ke)>0 )
   {
      K* tMin = arrayGet<K>(m.ke,0);
      int pMin = 0;
      for( int i = 1; i<arraySize<K>(m.ke); i++ )
      {
         K* t1 = arrayGet<K>(m.ke,i);
         int cmp = cmpKK(*t1,*tMin);
         if( cmp<0 )
         {
            tMin = t1;
            pMin = i;
         }
      }
      K removedKey = arrayRemove<K>(m.ke,pMin);
      V removedValue = arrayRemove<V>(m.va,pMin);
      arrayAdd<K>(kAux,removedKey);
      arrayAdd<V>(vAux,removedValue);
   }
   m.ke = kAux;
   m.va = vAux;
}

// Ordena los elementos del mapa por sus valores utilizando una función de comparación proporcionada.
template <typename K, typename V>
void mapSortByValues(Map<K, V>& m, int cmpVV(V, V))
{
   Array<K> vAux = array<V>();
   Array<V> kAux = array<K>();
   while( arraySize<V>(m.va)>0 )
   {
      V* tMin = arrayGet<V>(m.va,0);
      int pMin = 0;
      for( int i = 1; i<arraySize<V>(m.va); i++ )
      {
         K* t1 = arrayGet<V>(m.va,i);
         int cmp = cmpVV(*t1,*tMin);
         if( cmp<0 )
         {
            tMin = t1;
            pMin = i;
         }
      }
      V removedValue = arrayRemove<V>(m.va,pMin);
      K removedKey = arrayRemove<K>(m.ke,pMin);
      arrayAdd<V>(vAux,removedValue);
      arrayAdd<K>(kAux,removedKey);
   }
   m.va = vAux;
   m.ke = kAux;
}

// Si la clave no está en el mapa, inserta el par clave-valor y devuelve un puntero al valor. Si la clave ya está en el mapa, devuelve un puntero al valor existente.
template <typename K, typename V>
V* mapDiscover(Map<K, V>& m, K k, V v)
{
   V* dir;
   if( !mapContains<K, V>(m,k) )
   {
      dir = mapPut(m,k,v);
   }
   else
   {
      dir = mapGet<K, V>(m,k);
   }
   return dir;
}

#endif
