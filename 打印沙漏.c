#include <stdio.h>
#include <math.h>

void print(int number, char digit);
int main(void)
{
    int N;
    char digit;
    scanf_s("%d %c", &N, &digit, 1);

    int number = 0;
    for (int i = 1; 2 * i * i - 1 <= N; i++) {
        number = i;
    }

    print(number, digit);
    printf("%d", N - (2 * number * number - 1));

    return 0;
}

void print(int number, char digit) {
    //上三角
    for (int i = 0; i < number; i++) {
        //输出空格
        for (int j = 1; j <= i; j++) {
            printf(" ");
        }
        //行
        for (int j = 1; j <= 2 * (number - i) - 1; j++) {
            printf("%c", digit);
        }
        printf("\n");
    }
    //下三角
    for (int i = 1; i < number; i++) {
        int spaces = number - i;//计算并提前储存空格数

        //输出空格
        for (int j = 1; j < spaces; j++) {
            printf(" ");
        }
        //行
        for (int j = 1; j <= 2 * (i + 1) - 1; j++) {
            printf("%c", digit);
        }
        printf("\n");
    }
}