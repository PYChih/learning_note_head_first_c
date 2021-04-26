#include <stdio.h>
#include "hfcal.h"

void display_calories(float weight, float distance, float coeff) {
  printf("Weight: %3.2f lbs\n", weight);  // lb
  printf("Distance: %3.2f miles\n", distance);  // mile
  printf("Calories burned: %4.2f cal\n", coeff * weight * distance);
}