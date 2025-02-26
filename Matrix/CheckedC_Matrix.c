#include <stdio_checked.h>
#include <stdlib_checked.h>

#define SIZE 4  

void matrix_multiply(_Array_ptr<int> A : count(SIZE * SIZE),
                     _Array_ptr<int> B : count(SIZE * SIZE),
                     _Array_ptr<int> C : count(SIZE * SIZE)) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i * SIZE + j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i * SIZE + j] += A[i * SIZE + k] * B[k * SIZE + j];
            }
        }
    }
}

int main() {
    _Array_ptr<int> A : count(SIZE * SIZE) = malloc<int>(SIZE * SIZE * sizeof(int));
    _Array_ptr<int> B : count(SIZE * SIZE) = malloc<int>(SIZE * SIZE * sizeof(int));
    _Array_ptr<int> C : count(SIZE * SIZE) = malloc<int>(SIZE * SIZE * sizeof(int));

    for (int i = 0; i < SIZE * SIZE; i++) {
        A[i] = i + 1;
        B[i] = SIZE * SIZE - i;
    }

    matrix_multiply(A, B, C);

    for (int i = 0; i < SIZE * SIZE; i++) {
        if (i % SIZE == 0) printf("\n");
        printf("%d ", C[i]);
    }

    free(A);
    free(B);
    free(C);
    return 0;
}
