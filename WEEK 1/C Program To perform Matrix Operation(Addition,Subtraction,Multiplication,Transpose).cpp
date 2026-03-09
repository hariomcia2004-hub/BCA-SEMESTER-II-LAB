#include <stdio.h>

void inputMatrix(int r, int c, int mat[10][10]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int r, int c, int mat[10][10]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int a[10][10], b[10][10], res[10][10];
    int r1, c1, r2, c2, choice;

    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 4) {
        printf("Enter rows and columns: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter matrix elements:\n");
        inputMatrix(r1, c1, a);
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                res[j][i] = a[i][j];
        printf("Transpose:\n");
        displayMatrix(c1, r1, res);
    } else {
        printf("Enter rows and columns for Matrix A: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter elements of A:\n");
        inputMatrix(r1, c1, a);
        printf("Enter rows and columns for Matrix B: ");
        scanf("%d %d", &r2, &c2);
        printf("Enter elements of B:\n");
        inputMatrix(r2, c2, b);

        switch (choice) {
            case 1: // Addition
                if (r1 == r2 && c1 == c2) {
                    for (int i = 0; i < r1; i++)
                        for (int j = 0; j < c1; j++)
                            res[i][j] = a[i][j] + b[i][j];
                            printf("RESULTANT ADDITION MATRIX:\n");
                    displayMatrix(r1, c1, res);
                } else printf("Size mismatch!\n");
                break;
            case 2: // Subtraction
                if (r1 == r2 && c1 == c2) {
                    for (int i = 0; i < r1; i++)
                        for (int j = 0; j < c1; j++)
                            res[i][j] = a[i][j] - b[i][j];
                            printf("RESULTANT SUBTRACTION MATRIX:\n");
                    displayMatrix(r1, c1, res);
                } else printf("Size mismatch!\n");
                break;
            case 3: // Multiplication
                if (c1 == r2) {
                    for (int i = 0; i < r1; i++) {
                        for (int j = 0; j < c2; j++) {
                            res[i][j] = 0;
                            for (int k = 0; k < c1; k++)
                                res[i][j] += a[i][k] * b[k][j];
                        }
                    }
                    printf("RESULTANT MULTIPLICATION MATRIX:\n");
                    displayMatrix(r1, c2, res);
                } else printf("Multiplication not possible!\n");
                break;
        }
    }
    return 0;
}

