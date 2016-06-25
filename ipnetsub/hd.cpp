#include "hd.h"
#pragma warning(disable:4996)

unsigned int subnetinput()
{
	unsigned int msk = 0;
	unsigned char sba, sbb, sbc, sbd;

	printf("서브넷 마스크 : ");
	scanf("%hhd.%hhd.%hhd.%hhd", &sba,&sbb,&sbc,&sbd);
	msk = sba;
	msk = msk << 8;
	msk = msk | sbb;
	msk = msk << 8;
	msk = msk | sbc;
	msk = msk << 8;
	msk = msk | sbd;

	return msk;

}

unsigned int ipinput()
{
	unsigned char ipa, ipb, ipc, ipd;
	unsigned int ip = 0;
	printf("ip 입력 : ");
	scanf("%hhd.%hhd.%hhd.%hhd", &ipa,&ipb,&ipc,&ipd);
		ip = ipa; 
		ip = ip << 8;
		ip = ip | ipb;
		ip = ip << 8;
		ip = ip | ipc;
		ip = ip << 8;
		ip = ip | ipd;
		if (ipa < 0 | ipb < 0 | ipc < 0 | ipd < 0 | ipa > 255 | ipb > 255 | ipc > 255 | ipd > 255)
		{
			printf("올바르지 않은 아이피 주소");
			return 0x7F000000;
		}

	return ip;
}



unsigned int broadcast(unsigned int netid, int msk)
{
	int loopA = 0;
	unsigned int rt = 0;



	while (loopA <= (31-msk))
	{
		rt = rt << 1;
		rt = rt + 1;
		loopA++;
	}
	rt = netid | rt;

	return rt;
}


int tmask(unsigned int msk) //마스크 1숫자 판별
{
	unsigned int bf = msk;
	unsigned int con = 1;
	int loopA, lon, cdt;
	unsigned int mskb[32] = { 0 };
	loopA = 0;
	lon = 0;
	cdt = 0;
	while (loopA <= 31)//배열변수에 기록
	{
		mskb[loopA] = bf & con;
		bf = bf >> 1;
		loopA++;
	}

	loopA = 31;
	while (loopA >= 0) //역순비교
	{
		if (mskb[loopA] == 1) //1과 같으면
		{
			lon++;//마스크 길이 1 증가
			if (cdt == 1)//0에서 다시 1이 되면
			{
				printf("잘못된 마스크값 입력됨");
				return 99;
			}
		}
		else
		{
			cdt = 1;//0이 되면 조건테스트를 1로
		}
		loopA--;//이프문과 상관없이 루프카운터 증가
	}

	return lon;
}

