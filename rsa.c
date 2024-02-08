#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to calculate the greatest common divisor
uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Pollard's rho algorithm for prime factorization
uint64_t pollard_rho(uint64_t n) {
    if (n == 1) return 1;

    uint64_t x = rand() % (n - 2) + 2;
    uint64_t y = x;
    uint64_t c = rand() % (n - 1) + 1;
    uint64_t d = 1;

    while (d == 1) {
        x = (x * x + c) % n;
        y = (y * y + c) % n;
        y = (y * y + c) % n;
        d = gcd(abs(x - y), n);
    }

    return d;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: rsa <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    uint64_t n;
    if (fscanf(file, "%lu", &n) != 1) {
        printf("Error: Invalid input format.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    uint64_t p = pollard_rho(n);
    uint64_t q = n / p;

    printf("%lu=%lu*%lu\n", n, p, q);

    return 0;
}
