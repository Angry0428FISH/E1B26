#include<stdio.h>
#include<stdlib.h>
#define PASSWORD 2025
int main()
{
	int i, pass;
	
	printf("請輸入4個數字的密碼:");
	scanf("%d",&pass);
	for(i=0;i<=3;i++)
	{
		
		if(pass!=PASSWORD)
		{
			printf("輸入錯誤，請重新輸入:");
			scanf("%d",&pass);
			i++;
		}
		if(i==3 && pass!=PASSWORD) return 1;		
	}
	printf("輸入正確\n");
	
	system("pause");
	system("CLS");
	
	printf("--------------------------\n");
	printf("|   A.a. 畫出直角三角形  |\n");
	printf("|   B.b. 顯示乘法表      |\n");
	printf("|   C.c. 結束            |\n");
	printf("--------------------------\n");
	
	return 0;
}
