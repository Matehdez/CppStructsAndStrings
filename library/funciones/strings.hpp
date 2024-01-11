#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i = 0;
   while( s[i]!='\0' )
   {
      i++;
   }
   return i;
}

int charCount(string s, char c)
{
   int i = 0;
   int cc = 0;
   while( s[i]!='\0' )
   {
      if( s[i]==c )
      {
         cc = cc+1;
      }
      i = i+1;
   }
   return cc;
}

string substring(string s, int d, int h)
{
   string substring = "";

   while( d<h )
   {
      substring = substring+s[d];
      d++;

   }
   return substring;
}

string substring(string s, int d) // ok
{
   string substring = "";
   while( s[d]!='\0' )
   {
      substring = substring+s[d];
      d++;
   }
   return substring;
}

int indexOf(string s, char c) // ok
{
   int i = 0;
   int pos = -1;
   bool find = false;
   while( (s[i]!='\0')&&find==false )
   {
      if( s[i]==c )
      {
         pos = i;
         find = true;
      }
      i++;
   }
   return pos;
}

int indexOf(string s, char c, int offSet) // ok
{
   int pos = -1;
   bool find = false;
   while( (s[offSet]!='\0')&&find==false )
   {
      if( s[offSet]==c )
      {
         pos = offSet;
         find = true;
      }
      offSet++;
   }
   return pos;
}

int indexOf(string s, string toSearch) // ok
{
   int i = length(toSearch);
   int c = 0;
   int t = 0;
   int cont = 0;
   int pos = -1;
   bool find = false;
   while( (s[c]!='\0')&&find==false )
   {
      if( s[c]==toSearch[t] )
      {
         find = true;
         int cc = c;
         int tt = t;
         pos = c;
         while( (s[cc]==toSearch[tt])&&i>cont&&find==true )
         {
            if( s[cc]==toSearch[tt] )
            {
               cc++;
               tt++;
               cont++;
            }
            else
            {
               find = false;
            }
         }
      }
      c++;
   }
   return pos;
}

int indexOf(string s, string toSearch, int offset) // ok
{
   int i = length(toSearch);
   int c = offset;
   int t = 0;
   int cont = 0;
   int pos = -1;
   bool find = false;
   while( (s[c]!='\0')&&find==false )
   {
      if( s[c]==toSearch[t] )
      {
         find = true;
         int cc = c;
         int tt = t;
         pos = c;
         while( (s[cc]==toSearch[tt])&&i>cont&&find==true )
         {
            if( s[cc]==toSearch[tt] )
            {
               cc++;
               tt++;
               cont++;
            }
            else
            {
               find = false;
            }
         }
      }
      c++;
   }
   return pos;
}

int lastIndexOf(string s, char c)
{
   int i = 0;
   int pos = -1;
   while( s[i]!='\0' )
   {
      if( s[i]==c )
      {
         pos = i;
      }
      i++;
   }
   return pos;
}

int indexOfN(string s, char c, int n)
{
   int i = 0;
   int cont = 0;
   int pos = -1;
   while( (s[i]!='\0')&&(cont<n) )
   {
      if( s[i]==c )
      {
         pos = i;
         cont++;
      }
      i++;
   }
   if( n>cont )
   {
      pos = length(s);
   }
   return pos;
}

int charToInt(char c)
{
   string s = "0123456789";
   string a = "abcdefghijklmnopqrstuvwxyz";
   string a1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int i = 0;
   bool find = false;
   while( (s[i]!='\0')&&(find==false) )
   {
      if( s[i]==c )
      {
         find = true;
         i--;
      }
      i++;
   }
   if( find==false )
   {
      i = 0;
   }
   while( (a[i]!='\0')&&(find==false) )
   {
      if( (a[i]==c)||(a1[i]==c) )
      {
         find = true;
         i = i+9;
      }
      i++;
   }
   return i;
}
char intToChar(int i)
{
   char x;
   string s = "0123456789";
   string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   if( i<10 )
   {
      x = s[i];
   }
   if( i>=10 )
   {
      i = i-10;
      x = a[i];
   }
   return x;
}

int getDigit(int n, int i)
{
   string s = to_string(n);
   int dist = length(s)-1;
   string a = "";
   a = a+s[(dist-i)];
   int x = stoi(a);
   return x;
}

int digitCount(int n)
{
   string s = to_string(n);
   int dist = length(s);
   return dist;
}
string intToString(int i)
{
   string s = to_string(i);
   return s;
}

