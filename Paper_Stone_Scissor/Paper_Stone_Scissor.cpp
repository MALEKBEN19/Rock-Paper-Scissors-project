#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;


//cleaer debug consol
void CleaerDebugConsol() {
	system("color 0F");
	system("cls");
	system("color 0F");
}
char GiveAnswer() {
	char answer = ' ';
	cout << "\t\t\tDo you want to play again? Y or N ";
	cin >> answer;
	return answer;
}
bool CheckIfPlayAgain() {
	char answer = GiveAnswer();
	if (answer == 'y' || answer == 'Y') {
		return 1;
	}
	else {
		return 0;
	}
}



int RandomNumber(int from, int to) {
	int RandomN = rand() % (to - from + 1) + from;
	return RandomN;
}



enum enGetChoice{Paper=1,Stone=2,Scissor=3};
enum enPickWinner{Player1=1,Computer=2,NoWinner=3};



short HowManyRounds() {
	short rounds;
	do {
		cout << "How many rounds do you want to play? 1 to 10\n";
		cin >> rounds;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Worng Value, please enter how many rounds again? ";
			cin >> rounds;
		}
	} while (rounds <= 0 || rounds > 10);
	return rounds;
}



enGetChoice UserChoice() {
	short userchoice=0;
	
	cout << "Your choice {1} Paper . {2} Stone . {3} Scissor ?\n";
	cin >> userchoice;
	return enGetChoice(userchoice);
}
enGetChoice ComputerChoice() {
	short ComputerChoice=RandomNumber(1,3);
	return enGetChoice(ComputerChoice);
}


enPickWinner ChooseWinnerForRound(enGetChoice UserChoice, enGetChoice ComputerChoice) {
	if (UserChoice == Paper) {
		if (ComputerChoice == Stone) {
			system("color 2F ");
			return enPickWinner::Player1;
		}
		else if (ComputerChoice == Scissor) {
			system("color 4F ");
			cout << "\a";
			return enPickWinner::Computer;
		}
		else if(UserChoice==ComputerChoice){
			system("color 6F ");
			return enPickWinner::NoWinner;
		}
	}
	else if (UserChoice == Stone) {
		if (ComputerChoice == Scissor) {
			system("color 2F ");
			return enPickWinner::Player1;
		}
		else if (ComputerChoice == Paper) {
			system("color 4F ");
			cout << "\a";
			return enPickWinner::Computer;
		}
		else if (UserChoice == ComputerChoice) {
			system("color 6F ");
			return enPickWinner::NoWinner;
		}
	}
	else if (UserChoice == Scissor) {
		 if (ComputerChoice == Paper) {
			system("color 2F ");
			return enPickWinner::Player1;
		 }
		 else if (ComputerChoice == Stone) {
			system("color 4F ");
			cout << "\a";
			return enPickWinner::Computer;
		 }
		 else if (UserChoice == ComputerChoice) {
			 system("color 6F ");
			 return enPickWinner::NoWinner;
		 }
	}
	else {
		system("color 6F ");
		return enPickWinner::NoWinner;
	}
}
string PrintWinnerForOneRound(enPickWinner winner ) {
	switch (winner) {
	case enPickWinner::Player1:return "Player 1";
	case enPickWinner::Computer:return "Computer";
	case enPickWinner::NoWinner:return "No Winner";
	}
	return "No Winner";
}


string ConvertUserChoiceTostring(enGetChoice UserChoice) {
	switch (UserChoice) {
	case enGetChoice::Paper:return "Paper";
	case enGetChoice::Stone:return "Stone";
	case enGetChoice::Scissor:return "Scissor";
	}
	return "";
}
string ConvertComputerChoiceTostring(enGetChoice ComputerChoice) {
	switch (ComputerChoice) {
	case enGetChoice::Paper:return "Paper";
	case enGetChoice::Stone:return "Stone";
	case enGetChoice::Scissor:return "Scissor";
	}
	return "";
}


void countWinnr(enPickWinner winner,int &playercounter,int &ComputerCounter,int &NoWinnerCounter) {
	if (winner == Player1) {
		playercounter++;
	}
	else if (winner==Computer) {
		ComputerCounter++;
	}
	else {
		NoWinnerCounter++;
	}
}

string DeciedfinalWinner(int playercounter, int ComputerCounter, int NoWinnerCounter) {

	if (playercounter > ComputerCounter)
	{
		system("color 2F");
		return "Player 1";
	}
	else if(ComputerCounter > playercounter) {
		system("color 4F");
		return "Computer";
	}
	else {
		system("color 6F");
		return "No winner";
	}
}

void GameOverMenu(short round,int Playercounter,int computercounter,int nowinner) {

	cout << "\n\n\t\t\t__________________________________________\n\n";
	cout << "\t\t\t           +++ Game Over +++ \n";
	cout << "\t\t\t__________________________________________\n\n\n";
	cout << "\t\t\t_____________[Game Result]________________\n\n";
	cout << "\t\t\t Game round        : " << round << endl;
	cout << "\t\t\t Player 1 won time : " << Playercounter << endl;
	cout << "\t\t\t Computer won time : " << computercounter << endl;
	cout << "\t\t\t Draw time         : " << nowinner << endl;
	cout << "\t\t\t Final winner      : " << DeciedfinalWinner(Playercounter, computercounter, nowinner)<<endl;
	cout<<"\t\t\t__________________________________________\n\n";

}

void StartTheGame() {
	short rounds = HowManyRounds();
	int Playercounter = 0;
	int computercounter = 0;
	int nowinner = 0;

	enGetChoice userChoice;
	enGetChoice computerChoice;
	enPickWinner winner;

	for (int x = 1; x <=rounds;x++) {
		cout << "Round [" << x << "] begin :\n";
		userChoice = UserChoice();
		computerChoice = ComputerChoice();
		winner = ChooseWinnerForRound(userChoice, computerChoice);
		cout << "\n\n_____________[" << x << "]_____________\n\n";
		cout << " Player choice   :  " << ConvertUserChoiceTostring(userChoice) << endl;
		cout << " Computer choice :  " << ConvertComputerChoiceTostring(computerChoice) << endl;
		cout << " Round winner    : [" << PrintWinnerForOneRound(winner) << "]" << endl;
		cout << "_____________________________\n\n";
		countWinnr(winner, Playercounter, computercounter, nowinner);
	}

	GameOverMenu(rounds,Playercounter, computercounter, nowinner);

}

void RunTheGame() {
	bool clear;
	do {
		CleaerDebugConsol();
		StartTheGame();
		clear = CheckIfPlayAgain();
	} while (clear);
}

int main() {
	srand((unsigned)time(NULL));
	RunTheGame();
	return 0;
}