#include "hd.h"
#pragma warning(disable:4996)

unsigned int subnetinput()
{
	unsigned int msk = 0;
	unsigned char sba, sbb, sbc, sbd;

	printf("����� ����ũ(1����) : ");
	scanf("%hhd", &sba);
	msk = sba;
	printf("����� ����ũ(2����) : %d . ", sba);
	msk = msk << 8;
	scanf("%hhd", &sbb);
	msk = msk | sbb;
	printf("����� ����ũ(3����) : %d . %d . ", sba, sbb);
	msk = msk << 8;
	scanf("%hhd", &sbc);
	msk = msk | sbc;
	printf("����� ����ũ(4����) : %d . %d . %d . ", sba, sbb, sbc);
	msk = msk << 8;
	scanf("%hhd", &sbd);
	msk = msk | sbd;

	return msk;

}

unsigned int ipinput()
{
	unsigned char ipa, ipb, ipc, ipd;
	unsigned int ip = 0;
	printf("ip �Է�(1����) : ");
	scanf("%hhd", &ipa);
		ip = ipa; 
	printf("ip �Է�(2����) : %d . ", ipa);
		ip = ip << 8;
	scanf("%hhd", &ipb);
		ip = ip | ipb;
	printf("ip �Է�(3����) : %d . %d . ", ipa, ipb);
		ip = ip << 8;
	scanf("%hhd", &ipc);
		ip = ip | ipc;
	printf("ip �Է�(4����) : %d . %d . %d . ", ipa, ipb, ipc);
		ip = ip << 8;
	scanf("%hhd", &ipd);
		ip = ip | ipd;

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

