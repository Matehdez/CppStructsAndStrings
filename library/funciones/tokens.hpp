#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s, char sep)
{
   int contador = 0;
   if( contains(s,sep) )
   {
      contador = contador+charCount(s,sep)+1;
   }
   else
   {
      if( isEmpty(s) )
      {
         contador = 0;
      }
      else
      {
         contador = contador+1;
      }
   }
   return contador;
}

void addToken(string& s, char sep, string t)
{
   if( !isEmpty(s) )
   {
      s = s+sep+t;
   }
   else
   {
      s = t;
   }
}

string getTokenAt(string s, char sep, int i)
{
   int contador = tokenCount(s,sep);
   char x = 'x';
   string referencia = replicate(x,contador);
   int pos = indexOf(referencia,x,i);
   int posEx = indexOf(referencia,x,i+1);
   string cadenaT;
   if( pos==0 )
   {
      int ocurrenciaSep = indexOfN(s,sep,pos+1);
      cadenaT = substring(s,0,ocurrenciaSep);
   }
   else
   {
      int ocurrenciaSep = indexOfN(s,sep,pos);
      int ocurrenciaEx = indexOfN(s,sep,posEx);
      if( ocurrenciaEx!=-1 )
      {
         cadenaT = substring(s,ocurrenciaSep,ocurrenciaEx);
      }
      else
      {
         cadenaT = substring(s,ocurrenciaSep);
      }
   }
   if( contains(cadenaT,sep) )
   {
      cadenaT = removeAt(cadenaT,0);
   }
   return cadenaT;
}

void removeTokenAt(string& s, char sep, int i)
{
   int t = 0;
   string cadenaT = "";
   int conT = tokenCount(s,sep);
   while( t<i )
   {
      cadenaT = cadenaT+getTokenAt(s,sep,t)+'|';
      t++;
   }
   t = i+1;
   while( t<conT )
   {
      cadenaT = cadenaT+getTokenAt(s,sep,t)+'|';
      t++;
   }
   int l = length(cadenaT);
   s = removeAt(cadenaT,l-1);
}

void setTokenAt(string& s, char sep, string t, int i)
{
   string cadenaT = "";
   int conT = tokenCount(s,sep);
   int th = 0;
   while( th<i )
   {
      cadenaT = cadenaT+getTokenAt(s,sep,th)+'|';
      th++;
   }
   int l = length(cadenaT);
   cadenaT = removeAt(cadenaT,l-1);
   addToken(cadenaT,sep,t);
   th = i+1;
   cadenaT = cadenaT+'|';
   while( th<conT )
   {
      cadenaT = cadenaT+getTokenAt(s,sep,th)+'|';
      th++;
   }
   l = length(cadenaT);
   s = removeAt(cadenaT,l-1);
}

int findToken(string s, char sep, string t)
{
   int posicionT = 0;
   int posicionBuscada;
   int contador = tokenCount(s,sep);
   char x = 'x';
   string referencia = replicate(x,contador);
   string cadenaT = "";
   while( posicionT<contador )
   {
      cadenaT = cadenaT+getTokenAt(s,sep,posicionT);
      if( !endsWith(cadenaT,t) )
      {
         posicionT++;
      }
      else
      {
         posicionBuscada = posicionT;
         posicionT++;
      }
   }
   return posicionBuscada;
}

#endif
