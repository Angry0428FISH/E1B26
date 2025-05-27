#include <stdio.h>		// �򥻿�J��X�\��
#include <stdlib.h>		// ���� system() �禡�ϥΡ]�M���e���B�Ȱ���
#include <string.h>		// ���Ѧr��B�z�\��A�p strcmp()
#include <ctype.h>		// ���� isdigit() �Ω�P�_�O�_���Ʀr�]�K�X�ˬd�B�Ǹ����ҡ^

#define PASSWORD 2025	// �w�q�n�J�K�X�`��
#define MAX 10			// �̦h�ǥͼƶq

// �B�z getch()�A�ھڤ��P�@�~�t�Ωw�q
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

// �ǥ͸�Ƶ��c
typedef struct {
    char id[7];         // �Ǹ� (6��ơA�r��)
    char name[20];      // �m�W
    int math;
    int physics;
    int english;
    float average;		// �������Z
} Student;

Student students[MAX];	// �s��ǥͰ}�C
int n = 0;				// ��ھǥͤH��

// ���Ҿǥ� ID �榡�P�ߤ@��
void inputValidID(char *idBuffer, int index) 
{
    while (1) {
        int valid = 1;
        printf("Enter 6-digit student ID: ");
        scanf("%6s", idBuffer);

        if (strlen(idBuffer) != 6) {
            printf("Invalid input! Student ID must be exactly 6 digits.\n");
            valid = 0;
        } else {
            for (int i = 0; i < 6; i++) {
                if (!isdigit(idBuffer[i])) {
                    printf("Invalid input! Only digits are allowed.\n");
                    valid = 0;
                    break;
                }
            }
        }

        for (int i = 0; i < index; i++) {
            if (strcmp(students[i].id, idBuffer) == 0) {
                printf("Duplicate ID! Please enter a unique student ID.\n");
                valid = 0;
                break;
            }
        }

        if (valid) return;
    }
}

// ���ҳ�@��ؤ��ƿ�J
void inputValidScore(const char* subject, int* score) {
    while (1) {
        printf("Enter %s grade (0-100): ", subject);
        scanf("%d", score);
        if (*score >= 0 && *score <= 100) {
            return;
        } else {
            printf("Invalid score! %s grade must be between 0 and 100.\n", subject);
        }
    }
}

// ��J�Ҧ��ǥͦ��Z���
void enterGrades() {
    printf("Enter number of students (5 to 10): ");
    scanf("%d", &n);
    while (n < 5 || n > 10) {
        printf("Invalid number! Please enter a value between 5 and 10: ");
        scanf("%d", &n);
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        inputValidID(students[i].id, i);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        inputValidScore("Math", &students[i].math);
        inputValidScore("Physics", &students[i].physics);
        inputValidScore("English", &students[i].english);

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
    printf("\nData entry complete.\n");
}

// ��ܩҦ��ǥ͸��
void displayGrades() {
    if (n == 0) {
        printf("No student data available. Please enter data first.\n");
    } else {
        printf("\n%-8s %-10s %-6s %-8s %-8s %-8s\n", "ID", "Name", "Math", "Physics", "English", "Average");
        for (int i = 0; i < n; i++) {
            printf("%-8s %-10s %-6d %-8d %-8d %-8.2f\n",
                   students[i].id, students[i].name, students[i].math,
                   students[i].physics, students[i].english, students[i].average);
        }
    }
    printf("\nPress any key to return to main menu...");
	getch();
	system("CLS");

}

// �̾ǥͩm�W�d�ߦ��Z
void searchGrades() {
    if (n == 0) {
        printf("No student data available. Please enter data first.\n");
    } else {
        char targetName[20];
        printf("Enter student name to search: ");
        scanf("%19s", targetName);
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(students[i].name, targetName) == 0) {
                printf("Found %s (ID: %s): Math=%d, Physics=%d, English=%d, Average=%.2f\n",
                       students[i].name, students[i].id, students[i].math,
                       students[i].physics, students[i].english, students[i].average);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Student name %s not found.\n", targetName);
        }
    }
    printf("\nPress any key to return to main menu...");
    getch();
    system("CLS");
}

// �ھڥ������Z�i�歰�ǱƧǨ���ܱƦW
void gradeRanking() {
    if (n == 0) {
        printf("No student data available. Please enter data first.\n");
    } else {
        // �ϥ� Bubble Sort �ƧǾǥ͸��
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (students[j].average < students[j + 1].average) {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        // ��ܱƦW
        printf("\n--- Grade Ranking ---\n");
        printf("%-8s %-10s %-8s\n", "ID", "Name", "Average");
        for (int i = 0; i < n; i++) {
            printf("%-8s %-10s %-8.2f\n",
                   students[i].id, students[i].name, students[i].average);
        }
    }

    printf("\nPress any key to return to main menu...");
    getch();
    system("CLS");
}


int main() {
    char option;
    char confirm;
    int input;
    
    // ��ܬP�P�Ϯק@���w��e��
	for (int i = 1; i <= 20; i++) 
	{
        for (int j = 1; j <= i; j++) 
		{
            printf("*");
        }
        printf("\n");
    }
    
    // �n�J���ҡG�̦h�T�����|
    for (int attempt = 1; attempt <= 3; attempt++) 
    {
        printf("�п�J�K�X�G");
        scanf("%d", &input);
        if (input == PASSWORD)
        {
        	printf("�K�X���T�A�w��n�J�I\n");
        	system("PAUSE");
			system("CLS");
    		while(1)
			{
				// �D���
    			printf("----- [Grade System] ------\n");
    			printf("a. Enter student grades\n");
    			printf("b. Display student grades\n");
    			printf("c. Search for student grades\n");
    			printf("d. Grade ranking\n");
    			printf("e. Exit system\n");
    			printf("---------------------------\n");
    			printf("Enter your choice: ");
    			scanf(" %c", &option);
    			system("CLS");

    		switch (option) 
			{
        		case 'a': enterGrades(); break;
        		case 'b': displayGrades(); break;
        		case 'c': searchGrades(); break;
        		case 'd': gradeRanking(); break;
        		case 'e':
            		printf("Are you sure you want to exit? (y/n): ");
            		scanf(" %c", &confirm);
            		if (confirm == 'y' || confirm == 'Y') 
					{
            	    	printf("Exiting the system...\n");
            	    	return 0;
           			}
            		break;
        		default:
            		printf("Invalid option. Try again.\n");
            		printf("\nPress any key to return to main menu...");
            		getch();
            		system("CLS");
    		}
			}
		}
		else
		{
			printf("�K�X���~\n");
		}
	}
	printf("���~���ƹL�h�A�w��w�C\n");
    return 0;
}

/*
�����P�߱o�G
���{���O�@��²�����ǥͦ��Z�t�ΡA���ѨϥΪ̿�J�B�d�ߡB�ƧǾǥͦ��Z���\��C
�}�Y�ϥαK�X�n�J�O�@�A�קK�D���v�̾ާ@�C��Ƶ��c�ϥ� struct �x�s�C��ǥͪ���T�A�óz�L array �޲z�C
�ھǨ�F�ϥΦr���ˬd�B�Ʀr���һP�򥻸�ƱƧǡA�ü��x�F�p��b C �y�������X�h�Ө禡�ӧ����@�ӧ���t�ΡC
�t�~�ڤ]�@�F getch() �H�b Windows/Linux ����ާ@�Ȱ��P�e���M���C
���ӥi�X�R�\��p����x�s���ɮסB���\�ק�P�R�����C
*/
