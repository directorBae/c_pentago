#include <stdio.h>
#include <windows.h>
#include <conio.h> 

int cnthzn1 = 0;
int cnthzn2 = 0;
int cntvtc1 = 0;
int cntvtc2 = 0;
int cntcrs1 = 0;
int cntcrs2 = 0;
int noticer;
int gmboard[7][7] = { 0 }; //������
int gmboard1[4][4] = { 0 }; //������ 2��и�
int gmboard2[4][4] = { 0 }; //������ 1��и�
int gmboard3[4][4] = { 0 }; //������ 3��и�
int gmboard4[4][4] = { 0 }; //������ 4��и�
int rgmboard1[4][4] = { 0 }; //������ 2��и�
int rgmboard2[4][4] = { 0 }; //������ 1��и�
int rgmboard3[4][4] = { 0 }; //������ 3��и�
int rgmboard4[4][4] = { 0 }; //������ 4��и�
int gmboard5[3][3] = { 0 };
int gmboard6[3][3] = { 0 };
int gmboard7[3][3] = { 0 };
int gmboard8[3][3] = { 0 };
int gmboard9[3][3] = { 0 };
int rgmboard5[4][4] = { 0 };
int rgmboard6[4][4] = { 0 };
int rgmboard7[4][4] = { 0 };
int rgmboard8[4][4] = { 0 };
int rgmboard9[4][4] = { 0 };

int x, y; //��ǥ �Է�
int i, j, k, o, a, b, c, d, e; //�ݺ��� ����
int switint; //����ġ ��и� ���� ����
char switchar; //����ġ ���� ���� ����
int m, n; //��ɺ���
int turn = 1; //������ ������ ���
char ch;
int axi = 0;
int mode = 1;
int you; 

void rotate();
int input(int turn);
void output();
int decidegameset();
int setarray1();
int setarray2();
void gotoxy(int x, int y);
void cleanhelper();
void rotatedif();
int setarray1dif();
int setarray2dif();

