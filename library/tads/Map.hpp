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

//Returns a pointer to the value associated with the key in the map.
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

// Inserts a key-value pair into the map. If the key already exists in the map, it updates its value.
template <typename K, typename V>
V* mapPut(Map<K, V>& m, K k, V v)
{
   V* dir = NULL;
   bool keyFound = false;

   // If the map is not empty
   if( m.ke.len!=0 )
   {
      // Find the key on the map
      for( int i = 0; i<arraySize<K>(m.ke); i++ )
      {
         // If the key is found on the map
         if( k==m.ke.arr[i] )
         {
            // Update the value associated with the key
            arraySet<V>(m.va,i,v);
            dir = &(m.va.arr[i]);
            keyFound = true;
            break;
         }
      }
   }

   // If the key is not found on the map
   if( !keyFound )
   {
      // Add the new key and value to the map
      int add = arrayAdd<K>(m.ke,k);
      arrayAdd<V>(m.va,v);
      dir = &(m.va.arr[add]);
   }

   return dir;
}

// Checks if a key is present on the map.
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

// Removes a key and its associated value from the map.
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

// Removes all keys and values ​​from the map.
template <typename K, typename V>
void mapRemoveAll(Map<K, V>& m)
{
   arrayRemoveAll<K>(m.ke);
   arrayRemoveAll<V>(m.va);
}

// Returns the number of elements in the map.
template <typename K, typename V>
int mapSize(Map<K, V> m)
{
   return arraySize<V>(m.va);
}

// Checks if there are more elements in the map to iterate.
template <typename K, typename V>
bool mapHasNext(Map<K, V> m)
{
   return m.num<arraySize(m.va);
}

// Returns the next key in the map iteration.
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

// Returns the next value in the map iteration.
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

// Restart the map iteration at the beginning.
template <typename K, typename V>
void mapReset(Map<K, V>& m)
{
   m.num = 0;
}



// Sorts map elements by their keys using a provided compare function.
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

// Sorts map elements by their values ​​using a provided comparison function.
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

// If the key is not in the map, inserts the key-value pair and returns a pointer to the value. If the key is already in the map, it returns a pointer to the existing value.
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
