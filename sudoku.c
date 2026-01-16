#include <stdio.h>

#define N 9
#define MAX_STACK 100

typedef struct {
    int row;
    int col;
    int num;
} StackNode;

StackNode stack[MAX_STACK];
int top = -1;

void push(int row, int col, int num) {
    stack[++top] = (StackNode){row, col, num};
}

StackNode pop() {
    return stack[top--];
}

int isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return 0;

    int sr = row - row % 3;
    int sc = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[sr + i][sc + j] == num)
                return 0;

    return 1;
}

void printGrid(int grid[N][N]) {
    printf("\nSolved Sudoku Grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int solveSudoku(int grid[N][N]) {
    int row = 0, col = 0;

    while (row < N) {
        if (grid[row][col] == 0) {
            int placed = 0;

            for (int num = 1; num <= 9; num++) {
                if (isSafe(grid, row, col, num)) {
                    grid[row][col] = num;
                    push(row, col, num);
                    placed = 1;
                    break;
                }
            }

            if (!placed) {
                if (top < 0) return 0;

                StackNode prev = pop();
                row = prev.row;
                col = prev.col;
                grid[row][col] = 0;

                for (int num = prev.num + 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        push(row, col, num);
                        placed = 1;
                        break;
                    }
                }
                if (!placed) continue;
            }
        }

        col++;
        if (col == N) {
            row++;
            col = 0;
        }
    }
    return 1;
}

int main() {
    int grid[N][N];

    printf("=== Sudoku Solver Using Stack ===\n");
    printf("Enter the Sudoku grid (9 numbers per row, use 0 for empty):\n\n");

    for (int i = 0; i < N; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solveSudoku(grid))
        printGrid(grid);
    else
        printf("\nNo solution exists\n");

    return 0;
}
