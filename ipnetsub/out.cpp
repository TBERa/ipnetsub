#include "out.h"
#pragma warning(disable:4996)

int ipA(unsigned int ip)
{
	unsigned int ip2 = ip;
	unsigned int m = 0x0000FF;
	ip2 = ip2 >> 24;
	return (ip2&m);
}
int ipB(unsigned int ip)
{
	unsigned int ip2 = ip;
	unsigned int m = 0x0000FF;
	ip2 = ip2 >> 16;
	return (ip2&m);
}
int ipC(unsigned int ip)
{
	unsigned int ip2 = ip;
	unsigned int m = 0x0000FF;
	ip2 = ip2 >> 8;
	return (ip2&m);
}
int ipD(unsigned int ip)
{
	unsigned int m = 0x0000FF;
	return (ip&m);
}

int printbin(int dec) //2진수 출력 
{
	unsigned int ch = 1;
	unsigned int bf = dec;
	int loopA = 0;
	int loopB = 0;
	int loopi = 31;
	char rev[32] = { 0 };

	while (loopi >= 0)
	{
		rev[loopi] = bf&ch;
		loopi--;
		bf = bf >> 1;
	}

	loopi = 0;

	while (loopB <= 3)
	{
		while (loopA <= 7)
		{

			printf("%d", rev[loopi]);
			loopi++;
			loopA++;
		}
		printf(" ");
		loopB++;
		loopA = 0;
	}
	printf("\n");



	return (0);
}