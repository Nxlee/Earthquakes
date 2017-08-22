#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
int main(int argc, char** argv) {
   if(argc > 1) {
      if(!(strcmp(argv[1],"autopoll"))) {
         pullInfo();
         runAuto();
      }
   }
   pullInfo();


   return 0;
}
