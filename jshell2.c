// Timothy Fok
// David Borden
// CS 170

#include <stdio.h>
#include <stdlib.h>
#include "fields.h"

int main( int argc, const char* argv[] )
{

  // TODO:  need a newline
  char *prompt = "Jsh: ";
  //char **new_prompt = "";
  int c = 0;

  IS is;
  int i;

  //checks if there is more than 1 command line arg
  if (argc > 2) {
    fprintf(stderr, "usage, ./jshell <prompt>");
    exit(1);
  }
  if (argc == 2){
    prompt = argv[1];
    strcat ( prompt , " ");
  }
  while (c < 5){
  printf("%s", prompt);
  
  /*  
  is = new_inputstruct(argv[1]);
  if (is == NULL) {
    perror(argv[1]);
    exit(1);
  }
  */

  is = new_inputstruct(NULL);
  while(get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) {
      printf("%d: %s\n", is->line, is->fields[i]);
    }
  }

  jettison_inputstruct(is);
  exit(0);

  c++;
  }
  
}
