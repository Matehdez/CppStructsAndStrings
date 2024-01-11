#ifndef _TARRBITWRITER
#define _TARRBITWRITER

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../funciones/strings.hpp"
#include "../funciones/files.hpp"

using namespace std;

struct BitWriter
{
   string bString;
   FILE bFile;
};

// Crea e inicializa una variable tipo BitWriter.
BitWriter bitWriter(FILE* f)
{
   BitWriter bw;
   bw.bString = "";
   bw.bFile = f;
   return bw;
}

// Graba un bit en el archivo.
void bitWriterWrite(BitWriter &bw, int bit)
{
   bw.bString += intToChar(bit);
   if( length(bw.bString)==8 )
   {

      fwrite <string>(bw.bFile,stringToInt(bw.bString,2));
      bw.bString = "";
   }
}

// Graba en el archivo los unos y ceros que contiene bits.
void bitWriterWrite(BitWriter &bw, string sbit)
{
   bw.bString += sbit;
   while( length(bw.bString)>=8 )
   {
      string wString = substring(bw.bString,0,8);

      fwrite<string>(bw.bFile,stringToInt(wString,2));
      bw.bString = substring(bw.bString,8);
   }
}

//Indica que ya no se grabarán más bit. En caso de que la cantidad de bit
//que grabamos no sea múltiplo de 8, completa con ceros a la derecha y graba./
void bitWriterFlush(BitWriter &bw)
{
   if( length(bw.bString)<8&&length(bw.bString)!=0 )
   {
      bw.bString = rpad(bw.bString,8,'0');
      fwrite<string>(bw.bFile,stringToInt(bw.bString,2));
   }
}

#endif
