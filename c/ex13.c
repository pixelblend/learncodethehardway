#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  if(argc != 2) {
    printf("ERROR: You only need one argument.\n");
    //exit
    return 1;
  }

  int i = 0;
  for(i=0; argv[1][i] != '\0'; i++) {
    char letter = tolower(argv[1][i]);
    if(letter == ' ') {
      continue;
    }

    switch(letter) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        printf("%d: '%c'\n", i, letter);
        break;
      case 'y':
        if(i > 2) {
          //it's only sometimes Y
          printf("%d: 'Y'\n",i);
          break; //allow fallthrough if it's not a vowel this time
        }
      default:
        printf("%d: %c is not a vowel\n", i, letter);
    }
  }

  return 0;
}
