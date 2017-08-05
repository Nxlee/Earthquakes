#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "func.h"
char* getLine(FILE* file) {
   int i = 0;
   char *line;
   char *temp;
   int size = 10;
   line = malloc(size * sizeof(char));

   if(line == NULL) {
      fprintf(stderr, "Error with initial malloc");
      exit(-1);
   }

   while(i < size) {
      line[i] = getc(file);
      if(line[i] == '\n' || line[i] == EOF) {
         break;
      }
      i++;

      if(i == size -1) {
         size *= 2;
         temp = realloc(line, size*sizeof(char));
         if(temp == NULL) {
            fprintf(stderr, "Error with realloc");
            exit(-1);
         } else {
            line = temp;
         }
       }

   }

   line[i] = '\0';
   return line;
}



void pullInfo() {
   system("wget -O data https://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/significant_month.atom");
   cleanInfo();
}

void cleanInfo() {
   char* line;
   FILE* file = fopen("data", "r");
   line = getLine(file);
   while(line[0] != '\0') {
      if(strstr(line, "</id><title>")) {
         printf("%s\n", line);
      }
      free(line);
      line = getLine(file);
   }
   free(line);
}
