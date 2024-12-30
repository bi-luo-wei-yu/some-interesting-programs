#include <stdio.h>
#include <stdbool.h>

bool IsLeapYear(int year);
int GetDaysInMonth(int year, int month);

int main(void)
{
    int year, month, day;
    scanf_s("%d-%d-%d", &year, &month, &day);

    int sumDay = 0;
    for (int i = 1; i < month; i++) {
        sumDay += GetDaysInMonth(year, i);
    }

    sumDay += day;

    printf("%d", sumDay);

    return 0;
}

bool IsLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int GetDaysInMonth(int year, int month) {
    const int days[12] = { 31,
                    IsLeapYear(year) ? 29 : 28,
        31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    return days[month - 1];
}