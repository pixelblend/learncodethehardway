#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  int actual_args = argc - 1;

  if(actual_args == 0) {
    printf("You don't have a single argument. You sucka.\n");
  } else if(actual_args > 1 && actual_args < 4) {
    printf("Here's your arguments:\n");

    for(i=1; i < argc; i++) {
      printf("%s ", argv[i]);
    }
    printf("\n");
  } else {
    printf("You have too many arguments, sucka.\n");
  }

  return 0;
}
