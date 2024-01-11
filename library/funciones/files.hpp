#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template <typename T> void write(FILE* f, T t)
{
   fseek(f,0,SEEK_CUR);
   fwrite(&t,sizeof(T),1,f); //I write 1 element of the size of sizeof(T)
}

template <typename T> T read(FILE* f)
{
   fseek(f,0,SEEK_CUR);
   T t;
   fread(&t,sizeof(T),1,f); //I write 1 element of the size of sizeof(T)
   return t;
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,n,SEEK_CUR);
}

template<typename T> int fileSize(FILE* f)
{
   long int originalPos = ftell(f); // Save the original position of the file pointer
   fseek(f, 0, SEEK_END); // Move the file pointer to the end
   long int size = ftell(f); // Gets the position of the file pointer, which is now the size of the file
   fseek(f, originalPos, SEEK_SET); // Restores the original position of the file pointer
   return size / sizeof(T); // Returns the number of type T records contained in the file
}

   template<typename T> int filePos(FILE* f)
   {
      long int pos = ftell(f); // Gets the current position of the file pointer
      return pos / sizeof(T); // Returns the registration number that is being noted
   }


#endif
