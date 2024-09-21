// By Eymard Alarcon //

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <time.h>

typedef __int128 fib_type;

int can_add(fib_type a, fib_type b) {
    if (a > 0 && b > 0 && a > (INTMAX_MAX - b)) {
        return 0; 
    }
    return 1; 
}

fib_type fibonacci_recursive(fib_type n) {
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

fib_type fibonacci_iterative(fib_type n) {
    if (n == 0) return 0;
    if (n == 1) return 0;  
    if (n == 2) return 1;

    fib_type a = 0, b = 1, fib = 0;
    for (fib_type i = 3; i <= n; i++) {
        if (!can_add(a, b)) {
            printf("Overflow would occur at Fibonacci(%lld)\n", (long long)i);
            return -1;
        }
        fib = a + b;
        a = b;
        b = fib;
    }
    return b;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <integer> <r|i>\n", argv[0]);
        return 1;
    }

    fib_type N = atoll(argv[1]); 
    char method = argv[2][0];

    fib_type result = 0;

    if (method == 'r') {
        result = fibonacci_recursive(N);
    } else if (method == 'i') {
        result = fibonacci_iterative(N);
    } else {
        printf("Error: Invalid method '%c'. Use 'r' for recursive or 'i' for iterative.\n", method);
        return 1;
    }

    printf("%lld\n", (long long)result);

    return 0;
}

