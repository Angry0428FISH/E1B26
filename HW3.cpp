#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD 2025
#define ROWS 9
#define COLS 9
#define MAX_SEATS 4

char seats[ROWS][COLS];
void initSeats() 
{
	int i=0, j=0;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            seats[i][j] = '-';

    srand(time(NULL));
    int booked = 0;
    while (booked < 10) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            booked++;
        }
    }
}
void displaySeats() 
{
    printf(" \\123456789\n");
    int i=0, j=0;
	for (i = 0; i < ROWS; i++) {
        printf("%d ", 9 - i);
        for (j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

void showMenu()
 {
	printf("-------[Booking System]------\n");
	printf("|    a. Available seats     |\n");
	printf("|    b. Arrange for you     |\n");
	printf("|    c. Choose by yourself  |\n");
	printf("|    d. Exit                |\n");
	printf("-----------------------------\n");
 }
 
 void autoArrange(int count) 
{
    int tempSeats[ROWS][COLS];
    memcpy(tempSeats, seats, sizeof(tempSeats));
    int found = 0;

    srand(time(NULL));
    if (count >= 1 && count <= 3) {
    	int attempt;
        for (attempt = 0; attempt < 1000 && !found; attempt++) {
            int row = rand() % ROWS;
            int col = rand() % (COLS - count + 1);
            int ok = 1;
            int k=0;
            for (k = 0; k < count; k++) {
                if (seats[row][col + k] != '-') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                for (k = 0; k < count; k++) {
                    tempSeats[row][col + k] = '@';
                }
                found = 1;
            }
        }
    } else if (count == 4) {
    	int i=0, j=0, k=0;
        for (i = 0; i < ROWS && !found; i++) {
            for (j = 0; j <= COLS - 4; j++) {
                int ok = 1;
                for (k = 0; k < 4; k++) {
                    if (seats[i][j + k] != '-') {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    for (k = 0; k < 4; k++) {
                        tempSeats[i][j + k] = '@';
                    }
                    found = 1;
                }
            }
        }

        if (!found) {
            for (i = 0; i < ROWS - 1 && !found; i++) {
                for (j = 0; j <= COLS - 2; j++) {
                    if (seats[i][j] == '-' && seats[i][j+1] == '-' &&
                        seats[i+1][j] == '-' && seats[i+1][j+1] == '-') {
                        tempSeats[i][j] = tempSeats[i][j+1] = '@';
                        tempSeats[i+1][j] = tempSeats[i+1][j+1] = '@';
                        found = 1;
                    }
                }
            }
        }
    }

    if (found) {
        printf("Suggested seats:\n");
        printf(" \\123456789\n");
        int i=0, j=0;
        for (i = 0; i < ROWS; i++) {
            printf("%d ", 9 - i);
            for (j = 0; j < COLS; j++) {
                printf("%c", tempSeats[i][j]);
            }
            printf("\n");
        }
        char confirm;
        printf("Are you satisfied with these seats? (y/n): ");
        scanf(" %c", &confirm);
        if (confirm == 'y' || confirm == 'Y') {
            for (i = 0; i < ROWS; i++)
                for (j = 0; j < COLS; j++)
                    if (tempSeats[i][j] == '@')
                        seats[i][j] = '*';
            system("clear||cls");
        }
    } else {
        printf("No available arrangement found. Returning to menu.\n");
    }
}
void manualSelect() 
{
    char input[10];
    int selected[MAX_SEATS][2];
    int count = 0;

    while (count < MAX_SEATS) 
	{
        printf("Enter seat (e.g. 2-9 or q to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) break;

        int col, row;
        if (sscanf(input, "%d-%d", &col, &row) != 2 || col < 1 || col > 9 || row < 1 || row > 9) {
            printf("Invalid input.\n");
            continue;
        }

        int r = 9 - row;
        int c = col - 1;
        if (seats[r][c] != '-') {
            printf("Seat already taken.\n");
            continue;
        }

        seats[r][c] = '@';
        selected[count][0] = r;
        selected[count][1] = c;
        count++;
    }

    displaySeats();
    system("pause");
	system("CLS");
}

int main() 
{
//show Personal style image
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
	
    int inputPwd, attempts = 0;
    char option;
    char cont;

    initSeats();

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

    while (1) {
        showMenu();
        printf("Select an option (a/b/c/d): ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                displaySeats();
                printf("Press any key to return to menu...\n");
                getchar(); getchar(); 
                system("clear||cls");
                break;
            case 'b': 
			{
                int n;
                printf("How many seats do you need (1~4)? ");
                scanf("%d", &n);
                if (n >= 1 && n <= 4)
                    autoArrange(n);
                else
                    printf("Invalid number of seats.\n");
                break;
            }
            case 'c':
                manualSelect();
                break;
            case 'd':
                printf("Continue? (y/n): ");
                scanf(" %c", &cont);
                if (cont == 'y' || cont == 'Y')
                    continue;
                else if (cont == 'n' || cont == 'N') {
                    printf("Exiting system.\n");
                    return 0;
                } else {
                    printf("Invalid input.\n");
                }
                break;
            default:
                printf("Invalid selection.\n");
                break;
        }
    }

    return 0;
}