int main() {

	system("title Pentago Game Program");
	system("color 7f");
	system("mode con cols=123 lines=25");

	Sleep(100);
	system("color 7f");
	Sleep(100);
	system("color 6f");
	Sleep(100);
	system("color 5f");
	Sleep(100);
	system("color 4f");
	Sleep(100);
	system("color 3f");
	Sleep(100);
	system("color 2f");
	Sleep(100);
	system("color 1f");
	Sleep(100);
	system("color 9f");
	Sleep(100);
	system("color 8f");
	system("color 0c");
	printf("#####		########	  ####	       #         ##########		   ## 		  #####		    ####\n");
	printf("##   ##		##		  ##  ##       #	     ###	         ####            #   ##	       	   #    #\n");
	printf("##   ##		##		  ##   ##      #	      #		 	## ##	        #     #	   	   #    #\n");
	printf("##   ##		##		  ##    ##     #              #	  	       ##  ##	        #     #	     	   #	#\n");
	printf("#####		#######		  ##     ##    #	      #		      ##   ##	        #		   #	#\n");
	printf("####		#######		  ##      ##   #	      #	       	     ########	        #    ###           #    #\n");
	printf("##		##		  ##       ##  #	      #		    ##     ##		#     #	           #    #\n");
	printf("##		##		  ##        ## #	      #		   ##      ##	        #     #	           #    #\n");
	printf("##		##		  ##         ###	      #	      	  ##	   ##	         #    #	           #    #\n");
	printf("##		########	  ##         ###	      #		 ##	   ##	          #####		    ####\n");
	for (j = 16;j <= 24;j++) {
		gotoxy(0, j);
		system("color 0f");
		printf("**************************************************************************************************************************");
	}
	while (1) {
		ch = _kbhit();
		if (ch == 0) {
			gotoxy(42, 13);
			system("color 0a");
			printf("press space bar twice to start easy mode");
			Sleep(500);
			gotoxy(48, 14);
			system("color 0f");
			Sleep(500);
			gotoxy(48, 14);
			system("color 0d");
			Sleep(500);
			gotoxy(48, 14);
			system("color 0b");
			Sleep(500);
			gotoxy(48, 14);
			system("color 0c");
			Sleep(500);
			gotoxy(48, 14);
			system("color 0e");
			Sleep(500);
			gotoxy(48, 15);
			system("color 0f");
		}
		else {
			Sleep(100);
			system("color 7f");
			Sleep(100);
			system("color 6f");
			Sleep(100);
			system("color 5f");
			Sleep(100);
			system("color 4f");
			Sleep(100);
			system("color 3f");
			Sleep(100);
			system("cls");
			break;
		}
	}

	gotoxy(50, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("���� ����!");
	gotoxy(50, 4);
	printf("");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	Sleep(2000);
	system("cls");
	gotoxy(0, 15);

	printf("1. (x�� ��ǥ y�� ��ǥ) �������� ��ǥ�� �Է��Ѵ�.\n");

	printf("2. ���ڸ� ���� �Ŀ� 1���� 4������ ���ڸ� �Է��� ������ �ϳ��� ���ϰ� R �Ǵ� L�� �Է��� �ð���� �Ǵ� �ݴ�������� 90�� ������. �̶� ���ڸ� ���� ���� �������� ���� ���� �ִ�. \n");

	printf("(��, ������, ��������, ���ʾƷ�, �����ʾƷ��� ���� 1, 2, 3, 4�����ǿ� �ش��Ѵ�)\n");

	printf("3. ���� �ټ� ���� ���ڸ� �������� ������ ���� ����� �̱��.\n");

	printf("4. �� ���� ���̳� ��, �Ǵ� �밢���� �� �� �ְ� ������ �ΰ� �Ǵ� ������ ���� ���� �� �ִ�.\n");

	printf("5. �ѻ���� ���ڸ� ���� �� �ټ����� �������Ǹ� �̶��� �������� ���� �ʿ䰡 ����.\n");

	printf("6. �� ���� �� ���� �� ����� ���� �ټ����� ������ �����Ǹ� ���� ����.\n");

	printf("7. ���� ��� ���ڸ� �� ���������� ������ ���� �ټ����� ������ �ǰ� �������ϸ� ���� ���� ����. \n");
	while(1){
	for (o = 1;;o++) {
	switch(mode){
	
	case 1:
		{
		gotoxy(52, 0);
		printf("�Ǧ���������������������");
		gotoxy(52, 1);
		printf("��          ��");
		gotoxy(52, 2);
		printf("�Ŧ���������������������");
		gotoxy(79, 1);
		printf("�Ǧ�����������������������������������������");
		gotoxy(79, 2);
		printf("��                    ��");
		gotoxy(79, 3);
		printf("�Ŧ�����������������������������������������");
		gotoxy(0, 14);
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		gotoxy(54, 1);
		printf("%d��° ��\n", o);
		void cleanhelper();
		output();
		void cleanhelper();
		if (o % 2 != 0) {
			turn = 1;
			gotoxy(83, 2);
			printf("�÷��̾� %d�� ��", turn);
			input(turn);
		}
		else {
			turn = 2;
			gotoxy(83, 2);
			printf("�÷��̾� %d�� ��", turn);
			input(turn);
		}
		void cleanhelper();
		output();
		void cleanhelper();

			setarray1();

			rotate();

		void cleanhelper();

			setarray1();

			setarray2();

		void cleanhelper();
		output();
		void cleanhelper();
		if (decidegameset() == 1)
		{
			printf("�÷��̾� 1�� �¸��Դϴ�!\n");
			printf("start hard mode?, Press Y to start hard mode and Press any key without Y to exit.\n");
			scanf("%c", &you);
			if (((you == 'Y') || (you == 'y'))&&(mode==1)) {
				mode = 2;
				system("cls");
			}
			else return 0;
		}
		else if (decidegameset() == 2) {
			printf("�÷��̾� 2�� �¸��Դϴ�!\n");
			printf("start hard mode?, Press Y to start hard mode and Press any key without Y to exit.\n");
			scanf("%c", &you);
			if (((you == 'Y') || (you == 'y'))&&(mode==1)) {
				mode = 2;
				system("cls");
			}
			else return 0;
		}
		else if (decidegameset() == 3) {
			printf("��.��.��.");
			return 0;
		}
		else continue;
	}

	case 2:
		{
			gotoxy(0, 15);

	printf("1. (x�� ��ǥ y�� ��ǥ) �������� ��ǥ�� �Է��Ѵ�.\n");

	printf("2. ���ڸ� ���� �Ŀ� 1���� 9������ ���ڸ� �Է��� ������ �ϳ��� ���ϰ� R �Ǵ� L�� �Է��� �ð���� �Ǵ� �ݴ�������� 90�� ������. �̶� ���ڸ� ���� ���� �������� ���� ���� �ִ�. \n");

	printf("(��, Ű�е� �������� 1, 2, 3, 4, 5, 6, 7, 8, 9 �����ǿ� �ش��Ѵ�)\n");

	printf("3. ���� �ټ� ���� ���ڸ� �������� ������ ���� ����� �̱��.\n");

	printf("4. �� ���� ���̳� ��, �Ǵ� �밢���� �� �� �ְ� ������ �ΰ� �Ǵ� ������ ���� ���� �� �ִ�.\n");

	printf("5. �ѻ���� ���ڸ� ���� �� �ټ����� �������Ǹ� �̶��� �������� ���� �ʿ䰡 ����.\n");

	printf("6. �� ���� �� ���� �� ����� ���� �ټ����� ������ �����Ǹ� ���� ����.\n");

	printf("7. ���� ��� ���ڸ� �� ���������� ������ ���� �ټ����� ������ �ǰ� �������ϸ� ���� ���� ����. \n");
		gotoxy(52, 0);
		printf("�Ǧ���������������������");
		gotoxy(52, 1);
		printf("��          ��");
		gotoxy(52, 2);
		printf("�Ŧ���������������������");
		gotoxy(79, 1);
		printf("�Ǧ�����������������������������������������");
		gotoxy(79, 2);
		printf("��                    ��");
		gotoxy(79, 3);
		printf("�Ŧ�����������������������������������������");
		gotoxy(0, 14);
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		gotoxy(54, 1);
		printf("%d��° ��\n", o);
		void cleanhelper();
		output();
		void cleanhelper();
		if (o % 2 != 0) {
			turn = 1;
			gotoxy(83, 2);
			printf("�÷��̾� %d�� ��", turn);
			input(turn);
		}
		else {
			turn = 2;
			gotoxy(83, 2);
			printf("�÷��̾� %d�� ��", turn);
			input(turn);
		}
		void cleanhelper();
		output();
		void cleanhelper();

			setarray1dif();

			rotatedif();

		void cleanhelper();

			setarray1dif();

			setarray2dif();

		void cleanhelper();
		output();
		void cleanhelper();
		if (decidegameset() == 1)
		{
			printf("�÷��̾� 1�� �¸��Դϴ�!\n");
			return 0;
		}
		else if (decidegameset() == 2) {
			printf("�÷��̾� 2�� �¸��Դϴ�!\n");
			return 0;
		}
		else if (decidegameset() == 3) {
			printf("��.��.��.");
			return 0;
		}
		else continue;
	}	
}
}
}
}

void rotate() {
	gotoxy(80, 5);
	printf("4���� �ǳ� �� ���� ���� �����ϰ�,");
	gotoxy(80, 6);
	printf("���� ������ �����ϼ���.");
	gotoxy(80, 7);
	printf("���� ������ ���� ȸ���� L �Ǵ� l, ");
	gotoxy(80, 8);
	printf("������ ȸ���� R �Ǵ� r�� �Է��ϸ� �˴ϴ�.");
	gotoxy(60, 8);
	printf("              ");
	gotoxy(60, 8);
	scanf("%d %c", &switint, &switchar);
	gotoxy(80, 5);
	printf("                                         ");
	gotoxy(80, 6);
	printf("                                         ");
	gotoxy(80, 7);
	printf("                                            ");
	gotoxy(80, 8);
	printf("                                            ");
	switch (switint)
	{
	case 1:
	{
		noticer = 1;
		if ((switchar == 'L') || (switchar == 'l')) {
			rgmboard1[1][1] = gmboard1[1][3];
			rgmboard1[2][2] = gmboard1[2][2];
			rgmboard1[1][2] = gmboard1[2][3];
			rgmboard1[1][3] = gmboard1[3][3];
			rgmboard1[2][1] = gmboard1[1][2];
			rgmboard1[2][3] = gmboard1[3][2];
			rgmboard1[3][1] = gmboard1[1][1];
			rgmboard1[3][2] = gmboard1[2][1];
			rgmboard1[3][3] = gmboard1[3][1];
		}
		else if ((switchar == 'R') || (switchar == 'r')) {
			rgmboard1[1][1] = gmboard1[3][1];
			rgmboard1[2][2] = gmboard1[2][2];
			rgmboard1[1][2] = gmboard1[2][1];
			rgmboard1[1][3] = gmboard1[1][1];
			rgmboard1[2][1] = gmboard1[3][2];
			rgmboard1[2][3] = gmboard1[1][2];
			rgmboard1[3][1] = gmboard1[3][3];
			rgmboard1[3][2] = gmboard1[2][3];
			rgmboard1[3][3] = gmboard1[1][3];
		}
		else {
			gotoxy(80, 5);
			printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
			Sleep(2000);
			gotoxy(80, 5);
			printf("                         ");
			gotoxy(80, 6);
			printf("                         ");
			gotoxy(80, 7);
			printf("                         ");
			gotoxy(80, 8);
			printf("                         ");
			rotate();
		}
		break;
	}
	case 2:
	{
		noticer = 2;
		if ((switchar == 'L') || (switchar == 'l')) {
			rgmboard2[1][1] = gmboard2[1][3];
			rgmboard2[2][2] = gmboard2[2][2];
			rgmboard2[1][2] = gmboard2[2][3];
			rgmboard2[1][3] = gmboard2[3][3];
			rgmboard2[2][1] = gmboard2[1][2];
			rgmboard2[2][3] = gmboard2[3][2];
			rgmboard2[3][1] = gmboard2[1][1];
			rgmboard2[3][2] = gmboard2[2][1];
			rgmboard2[3][3] = gmboard2[3][1];
		}
		else if ((switchar == 'R') || (switchar == 'r')) {
			rgmboard2[1][1] = gmboard2[3][1];
			rgmboard2[2][2] = gmboard2[2][2];
			rgmboard2[1][2] = gmboard2[2][1];
			rgmboard2[1][3] = gmboard2[1][1];
			rgmboard2[2][1] = gmboard2[3][2];
			rgmboard2[2][3] = gmboard2[1][2];
			rgmboard2[3][1] = gmboard2[3][3];
			rgmboard2[3][2] = gmboard2[2][3];
			rgmboard2[3][3] = gmboard2[1][3];
		}
		else {
			gotoxy(80, 5);
			printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
			Sleep(2000);
			gotoxy(80, 5);
			printf("                         ");
			gotoxy(80, 6);
			printf("                         ");
			gotoxy(80, 7);
			printf("                         ");
			gotoxy(80, 8);
			printf("                         ");
			rotate();
		}
		break;
	}
	case 3:
	{
		noticer = 3;
		if ((switchar == 'L') || (switchar == 'l')) {
			rgmboard3[1][1] = gmboard3[1][3];
			rgmboard3[2][2] = gmboard3[2][2];
			rgmboard3[1][2] = gmboard3[2][3];
			rgmboard3[1][3] = gmboard3[3][3];
			rgmboard3[2][1] = gmboard3[1][2];
			rgmboard3[2][3] = gmboard3[3][2];
			rgmboard3[3][1] = gmboard3[1][1];
			rgmboard3[3][2] = gmboard3[2][1];
			rgmboard3[3][3] = gmboard3[3][1];
		}
		else if ((switchar == 'R') || (switchar == 'r')) {
			rgmboard3[1][1] = gmboard3[3][1];
			rgmboard3[2][2] = gmboard3[2][2];
			rgmboard3[1][2] = gmboard3[2][1];
			rgmboard3[1][3] = gmboard3[1][1];
			rgmboard3[2][1] = gmboard3[3][2];
			rgmboard3[2][3] = gmboard3[1][2];
			rgmboard3[3][1] = gmboard3[3][3];
			rgmboard3[3][2] = gmboard3[2][3];
			rgmboard3[3][3] = gmboard3[1][3];
		}
		else {
			gotoxy(80, 5);
			printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
			Sleep(2000);
			gotoxy(80, 5);
			printf("                         ");
			gotoxy(80, 6);
			printf("                         ");
			gotoxy(80, 7);
			printf("                         ");
			gotoxy(80, 8);
			printf("                         ");
			rotate();
		}
		break;
	}
	case 4:
		noticer = 4;
		{
			if ((switchar == 'L') || (switchar == 'l')) {
				rgmboard4[1][1] = gmboard4[1][3];
				rgmboard4[2][2] = gmboard4[2][2];
				rgmboard4[1][2] = gmboard4[2][3];
				rgmboard4[1][3] = gmboard4[3][3];
				rgmboard4[2][1] = gmboard4[1][2];
				rgmboard4[2][3] = gmboard4[3][2];
				rgmboard4[3][1] = gmboard4[1][1];
				rgmboard4[3][2] = gmboard4[2][1];
				rgmboard4[3][3] = gmboard4[3][1];
			}
			else if ((switchar == 'R') || (switchar == 'r')) {
				rgmboard4[1][1] = gmboard4[3][1];
				rgmboard4[2][2] = gmboard4[2][2];
				rgmboard4[1][2] = gmboard4[2][1];
				rgmboard4[1][3] = gmboard4[1][1];
				rgmboard4[2][1] = gmboard4[3][2];
				rgmboard4[2][3] = gmboard4[1][2];
				rgmboard4[3][1] = gmboard4[3][3];
				rgmboard4[3][2] = gmboard4[2][3];
				rgmboard4[3][3] = gmboard4[1][3];
			}
			else {
				gotoxy(80, 5);
				printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
				Sleep(2000);
				gotoxy(80, 5);
				printf("                         ");
				gotoxy(80, 6);
				printf("                         ");
				gotoxy(80, 7);
				printf("                         ");
				gotoxy(80, 8);
				printf("                         ");
				rotate();
			}
			break;
		}
	default:
	{
		gotoxy(80, 5);
		printf("1~4������ ���� �Է��ϼ���.");
		Sleep(2000);
		gotoxy(80, 5);
		printf("                         ");
		gotoxy(80, 6);
		printf("                         ");
		gotoxy(80, 7);
		printf("                         ");
		gotoxy(80, 8);
		printf("                         ");
		rotate();
	}
	}
}
int input(int turn) {
	gotoxy(80, 5);
	printf("���� ���� ��ǥ�� �Է��ϼ���.");
	x = 0;
	y = 0;
	gotoxy(60, 8);
	printf("              ");
	gotoxy(60, 8);
	scanf("%d %d", &x, &y);
	if ((gmboard[y][x] == 0) && (x <= 6) && (y <= 6) && (x > 0) && (y > 0)) {
		if (turn == 1) {
			gmboard[y][x] = 1;
			return 0;
		}
		if (turn == 2) {
			gmboard[y][x] = 2;
			return 0;
		}
	}
	else {
		gotoxy(80, 5);
		printf("���� �� �ִ� ���� �ƴմϴ�.");
		gotoxy(80, 6);
		printf("�ٸ� ���� �����ϼ���.");
		Sleep(2000);
		gotoxy(80, 5);
		printf("                              ");
		gotoxy(80, 6);
		printf("                         ");
		gotoxy(80, 7);
		printf("                         ");
		gotoxy(80, 8);
		printf("                         ");
		input(turn);
	}
}
void output() {
	gotoxy(13, 5);
	for (i = 1;i <= 6;i++) {
		for (j = 1;j <= 6;j++) {
			if (gmboard[i][j] == 0) printf("�� ");
			else if (gmboard[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("�� ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				printf("�� ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
		}
		gotoxy(13, 5 + i);
	}
	printf("\n");
}
int decidegameset() {

	cnthzn1 = 0;
	cnthzn2 = 0;
	cntvtc1 = 0;
	cntvtc2 = 0;
	cntcrs1 = 0;
	cntcrs2 = 0;

	for (i = 1;i <= 6;i++) {
		m = gmboard[i][1];
		for (j = 2;j <= 6;j++) {
			if ((gmboard[i][j] == m) && (m == 1)) cnthzn1++;
			else if ((gmboard[i][j] == m) && (m == 2)) cnthzn2++;
			else if (gmboard[i][j] != m) {
				if ((cnthzn1 != 4)) {
					m = gmboard[i][j];
					cnthzn1 = 0;
				}
				else if (cnthzn2 != 4) {
					m = gmboard[i][j];
					cnthzn2 = 0;
				}
			}
		}
		if (cnthzn1 == 4) break;
		else if (cnthzn2 == 4) break;
	}

	for (j = 1;j <= 6;j++) {
		m = gmboard[1][j];
		for (i = 2;i <= 6;i++) {
			if ((gmboard[i][j] == m) && (m == 1)) cntvtc1++;
			else if ((gmboard[i][j] == m) && (m == 2)) cntvtc2++;
			else if (gmboard[i][j] != m) {
				if ((cntvtc1 != 4)) {
					m = gmboard[i][j];
					cntvtc1 = 0;
				}
				else if (cntvtc2 != 4) {
					m = gmboard[i][j];
					cntvtc2 = 0;
				}
			}
		}
		if (cntvtc1 == 4) break;
		else if (cntvtc2 == 4) break;
	}

	m = gmboard[2][1];
	for (i = 2;i <= 6;i++) {
		m *= gmboard[i][i - 1];
	}
	if (m == 1) cntcrs1 = 4;
	else if (m == 64) cntcrs2 = 4;

	m = gmboard[1][2];
	for (i = 1;i <= 5;i++) {
		m *= gmboard[i][i + 1];
	}
	if (m == 1) cntcrs1 = 4;
	else if (m == 64) cntcrs2 = 4;

	m = gmboard[6][5];
	for (i = 6;i >= 2;i--) {
		m *= gmboard[i][i - 1];
	}
	if (m == 1) cntcrs1 = 4;
	else if (m == 64) cntcrs2 = 4;

	m = gmboard[5][6];
	for (i = 5;i >= 1;i--) {
		m *= gmboard[i][i + 1];
	}
	if (m == 1) cntcrs1 = 4;
	else if (m == 64) cntcrs2 = 4;

	m = gmboard[1][1];
	for (i = 1;i <= 5;i++) {
		m *= gmboard[i][i];
	}
	if ((m == 1) && (gmboard[6][6] != 1)) cntcrs1 = 4;
	else if ((m == 64) && (gmboard[6][6] != 2)) cntcrs2 = 4;

	m = gmboard[2][2];
	for (i = 2;i <= 6;i++) {
		m *= gmboard[i][i];
	}
	if ((m == 1) && (gmboard[1][1] != 1)) cntcrs1 = 4;
	else if ((m == 64) && (gmboard[1][1] != 2)) cntcrs2 = 4;

	m = gmboard[1][6];
	for (i = 1;i <= 5;i++) {
		m *= gmboard[i][7 - i];
	}
	if ((m == 1) && (gmboard[6][1] != 1)) cntcrs1 = 4;
	else if ((m == 64) && (gmboard[6][1] != 2)) cntcrs2 = 4;

	m = gmboard[6][1];
	for (i = 1;i <= 5;i++) {
		m *= gmboard[7 - i][i];
	}
	if ((m == 1) && (gmboard[1][6] != 1)) cntcrs1 = 4;
	else if ((m == 64) && (gmboard[1][6] != 2)) cntcrs2 = 4;

	axi = 0;
	for (i = 1;i <= 6;i++) {
		for (j = 1;j <= 6;j++) {
			if (gmboard[i][j] == 0) axi++;
		}
	}

	if (((cnthzn1 == 4) || (cntvtc1 == 4) || (cntcrs1 == 4)) && ((cnthzn2 != 4) && (cntvtc2 != 4) && (cntcrs2 != 4))) { return 1; }
	else if (((cnthzn1 != 4) && (cntvtc1 != 4) && (cntcrs1 != 4)) && ((cnthzn2 == 4) || (cntvtc2 == 4) || (cntcrs2 == 4))) { return 2; }
	else if (((cnthzn1 == 4) || (cntvtc1 == 4) || (cntcrs1 == 4)) && ((cnthzn2 == 4) || (cntvtc2 == 4) || (cntcrs2 == 4))) { return 3; }
	else if (axi == 0) return 3;
	else { return 0; }

}

int setarray1() {
	for (i = 1;i <= 3;i++) {
		for (j = 1;j <= 3;j++) {
			gmboard1[i][j] = gmboard[i][j];
			gmboard2[i][j] = gmboard[i][j + 3];
			gmboard3[i][j] = gmboard[i + 3][j];
			gmboard4[i][j] = gmboard[i + 3][j + 3];
		}
	}
	return 0;
}
int setarray2() {
	for (i = 1;i <= 3;i++) {
		for (j = 1;j <= 3;j++) {
			if (noticer == 1)
				gmboard[i][j] = rgmboard1[i][j];
			if (noticer == 2)
				gmboard[i][j + 3] = rgmboard2[i][j];
			if (noticer == 3)
				gmboard[i + 3][j] = rgmboard3[i][j];
			if (noticer == 4)
				gmboard[i + 3][j + 3] = rgmboard4[i][j];
		}
	}
	return 0;
}

void cleanhelper() {
	gotoxy(80, 5);
	printf("                          		                              ");
	gotoxy(80, 6);
	printf("                            				                ");
	gotoxy(80, 7);
	printf("                               		                       ");
	gotoxy(80, 8);
	printf("              		                                   ");
	gotoxy(60, 8);
	printf("              		                                   ");
}

void gotoxy(int x, int y){
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void rotatedif() {
	gotoxy(80, 5);
	printf("9���� �ǳ� �� ���� ���� �����ϰ�,");
	gotoxy(80, 6);
	printf("���� ������ �����ϼ���.");
	gotoxy(80, 7);
	printf("���� ������ ���� ȸ���� L �Ǵ� l, ");
	gotoxy(80, 8);
	printf("������ ȸ���� R �Ǵ� r�� �Է��ϸ� �˴ϴ�.");
	gotoxy(60, 8);
	printf("              ");
	gotoxy(60, 8);
	scanf("%d %c", &switint, &switchar);
	gotoxy(80, 5);
	printf("                                         ");
	gotoxy(80, 6);
	printf("                                         ");
	gotoxy(80, 7);
	printf("                                            ");
	gotoxy(80, 8);
	printf("                                            ");
	switch (switint)
	{
	case 1:
	{
		noticer = 1;
		if ((switchar == 'L') || (switchar == 'l')) {
			rgmboard1[1][1] = gmboard1[1][2];
			rgmboard1[1][2] = gmboard1[2][2];
			rgmboard1[2][1] = gmboard1[1][1];
			rgmboard1[2][2] = gmboard1[2][1];
		}
		else if ((switchar == 'R') || (switchar == 'r')) {
			rgmboard1[1][1] = gmboard1[2][1];
			rgmboard1[1][2] = gmboard1[1][1];
			rgmboard1[2][1] = gmboard1[2][2];
			rgmboard1[2][2] = gmboard1[1][2];
		}
		else {
			gotoxy(80, 5);
			printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
			Sleep(2000);
			gotoxy(80, 5);
			printf("                         ");
			gotoxy(80, 6);
			printf("                         ");
			gotoxy(80, 7);
			printf("                         ");
			gotoxy(80, 8);
			printf("                         ");
			rotate();
		}
		break;
	}
	case 2:
	{
		noticer = 2;
		if ((switchar == 'L') || (switchar == 'l')) {
			rgmboard2[1][1] = gmboard2[1][2];
			rgmboard2[1][2] = gmboard2[2][2];
			rgmboard2[2][1] = gmboard2[1][1];
			rgmboard2[2][2] = gmboard2[2][1];
		}
		else if ((switchar == 'R') || (switchar == 'r')) {
			rgmboard2[1][1] = gmboard2[2][1];
			rgmboard2[1][2] = gmboard2[1][1];
			rgmboard2[2][1] = gmboard2[2][2];
			rgmboard2[2][2] = gmboard2[1][2];
		}
		else {
			gotoxy(80, 5);
			printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
			Sleep(2000);
			gotoxy(80, 5);
			printf("                         ");
			gotoxy(80, 6);
			printf("                         ");
			gotoxy(80, 7);
			printf("                         ");
			gotoxy(80, 8);
			printf("                         ");
			rotate();
		}
		break;
	}
	case 3:
	{
		noticer = 3;
		if ((switchar == 'L') || (switchar == 'l')) {
			rgmboard3[1][1] = gmboard3[1][2];
			rgmboard3[1][2] = gmboard3[2][2];
			rgmboard3[2][1] = gmboard3[1][1];
			rgmboard3[2][2] = gmboard3[2][1];
		}
		else if ((switchar == 'R') || (switchar == 'r')) {
			rgmboard3[1][1] = gmboard3[2][1];
			rgmboard3[1][2] = gmboard3[1][1];
			rgmboard3[2][1] = gmboard3[2][2];
			rgmboard3[2][2] = gmboard3[1][2];
		}
		else {
			gotoxy(80, 5);
			printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
			Sleep(2000);
			gotoxy(80, 5);
			printf("                         ");
			gotoxy(80, 6);
			printf("                         ");
			gotoxy(80, 7);
			printf("                         ");
			gotoxy(80, 8);
			printf("                         ");
			rotate();
		}
		break;
	}
	case 4:
		noticer = 4;
		{
			if ((switchar == 'L') || (switchar == 'l')) {
				rgmboard4[1][1] = gmboard4[1][2];
				rgmboard4[1][2] = gmboard4[2][2];
				rgmboard4[2][1] = gmboard4[1][1];
				rgmboard4[2][2] = gmboard4[2][1];
			}
			else if ((switchar == 'R') || (switchar == 'r')) {
				rgmboard4[1][1] = gmboard4[2][1];
				rgmboard4[1][2] = gmboard4[1][1];
				rgmboard4[2][1] = gmboard4[2][2];
				rgmboard4[2][2] = gmboard4[1][2];
			}
			else {
				gotoxy(80, 5);
				printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
				Sleep(2000);
				gotoxy(80, 5);
				printf("                         ");
				gotoxy(80, 6);
				printf("                         ");
				gotoxy(80, 7);
				printf("                         ");
				gotoxy(80, 8);
				printf("                         ");
				rotate();
			}
			break;
		}
	case 5:
		noticer = 5;
		{
			if ((switchar == 'L') || (switchar == 'l')) {
				rgmboard5[1][1] = gmboard5[1][2];
				rgmboard5[1][2] = gmboard5[2][2];
				rgmboard5[2][1] = gmboard5[1][1];
				rgmboard5[2][2] = gmboard5[2][1];
			}
			else if ((switchar == 'R') || (switchar == 'r')) {
				rgmboard5[1][1] = gmboard5[2][1];
				rgmboard5[1][2] = gmboard5[1][1];
				rgmboard5[2][1] = gmboard5[2][2];
				rgmboard5[2][2] = gmboard5[1][2];
			}
			else {
				gotoxy(80, 5);
				printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
				Sleep(2000);
				gotoxy(80, 5);
				printf("                         ");
				gotoxy(80, 6);
				printf("                         ");
				gotoxy(80, 7);
				printf("                         ");
				gotoxy(80, 8);
				printf("                         ");
				rotate();
			}
			break;
		}
	case 6:
		noticer = 6;
		{
			if ((switchar == 'L') || (switchar == 'l')) {
				rgmboard6[1][1] = gmboard6[1][2];
				rgmboard6[1][2] = gmboard6[2][2];
				rgmboard6[2][1] = gmboard6[1][1];
				rgmboard6[2][2] = gmboard6[2][1];
			}
			else if ((switchar == 'R') || (switchar == 'r')) {
				rgmboard6[1][1] = gmboard6[2][1];
				rgmboard6[1][2] = gmboard6[1][1];
				rgmboard6[2][1] = gmboard6[2][2];
				rgmboard6[2][2] = gmboard6[1][2];
			}
			else {
				gotoxy(80, 5);
				printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
				Sleep(2000);
				gotoxy(80, 5);
				printf("                         ");
				gotoxy(80, 6);
				printf("                         ");
				gotoxy(80, 7);
				printf("                         ");
				gotoxy(80, 8);
				printf("                         ");
				rotate();
			}
			break;
		}
	case 7:
		noticer = 7;
		{
			if ((switchar == 'L') || (switchar == 'l')) {
				rgmboard7[1][1] = gmboard7[1][2];
				rgmboard7[1][2] = gmboard7[2][2];
				rgmboard7[2][1] = gmboard7[1][1];
				rgmboard7[2][2] = gmboard7[2][1];
			}
			else if ((switchar == 'R') || (switchar == 'r')) {
				rgmboard7[1][1] = gmboard7[2][1];
				rgmboard7[1][2] = gmboard7[1][1];
				rgmboard7[2][1] = gmboard7[2][2];
				rgmboard7[2][2] = gmboard7[1][2];
			}
			else {
				gotoxy(80, 5);
				printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
				Sleep(2000);
				gotoxy(80, 5);
				printf("                         ");
				gotoxy(80, 6);
				printf("                         ");
				gotoxy(80, 7);
				printf("                         ");
				gotoxy(80, 8);
				printf("                         ");
				rotate();
			}
			break;
		}
	case 8:
		noticer = 8;
		{
			if ((switchar == 'L') || (switchar == 'l')) {
				rgmboard8[1][1] = gmboard8[1][2];
				rgmboard8[1][2] = gmboard8[2][2];
				rgmboard8[2][1] = gmboard8[1][1];
				rgmboard8[2][2] = gmboard8[2][1];
			}
			else if ((switchar == 'R') || (switchar == 'r')) {
				rgmboard8[1][1] = gmboard8[2][1];
				rgmboard8[1][2] = gmboard8[1][1];
				rgmboard8[2][1] = gmboard8[2][2];
				rgmboard8[2][2] = gmboard8[1][2];
			}
			else {
				gotoxy(80, 5);
				printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
				Sleep(2000);
				gotoxy(80, 5);
				printf("                         ");
				gotoxy(80, 6);
				printf("                         ");
				gotoxy(80, 7);
				printf("                         ");
				gotoxy(80, 8);
				printf("                         ");
				rotate();
			}
			break;
		}
	case 9:
		noticer = 9;
		{
			if ((switchar == 'L') || (switchar == 'l')) {
				rgmboard9[1][1] = gmboard9[1][2];
				rgmboard9[1][2] = gmboard9[2][2];
				rgmboard9[2][1] = gmboard9[1][1];
				rgmboard9[2][2] = gmboard9[2][1];
			}
			else if ((switchar == 'R') || (switchar == 'r')) {
				rgmboard9[1][1] = gmboard9[2][1];
				rgmboard9[1][2] = gmboard9[1][1];
				rgmboard9[2][1] = gmboard9[2][2];
				rgmboard9[2][2] = gmboard9[1][2];
			}
			else {
				gotoxy(80, 5);
				printf("R, L, r, l �߿� �ϳ��� �Է��ϼ���.\n");
				Sleep(2000);
				gotoxy(80, 5);
				printf("                         ");
				gotoxy(80, 6);
				printf("                         ");
				gotoxy(80, 7);
				printf("                         ");
				gotoxy(80, 8);
				printf("                         ");
				rotate();
			}
			break;
		}
	default:
	{
		gotoxy(80, 5);
		printf("1~9������ ���� �Է��ϼ���.");
		Sleep(2000);
		gotoxy(80, 5);
		printf("                         ");
		gotoxy(80, 6);
		printf("                         ");
		gotoxy(80, 7);
		printf("                         ");
		gotoxy(80, 8);
		printf("                         ");
		rotate();
	}
	}
}
int setarray1dif() {
	for (i = 1;i <= 2;i++) {
		for (j = 1;j <= 2;j++) {
			gmboard1[i][j] = gmboard[i][j];
			gmboard2[i][j] = gmboard[i][j + 2];
			gmboard3[i][j] = gmboard[i][j + 4];
			gmboard4[i][j] = gmboard[i + 2][j];
			gmboard5[i][j] = gmboard[i + 2][j + 2];
			gmboard6[i][j] = gmboard[i + 2][j + 4];
			gmboard7[i][j] = gmboard[i + 4][j];
			gmboard8[i][j] = gmboard[i + 4][j + 2];
			gmboard9[i][j] = gmboard[i + 4][j + 4];
		}
	}
	return 0;
}
int setarray2dif() {
	for (i = 1;i <= 2;i++) {
		for (j = 1;j <= 2;j++) {
			if (noticer == 1)
				gmboard[i][j] = rgmboard1[i][j];
			if (noticer == 2)
				gmboard[i][j + 2] = rgmboard2[i][j];
			if (noticer == 3)
				gmboard[i][j + 4] = rgmboard3[i][j];
			if (noticer == 4)
				gmboard[i + 2][j] = rgmboard4[i][j];
			if (noticer == 5)
				gmboard[i + 2][j + 2] = rgmboard5[i][j];
			if (noticer == 6)
				gmboard[i + 2][j + 4] = rgmboard6[i][j];
			if (noticer == 7)
				gmboard[i + 4][j] = rgmboard7[i][j];
			if (noticer == 8)
				gmboard[i + 4][j + 2] = rgmboard8[i][j];
			if (noticer == 9)
				gmboard[i + 4][j + 4] = rgmboard9[i][j];
		}
	}
}

