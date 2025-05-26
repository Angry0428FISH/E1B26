#include <stdio.h>
#include <stdlib.h>
#define PASSWORD 2025
#include <string.h>
#include <ctype.h>
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

#define MAX 10

typedef struct {
    char id[7];           // 學號 (6位數，字串)
    char name[20];        // 姓名
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX];
int n = 0;

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
int main() {
    char option;
    char confirm;
    int input;
    
	for (int i = 1; i <= 20; i++) 
	{
        for (int j = 1; j <= i; j++) 
		{
            printf("*");
        }
        printf("\n");
    }
    for (int attempt = 1; attempt <= 3; attempt++) 
    {
        printf("請輸入密碼：");
        scanf("%d", &input);
        if (input == PASSWORD)
        {
        	printf("密碼正確，歡迎登入！\n");
        	system("PAUSE");
			system("CLS");
    		while(1)
			{
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
        		case 'b': //displayGrades(); break;
        		case 'c': //searchGrades(); break;
        		case 'd': //gradeRanking(); break;
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
			printf("密碼錯誤\n");
		}
	}
	printf("錯誤次數過多，已鎖定。\n");
    return 0;
}
