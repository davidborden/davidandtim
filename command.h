#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// linked list code adapted from:
// http://www.thegeekstuff.com/2012/08/c-linked-list-example/

  struct command{
    char* the_command;
    int isRedirect;
    char* inFile;
    char* outFile;
    char* arguments[128];
    int num_of_command_args;
    int isFirst;
    int isLast;
    struct command *next;
    // value is for testing purposes only
    char* struct_test_command;
  };

struct command *head = NULL;
struct command *current = NULL;

//TODO: add parameters
struct command* create_list(char* a_command, int redirect, char* infile, char* outfile, char* args[128], int num_args, int isfirst, int islast)
{

  printf("\n creating list with headnode command as <%s>\n",a_command);
  struct command *pointer = (struct command*)malloc(sizeof(struct command));
  if(NULL == pointer) {
    printf("\n Node creation failed \n");
    return NULL;
  }

  pointer->struct_test_command = a_command;
  pointer->isRedirect = redirect;
  pointer->inFile = infile;
  pointer->outFile = outfile;
  pointer->arguments[128] = args;
  pointer->num_of_command_args = num_args;
  pointer->isFirst = isfirst;
  pointer->isLast = islast;

  pointer->next = NULL;
  
  head = current = pointer;
  return pointer;

}

struct command* add_to_list(char* a_command, int redirect, char* infile, char* outfile, char* args[128], int num_args, int isfirst, int islast) {
  
  if(NULL == head) {
    return (create_list(test_command));
    }
  
  printf("\n Adding node to end of list with command <%s>\n",test_command);
  struct command *pointer = (struct command*)malloc(sizeof(struct command));

  if(NULL == pointer) {
    printf("\n Node creation failed \n");
    return NULL;
  }

  pointer->struct_test_command = a_command;
  pointer->isRedirect = redirect;
  pointer->inFile = infile;
  pointer->outFile = outfile;
  pointer->arguments[128] = args;
  pointer->num_of_command_args = num_args;
  pointer->isFirst = isfirst;
  pointer->isLast = islast;

  pointer->next = NULL;

  current->next = pointer;
  current = pointer;

  return pointer;
}