int stringToInt(string s, int b) // ok
{
   int num = 0;
   if( b==2 )
   {
      double dist = length(s)-1,i = 0;
      while( s[i]!='\0' )
      {
         if( s[i]=='1' )
         {
            num = num+pow(2,dist);
         }
         dist--;
         i++;
      }
   }
   if( b==16 )
   {
      string n = "0123456789";
      double dist = length(s)-1;
      int i = 0;
      while( s[i]!='\0' )
      {
         if( s[i]=='A' )
         {
            num = num+(10*pow(16,dist));
         }
         if( s[i]=='B' )
         {
            num = num+(11*pow(16,dist));
         }
         if( s[i]=='C' )
         {
            num = num+(12*pow(16,dist));
         }
         if( s[i]=='D' )
         {
            num = num+(13*pow(16,dist));
         }
         if( s[i]=='E' )
         {
            num = num+(14*pow(16,dist));
         }
         if( s[i]=='F' )
         {
            num = num+(15*pow(16,dist));
         }
         if( s[i]!='A'&&s[i]!='B'&&s[i]!='C'&&s[i]!='D'&&s[i]!='E'&&s[i]!='F' )
         {
            int x = 0;
            while( s[i]!=n[x] )
            {
               x++;
            }
            num = num+(x*pow(16,dist));
         }
         i++;
         dist--;
      }
   }
   if( b==8 )
   {
      string n = "01234567";
      double dist = length(s)-1;
      int i = 0;
      while( s[i]!='\0' )
      {
         int x = 0;
         while( s[i]!=n[x] )
         {
            x++;
         }
         num = num+(x*pow(8,dist));
         i++;
         dist--;
      }
   }
   if( b==10 )
   {
      num = stoi(s);
   }
   return num;
}

int stringToInt(string s) // ok
{
   int n;
   n = stoi(s);
   return n;
}

string charToString(char c)
{
   string s = "";
   s = s+c;
   return s;
}

char stringToChar(string s)
{
   char x = s[0];
   return x;
}

string stringToString(string s)
{
   string x = s;
   return x;
}

string doubleToString(double d)
{
   return to_string(d);
}

double stringToDouble(string s)
{
   return stod(s);
}

bool isEmpty(string s)
{
   return (s[0]=='\0');
}

bool startsWith(string s, string x)
{
   bool ret = true;
   int dist = length(x),i = 0;
   while( i!=dist&&ret )
   {
      if( s[i]!=x[i] )
      {
         ret = false;
      }
      i++;
   }
   return ret;
}

bool endsWith(string s, string x)
{
   bool b;
   int i = length(s)-1;
   int j = length(x)-1;

   while( s[i]==x[j]&&j>0 )
   {
      if( s[i]!=x[j] )
      {

         b = false;
      }
      else
      {
         b = true;
      }
      i--;
      j--;

   }
   if( s[i]!=x[j] )
   {
      b = false;
   }

   return b;
}

bool contains(string s, char c)
{
   bool ret = false;
   int i = 0;
   while( s[i]!='\0'&&!ret )
   {
      if( s[i]==c )
      {
         ret = true;
      }
      i++;
   }
   return ret;
}

string replace(string s, char oldChar, char newChar)
{
   int i = 0;
   while( s[i]!='\0' )
   {
      if( oldChar==s[i] )
      {
         s[i] = newChar;
      }
      i++;
   }
   return s;
}

string insertAt(string s, int pos, char c)
{
   string x = "",y = "";
   int i = pos,cont = 0;
   while( s[pos]!='\0' )
   {
      x = x+s[pos];
      pos++;
   }
   while( cont<i )
   {
      y = y+s[cont];
      cont++;
   }
   y = y+c;
   s = y+x;
   return s;
}

string removeAt(string s, int pos)
{
   string x = "",y = "";
   int i = pos,cont = 0;
   while( s[pos+1]!='\0' )
   {
      x = x+s[pos+1];
      pos++;
   }
   while( cont<i )
   {
      y = y+s[cont];
      cont++;
   }
   s = y+x;
   return s;
}

string ltrim(string s)
{
   string x = "";
   int i = 0;
   while( s[i]==' ' )
   {
      i++;
   }
   while( s[i]!='\0' )
   {
      x = x+s[i];
      i++;
   }
   return x;
}

string rtrim(string s)
{
   string x = "";
   int i = length(s)-1,pos = 0;
   while( s[i]==' ' )
   {
      i--;
   }
   i++;
   while( pos<i )
   {
      x = x+s[pos];
      pos++;
   }
   return x;
}

