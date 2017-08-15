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

char* getMagnitude(char** extracted) {
   char* magnitude;
   strsep(extracted, " ");
   magnitude = strsep(extracted, " ");
   return magnitude;
}

char* getLocation(char** extracted) {
   char* loc;
   strsep(extracted, "- ");
   loc = strsep(extracted, "<");
   return loc;
}

char* getTime(char** extracted) {
   char* time;
   strsep(extracted, ">");
   strsep(extracted, ">");
   time = strsep(extracted, "<");
   return time;
}

void printAll(char* mag, char* loc, char* time) {
   if(!mag || !loc || !time) {
      return;
   }
   printf("Time: %s\n", time);
   printf("Location:%s\n", loc);
   printf("Magnitude: %s\n\n", mag);
}
void extract(char* line) {
   char* extracted;
   char* magnitude;
   char* location;
   char* timestamp;

   if((extracted = strstr(line, "</id><title>")) != 0) {
      magnitude = getMagnitude(&extracted);
      location = getLocation(&extracted);
      timestamp = getTime(&extracted);
   }
   printAll(magnitude, location, timestamp);
}

void cleanInfo() {
   char* line;
   FILE* file = fopen("data", "r");
   line = getLine(file);
   while(line[0] != '\0') {
      extract(line);
      free(line);
      line = getLine(file);
   }
   free(line);
   fclose(file);
}
