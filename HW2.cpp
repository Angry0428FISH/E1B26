#include<stdio.h>
#include<stdlib.h>
#define PASSWORD 2025
#include <conio.h> //getch()
int main()
{
	//01
	int i, pass;
	printf("�п�J4�ӼƦr���K�X:");
	scanf("%d",&pass);
	for(i=0;i<=3;i++)
	{
		
		if(pass!=PASSWORD)
		{
			printf("��J���~�A�Э��s��J:");
			scanf("%d",&pass);
			i++;
		}
		if(i==3 && pass!=PASSWORD) return 1;		
	}
	printf("��J���T\n");	
	system("pause");
	system("CLS");
	
	//02
MENU:
	printf("--------------------------\n");
	printf("|   A.a. �e�X�����T����  |\n");
	printf("|   B.b. ��ܭ��k��      |\n");
	printf("|   C.c. ����            |\n");
	printf("--------------------------\n");
	char choice;
	printf("��J�ﶵ:");
	fflush(stdin); //�קKŪ�� Enter�C
	scanf("%c",&choice);
	
	//03
	switch(choice)
	{
		case 'A':
		case 'a':
		{
			char ch;
			system("cls");
			printf("��J�@�ӡ�a���졥n�����r��:");
            do 
			{
                
                fflush(stdin);
                scanf("%c", &ch);
//�T���ή榡���~�A 
                if (ch >= 'a' && ch <= 'n') 
				{
                    for (char i = ch; i >= 'a'; i--) 
					{
						for (char space = 'a'; space < i; space++) // �L�X�Ů�A����k��
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
					printf("��J���~!�п�J�@�ӡ�a���졥n�����r��:"); //��J���~�A�S����ܡA��]: do-while�j�餺�� system("cls") 
            } while (!(ch >= 'a' && ch <= 'n'));

            printf("���U���N�ؤw�^��D���\n");
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
			printf("�п�J1��9���������: ");
            do
            {  
                
                scanf("%d", &n);
                if(n >= 1 && n <= 9)
                {
                    printf("���k��(1~%d):\n", n);
                    for(int i = 1; i <= n; i++)
                    {
                        for(int j = 1; j <= n; j++)
                        {
                            printf("%2d*%2d=%2d ", i, j, i*j); // �ƪ������X
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("��J���~!�Э��s��J:");
                }
            } while(!(n >= 1 && n <= 9));

            printf("���U���N���^�D���\n");
            getch();
            system("cls");
            goto MENU;
		}
	}
	
	
	return 0;
}
