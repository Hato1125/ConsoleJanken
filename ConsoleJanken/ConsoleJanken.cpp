#include "stdio.h"
#include "stdlib.h"

// 背景色の定義
#define BACKCOLOR_BLACK "\x1b[40m"
#define BACKCOLOR_RED "\x1b[41m"
#define BACKCOLOR_GREEN "\x1b[42m"
#define BACKCOLOR_YELLOW "\x1b[43m"
#define BACKCOLOR_BLUE "\x1b[44m"
#define BACKCOLOR_MAGELLAN "\x1b[45m"
#define BACKCOLOR_CYAN "\x1b[46m"
#define BACKCOLOR_GRAY "\x1b[47m"
#define BACKCOLOR_RESET "\x1b[49m"

// 前景色の定義
#define TEXTCOLOR_BLACK "\x1b[30m"
#define TEXTCOLOR_RED "\x1b[311m"
#define TEXTCOLOR_GREEN "\x1b[32m"
#define TEXTCOLOR_YELLOW "\x1b[33m"
#define TEXTCOLOR_BLUE "\x1b[34m"
#define TEXTCOLOR_MAGELLAN "\x1b[35m"
#define TEXTCOLOR_CYAN "\x1b[36m"
#define TEXTCOLOR_GRAY "\x1b[37m"
#define TEXTCOLOR_RESET "\x1b[39m"

// プロトタイプ宣言
int GetJudge(int* my, int* enemy);

int main(void)
{
	printf(" /$$$$$                     /$$                            /$$ /$$ \n");
	printf(" |__  $$                    | $$                          | $$| $$ \n");
	printf("    | $$  /$$$$$$  /$$$$$$$ | $$   /$$  /$$$$$$  /$$$$$$$ | $$| $$ \n");
	printf("    | $$ |____  $$| $$__  $$| $$  /$$/ /$$__  $$| $$__  $$| $$| $$ \n");
	printf("    | $$  /$$$$$$$| $$  \\ $$| $$$$$$/ | $$$$$$$$| $$  \\ $$|__/|__/ \n");
	printf(" /$$| $$ /$$__  $$| $$  | $$| $$_  $$ | $$_____/| $$  | $$         \n");
	printf("|$$$$$$/ |$$$$$$$$| $$  | $$| $$ \\  $$|  $$$$$$$| $$  | $$ /$$ /$$ \n");
	printf("\\______/  \\_______/|__/  |__/|__/  \\__/ \\_______/|__/  |__/|__/|__/ \n\n\n");

	int myHand;
	int enemyHand;

	LOOP:

	myHand = 0;
	enemyHand = 0;

	printf(BACKCOLOR_GREEN);
	printf(TEXTCOLOR_BLACK);
	printf("手を選んでください   \n");
	printf("---------------------\n");
	printf("|  A  |   S   |  D  |\n");
	printf("|-----|-------|-----|\n");
	printf("| Guu | Tyoki | Paa |\n");
	printf("---------------------\n");
	printf(TEXTCOLOR_RESET);
	printf(BACKCOLOR_RESET);

	char input[2];
	scanf_s("%s", input, 2);

	switch (input[0])
	{
	case 'a':
	case 'A':
		myHand = 0;
		break;

	case 's':
	case 'S':
		myHand = 1;
		break;

	case 'd':
	case 'D':
		myHand = 2;
		break;

	default:
		printf("不正な値が入力されたためコンソールを閉じます。");
		return 0;
		break;
	}

	// 敵の手をランダムに決める
	enemyHand = rand() % 3;

	switch (GetJudge(&myHand, &enemyHand))
	{
	case 0:
		printf("勝ち\n\n\n");
		break;

	case 1:
		printf("あいこ\n\n\n");
		break;

	case 2:
		printf("負け\n\n\n");
		break;

	default:
		printf("不正な値が入力されたためコンソールを閉じます。");
		return 0;
		break;
	}

	printf(BACKCOLOR_GREEN);
	printf(TEXTCOLOR_BLACK);
	printf("じゃんけんを続けますか？ \n");
	printf("-------------            \n");
	printf("|  A  |  S  |            \n");
	printf("|-----|-----|            \n");
	printf("| Yes |  No |            \n");
	printf("-------------            \n");
	printf(TEXTCOLOR_RESET);
	printf(BACKCOLOR_RESET);

	char input2[2];
	scanf_s("%s", input2, 2);
	printf("\n\n\n");

	switch (input2[0])
	{
	case 'a':
	case 'A':
		goto LOOP;
		break;

	case 's':
	case 'S':
		return 0;
		break;

	default:
		printf("不正な値が入力されたためコンソールを閉じます。");
		return 0;
		break;
	}
}

/*------------
  勝敗を判定する
    0 勝ち
    1 あいこ
    2 負け
-------------*/
int GetJudge(int* my, int* enemy)
{
	if (*my == 0)
	{
		if (*enemy == 0)
			return 1;
		else if (*enemy == 1)
			return 0;
		else if (*enemy == 2)
			return 2;
	}
	else if (*my == 1)
	{
		if (*enemy == 0)
			return 2;
		else if (*enemy == 1)
			return 1;
		else if (*enemy == 2)
			return 0;
	}
	else if (*my == 2)
	{
		if (*enemy == 0)
			return 1;
		else if (*enemy == 1)
			return 2;
		else if (*enemy == 2)
			return 0;
	}
}
