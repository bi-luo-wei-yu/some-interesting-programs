#include <stdio.h>

void dectobin(int n);

int main()
{
    int n;

    scanf_s("%d", &n);
    dectobin(n);

    return 0;
}

#include <string.h>

void dectobin(int n) {
    //defence
    if (n == 0) {
        printf("0");
        return;
    }

    //Ω®“È≤πstore[i + 1] = '\0'
    char store[100];

    for (int i = 0; i < 100; i++) {
        if (n != 0) {
            if (n & 1) {
                store[i] = '1';
            }
            else {
                store[i] = '0';
            }
        }
        n = n >> 1;
    }

    int length = strlen(store);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", store[i]);
    }
}