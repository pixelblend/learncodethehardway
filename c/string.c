#include <stdio.h>

int main(int argc, char *argv[])
{
  char *first_string = "HELLO THERE";
  char *new_string;

  printf("first string: %s\n", first_string);
  new_string = first_string;
  printf("new string: %s\n", new_string);
  new_string = "BYE!";
  printf("first string: %s\n", first_string);
  printf("new string: %s\n", new_string);

  return 0;
}
