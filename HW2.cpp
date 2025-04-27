#include<stdio.h>
#include<stdlib.h>
#define PASSWORD 2025
#include <conio.h> //getch()
int main()
{
	//01
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
	
	//02
MENU:
	printf("--------------------------\n");
	printf("|   A.a. 畫出直角三角形  |\n");
	printf("|   B.b. 顯示乘法表      |\n");
	printf("|   C.c. 結束            |\n");
	printf("--------------------------\n");
	char choice;
	printf("輸入選項:");
	fflush(stdin); //避免讀到 Enter。
	scanf("%c",&choice);
	
	//03
	switch(choice)
	{
		case 'A':
		case 'a':
		{
			char ch;
			system("cls");
			printf("輸入一個‘a’到‘n’的字元:");
            do 
			{
                
                fflush(stdin);
                scanf("%c", &ch);
//三角形格式錯誤， 
                if (ch >= 'a' && ch <= 'n') 
				{
                    for (char i = ch; i >= 'a'; i--) 
					{
						for (char space = 'a'; space < i; space++) // 印出空格，對齊右側
						{
							printf(" ");
						}
                        for (char j = i; j <= ch; j++) 
						{
                            printf("%c",j); 
                        }
                        printf("\n");
                    }
                } 
				else
					printf("輸入錯誤!請輸入一個‘a’到‘n’的字元:"); //輸入錯誤，沒有顯示，原因: do-while迴圈內有 system("cls") 
            } while (!(ch >= 'a' && ch <= 'n'));

            printf("按下任意建已回到主選單\n");
            getch();
			system("CLS");
            goto MENU;
		}
		
	//04
		case 'B':
		case 'b':
		{
			int n;
			system("cls");
			printf("請輸入1到9之間的整數: ");
            do
            {  
                
                scanf("%d", &n);
                if(n >= 1 && n <= 9)
                {
                    printf("乘法表(1~%d):\n", n);
                    for(int i = 1; i <= n; i++)
                    {
                        for(int j = 1; j <= n; j++)
                        {
                            printf("%2d*%2d=%2d ", i, j, i*j); // 排版整齊輸出
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("輸入錯誤!請重新輸入:");
                }
            } while(!(n >= 1 && n <= 9));

            printf("按下任意鍵返回主選單\n");
            getch();
            system("cls");
            goto MENU;
		}
	}
	
	
	return 0;
}
