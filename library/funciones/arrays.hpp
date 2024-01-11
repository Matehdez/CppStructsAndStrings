#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

// Resize the array
template <typename T>
void redimention ( T*& a, int len, int newCap ){
T* newArr = new int [newCap]; 
for ( int i = 0; i<len; i++){
newArr[i] = a[i];
}
delete[] a; 
a= newArr;
}

template <typename T>
int add(T arr[], int& len, T e)
{
   redimention(arr, len, len++);
   arr[len] = e;
   len++;
   return len-1;;
}

template <typename T>
void insert(T arr[], int& len, T e, int p)
{
   redimention(arr, len, len++);
   for( int i = len; i>p; i-- )
   {
      arr[i] = arr[i-1];
   }
   arr[p] = e;
   len++;
}

template <typename T>
T remove(T arr[], int& len, int p)
{
   // p = posicion
   T ret = arr[p];
   for( int i = p+1; i<len; i++ )
   {
      arr[i-1] = arr[i];
   }
   len--;
   return ret;
}

template <typename T, typename K>
int find(T arr[], int len, K k, int cmpTK(T, K))
{
   for( int i = 0; i<len; i++ )
   {
      if( cmpTK(arr[i],k)==0 )
      {
         return i;
      }
   }
   return -1;
}

template <typename T>
int orderedInsert(T arr[], int& len, T e, int cmpTT(T, T))
{
   int pos=0;


   while (cmpTT(e,arr[pos])>0 && pos<len){
      pos++;
      }
   insert <T>(arr, len, e, pos);
   return pos;
   }


template <typename T>
void sort(T arr[], int len, int cmpTT(T, T))
{
   for( int i = 0; i<len; i++ )
   {
      for( int h = i+1; h<len; h++ )
      {
         if( cmpTT(arr[i],arr[h])>0 )
         {
            T temp = arr[i];
            arr[i] = arr[h];
            arr[h] = temp;
         }

      }
   }
}





#endif

