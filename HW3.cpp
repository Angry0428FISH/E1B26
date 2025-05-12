#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD 2025 	 // Predefined password for system access 
#define ROWS 9 			 // Number of rows in the seat layout
#define COLS 9  		 // Number of columns in the seat layout
#define MAX_SEATS 4		 // Maximum number of seats that can be selected

char seats[ROWS][COLS];	 // 2D array representing the seating arrangement

// Function to initialize the seats (empty seats are marked as '-', and booked ones as '*')
void initSeats() 
{
	int i=0, j=0;
	// Initialize all seats to '-'
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            seats[i][j] = '-';

    srand(time(NULL)); // Seed the random number generator to ensure different randomization each time
    int booked = 0;
    // Randomly book 10 seats
    while (booked < 10) {
        int r = rand() % ROWS;		// Random row 
        int c = rand() % COLS; 		// Random column 
        if (seats[r][c] == '-') { 	// Only book if the seat is available 
            seats[r][c] = '*';
            booked++;
        }
    }
}
// Function to display the seating arrangement
void displaySeats() 
{
    printf(" \\123456789\n"); // Print column numbers 
    int i=0, j=0;
    // Print each row of seats
	for (i = 0; i < ROWS; i++) {
        printf("%d ", 9 - i); // Print row number 
        for (j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]); // Print seat status ('-', '*', or '@') 
        }
        printf("\n");
    }
}

