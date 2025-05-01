#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define u32 uint32_t

int main(void)
{
	int n;
	scanf_s("%d", &n);

	u32 juzhen[100][100] = { 0 };

	//标签(数组下标版)
	u32 rowSt = 0;
	u32 rowDl = n - 1;
	u32 colSt = 0;
	u32 colDl = n / 2 - 1;

	u32 number = 0;//inject

	//左侧

	while (colSt <= colDl) {

		//上
		for (int j = colDl; j > colSt; j--) {
			number += 1;
			juzhen[rowSt][j] = number;
		}
		//左
		for (int i = rowSt; i < rowDl; i++) {
			number += 1;
			juzhen[i][colSt] = number;
		}

		// 卫语句
		if (colSt == colDl) {
			number += 1;
			juzhen[rowDl][colDl] = number;
			break;
		}

		//下
		for (int j = colSt; j < colDl; j++) {
			number += 1;
			juzhen[rowDl][j] = number;
		}
		//右
		for (int i = rowDl; i > rowSt; i--) {
			number += 1;
			juzhen[i][colDl] = number;
		}

		rowSt += 1;
		rowDl -= 1;
		colSt += 1;
		colDl -= 1;
	}

	//copy
	for (int i = 0; i < n; i++) {
		int j = 0, jr = n - 1;
		while (j < jr) {
			juzhen[i][jr--] = juzhen[i][j++];
		}
	}
		
	//output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", juzhen[i][j]);
		}
		printf("\n");
	}

	return 0;
}