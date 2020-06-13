#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;





void drawLine(int n, char symbol);
void rules();

int main() {
	srand(time(NULL));
	string player1;
	string player2;
	int amount;
	int amount2;
	int bettingAmount;
	int bettingAmount2;
	int roll;
	int roll2;
	char playAgain;

	drawLine(60, '_');
	cout << "\n\n\n\t\tMULTIPLAYER: HIGH ROLLER GAME\n\n\n\n";
	drawLine(60, '_');

	cout << "\n\nPlayer 1 enter your name : ";
	cin >> player1;

	cout << "\n\nEnter Deposit amount to play game : $";
	cin >> amount;

	cout << "\n\nPlayer 2 enter your name : ";
	cin >> player2;

	cout << "\n\nEnter Deposit amount to play game : $";
	cin >> amount2;
	do
	{
		system("cls");
		rules();
		cout << "\n\n" << player1 <<"'s"<< " balance is $ " << amount << "\n";
		cout << "\n\n" << player2 << "'s" << " balance is $ " << amount2 << "\n";

				// get the betting amount
		do
		{
			cout << player1 << ", enter money to bet : $";
			cin >> bettingAmount;
			if (bettingAmount > amount)
				cout << "Your betting amount is more than your current balance\n"
				<< "\nRe-enter data\n ";
		} while (bettingAmount > amount);

		do
		{
			cout << player2 << ", enter money to bet : $";
			cin >> bettingAmount2;
			if (bettingAmount2 > amount2)
				cout << "Your betting amount is more than your current balance\n"
				<< "\nRe-enter data\n ";
		} while (bettingAmount2 > amount2);

		roll = rand() % 500;
		roll2 = rand() % 500;
		cout << player1 << " rolled a: " << roll << endl;
		cout << player2 << " rolled a: " << roll2 << endl;

		if (roll > roll2) {
			cout << player2 << " lost $" << bettingAmount2 << endl;
			cout << player1 << " won $" << bettingAmount2 << " CONGRATULATIONS!!" << endl;
			amount = amount + bettingAmount2;
			amount2 = amount2 - bettingAmount2;
		}
		else if (roll2 > roll) {
			cout << player1 << " lost $" << bettingAmount << endl;
			cout << player2 << " won $" << bettingAmount << " CONGRATULATIONS!!" << endl;
			amount2 = amount2 + bettingAmount;
			amount = amount - bettingAmount;

		}
		else
			cout << player1 << " and " << player2 << "draw" << endl;
			amount = amount;
			amount2 = amount2;
		
		cout << "\n" << player1 << ", You have $ " << amount << "\n";
		cout << "\n" << player2 << ", You have $ " << amount2 << "\n";
		if (amount == 0) {
			cout << player1 << " has no money to play ";
			break;
		}
		else if (amount2 == 0) {
			cout << player2 << " has no money to play ";
			break;
		}	
		else
			cout << "\n\n-->Do you want to play again (y/n)? ";
			cin >> playAgain;
		
	
	} while (playAgain == 'Y' || playAgain == 'y');

	cout << "\n\n\n";
	drawLine(70, '=');
	cout << "\n\nThanks for playing the game. "<< player1 << "'s balance amount is $" << amount << "\n\n";
	cout << "and " << player2 << "'s balance amount is $" << amount2 << "\n\n";
	drawLine(70, '=');
		
	return 0;
}

void drawLine(int n, char symbol) {
	for (int i = 0; i < n; i++)
		cout << symbol;
	cout << "\n";
}

void rules() {
	system("cls");
	cout << "\n\n";
	drawLine(80, '-');
	cout << "\t\tRULES OF THE GAME\n";
	drawLine(80, '-');
	cout << "\t1. ***Whoever rolls higher wins***\n";
	cout << "\t2. The winner gets the loser's money that they bet\n";
	drawLine(80, '-');
}
