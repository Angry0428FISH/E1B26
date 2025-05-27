#include <stdio.h>		// 基本輸入輸出功能
#include <stdlib.h>		// 提供 system() 函式使用（清除畫面、暫停等
#include <string.h>		// 提供字串處理功能，如 strcmp()
#include <ctype.h>		// 提供 isdigit() 用於判斷是否為數字（密碼檢查、學號驗證）

#define PASSWORD 2025	// 定義登入密碼常數
#define MAX 10			// 最多學生數量

// 處理 getch()，根據不同作業系統定義
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

// 學生資料結構
typedef struct {
    char id[7];         // 學號 (6位數，字串)
    char name[20];      // 姓名
    int math;
    int physics;
    int english;
    float average;		// 平均成績
} Student;

Student students[MAX];	// 存放學生陣列
int n = 0;				// 實際學生人數

// 驗證學生 ID 格式與唯一性
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

// 驗證單一科目分數輸入
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

// 輸入所有學生成績資料
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

// 顯示所有學生資料
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

// 依學生姓名查詢成績
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

// 根據平均成績進行降序排序並顯示排名
void gradeRanking() {
    if (n == 0) {
        printf("No student data available. Please enter data first.\n");
    } else {
        // 使用 Bubble Sort 排序學生資料
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (students[j].average < students[j + 1].average) {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        // 顯示排名
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
    
    // 顯示星星圖案作為歡迎畫面
	for (int i = 1; i <= 20; i++) 
	{
        for (int j = 1; j <= i; j++) 
		{
            printf("*");
        }
        printf("\n");
    }
    
    // 登入驗證：最多三次機會
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
				// 主選單
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
			printf("密碼錯誤\n");
		}
	}
	printf("錯誤次數過多，已鎖定。\n");
    return 0;
}

/*
說明與心得：
本程式是一個簡易的學生成績系統，提供使用者輸入、查詢、排序學生成績的功能。
開頭使用密碼登入保護，避免非授權者操作。資料結構使用 struct 儲存每位學生的資訊，並透過 array 管理。
我學到了使用字串檢查、數字驗證與基本資料排序，並熟悉了如何在 C 語言中結合多個函式來完成一個完整系統。
另外我也作了 getch() 以在 Windows/Linux 都能操作暫停與畫面清除。
未來可擴充功能如資料儲存至檔案、允許修改與刪除等。
*/
