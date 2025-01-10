#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    uint32_t number;
    scanf_s("%d", &number);

    int32_t devide[4];
    memset(devide, -1, sizeof(devide));

    bool judge = false;

    //defend
    if (number == 0) {
        printf("0");
        return 0;
    }

    for (int i = 0; number != 0; i++) {
        devide[i] = number % 1000;
        number /= 1000;
    }

    for (int i = 3; i >= 0; i--) {
        //defend
        if (devide[i] == -1) {
            continue;
        }

        if (!judge) {
            printf("%d", devide[i]);
            judge = true;
        }
        else {
            printf(",%03d", devide[i]);
        }
    }

    return 0;
}