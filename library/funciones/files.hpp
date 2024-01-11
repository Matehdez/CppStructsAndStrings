#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template <typename T> void write(FILE* f, T t)
{
   fseek(f,0,SEEK_CUR);
   fwrite(&t,sizeof(T),1,f); //escribo 1 elemento del tamaño de sizeof(T)
}

template <typename T> T read(FILE* f)
{
   fseek(f,0,SEEK_CUR);
   T t;
   fread(&t,sizeof(T),1,f); //escribo 1 elemento del tamaño de sizeof(T)
   return t;
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,n,SEEK_CUR);
}

template<typename T> int fileSize(FILE* f)
{
   long int originalPos = ftell(f); // Guarda la posición original del puntero del archivo
   fseek(f, 0, SEEK_END); // Mueve el puntero del archivo al final
   long int size = ftell(f); // Obtiene la posición del puntero del archivo, que ahora es el tamaño del archivo
   fseek(f, originalPos, SEEK_SET); // Restaura la posición original del puntero del archivo
   return size / sizeof(T); // Retorna la cantidad de registros tipo T que contiene el archivo
}

   template<typename T> int filePos(FILE* f)
   {
      long int pos = ftell(f); // Obtiene la posición actual del puntero del archivo
      return pos / sizeof(T); // Retorna el número de registro que está siendo apuntado
   }


#endif
