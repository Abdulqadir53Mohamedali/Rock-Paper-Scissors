#include <iostream>
#include <ctime>

// Function to get the choice of the user: rock, paper, or scissors
char getUserchoice();

// Function to get a random choice for the computer: rock, paper, or scissors
char getComputerchoice();

// Function to display the choice in a user-friendly manner
void showChoice(char choice);

// Function to determine and display the winner based on user and computer choices
void chooseWinner(char player, char computer);

int main() {
    char player;
    char computer;

    // Get user's choice
    player = getUserchoice();
    std::cout << "You chose: ";
    showChoice(player); // Display the user's choice
    std::cout << ' '  << '\n';

    // Get computer's random choice
    computer = getComputerchoice();
    std::cout << "Computer choice: ";
    showChoice(computer); // Display the computer's choice
    std::cout << ' ' <<  '\n';
    std::cout << "***************************\n";

    // Determine the winner
    chooseWinner(player, computer);

    return 0;
}

char getUserchoice() {
    char player;

    // Game menu
    std::cout << "***************************\n";
    std::cout << "ROCK-PAPER-SCISSORS\n";
    std::cout << "***************************\n";

    do {
        // Asking the user for their choice
        std::cout << "Please enter you're choice\n";
        std::cout << "***************************\n";
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for scissors\n";
        std::cout << "***************************\n";
        std::cout << "choice:";
        std::cin >> player;

        // Loop until a valid choice is entered
    } while(player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerchoice() {
    srand(time(0));

    // Generating a random number to decide computer's choice
    int com_num = rand() % 3 + 1;

    switch(com_num) {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }

    return 0; // Default return (should never be reached)
}

void showChoice(char choice) {
    // Convert choice character to readable string and display
    switch(choice) {
        case 'r': std::cout << "Rock"; break;
        case 'p': std::cout << "Paper"; break;
        case 's': std::cout << "Scissors"; break;
    }
}

void chooseWinner(char player, char computer) {
    // Determine the game outcome based on choices
    switch(player) {
        case 'r':
            if (computer == 'r') {
                std::cout <<"It's a Draw\n";
            }
            else if (computer == 'p') {
                std::cout << "You lose\n";
            }
            else {
                std::cout << "You win\n";
            }
            break;
        case 'p':
            if (computer == 'p') {
                std::cout <<"It's a Draw\n";
            }
            else if (computer == 's') {
                std::cout << "You lose\n";
            }
            else {
                std::cout << "You win\n";
            }
            break;
        case 's':
            if (computer == 's') {
                std::cout <<"It's a Draw\n";
            }
            else if (computer == 'r') {
                std::cout << "You lose\n";
            }
            else {
                std::cout << "You win\n";
            }
            break;
    }
}
