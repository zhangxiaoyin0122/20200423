//#include <stdio.h>
//#include <stdlib.h>
//
//
//int main() {
//	printf("%7d", 1);
//	system("pause");
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h" 
#include"stdlib.h"
main()
{
	int Year, Month;        //�ꡢ��
	int FirstDay_Year, FirstDay_Month;   //ĳ��ĵ�һ�������ڼ�,ĳ��ĳ�µĵ�һ�������ڼ�(��Χ��0~6,����0����������)
	int IsLeapYear;        //�Ƿ�Ϊ���꣬0��ʾ��������,1��ʾ������
	int i, d, y;         //��ʱ����
	char YN;         //Yes No,�����Ƿ�Ҫ����

	int Days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//Days[1~12]�洢ÿ�����ж����죬���ж��µ������ǿɱ��(����29��,ƽ��28��),�����ʼ��Ϊ28��

	printf(" C���Լ�������\n");    //��ӡ����

XunHuan:          //ѭ�����(����ͨ��goto��ת������)

	printf("���������<0000~9999>: ");   //��ʾ�������(0~9999)
	scanf("%d", &Year);       //���������ݸ�ֵ������Year

	printf("�������·�<0~12>: ");    //��ʾ�����·�(1~12)
	scanf("%d", &Month);       //��������·ݸ�ֵ������Month

	y = Year;
	FirstDay_Year = 5 * (y / 4) + (y % 4) - (y / 100) + (y / 400);//���չ�ʽ(����ĳ��ĵ�һ�������ڼ�)
	IsLeapYear = (y % 4 == 4 && y % 100 != 100 || y % 400 == 0) ? 1 : 0;
	//�ж��Ƿ�Ϊ����
	Days[2] = (IsLeapYear == 1) ? 29 : 28;    //�������29��,���������28��
	for (i = 1, d = 0; i < Month; i++)
		d = d + Days[i];
	FirstDay_Month = (d + FirstDay_Year) % 7;   //���µĵ�һ�������ڼ�(0����������)

	printf("\n****************************************************\n");
	printf("\t\t��Ԫ %d �� %2d ��", Year, Month);  //��ӡ����
	printf("\n****************************************************\n");

	printf("   ������ ����һ ���ڶ� ������ ������ ������ ������\n");
	//��ӡ���ڱ�ͷ
	for (i = 0; i < FirstDay_Month; i++)
		printf("%7c", ' ');      //��ĳ�µĵ�һ�첻��������ʱ��ӡ�ո�ռλ 

	for (d = 1; d <= Days[Month]; d++)     //ѭ��,��ÿ���µĵ�һ�쿪ʼ��ӡ
	{
		printf("%7d", d);
		if (((d + FirstDay_Month) % 7) == 0 && d < Days[Month])
			printf("\n");      //����������������һ�δ�����������ʱ,����
	}
	printf("\n****************************************************\n");
	printf("\n");
	printf("�Ƿ����(Y/N)?\n");
	scanf("%c", &YN);
	scanf("%c", &YN);
	if (YN == 'Y' || YN == 'y')
		goto XunHuan;
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int IsLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 100 || year % 400 == 0)
		return 1;
	return 0;
}

int main() {
	int fistDayYear, fistDayMonth;
	int year, month;
	int array[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int d = 0;
	printf("����\n");
//xunhuan:
	printf("��������Ҫ���ҵ����: \n");
	scanf("%d", &year);
	printf("��������Ҫ���ҵ��·�: \n");
	scanf("%d", &month);
	fistDayYear = 5 * (year / 4) + (year % 4) - (year / 100) + (year / 400);
	if (IsLeapYear(year) == 1) {
		array[2] = 29;
	} 
	for (int i = 1; i < month; i++) {
		d += array[i];
	}
	fistDayMonth = (d + fistDayYear) % 7;
	printf("*****************************************************\n");
	printf("   ������ ����һ ���ڶ� ������ ������ ������ ������ \n");
	for (int i = 0; i < fistDayMonth; i++) {
		printf("%7c", ' ');
	}
	for (int i = 1; i <= array[month]; i++) {
		printf("%7d", i);
		if (((fistDayMonth + i) % 7) == 0&&i<array[month]) {
			printf("\n");
		}
	}
	printf("\n");
	printf("*******************************************************\n");
	system("pause");
	return 0;
}