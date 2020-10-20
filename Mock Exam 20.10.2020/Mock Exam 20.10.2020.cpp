// Mock Exam 20.10.2020.cpp //

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>


bool exit_program = false;

//Task - Login screen
const int size = 3;
int login = 0;
int allowed_attempts = 3;
int attempt_counter = 0;
char last_login_digit = '3';
char login_character = '*';
bool login_accepted = false;
bool login_failed = false;

int array[size]{};
std::vector <char> board = { '1','2','3','4','5','6','7','8','9' };

void login_screen();
void display_loginscreen();
void reset_login();
void login_control();
void check_loginattempts();

//Menu task
int menu_choice = 0;

void task_menu();

//Task 1
std::vector <int> dice_rolls = {2000};

void throwdice();

//Task 2


int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //login_screen();
    //task_menu();
    throwdice();



}

// Login functions
void login_screen() {
    do {
        system("CLS");
        if (attempt_counter > 0) {
            std::cout << "\n Wrong password sequence. You have " << allowed_attempts << " more tries." << std::endl;
        }
        display_loginscreen();
        login_control();
        check_loginattempts();
    } while (!login_accepted || !login_failed);
}

void display_loginscreen(){

    board[login] = login_character;

    for (int i = 0; i < board.size(); i++) {
        if (i % size == 0) {
            std::cout << "\n------------\n|";
        }
        std::cout << board[i] << " | ";
    }
    std::cout << "\n------------" << std::endl;

  
}

void check_loginattempts() {
    if (allowed_attempts <= 0) {
        login_failed = true;
    }
}

void reset_login() {
    int login = 0;
    int array[size]{};
    std::vector <char> board = { '1','2','3','4','5','6','7','8','9' };
    
    attempt_counter++;
}

void login_control() {
   
    char user_input = _getch();

    switch (user_input) {

    case 'W':
    case 'w':
        if (login < 3) {
            allowed_attempts -= 1;
            break;
        }
        board[login] = ' ';
        login -= 3;
        break;
    case 'A':
    case 'a':
        if (login == 0 || login == 4 || login == 2) {
            allowed_attempts -= 1;
            break;
        }
        break;
    case 'S':
    case 's':
        if (login >= 3 || login == 7 || login == 8 || login == 9 || login == 1) {
            allowed_attempts -= 1;
            break;
        }
        board[login] = ' ';
        login += 3;
        break;
    case 'D':
    case 'd':
        if (login >= 4 || login == 0){
            allowed_attempts -= 1;
            break;
        }
        board[login] = ' ';
        login += 1;
        break;

    }

    if (board[login] == last_login_digit) {
        login_accepted = true;
    }

    board[login] = login_character;
}

//Menu functions
void task_menu() {
    
    system("CLS");

    bool choice_valid = false;

    std::cout << R"(
                Task menu
----------------------------------------------------
Please make a selection by pressing numbers (1-5).

1. Task 1
2. Task 2
3. Task 3
4. Task 4
5. Exit the program
)" << std::endl;

    do {
        char user_input = _getch();

        switch (user_input) {
        case '1':
            menu_choice = 1;
            choice_valid = true;
            break;
        case '2':
            menu_choice = 2;
            choice_valid = true;
            break;
        case '3':
            menu_choice = 3;
            choice_valid = true;
            break;
        case '4':
            menu_choice = 4;
            choice_valid = true;
            break;
        case '5':
            menu_choice = 5;
            choice_valid = true;
            break;
        default:
            menu_choice = -1;
            break;
        }

        if (menu_choice == -1) {
            bool tryagain_choice = false;
            do {
                std::cout << "\n Wrong input... Do you want to try again : (y / n)";
                char tryagain = _getch();
                switch (tryagain) {
                case 'y':
                case 'Y':
                    choice_valid = false;
                    tryagain_choice = true;
                    menu_choice = 0;
                    break;
                case 'n':
                case 'N':
                    choice_valid = true;
                    tryagain_choice = true;
                    exit_program = true;
                    break;
                default:
                    tryagain_choice = false;

                }
            }while (!tryagain_choice);

        }

    } while (!choice_valid);

}

//Dice functions
void throwdice() {

    int dice_roll = 0;
    int dice_count = 1;
    
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;

    do {
        for (int i = 0; i < dice_rolls.size(); i++) {
            dice_roll = std::rand() % 6 + 1;
            dice_rolls[i] = dice_roll;
            if (dice_rolls[i] == 1) {
                count1++;
            }
            else if (dice_rolls[i] == 2) {
                count2++;
            }
            else if (dice_rolls[i] == 3) {
                count3++;
            }
            else if (dice_rolls[i] == 4) {
                count4++;
            }
            else if (dice_rolls[i] == 5) {
                count5++;
            }
            else if (dice_rolls[i] == 6) {
                count6++;
            }
            std::cout << "Dice " << dice_count << " is a " << dice_rolls[i] << std::endl;
            dice_count++;
        }
    } while (dice_count < 2001);

    std::cout << "\n\n These are the results of your throws:" << std::endl;
    std::cout << " 1: " << count1 << " times." << std::endl;
    std::cout << " 2: " << count2 << " times." << std::endl;
    std::cout << " 3: " << count3 << " times." << std::endl;
    std::cout << " 4: " << count4 << " times." << std::endl;
    std::cout << " 5: " << count5 << " times." << std::endl;
    std::cout << " 6: " << count6 << " times." << std::endl;

}

