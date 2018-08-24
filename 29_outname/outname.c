#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char * outname = malloc((strlen(inputName)+4)*sizeof(*outname));
  strcpy(outname , inputName);
  outname= realloc(outname ,(strlen(inputName)+10)*sizeof(*outname));
  strcat(outname,".counts");
  return outname;
  //WRITE ME
}
