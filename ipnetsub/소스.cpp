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

	printf("입력한 ip \n");
	if (ip == 0x7F000000)
	{
		return 0;
	}
	printbin(ip);

	printf("서브넷 마스크 \n");
	ma = tmask(msk);
	printbin(msk);
	
	printf("네트워크 주소 \n");
	printf("%d.%d.%d.%d\n", ipA((ip&msk)), ipB((ip&msk)), ipC((ip&msk)),ipD((ip&msk)));
	printbin(ip&msk);

	if (ma == 99)
	{

		return 0;
	}


	printf("브로드캐스트 주소 \n");

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
	int na = 1;
	unsigned int  md = 0;
	unsigned int msk2 = msk;
	unsigned int netid2 = 0;
	unsigned int ip2;
	unsigned int sumip = 1;
	unsigned int ip2b;
	printf("서브넷 비트를 입력 : ");
	scanf("%d", &subb);


	if (subb < 0)
	{
		printf("슈퍼넷팅은 아직 지원하지 않습니다\n");
	}
	else if(subb == 0)
	{
		printf("서브넷을 그대로 사용\n");
	}
	else
	{
		ma = tmask(msk);
		while (loopA < subb)
			{
			md = md << 1;
			md = md + 1;
			na = na << 1;
			loopA++;
			}
		md = md << (32 - ma - subb);
		msk2 = msk | md;
		printf("증가된 서브넷 비트\n");
		printbin(msk2);
		netid2 = ip&msk2;
		printbin(netid2);
		printf("나눠진 네트워크 수 : %d\n", na);
		printf("네트워크 범위 \n");

		loopA = 0;
		ip2 = ip&msk;
		sumip = sumip << (32 - ma - subb);
		while (loopA < na)
			{
				ip2b = broadcast(ip2, tmask(msk2));
				printf("%d. 네트워크 주소 : %d.%d.%d.%d\n", (loopA + 1), ipA(ip2), ipB(ip2), ipC(ip2), ipD(ip2));
				printf("%d. 브로드캐스트 : %d.%d.%d.%d\n", (loopA + 1), ipA(ip2b), ipB(ip2b), ipC(ip2b), ipD(ip2b));
				ip2 = ip2 + sumip;
				loopA++;
			}

		printf("입력한 ip가 속한 네트워크 주소 : %d.%d.%d.%d\n", ipA(netid2), ipB(netid2), ipC(netid2), ipD(netid2));

	}


	return 0;
}