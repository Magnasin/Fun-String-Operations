#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "fancy_replace.h"

int main(int argc, char* argv[]){

  char *string_a, *string_b;
  char s[256];
  int l;

  if(argc != 3) {
    fprintf(stderr, "Usage: %s a_string b_string\n", argv[0]);
    return -1;
  }
  string_a = argv[1];
  string_b = argv[2];

  while(fgets(s, 255, stdin) != NULL) {
    if((l = strlen(s)) > 0 && s[l-1] == '\n')
      s[l-1] = '\0';
    printf("fancy_replace(\"%s\", \"%s\", \"%s\"): \"%s\"\n",
           s, string_a, string_b,
           fancy_replace(s, string_a, string_b));
  }

  return 0;
}
