// Author      : K.Uday Kumar Reddy
// Date        : 12-01-2024
// Description : Rock-Paper-Scissor Game

#include <iostream>
#include <cstring> //for using to convert lower to upper case alphabet(R,P,S)
#include <cstdlib> //for using rand() function
#include <ctime>   //for using time() function


std::string RPS[3] = { "ROCK","PAPER","SCISSOR" }; // string notations of R,P,S


char getUserInput() { //input from the user
	char choice;
	std::cout << "\t\t\t\tenter your choice: ";
	std::cin >> choice;
	if (islower(choice)) {
		choice = toupper(choice);   // if user enter lower case (r,p,s) it converts into uppercase (R,P,S)
	}
	return choice;
}
char getComputerInput() {   //input from the computer
	char charset[3] = { 'R','P','S' };
	srand(time(NULL)); //the computer will choose (R,P,S) at the same time when the user gives input on the screen 
	int index = rand() % (sizeof(charset) - 1);
	return charset[index];
}
std::string getString(char Choice) { // to convert into string notation of (R,P,S) and return 
	if (Choice == 'R') {
		return RPS[0];
	}
	if (Choice == 'P') {
		return RPS[1];
	}
	return RPS[2];
}

std::string decideWinner(char userInput, char computerInput) { // function to decide the winner and return
	if (userInput == 'R' && computerInput == 'P') {
		return "Computer Wins!";
	}
	if (userInput == 'R' && computerInput == 'S') {
		return "You Win!";
	}
	if (userInput == 'P' && computerInput == 'R') {
		return "You Win!";
	}
	if (userInput == 'P' && computerInput == 'S') {
		return "Computer Wins!";
	}
	if (userInput == 'S' && computerInput == 'R') {
		return "Computer Wins!";
	}
	if (userInput == 'S' && computerInput == 'P'){
		return "You Win!";
	}
	return "Draw!";
}

int main() {
	char userChoice;
	char computerChoice;
	std::string userEntered; // string notation of user input
	std::string computerEntered; // string notation of  computer input
	std::cout << "\t\t\t___ Welcome to ROCK-PAPER-SCISSOR game ___\n\n";
	std::cout << "\t\t    Enter R for \"Rock\", P for \"PAPER\", S for \"SCISSOR\".\n";
	userChoice = getUserInput();
	computerChoice = getComputerInput();
	while (1) {   //looping until the user give the valid input
		if (userChoice != 'R' && userChoice != 'P' && userChoice != 'S') {
			std::cout << "\t\t\t\t  invalid input\n";
			userChoice = getUserInput();
		}
		else {
			break;
		}
	}
	userEntered = getString(userChoice);
	computerEntered = getString(computerChoice);
	std::cout << "\n\t\t\t\tUser's Input    : " << userEntered << "\n";
	std::cout << "\t\t\t\tComputer's Input: " << computerEntered << "\n\n";
	std::string winner = decideWinner(userChoice, computerChoice);
	std::cout << "\t\t\t\t" << winner << "\n\n";
	// looping the above process if the user wants to play the game again and again until user get bored
	while (1) {
		std::cout << "\n\t\t\t\tTo play again press \"C\".\n";
		std::cout << "\t\t\t\tTo Exit the game press \"Q\".\n";
		char choice; // variable is using weather the player want to play again or exit the game
		std::cout << "\t\t\t\t\t   ";
		std::cin >> choice;
		if (islower(choice)) {
			choice = toupper(choice);
		}
		if (choice == 'Q') {
			break;
		}
		else if (choice == 'C') {
			userChoice = getUserInput();
			while (1) { // looping until the user give the valid input based on given condition lines 83-84
				if (userChoice != 'R' && userChoice != 'P' && userChoice != 'S') {
					std::cout << "\t\t\t\t  invalid input\n";
					userChoice = getUserInput();
				}
				else {
					break;
				}
			}
			userEntered = getString(userChoice);
			std::cout << "\n\t\t\t\tUser's Input    : " << userEntered << "\n";
			computerChoice = getComputerInput();
			computerEntered = getString(computerChoice);
			std::cout << "\t\t\t\tComputer's Input: " << computerEntered << "\n\n";
			winner = decideWinner(userChoice, computerChoice);
			std::cout << "\t\t\t\t" << winner << "\n\n";
		}
		else {
			std::cout << "\n\t\t\t        \"oops wrong choice\"\n";  //if user input invalid choice 
		}
	}
	return 0;
}
