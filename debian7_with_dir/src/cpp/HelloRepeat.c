#include <stdio.h>
#include "HelloRepeat.h"

int hello_repeat(char* name, int times) {
  int i;
  for (i = 0; i < times; i++) {
    printf("Hello %s\n", name);
  }
  return times;
}

int main(int argc, char *args[]){
  int i;
  for(i = 0; i < argc; i++) {
    hello_repeat(args[i], argc);
  }
}
