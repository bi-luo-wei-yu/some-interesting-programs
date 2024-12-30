#include<stdio.h>
#include <stdint.h>
#include <string.h>

#define u32 uint32_t

struct product {
    int id;
    char name[20];
    double price;
};

void menu(struct product p[], int n);
void order(struct product p[], int n);

int main()
{
    struct product p[20];   // ������50����Ʒ
    int n;
    scanf_s("%d", &n);        // ��Ʒ���� 
    for (int i = 0; i < n; i++) {
        scanf_s("%d %s %lf", &p[i].id, p[i].name, (u32)sizeof(p[i].name), &p[i].price);  // �������Ʒ�ı�š����ƺ͵���
    }

    menu(p, n);     // ��ʾ�˵�
    order(p, n);    // �㵥������������Ʒ������Ҫ���������Ʒ�����ơ��������۸��Լ����յ��ܼ۸�

    return 0;
}

void menu(struct product p[], int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d] %s %.1f\n", p->id, p->name, p->price);
        p++;
    }
}
void order(struct product p[], int n) {
    double sum = 0.0f;

    int id;
    while (~scanf("%d", &id) && id != 0) {
        int number;
        scanf_s("%d", &number);

        double sumPrice = 0.0f;
        for (int i = 0; i < n; i++) {
            if (id == p[i].id) {
                sumPrice = p[i].price * number;
                sum += sumPrice;
                printf("%s * %d = %.1f\n", p[i].name, number, sumPrice);
                break;
            }
        }
    }

    printf("Total = %.1f\n", sum);
}