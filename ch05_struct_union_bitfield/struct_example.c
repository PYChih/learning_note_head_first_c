/* gcc struct_example.c && ./a.out
 *
 */

#include <stdlib.h>
#include <stdio.h>

struct preferences {
  const char *food;
  float exercise_hours;
};

struct fish {
  const char *name;
  const char *species;
  int teeth;
  int age;
  struct preferences care;
};

typedef struct {
  const char *name;
  const char *species;
  int age;
} turtle;

void happy_birthday_value(turtle t) {
  t.age = t.age + 1;
  printf("Happy Birthday %s! You are now %i years old!\n", t.name, t.age);
}

void happy_birthday_ptr(turtle *t) {
  t->age += 1;
  printf("Happy Birthday %s! You are now %i years old!\n", t->name, t->age);
}


void catalog(struct fish f) {
  printf("%s is a %s with %i teeth. He is %i years old\n",
        f.name, f.species, f.teeth, f.age);
}

void label(struct fish f) {
  printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n",
        f.name, f.species, f.age, f.teeth);
}

int main() {
  struct fish snappy = {"Snappy", "Piranha", 69, 4, {"Meat", 7.5}};
  catalog(snappy);
  label(snappy);
  printf("sizeof fish %li\n", sizeof(snappy));  // 32?
  printf("perfer food: %s, exercise_hours: %f\n", snappy.care.food, snappy.care.exercise_hours);
  // struct update pass by value or pointer
  turtle mytle = {"Mytle", "Leatherback sea turtle", 99};
  printf("age in main : %i\n", mytle.age);
  happy_birthday_value(mytle);
  printf("age after hb_value: %i\n", mytle.age);
  happy_birthday_ptr(&mytle);
  printf("age after hb_ptr: %i\n", mytle.age);

}