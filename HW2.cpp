#include<stdio.h>
#include<stdlib.h>
#define PASSWORD 2025
#include <conio.h> //getch()
int main()
{
	//01
	printf("************************************\n");
	printf("         ��\n");
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
	//05
		case 'C':
		case 'c':
		{
			char confirm;
			printf("�O�_�T�w�n�����H(y/n)�G");
			confirm = getch();
			printf("%c\n", confirm);
			do 
			{
			    if (confirm == 'n' || confirm == 'N')
    			{
        			printf("�{�������A�T�T�I\n");
        			return 0;
    			}
    			else if (confirm == 'y' || confirm == 'Y') 
    			{
        			system("cls");
        			goto MENU;
    			}
    		else
   			{
        		printf("��J���~�I�Э��s��J (y/n)�G");
        		scanf(" %c", &confirm);
    		}
			} while (1);
		}
	}
	
	return 0;
}
//��������
//�N case 'C'/'c' �B�z�y�{�i��ץ��G

//�ϥ� do-while �j��B�z�T�{�����]�O�_�T�w�n���}�{���^�C

//�� getch() ����Ū���Ĥ@����J�A�ð��W��ܥX�ӡC

//�p�G��J�O 'n' �� 'N'�A�h�T�w�����{���Areturn 0�C

//�p�G��J�O 'y' �� 'Y'�A�h�^��D��� goto MENU�C

//�p�G��J���~�]�D 'y'/'Y'/'n'/'N'�^�A�h��ܿ��~���ܡA�ín�D���s��J�C

//�ץ����~�I�G

//�쥻 if ����g���A�ɭP�Y�Ͽ�J���T�]�|�����~���s��J�C

//�ץ� if �P�_���޿�A�ç�M������J�P�_��� do-while ���C

//�u�ơG

//�����b do-while(1) �j�餤�����θ���A���Ȧ��`���A�{���y�{��M���C

//�Q�פ߱o
//�o���D�n�O�w��u�����T�{�v�����c�ʪ��ץ��A�o�{�G

//getch() �ܾA�X���Ӱ��ֳt��J�A���Ϋ� Enter�C

//do-while ���Ĥ@����J��N�i�H���W�ˬd�A���ݭn���Ƽg�ܦh���P�_�C

//��|��@�Ӥp�p�a��S�`�N�]���O if �P�_�g���^�A�|����ӥ\��]���εL���j��C

//�Ǩ쪺���I�G

//���󦡭n�D�`�J���ˬd�]�ר�O &&�B|| �o���޿�Ÿ��^�C

//system("cls") �n�`�N�I�s���ɾ��A���M�|�ⴣ�ܤ�r�����M���C

//goto �i�H�b�o��²���椤��K�a����A���ϥήɤ@�w�n�p���קK�V�áC

//�`���G

//�o�ӭק�����ӿ��ާ@�ܱo�y�Z�B���e������A�ϥΪ�����]��n�C

//�g�{���ɭn�����ˬd�u�޿西�T�ʡv�A�åB�b�C���p��ʫᰵ���սT�{�C
