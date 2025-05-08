#include<stdio.h>
#include<stdlib.h>
#define PASSWORD 2025

void showMenu()
 {
	printf("-------[Booking System]------\n");
	printf("|    a. Available seats     |\n");
	printf("|    b. Arrange for you     |\n");
	printf("|    c. Choose by yourself  |\n");
	printf("|    d. Exit                |\n");
	printf("-----------------------------\n");
 }
 
int main()
{
//01 顯示聖誕樹圖案
	printf("************************************\n");
	printf("         ☆\n");
    printf("        /_\\\n");
    printf("       /___\\\n");
    printf("      /_*__*\\\n");
    printf("     /___*___\\\n");
    printf("    /_*___*__*\\\n");
    printf("   /___*___*___\\\n");
    printf("  /_*___*___*__*\\\n");
    printf(" /___*___*___*___\\\n");
    printf("        |||\n");
    printf("        |||\n");
    printf("        |||\n");
    printf("        |||\n");
    printf("       /|||\\\n");
    printf("      /_|||_\\\n");
    printf("     /__|||__\\\n");
    printf("    /___|||___\\\n");
    printf("   /____|||____\\\n");
    printf("  /_____|||_____\\\n");
    printf("        |||\n");
	printf("************************************\n");
	
	// 密碼驗證，最多輸入3次 
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
		if(i==3 && pass!=PASSWORD) return 1;// 錯誤三次直接結束程式	
	}
	printf("輸入正確\n");	
	system("pause");
	system("CLS");// 清除螢幕
	
//02顯示主選單 
showMenu();
	char choice;
	printf("輸入選項:");
	fflush(stdin); //清空輸入緩衝區，避免讀到 Enter。
	scanf("%c",&choice);
	
	return 0;
}
