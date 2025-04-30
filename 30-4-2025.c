#include <stdbool.h>
#include <stdio.h>

/*
    Given an array of size 10 with a range of 0-10 determine if the order of
   integers are shuffled well. I.E. 3 or more numbers do not appear in order
   acsending or descending.

    isShuffledWell([1, 2, 3, 5, 8, 6, 9, 10, 7, 4])
    output = false
    # 1, 2, 3 appear consecutively

    isShuffledWell([3, 5, 1, 9, 8, 7, 6, 4, 2, 10])
    output = false
    # 9, 8, 7, 6 appear consecutively

    isShuffledWell([1, 5, 3, 8, 10, 2, 7, 6, 4, 9])
    output = true
    # No consecutive numbers appear

    isShuffledWell([1, 3, 5, 7, 9, 2, 4, 6, 8, 10])
    output = true
    # No consecutive numbers appear
*/

bool isShuffledWell(const int arr[]) {
  int consecutive = 1;
  int direction = 0;  // 1 for ascending, -1 for descending, 0 for none

  for (int i = 1; i < 10; i++) {
    int diff = arr[i] - arr[i - 1];
    if (diff == 1) {
      if (direction == 1) {
        consecutive++;
      } else {
        direction = 1;
        consecutive = 2;
      }
    } else if (diff == -1) {
      if (direction == -1) {
        consecutive++;
      } else {
        direction = -1;
        consecutive = 2;
      }
    } else {
      direction = 0;
      consecutive = 1;
    }

    if (consecutive >= 3) return false;
  }
  return true;
}

int main() {
  int test1[] = {1, 2, 3, 5, 8, 6, 9, 10, 7, 4};
  int test2[] = {3, 5, 1, 9, 8, 7, 6, 4, 2, 10};
  int test3[] = {1, 5, 3, 8, 10, 2, 7, 6, 4, 9};
  int test4[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  printf("Test 1: %s\n", isShuffledWell(test1) ? "true" : "false");
  printf("Test 2: %s\n", isShuffledWell(test2) ? "true" : "false");
  printf("Test 3: %s\n", isShuffledWell(test3) ? "true" : "false");
  printf("Test 4: %s\n", isShuffledWell(test4) ? "true" : "false");

  return 0;
}