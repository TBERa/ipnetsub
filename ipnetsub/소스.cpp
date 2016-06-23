#include <iostream>
#include <conio.h>
#include<stdlib.h>
#include "hd.h"
#include "out.h"

#pragma warning(disable:4996)
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int netadd(void);
int subnetting(unsigned int, unsigned int);


int main(void) {

	netadd();

	getchar();



	return 0;
}




int netadd(void)
{
	unsigned int ip, msk, brd = 0;
	int subb = 0;
	int ma = 0;
	ip = ipinput();
	msk = subnetinput();

	printf("�Է��� ip \n");
	printbin(ip);

	printf("����� ����ũ \n");
	ma = tmask(msk);
	printbin(msk);
	
	printf("��Ʈ��ũ �ּ� \n");
	printf("%d.%d.%d.%d\n", ipA((ip&msk)), ipB((ip&msk)), ipC((ip&msk)),ipD((ip&msk)));
	printbin(ip&msk);

	if (ma == 99)
	{

		return 0;
	}


	printf("��ε�ĳ��Ʈ �ּ� \n");

	brd = broadcast((ip&msk), ma);
	printf("%d.%d.%d.%d\n", ipA(brd), ipB(brd), ipC(brd), ipD(brd));


	printbin(brd);

	subnetting(msk, ip);

	return 0;
}

int subnetting(unsigned int msk, unsigned int ip)
{
	int subb,ma = 0;
	int loopA = 0;
	unsigned int  md = 0;
	unsigned int msk2 = msk;
	printf("����� ��Ʈ�� �Է� : ");
	scanf("%d", &subb);


	if (subb < 0)
	{
		printf("���۳����� ���� �������� �ʽ��ϴ�\n");
	}
	else if(subb == 0)
	{
		printf("������� �״�� ���\n");
	}
	else
	{
		ma = tmask(msk);
		while (loopA <= subb)
		{
			md = md << 1;
			md = md + 1;
			loopA++;
		}
		md = md << (32 - ma - subb);
		msk2 = msk | md;
		printf("������ ����� ��Ʈ\n");
		printbin(msk2);

	}

	return 0;
}