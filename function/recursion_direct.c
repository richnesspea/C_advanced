#include <stdio.h>

// Head Recursion: In các số từ 1 đến n theo thứ tự tăng dần
void headRecursion(int n) {
    if (n == 0) return;
    headRecursion(n - 1);
    printf("%d ", n);  // Thao tác sau lời gọi đệ quy
}

// Tail Recursion: In các số từ n đến 1 theo thứ tự giảm dần
void tailRecursion(int n) {
    if (n == 0) return;
    printf("%d ", n);  // Thao tác trước lời gọi đệ quy
    tailRecursion(n - 1);
}

// Tree Recursion: Tính số Fibonacci thứ n
int treeRecursion(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return treeRecursion(n - 1) + treeRecursion(n - 2);  // Gọi đệ quy hai lần
}

int main() {
    int n = 5;

    // Head Recursion
    printf("Head Recursion (1 to %d): ", n);
    headRecursion(n);
    printf("\n");

    // Tail Recursion
    printf("Tail Recursion (%d to 1): ", n);
    tailRecursion(n);
    printf("\n");

    // Tree Recursion
    printf("Tree Recursion (Fibonacci of %d): ", n);
    int fib = treeRecursion(n);
    printf("%d\n", fib);

    return 0;
}
