#include<stdio.h>
#include<stdlib.h>
#define PASSWORD 2025
int main()
{
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
	
	printf("--------------------------\n");
	printf("|   A.a. �e�X�����T����  |\n");
	printf("|   B.b. ��ܭ��k��      |\n");
	printf("|   C.c. ����            |\n");
	printf("--------------------------\n");
	
	return 0;
}
