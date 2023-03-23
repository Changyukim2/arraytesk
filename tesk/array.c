#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} term;

void smTranspose(term a[], term b[]) {
    int i, j, currentb;

    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = a[0].value;

    if (a[0].value > 0) {
        currentb = 1;
        for (i = 0; i < a[0].col; i++)
            for (j = 1; j <= a[0].value; j++)
                if (a[j].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
    }
}

int main(void) {
    int i, j;
    term A[8] = { {6,6,7}, {0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5}, {4,5,1}, {5,2,2} };
    term B[8];

    smTranspose(A, B);



    printf("행의 수: %d, 열의 수: %d, 0이 아닌 항의 수: %d\n", A[0].row, A[0].col, A[0].value);

    for (i = 1; i < 8; i++)
        printf("행: %d, 열: %d, 값: %d\n", A[i].row, A[i].col, A[i].value);
    printf("\n\n");


    smTranspose(A, B);

    printf("Transpose processing has been finished.\n");
    printf("\n\n");

    printf("행의 수: %d, 열의 수: %d, 0이 아닌 항의 수: %d\n", B[0].row, B[0].col, B[0].value);

    for (i = 1; i < 8; i++)
        printf("행: %d, 열: %d, 값: %d\n", B[i].row, B[i].col, B[i].value);
    printf("\n\n");



    return 0;
}