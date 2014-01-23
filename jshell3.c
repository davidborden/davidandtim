// Timothy Fok
// David Borden
// CS 170

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"

//TODO: add flags, and exit. 

int main( int argc, const char* argv[] )
{
  
  // TODO: need a newline
  char *prompt = "Jsh: ";
  
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
  
  while(1){
    printf("%s", prompt);
    is = new_inputstruct(NULL);
    
    get_line(is);
    // for debugging purposes, prints out stdin using fields library
    /*for (i = 0; i < is->NF; i++) {
      printf("%d: %s\n", is->line, is->fields[i]);
    }
    */
    int num_of_args = is->NF;
    char* command = is->fields[0];
    char* command_arg = is->fields[1];

    int pid, status;
    char **newargv;
    
    newargv = (char **) malloc(sizeof(char *)*num_of_args);
    
    // if user tries to exit:
    // only need to account for CNTL-D or exit

    // is it exit() or pthread_exit() or something else?
    // should we check to see if there is anything else written?
    // e.g. exit test.sh 34
    // do we need strings library for this?
    // look for zombies!
    printf("the inputted command is: %s ",command);

    int result = strcmp(command, "exit");
    //char* other_result = command;
    //int new_result = atoi(result);
    if ( result == 0){// || new_result == EOF) {
      exit(0);
    }
    
    // by convention the first argument is the command / file itself
    newargv[0] = command;
    newargv[1] = command_arg;
    // array MUST end in NULL
    newargv[2] = NULL;
    
    if (fork() == 0) {
      execvp(command, newargv);
      perror("forkcat1");
      exit(1);
    } else {
      wait(&status);
    }
    
    jettison_inputstruct(is);
    
  }
}

// Notes section //
/**

"we're using a limit of 256 characters per input line"
'<' redirection can go anywhere
use WNOHANG option so you don't block waiting for background jobs
 
*/
