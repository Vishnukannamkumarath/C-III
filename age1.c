#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()
{
	int day,month,year,cdate,cmonth,cyear;
	printf("enter date of birth\n");
	scanf("%d",&day);
	printf("enter month of birth\n");
	scanf("%d",&month);
	printf("enter year of birth\n");
	scanf("%d",&year);
	printf("enter current date\n");
	scanf("%d",&cdate);
	printf("enter current month\n");
	scanf("%d",&cmonth);
	printf("enter current year\n");
	scanf("%d",&cyear);
	int ddate=abs(day-cdate);
	int dmonth=abs(month-cmonth);
	int dyear=abs(year-cyear);
	printf("difference in date=%d\t",ddate);
	printf("difference in month=%d\t",dmonth);
	printf("age=%d\t",dyear);
}
	
