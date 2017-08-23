#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
int main(int argc, char** argv) {
   pullInfo();

   if(argc > 1) {
      if(!(strcmp(argv[1],"autopoll"))) {
         runAuto();
      }
   }



   return 0;
}
