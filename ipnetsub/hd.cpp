#include "hd.h"
#pragma warning(disable:4996)

unsigned int subnetinput()
{
	unsigned int msk = 0;
	unsigned char sba, sbb, sbc, sbd;

	printf("����� ����ũ : ");
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
	printf("ip �Է� : ");
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
			printf("�ùٸ��� ���� ������ �ּ�");
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


int tmask(unsigned int msk) //����ũ 1���� �Ǻ�
{
	unsigned int bf = msk;
	unsigned int con = 1;
	int loopA, lon, cdt;
	unsigned int mskb[32] = { 0 };
	loopA = 0;
	lon = 0;
	cdt = 0;
	while (loopA <= 31)//�迭������ ���
	{
		mskb[loopA] = bf & con;
		bf = bf >> 1;
		loopA++;
	}

	loopA = 31;
	while (loopA >= 0) //������
	{
		if (mskb[loopA] == 1) //1�� ������
		{
			lon++;//����ũ ���� 1 ����
			if (cdt == 1)//0���� �ٽ� 1�� �Ǹ�
			{
				printf("�߸��� ����ũ�� �Էµ�");
				return 99;
			}
		}
		else
		{
			cdt = 1;//0�� �Ǹ� �����׽�Ʈ�� 1��
		}
		loopA--;//�������� ������� ����ī���� ����
	}

	return lon;
}

