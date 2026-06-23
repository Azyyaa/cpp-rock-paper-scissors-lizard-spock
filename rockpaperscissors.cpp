#include <iostream>
# include <ctime>
using namespace std;
enum Choise {
	Rock = 1,
	Scissors,
	Paper,
	Lizard,
	Spock
};

void menu();
string playerChoise(Choise selection);//vozvrashayet v vide stroki vibor "selection"
Choise ezcomputerChoise();//vibor computera
Choise hardcomputerChoise();
Choise ezuserChoise();//vibor polzovatelya
Choise harduserChoise();
void rules();//pravila
void gamesettings();
void gamemode();
void theme();
void hardgame();
void ezgame();
string ezwinner(Choise user, Choise computer);//opredeleniye pobeditelya
string hardwinner(Choise user, Choise computer);

bool isEasymode = true;

Choise user;
Choise computer; 

int main() {
	bool IsGameContinue = true;


	while (IsGameContinue) {
		menu();
		int menuItem;
		cout << "Choose menu item: ";
		cin >> menuItem;
		switch (menuItem) {
		case 1:
			system("cls");
			if (isEasymode) {
				user = ezuserChoise();
				computer = ezcomputerChoise();
				system("cls");
				cout << "You choose: " << playerChoise(user)<< endl << "Computer choose: " << playerChoise(computer)<< endl << ezwinner(user, computer) << endl;
			}
			else {
				user = harduserChoise();
				computer = hardcomputerChoise();
				system("cls");
				cout << "You choose: " << playerChoise(user) << endl << "Computer choose: " << playerChoise(computer) << endl << hardwinner(user, computer) << endl;
			}
			system("pause");
			break;
		case 2:
			system("cls");
			rules();
			system("pause");
			break;
		case 3:
			system("cls");
			gamesettings();
			break;
		case 4:
			system("cls");
			cout << "Why???? I wrote the entire code for 3 hours!!!" << endl;
			system("pause");
			IsGameContinue = false;
			break;
		}
	}

}

void menu() {
	system("cls");
	cout << "Rock/Scissors/Paper and Rock/Scissors/Paper/Lizard/Spock!" << endl;
	cout << "1. New Game" << endl;
	cout << "2. Rules" << endl;
	cout << "3. Settings" << endl;
	cout << "4. Exit Game" << endl;


}

string playerChoise(Choise selection) {
	switch (selection) {
	case Rock:
		return "Rock";
		break;
	case Scissors:
		return "Scissors";
		break;
	case Paper:
		return "Paper";
		break;
	case Lizard:
		return "Lizard";
		break;
	case Spock:
		return "Spock";
		break;
	default:
		return "Wrong choise!";
		break;
	}

}

Choise ezcomputerChoise() {
	srand(time(0));
	int select = rand() % 3 + 1;
	return static_cast <Choise> (select);
}

Choise hardcomputerChoise() {
	srand(time(0));
	int select = rand() % 5 + 1;
	return static_cast <Choise> (select);
}

Choise ezuserChoise() {
	int select;
	cout << "Choose: \n1-Rock\n2-Scissors\n3-Paper " << endl;
	cin >> select;
	return static_cast<Choise>(select);
}

Choise harduserChoise() {
	int select;
	cout << "Choose: \n1-Rock\n2-Scissors\n3-Paper\n4-Lizard\n5-Spock " << endl;
	cin >> select;
	return static_cast<Choise>(select);
}



string ezwinner(Choise user, Choise computer) {
	string winner = "";
	if (user == computer) {
		winner = "Draw";
	}
	else if ((user == 1 && computer == 2) || (user == 2 && computer == 3) || (user == 3 && computer == 1)) {
		winner = "You win";
	}
	else if ((user == 1 && computer == 3) || (user == 2 && computer == 1) || (user == 3 && computer == 2)) {
		winner = "Computer wins!";
	}
	else {
		winner = "Something went wrong!";
	}
	return winner;
}

string hardwinner(Choise user, Choise computer) {
	string winner = "";
	if (user == computer) {
		winner = "Draw";
	}
	else if ((user == 1 && computer == 2) || (user == 2 && computer == 3) || (user == 3 && computer == 1) || (user == 4 && computer == 5) || (user == 4 && computer == 3) || (user == 5 && computer == 1) || (user == 5 && computer == 2)) {
		winner = "You win";
	}
	else if ((user == 1 && computer == 3) || (user == 2 && computer == 1) || (user == 3 && computer == 2) || (user == 5 && computer == 4) || (user == 3 && computer == 4) || (user == 1 && computer == 5) || (user == 2 && computer == 5)) {
		winner = "Computer wins!";
	}
	else {
		winner = "Something went wrong!";
	}
	return winner;
}

void gamesettings() {
	int settingsChoice;
	cout << "   --- Settings ---   " << endl;
	cout << "1-Gamemode\n2-Theme\n3-Exit" << endl;
	cin >> settingsChoice;
	switch (settingsChoice) {
	case 1:
		return gamemode();
		break;
	case 2:
		return theme();
		break;
	case 3:
		system("cls");
		break;
	default:
		cout<< "wrong choice!";
		break;
	}
}

void hardgame(){
	isEasymode = false;
}

void ezgame() {
	isEasymode = true;
}

void gamemode() {
	int gamemode;
	cout << "Choose game mode:\n1-Easy\n2-Hard\n";
	cin >> gamemode;
	if (gamemode == 1) {
		ezgame();
	}
	else if (gamemode == 2) {
		hardgame();
	}
	else {
		cout << "wrong choice" << endl;
	}
}



void theme() {
	system("cls");
	int themeChoice;
	cout << "Choose theme:\n1-blue background and white font\n2-black background and red font\n3-white background and black font\n4-white background and blue font\n";
	cin >> themeChoice;
	switch (themeChoice) {
	case 1:
		system("color 9F");
		break;
	case 2:
		system("color 0C");
		break;
	case 3:
		system("color F0");
		break;
	case 4:
		system("color F9");
		break;
	default:
		cout << "wrong choice";
		break;
	}
}


void rules() {
	cout << "The game is played with three"
		"possible hand signals that represent a rock,"
		"paper, and scissors. The rock is a closed fist;"
		"paper is a flat hand with fingers and thumb extended"
		"and the palm facing downward; and scissors is a fist "
		"with the index and middle fingers fully extended "
		"toward the opposing player. Rock wins against scissors;"
		"paper wins against rock; and scissors wins against paper."
		"If both players throw the same hand signal, it is"
		"considered a tie, and play resumes until there is"
		"a clear winner."
		"The hand signals are given simultaneously by both players."
		"The ritual used to get players in sync with each other so"
		"they can deliver their throws simultaneously is called the prime."
		"This action requires retracting the player’s fist from full - "
		"arm extension towards the shoulder and then back to full extension."
		"To ensure a fair match the players must be in sync with their primes."
		"Players must determine before play how many times they pump their"
		"arms during the prime phase, usually two or three times before the"
		"final delivery of their throw." << endl;
}