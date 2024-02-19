#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void drawLine(int n, char symbol);
void rules();

int main() {
    srand(time(0)); // Seed the random number generator.
    string player1, player2;
    int amount, amount2, bettingAmount, bettingAmount2, roll, roll2;
    char playAgain;

    drawLine(60, '_');
    cout << "\n\n\t\tMULTIPLAYER HIGH ROLLER GAME\n\n";
    drawLine(60, '_');

    cout << "\nPlayer 1, enter your name: ";
    cin >> player1;
    cout << "Enter deposit amount to play game: $";
    cin >> amount;

    cout << "\nPlayer 2, enter your name: ";
    cin >> player2;
    cout << "Enter deposit amount to play game: $";
    cin >> amount2;

    do {
        cout << "\033[2J\033[0;0H";; // Use system("cls") on Windows or System("clear")
        rules();

        cout << "\n" << player1 << "'s balance is $" << amount << "\n";
        cout << player2 << "'s balance is $" << amount2 << "\n";

        // Player 1 betting amount
        do {
            cout << player1 << ", enter money to bet: $";
            cin >> bettingAmount;
            if (bettingAmount > amount) {
                cout << "Betting amount is more than your current balance.\nRe-enter data.\n";
            }
        } while (bettingAmount > amount);

        // Player 2 betting amount
        do {
            cout << player2 << ", enter money to bet: $";
            cin >> bettingAmount2;
            if (bettingAmount2 > amount2) {
                cout << "Betting amount is more than your current balance.\nRe-enter data.\n";
            }
        } while (bettingAmount2 > amount2);

        roll = rand() % 10 + 1; // Roll between 1 and 10
        roll2 = rand() % 10 + 1;

        cout << player1 << " rolled a " << roll << endl;
        cout << player2 << " rolled a " << roll2 << endl;

        if (roll > roll2) {
            cout << player1 << " wins $" << bettingAmount2 << "!\n";
            amount += bettingAmount2;
            amount2 -= bettingAmount2;
        } else if (roll2 > roll) {
            cout << player2 << " wins $" << bettingAmount << "!\n";
            amount2 += bettingAmount;
            amount -= bettingAmount;
        } else {
            cout << "It's a draw.\n";
        }

        cout << player1 << ", you have $" << amount << "\n";
        cout << player2 << ", you have $" << amount2 << "\n";

        if (amount == 0 || amount2 == 0) {
            cout << (amount == 0 ? player1 : player2) << " has no money to play.\n";
            break;
        }

        cout << "Do you want to play again (Y/N)? ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    drawLine(70, '=');
    cout << "\nThanks for playing. " << player1 << "'s balance is $" << amount << "\n";
    cout << player2 << "'s balance is $" << amount2 << "\n";
    drawLine(70, '=');

    return 0;
}

void drawLine(int n, char symbol) {
    for (int i = 0; i < n; i++) cout << symbol;
    cout << "\n";
}

void rules() {
    cout << "\033[2J\033[0;0H";; // Use system("cls") on Windows or System("clear")
    drawLine(80, '-');
    cout << "\tRULES OF THE GAME\n";
    drawLine(80, '-');
    cout << "\t1. Each player rolls a die; the higher roll wins the round.\n";
    cout << "\t2. The winner takes the loser's bet.\n";
    cout << "\t3. If it's a draw, no money is exchanged.\n";
    drawLine(80, '-');
    cout << "\n";
}
