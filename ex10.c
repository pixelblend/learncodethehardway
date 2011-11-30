#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;

  //go through each string in argv
  //skipping the first arg because 
  //that's the filename
  for(i = 0; i < argc, i != 2; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }

  //own array of strings
  char *states[] = {
    NULL, "California", "Oregon",
    "Washington", "Texas"
  };

  states[0] = argv[1];

  int num_states = 5;

  for(i = 0; i < num_states; i++) {
    printf("state %d: %s\n", i, states[i]);
  }

  return 0;
}

