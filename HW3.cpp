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
//01 ��ܸt�Ͼ�Ϯ�
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
	
	// �K�X���ҡA�̦h��J3�� 
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
		if(i==3 && pass!=PASSWORD) return 1;// ���~�T�����������{��	
	}
	printf("��J���T\n");	
	system("pause");
	system("CLS");// �M���ù�
	
//02��ܥD��� 
showMenu();
	char choice;
	printf("��J�ﶵ:");
	fflush(stdin); //�M�ſ�J�w�İϡA�קKŪ�� Enter�C
	scanf("%c",&choice);
	
	return 0;
}
