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

BitWriter bitWriter(FILE* f)
{
   BitWriter bw;
   bw.bString = "";
   bw.bFile = f;
   return bw;
}

// Write a bit to the file.
void bitWriterWrite(BitWriter &bw, int bit)
{
   bw.bString += intToChar(bit);
   if( length(bw.bString)==8 )
   {

      fwrite <string>(bw.bFile,stringToInt(bw.bString,2));
      bw.bString = "";
   }
}

// Records the ones and zeros that contain bits into the file.
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

//Indicates that no more bits will be recorded. In case the bit amount
//that we record is not a multiple of 8, complete with zeros on the right and record./
void bitWriterFlush(BitWriter &bw)
{
   if( length(bw.bString)<8&&length(bw.bString)!=0 )
   {
      bw.bString = rpad(bw.bString,8,'0');
      fwrite<string>(bw.bFile,stringToInt(bw.bString,2));
   }
}

#endif