// Function to display the menu
void showMenu()
 {
	printf("-------[Booking System]------\n");
	printf("|    a. Available seats     |\n");
	printf("|    b. Arrange for you     |\n");
	printf("|    c. Choose by yourself  |\n");
	printf("|    d. Exit                |\n");
	printf("-----------------------------\n");
 }
 
 // Function to automatically arrange seats based on the user's request
 void autoArrange(int count) 
{
    int tempSeats[ROWS][COLS];
    memcpy(tempSeats, seats, sizeof(tempSeats)); // Copy the current seating arrangement to tempSeats 
    int found = 0;

    srand(time(NULL)); // Seed the random number generator for randomness 
    // Try to find a block of continuous empty seats for the required number of seats
	if (count >= 1 && count <= 3) {
    	int attempt;
        for (attempt = 0; attempt < 1000 && !found; attempt++) {
            int row = rand() % ROWS;
            int col = rand() % (COLS - count + 1); // Ensure we don't go out of bounds 
            int ok = 1;
            // Check if the seats are available
            int k=0;
            for (k = 0; k < count; k++) {
                if (seats[row][col + k] != '-') {
                    ok = 0;
                    break;
                }
            }
            // If seats are available, mark them with '@'
            if (ok) {
                for (k = 0; k < count; k++) {
                    tempSeats[row][col + k] = '@';
                }
                found = 1;
            }
        }
    } else if (count == 4) { // Special case for 4 seats 
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

		// If no continuous 4 seats found, try a 2x2 block
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
	// Display the suggested seating arrangement
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
        // Confirm with the user if they are satisfied with the arrangement
        char confirm;
        printf("Are you satisfied with these seats? (y/n): ");
        scanf(" %c", &confirm);
        if (confirm == 'y' || confirm == 'Y') {
        	// If confirmed, book the seats by marking them as '*'
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
// Function to manually select seats
void manualSelect() 
{
    char input[10];
    int selected[MAX_SEATS][2];
    int count = 0;

    while (count < MAX_SEATS) 
	{
        printf("Enter seat (e.g. 2-9 or q to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) break; // Allow user to quit by entering 'q' 

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

        seats[r][c] = '@'; // Mark the seat as selected 
        selected[count][0] = r;
        selected[count][1] = c;
        count++;
    }

    displaySeats();  // Show updated seating arrangement 
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

    initSeats();  // Initialize the seat layout 

	// Request the user to enter the password
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
		if(i==3 && pass!=PASSWORD) return 1; // Exit if the password is entered incorrectly three times
	}
	printf("輸入正確\n");	
	system("pause");
	system("CLS");

	// Main menu loop
    while (1) {
        showMenu(); // Show menu options
        printf("Select an option (a/b/c/d): ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                displaySeats(); // Display the current seat layout
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

//Here’s a detailed explanation and discussion regarding your program, including the design choices, challenges, and a reflection on the experience:

//1. **Password Protection**:
   //* The program starts by asking the user to input a 4-digit password. If the password is entered incorrectly three times, the program exits. This step ensures that only authorized users can access the booking system.
   //* This is a basic security feature to add a layer of protection, though it could be expanded with encryption or more sophisticated password handling.

//2. **Seating Grid Initialization**:
   //* The seating grid is represented by a 2D array where each seat can either be available ('-'), booked ('\*'), or selected by the user ('@').
   //* The `initSeats()` function initializes the grid and randomly books 10 seats. This provides a realistic scenario where some seats are pre-booked when the system starts.

//3. **Menu System**:
   //* After the user successfully logs in, they are presented with a menu where they can choose from the following options:
     //* **Option a**: View the current seating arrangement.
     //* **Option b**: Automatically arrange seats for a group (1 to 4 seats).
     //* **Option c**: Manually select specific seats.
     //* **Option d**: Exit the system.

//4. **Automatic Seat Arrangement**:
   //* The `autoArrange()` function handles automatic seat booking. It attempts to find a contiguous block of empty seats based on the user's requested number of seats (1-4).
   //* If no valid arrangement is found after multiple attempts, the function will return a message indicating that no available seats are found.
   //* For the case where 4 seats are requested, the program tries to find either a horizontal line of 4 consecutive seats or a 2x2 block of empty seats.

//5. **Manual Seat Selection**:
   //* The `manualSelect()` function allows users to manually input seat coordinates. If the seat is available, it will be marked with '@', and the user can select up to 4 seats.
   //* Input is validated, and the user can quit by entering 'q'.

//6. **Displaying Seating Arrangements**:
   //* Both the `displaySeats()` and `autoArrange()` functions show the current seating arrangement to the user in a clear, easy-to-read format.
   //* The seat numbers are displayed at the top, and the rows are numbered in reverse for ease of understanding.

//### **Discussion of Key Features**

//1. **User Interface (UI) Considerations**:

  //* The program uses a text-based UI with clear prompts for the user. While simple, it effectively guides the user through the process of booking and viewing seats.
  //* The seating arrangement is displayed in a matrix format with row and column numbers, making it easy for users to understand the status of each seat.
  //* The use of ASCII art to display a "personal style" logo adds a bit of fun to the program and creates a more personalized experience.

//2. **Seat Booking Logic**:
   //* One interesting aspect of this program is the approach to automatically arranging seats. Instead of just filling up available seats randomly, the program tries to find contiguous blocks or small groups of seats that are available, which is more useful in real-world scenarios (e.g., booking 2-4 seats together for a group).
   //* The program uses a random approach to seat allocation, which is appropriate for this type of booking system. However, it may be improved by considering priorities, such as reserving a seat next to a window or closer to the center for better customer experience.

//3. **Challenges and Issues**:
   //* **Randomness in Seat Booking**: While using randomness can simulate a real-world scenario, the chances of failing to find a contiguous block of seats (especially for larger groups) may frustrate the user. More complex algorithms, such as backtracking or greedy algorithms, could be implemented to optimize seat selection and improve the success rate.
   //* **Limited Seat Count**: The program only allows booking up to 4 seats at once, which might not be sufficient for larger groups. Extending this limit could make the system more flexible.

//4. **Improvements**:
  // * **More Advanced UI**: The text-based UI could be enhanced with more detailed messages, error handling, and even a graphical interface (though this would require more effort and libraries like `ncurses` or graphical libraries in C).
  // * **Persistent Storage**: Currently, the seating arrangement is reset every time the program runs. Implementing file I/O could allow users to save their seating arrangements or bookings, so the state persists between sessions.
  // * **User Feedback**: Additional feedback can be added after each user action, e.g., confirming successful bookings, showing available seats dynamically, and offering suggestions based on seat availability.

//### **Personal Reflection and Learning Experience**

//1. **What Went Well**:
   //* The logic for seat initialization and booking works well. The random seat assignment and manual selection options provide flexibility, and the program responds correctly to most user inputs.
   //* I also feel confident that I was able to implement the basic functionality, such as seat display, seat booking, and password protection, in a way that is both clear and effective.

//2. **Challenges Faced**:
   //* One of the challenges I encountered was ensuring that the seating arrangements are correctly handled. Managing a 2D array and making sure the seat selection logic is sound (especially in the auto-arrangement function) was a bit tricky.
   //* Also, understanding how to handle user input and validating it correctly (such as for seat selection) required some extra care to prevent crashes or errors.

//3. **Skills Gained**:
   //* I learned how to work with 2D arrays and how to manipulate and display them effectively. I also got better at using random number generation for seat booking and managing user input.
   //* This project allowed me to practice managing different parts of a program (like functions, conditionals, and loops) while keeping everything logically separated for ease of maintenance.

//### **Conclusion**

//This project was a great exercise in understanding how to implement a basic booking system with seating arrangements. 
//It helped me develop a better understanding of arrays, random number generation, and user input validation. 
//Moving forward, I can build on this foundation by adding more complex features like better seat selection algorithms, improved user interfaces, and persistent data storage.

