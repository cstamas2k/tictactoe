#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'};

uint8_t maxCpuTries = 9;
uint8_t currCpuTries = 0;

/*
 *  0 | 1 | 2 
 *------------
    3 | 4 | 5 
  ------------
    6 | 7 | 8   */

bool isWinned() {
	if ((board[0] == board[1]) && (board[1] == board[2])) return true;
	if ((board[3] == board[4]) && (board[4] == board[5])) return true;
	if ((board[6] == board[7]) && (board[7] == board[8])) return true;
	if ((board[0] == board[3]) && (board[3] == board[6])) return true;
	if ((board[1] == board[4]) && (board[4] == board[7])) return true;
	if ((board[2] == board[5]) && (board[5] == board[8])) return true;
	if ((board[0] == board[4]) && (board[4] == board[8])) return true;
	if ((board[2] == board[4]) && (board[4] == board[6])) return true;
	return false;
}

void cpuMove() {
	currCpuTries++;
	if (currCpuTries >= maxCpuTries) return;
	uint8_t location = std::rand() % 9; //between 0-8
	if (board[location] != 'X' && board[location] != 'O') { board[location] = 'O'; } else cpuMove();
}

int main(int argc, char* argv[]) {
	bool playGame = true;
	std::srand(std::time(nullptr));
	while (playGame) {
		system("clear");
		std::cout << "tic-tac-toe written by cstamas2k\n\n";
		if (isWinned()) {
			std::cout << "\033[0;31mGame over\033[0m\n";
			playGame = false;
		}
		std::cout << "  " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
		std::cout << "------------" << std::endl;
		std::cout << "  " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
		std::cout << "------------" << std::endl;
		std::cout << "  " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;

		std::cout << "\nSelect a number to place an X (computer uses O)\n";
		std::cout << "Press q to exit\n";
		char input;
		std::cin >> input;

		switch(input) {
			case '1': input=0; break;
			case '2': input=1; break;
			case '3': input=2; break;
			case '4': input=3; break;
			case '5': input=4; break;
			case '6': input=5; break;
			case '7': input=6; break;
			case '8': input=7; break;
			case '9': input=8; break;
			case 'q': playGame = false; break;
			default: input = 10;
		}
		
		if (!playGame) break;

		if (input == 10) {
		std::cout << "Bad input... exitting";
		playGame = false;
		}
		if (board[input] != 'X' && board[input] != 'O') {
		board[input] = 'X';
		} else {
		std::cout << "You selected an already occupied cell.\n";
		sleep(3);
		continue;
		}
		std::cout << "You selected " << input << ". Cpu moves...\n";
		currCpuTries = 0;
		cpuMove();
		sleep(1);
	}

	return 0;
}
