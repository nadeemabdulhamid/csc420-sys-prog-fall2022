
#include <stdio.h>

void sqrs(int *ar, int n);
void dump(int ar[], int n);
void dumpp(int ar[], int n);


int main() {
  int nums[] = { 5, 3, 5, 9, 19, 2, 4 };

  dump(nums, 7);

  sqrs(nums, 7);
  dumpp(nums, 7);
}

void sqrs(int *ar, int n) {
  while (n-- > 0) {
    *ar = *ar * *ar;
    ar++;
  }
}

void dump(int ar[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%5d", ar[i]);
  }
  printf("\n");
}

void dumpp(int *ar, int n) {
  for (int i = 0; i < n; i++) {
    printf("%5d", *(ar+i));
  }
  printf("\n");
}