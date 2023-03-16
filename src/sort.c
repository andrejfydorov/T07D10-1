#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void quick_sort(int *s_arr, int first, int last);
int check_array(int *a, int n);
void swap(int *a, int *b);

int main() {
  int n = NMAX;
  int *data = malloc(n * sizeof(int));

  if (input(data, &n) == 0 && check_array(data, n) == 0) {
    quick_sort(data, 0, n - 1);
    output(data, n);
  } else {
    printf("n/a");
  }
  free(data);

  return 0;
}

int input(int *a, int *n) {
  scanf("%d", n);
  if (*n > 10)
    return -1;

  for (int *p = a; p - a < *n; p++) {
    if (scanf("%d", p) != 1) {
      return -1;
    }
  }
  return 0;
}

void output(int *a, int n) {
  for (int *p = a; p - a < n; p++) {
    if ((p - a) == n - 1) {
      printf("%d", *p);
    } else {
      printf("%d ", *p);
    }
  }
}

void quick_sort(int *s_arr, int first, int last) {
  int i = first, j = last, x = s_arr[(first + last) / 2];

  do {
    while (s_arr[i] < x)
      i++;
    while (s_arr[j] > x)
      j--;

    if (i <= j) {
      if (s_arr[i] > s_arr[j])
        swap(&s_arr[i], &s_arr[j]);
      i++;
      j--;
    }
  } while (i <= j);

  if (i < last)
    quick_sort(s_arr, i, last);
  if (first < j)
    quick_sort(s_arr, first, j);
}

int check_array(int *a, int n) {
  int res = 0;
  for (int *p = a; p - a < n; p++) {
    if (isdigit(*p) != 0) {
      return -1;
    }
  }

  return res;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}