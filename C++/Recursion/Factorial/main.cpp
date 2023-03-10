#include <cstdio>

// Recursive factorial of a number
int fact(int n) {
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

// Iterative factorial
int factItr(int n) {
    int f{1};
    for (int i{1}; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    printf("Recursive: %d ", fact(4));
    printf("\nIterative: %d ", factItr(4));
}
