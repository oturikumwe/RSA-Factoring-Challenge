#include<stdio.h>
#include <stdlib.h>

void factorize(int num) {
    int factor1 = 2;
    int factor2 = num / factor1;
    while (factor1 <= factor2) {
        if (factor1 * factor2 == num) {
            printf("%d=%d*%d\n", num, factor1, factor2);
            return;
        }
        factor1++;
        factor2 = num / factor1;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        factorize(num);
    }
    fclose(file);
    return 0;
}
