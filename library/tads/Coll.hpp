#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

// TAD Coll is a primitive version of what arrays do. Is more like to practice and get used to it ;)

template <typename T>
struct Coll
{
   //tokenized string
   string s;
   char sep;
   int curr;
};

template <typename T>
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.s = "";
   c.sep = sep;
   c.curr = 0;
   return c;
}

template <typename T>
Coll<T> coll()
{
   Coll<T> c;
   c.s = "";
   c.sep = '|';
   return c;
}

template <typename T>
int collSize(Coll<T> c)
{
   int nToken = tokenCount(c.s,c.sep);
   return nToken;
}

template <typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s = "";
   c.curr = 0;
}

template <typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   c.s = removeTokenAt(c.s,c.sep,p);
}

template <typename T>
int collAdd(Coll<T>& c, T t, string tToString(T))
{
   addToken(c.s,c.sep,tToString(t));
   int p = tokenCount(c.s,c.sep)-1;
   return p;
   //ECLIPSE DE MIERDA
}

template <typename T>
void collSetAt(Coll<T>& c, T t, int p, string tToString(T))
{
   setTokenAt(c.s,c.sep,tToString(t),p);
}

template <typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string))
{
   T t;
   t = tFromString(getTokenAt(c.s,c.sep,p));
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string))
{
   string s = stringToString(k);
   string token;
   int posicion = 0;
   for( int i = 0; i<tokenCount(c.s,c.sep), i++; )
   {

      token = getTokenAt(c.s,c.sep,i);
      if( cmpString(token,k)==0 )
      {
         //t=i;
         posicion = i;
         i = tokenCount(c.s,c.sep);
      }
   }
   T t = tFromString(token);
   int a = cmpTK(t,k);
   if( a==0 )
   {
      return posicion;
   }
   else
   {
      return -1;
   }

}

template <typename T>
void collSort(Coll<T>& c, int cmpTT(T, T), T tFromString(string), string tToString(T))
{
   Coll<T> cAux = coll<T>();

   while( collSize(c)>0 )
   {
      T tMin = collGetAt<T>(c,0,tFromString);
      int pMin = 0;
      for( int i = 1; i<collSize<T>(c); i++ )
      {
         T t1 = collGetAt<T>(c,i,tFromString);
         int cmp = cmpTT(t1,tMin);
         tMin = cmp<=0?t1:tMin;
         pMin = cmp<=0?i:pMin;
      }
      collRemoveAt<T>(c,pMin);

      collAdd<T>(cAux,tMin,tToString);
   }
   c = cAux;
}

template <typename T>
bool collHasNext(Coll<T> c)
{
   return c.curr<collSize(c);
}

template <typename T>
T collNext(Coll<T>& c, T tFromString(string))
{
   return collGetAt<T>(c,c.curr++,tFromString);
}

template <typename T>
T collNext(Coll<T>& c, bool& endOfColl, T tFromString(string))
{
   endOfColl = !collHasNext<T>(c);
}

template <typename T>
void collReset(Coll<T>& c)
{
   c.curr = 0;
}

#endif
