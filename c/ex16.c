#include <stdio.h>  //standard input - output. printf
#include <assert.h> //assertions - raise exception on failure
#include <stdlib.h> //memory allocation, amoungst others
#include <string.h> //string manipulation - to upper/lower

struct Person { //returns compound data type covering the 4 elements
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
  struct Person *who = malloc(sizeof(struct Person)); //request raw memory, the size of the total required for Person's fields
  assert(who != NULL); //check memory chunk is valid (non-null)

  who->name = strdup(name); //creates copy of name and passes pointer to who->name; like malloc
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void Person_destroy(struct Person *who) //input is a pointer of struct Person, called 'who'
{
  assert(who != NULL); //check input is a valid memory address

  //prevent memory leaks by freeing malloc'd resources
  free(who->name);
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
  // make two people structures
  struct Person *joe = Person_create(
      "Joe Alex", 32, 64, 140);
  
  struct Person *frank = Person_create(
      "Frank Black", 20, 72, 180);

  printf("Size of Person in bytes: %d\n", sizeof(struct Person));

  // print them out and where they are in memory
  printf("Joe is at memory location %p, and %d bytes:\n", joe, sizeof(joe));
  Person_print(joe);

  printf("Frank is at memory location %p:\n", frank);
  Person_print(frank);

  // make everyone age 20 years and print them again
  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print(joe);

  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  // destroy them both so we can clean up
  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}
