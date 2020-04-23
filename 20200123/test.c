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
	int Year, Month;        //年、月
	int FirstDay_Year, FirstDay_Month;   //某年的第一天是星期几,某年某月的第一天是星期几(范围是0~6,其中0代表星期日)
	int IsLeapYear;        //是否为闰年，0表示不是闰年,1表示是闰年
	int i, d, y;         //临时变量
	char YN;         //Yes No,程序是否要继续

	int Days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//Days[1~12]存储每个月有多少天，其中二月的天数是可变的(闰年29天,平年28天),这里初始化为28天

	printf(" C语言简单万年历\n");    //打印标题

XunHuan:          //循环标号(可以通过goto跳转到这里)

	printf("请输入年份<0000~9999>: ");   //提示输入年份(0~9999)
	scanf("%d", &Year);       //把输入的年份赋值给变量Year

	printf("请输入月份<0~12>: ");    //提示输入月份(1~12)
	scanf("%d", &Month);       //把输入的月份赋值给变量Month

	y = Year;
	FirstDay_Year = 5 * (y / 4) + (y % 4) - (y / 100) + (y / 400);//蔡勒公式(计算某年的第一天是星期几)
	IsLeapYear = (y % 4 == 4 && y % 100 != 100 || y % 400 == 0) ? 1 : 0;
	//判断是否为闰年
	Days[2] = (IsLeapYear == 1) ? 29 : 28;    //闰年二月29天,非闰年二月28天
	for (i = 1, d = 0; i < Month; i++)
		d = d + Days[i];
	FirstDay_Month = (d + FirstDay_Year) % 7;   //当月的第一天是星期几(0代表星期日)

	printf("\n****************************************************\n");
	printf("\t\t公元 %d 年 %2d 月", Year, Month);  //打印年月
	printf("\n****************************************************\n");

	printf("   星期日 星期一 星期二 星期三 星期四 星期五 星期六\n");
	//打印星期表头
	for (i = 0; i < FirstDay_Month; i++)
		printf("%7c", ' ');      //当某月的第一天不是星期日时打印空格占位 

	for (d = 1; d <= Days[Month]; d++)     //循环,从每个月的第一天开始打印
	{
		printf("%7d", d);
		if (((d + FirstDay_Month) % 7) == 0 && d < Days[Month])
			printf("\n");      //当输出了星期六而且还未输出所有天数时,换行
	}
	printf("\n****************************************************\n");
	printf("\n");
	printf("是否继续(Y/N)?\n");
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
	printf("日历\n");
//xunhuan:
	printf("请输入您要查找的年份: \n");
	scanf("%d", &year);
	printf("请输入您要查找的月份: \n");
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
	printf("   星期日 星期一 星期二 星期三 星期四 星期五 星期六 \n");
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