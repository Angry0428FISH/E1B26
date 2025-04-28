#include<stdio.h>
#include<stdlib.h>
#define PASSWORD 2025
#include <conio.h> //getch()
int main()
{
	//01
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
	//05
		case 'C':
		case 'c':
		{
			char confirm;
			printf("是否確定要結束？(y/n)：");
			confirm = getch();
			printf("%c\n", confirm);
			do 
			{
			    if (confirm == 'n' || confirm == 'N')
    			{
        			printf("程式結束，掰掰！\n");
        			return 0;
    			}
    			else if (confirm == 'y' || confirm == 'Y') 
    			{
        			system("cls");
        			goto MENU;
    			}
    		else
   			{
        		printf("輸入錯誤！請重新輸入 (y/n)：");
        		scanf(" %c", &confirm);
    		}
			} while (1);
		}
	}
	
	return 0;
}
//相關說明
//將 case 'C'/'c' 處理流程進行修正：

//使用 do-while 迴圈處理確認結束（是否確定要離開程式）。

//用 getch() 直接讀取第一次輸入，並馬上顯示出來。

//如果輸入是 'n' 或 'N'，則確定結束程式，return 0。

//如果輸入是 'y' 或 'Y'，則回到主選單 goto MENU。

//如果輸入錯誤（非 'y'/'Y'/'n'/'N'），則顯示錯誤提示，並要求重新輸入。

//修正錯誤點：

//原本 if 條件寫錯，導致即使輸入正確也會當成錯誤重新輸入。

//修正 if 判斷的邏輯，並把清楚的輸入判斷放到 do-while 中。

//優化：

//直接在 do-while(1) 迴圈中結束或跳轉，不怕死循環，程式流程更清楚。

//討論心得
//這次主要是針對「結束確認」做結構性的修正，發現：

//getch() 很適合拿來做快速輸入，不用按 Enter。

//do-while 讓第一次輸入後就可以馬上檢查，不需要重複寫很多次判斷。

//體會到一個小小地方沒注意（像是 if 判斷寫錯），會讓整個功能跑錯或無限迴圈。

//學到的重點：

//條件式要非常仔細檢查（尤其是 &&、|| 這些邏輯符號）。

//system("cls") 要注意呼叫的時機，不然會把提示文字直接清掉。

//goto 可以在這種簡單選單中方便地跳轉，但使用時一定要小心避免混亂。

//總結：

//這個修改讓整個選單操作變得流暢且有容錯機制，使用者體驗也更好。

//寫程式時要反覆檢查「邏輯正確性」，並且在每次小改動後做測試確認。
