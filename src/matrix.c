#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 100

void input1(int *n, int *m);
void input2(int *n, int *m);
void input3(int *n, int *m);
void input4(int *n, int *m);
void output(int **a, int n, int m);
void output1(int a[LEN][LEN], int n, int m);

int main() {

  int n, m;
  printf("Input 1 2 3 or 4: ");
  int sel;
  scanf("%d", &sel);

  if (sel == 1) {
    input1(&n, &m);
  } else if (sel == 2) {
    input2(&n, &m);
  } else if (sel == 3) {
    input3(&n, &m);
  } else if (sel == 4) {
    input4(&n, &m);
  } else {
    printf("n/a");
  }

  return 0;
}

void input1(int *n, int *m) {
  scanf("%d", n);
  scanf("%d", m);

  if (*n > LEN || *m > LEN) {
    printf("n/a");
    return;
  }

  int arr[LEN][LEN];
  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < *m; j++) {
      int d;
      if (scanf("%d", &d) != 1) {
        printf("n/a");
        return;
      }
      arr[i][j] = d;
    }
  }

  output1(arr, *n, *m);
}

void input2(int *n, int *m) {
  scanf("%d", n);
  scanf("%d", m);

  int **arr = malloc((*n) * *m * sizeof(int *) + *n * sizeof(int *));
  int *ptr = (int *)(arr + *n);

  for (int i = 0; i < *n; i++) {
    arr[i] = ptr + *m * i;

    for (int j = 0; j < *m; j++) {
      int d;
      if (scanf("%d", &d) != 1) {
        printf("n/a");
        return;
      }
      arr[i][j] = d;
    }
  }

  output(arr, *n, *m);

  free(arr);
}

void input3(int *n, int *m) {
  scanf("%d", n);
  scanf("%d", m);

  int **arr = malloc((*n) * sizeof(int *));

  for (int i = 0; i < *n; i++) {
    arr[i] = malloc(sizeof(int) * (*m));

    for (int j = 0; j < *m; j++) {
      int d;
      if (scanf("%d", &d) != 1) {
        printf("n/a");
        return;
      }
      arr[i][j] = d;
    }
  }

  output(arr, *n, *m);

  for (int i = 0; i < *n; i++) {
    free(arr[i]);
  }
  free(arr);
}

void input4(int *n, int *m) {
  scanf("%d", n);
  scanf("%d", m);

  int **arr = malloc(*n * sizeof(int *));
  int *value_array = malloc(*n * *m * sizeof(int));

  for (int i = 0; i < *n; i++) {
    arr[i] = value_array + *m * i;

    for (int j = 0; j < *m; j++) {
      int d;
      if (scanf("%d", &d) != 1) {
        printf("n/a");
        return;
      }
      arr[i][j] = d;
    }
  }

  output(arr, *n, *m);
  free(value_array);
  free(arr);
}

void output(int **arr, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j < m - 2) {
        printf("%d", arr[i][j]);
      } else {
        printf("%d ", arr[i][j]);
      }
    }
    if (i < n - 1) {
      printf("\n");
    }
  }
}

void output1(int arr[LEN][LEN], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j < m - 2) {
        printf("%d", arr[i][j]);
      } else {
        printf("%d ", arr[i][j]);
      }
    }
    if (i < n - 1) {
      printf("\n");
    }
  }
}