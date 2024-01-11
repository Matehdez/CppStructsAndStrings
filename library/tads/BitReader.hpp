#ifndef _TARR_BITREADER_
#define _TARR_BITREADER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../funciones/strings.hpp"
#include "../funciones/files.hpp"

using namespace std;

struct BitReader
{
   FILE *brFile;
};

BitReader bitReader(FILE *f)
{
   BitReader br;
   br.brFile = f;
   return br;
}

// Lee un bit desde el archivo.
int bitReaderRead(BitReader &br)
{
   int byte = read<int>(br.brFile);
   return byte;
}

#endif