string trim(string s)
{
   string x = ltrim(s);
   x = rtrim(x);
   return x;
}

string replicate(char c, int n)
{
   int i = 0;
   string x = "";
   while( i<n )
   {
      x = x+c;
      i++;
   }
   return x;
}

string spaces(int n)
{
   int i = 0;
   string x = "";
   while( i<n )
   {
      x = x+' ';
      i++;
   }
   return x;
}
string lpad(string s, int n, char c)
{
   int dist = length(s);
   string j;
   if( dist==n )
   {
      j = s;
   }
   else
   {
      int cadena = n-dist;
      string x = replicate(c,cadena);
      j = x+s;
   }
   return j;
}

string rpad(string s, int n, char c)
{
   int dist = length(s);
   string j;
   if( dist==n )
   {
      j = s;
   }
   else
   {
      int cadena = n-dist;
      string x = replicate(c,cadena);
      j = s+x;
   }
   return j;
}

string cpad(string s, int n, char c)
{
   int dist = length(s);
   string j;
   string k;
   if( dist==n )
   {
      j = s;
   }
   else
   {
   }
   int cadena = n-dist;
   string x = replicate(c,cadena/2);
   j = s+x;
   string h = replicate(c,cadena/2);
   k = h+j;
   return k;
}

bool isDigit(char c)
{
   string x = charToString(c);
   bool a = contains(x,'0');
   bool b = contains(x,'1');
   bool e = contains(x,'2');
   bool d = contains(x,'3');
   bool f = contains(x,'4');
   bool g = contains(x,'5');
   bool h = contains(x,'6');
   bool i = contains(x,'7');
   bool j = contains(x,'8');
   bool k = contains(x,'9');
   bool l;
   if( a or true or b==true or d==true or e==true or f==true or g==true or h==true or i==true or j==true or k==true )
   {
      l = true;
   }
   return l;
}

bool isLetter(char c)
{
   string s = "0123456789";
   int i = 0;
   bool ret = true;
   while( s[i]!='\0'&&ret )
   {
      if( s[i]==c )
      {
         ret = false;
      }
      i++;
   }
   return ret;
}

bool isUpperCase(char c)
{
   string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   bool x = contains(mayusculas,c);
   return x;
}

bool isLowerCase(char c)
{
   string minusculas = "qwertyuiopasdfghjklzxcvbnm";
   bool x = contains(minusculas,c);
   return x;
}

char toUpperCase(char c)
{
   string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   string minusculas = "abcdefghijklmnopqrstuvwxyz";
   char caracter = c;
   int i = 0;
   if( contains(minusculas,caracter) )
   {
      while( c!=minusculas[i] )
      {
         i++;
      }
      caracter = mayusculas[i];
   }
   else
   {
   }
   return caracter;
}

char toLowerCase(char c)
{
   string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   string minusculas = "abcdefghijklmnopqrstuvwxyz";
   char caracter = c;
   int i = 0;
   if( contains(mayusculas,caracter) )
   {
      while( c!=mayusculas[i] )
      {
         i++;
      }
      caracter = minusculas[i];
   }
   else
   {
   }
   return caracter;
}

string toUpperCase(string s)
{
   string x = "";
   int i = 0;
   while( s[i]!='\0' )
   {
      char f = s[i];
      x = x+toUpperCase(f);
      i++;
   }
   return x;
}

string toLowerCase(string s)
{
   string x = "";
   int i = 0;
   while( s[i]!='\0' )
   {
      char f = s[i];
      x = x+toLowerCase(f);
      i++;
   }
   return x;
}

int cmpString(string a, string b)
{
   int i = 0,num = 0;
   bool find = false;
   a = toLowerCase(a), b = toLowerCase(b);
   string x = "abcdefghijklmnopqrstuvwxyz";
   while( a[i]!='\0'&&!find )
   {
      int cont1 = 0,cont2 = 0;
      while( a[i]!=x[cont1] )
      {
         cont1++;
      }
      while( b[i]!=x[cont2] )
      {
         cont2++;
      }
      if( cont1<cont2 )
      {
         num = -1;
         find = true;
      }
      else
      {
         if( cont2<cont1 )
         {
            num = 1;
            find = true;
         }
      }
      i++;
   }
   return num;
}

int cmpDouble(double a, double b)
{
   int variable;
   if (a>b){
      variable=1;
   }
   else {
      if (a==b){
         variable=0;
      }
      else{ variable= -1;}
   }
   return variable;
}

#endif
