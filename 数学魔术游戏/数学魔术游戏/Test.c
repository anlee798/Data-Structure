#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int array[5][16];
int main() {
	showNum();
	int RealNum=RandomNum();

	printf("请输入您猜测的数字:\n");
	int guessNum = 0;
	scanf("%d", &guessNum);
	if (guessNum == RealNum) {
		printf("猜对了！\n");
	}
	else {
		printf("很遗憾，猜错了！\n");
		printf("卡片上的数字%d\n", RealNum);
	}

}
int randomNum() {
	srand((unsigned)time(NULL));
	int num = rand() % 31 + 1;
	int count = num;
	int n[5];
	for (int j = 0; j<5; j++) {
		n[j] = num % 2;
		num = num / 2;
	}

	for (int i = 0; i<5; i++) {
		if (n[i] == 1) {
			printf("数字出现在卡片%d上\n", i + 1);
		}
	}
	return count;
}
int showNum() {
	int arr[31][5];
	for (int i = 1; i < 32; i++) {
		int num = i;
		for (int j = 0; j < 5; j++) {
			arr[i-1][j] = num % 2;
			num = num / 2;
		}
	}

	for (int i = 0; i < 5; i++) {
		int count = 0;
		for (int j = 0; j < 31; j++) {
			if (arr[j][i] == 1) {
				array[i][count] = j+1;
				count++;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 16; j++) {
			printf("%5d", array[i][j]);
		}
		printf("\n");
	}
}