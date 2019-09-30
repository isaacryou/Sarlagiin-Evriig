//A program that imitates Sarlagiin Evriig, traditional game in Siberian region of Tyva

#include <stdio.h>
#include <stdlib.h>

int computerStrategy(int, int*);
int playerStrategy(int, int*);
void EnterRandomSeed();

int main() {
	//First part of function.
	//Call EnterRandomSeed and declare variables used in program
	EnterRandomSeed();
	char a;
	char b;
	char c;
	int first = 0;
	int loop = 1;
	int playerSteak = 10;
	int computerSteak = 10;
	int playerScore = 0;
	int computerScore = 0;
	int winner = 0;
	int myRandomNum;
	printf("Welcome to Sarlagiin Evriig!\n");
	printf("Would you like to play? (Y\\N)\n");
	scanf(" %c", &c);
	if (c == 78 || c == 110) {
		return 0;
	}
	printf("Would you like to throw first?(Y\\N)\n");
	scanf(" %c", &a);
	//If character is lower case alphabet, make it upper case
	if ((a >= 97) && (a <= 122)) {
		a -= 32;
	}
	//If a is Y, set first to 1 which will cause player to go first
	switch (a) {
		case 'Y':
			first = 1;
			break;
		case 'N':
			break;
	}		
	//Variable loop is set to 1. The loop will be changed to 0 when player decided to quit the game.
	while(loop) {
		if (first == 1) {
			//Call function to perform players play. If player scores more than 132, 
			//player wins and does not let computer play
			playerScore = playerStrategy(playerScore, &myRandomNum);
			if (playerScore >= 132) {
				winner = 1;
			} else {
				//Call function to perform computer play. If computer scores more than 132,
				//computer wins
				computerScore = computerStrategy(computerScore, &myRandomNum);
				if (computerScore >= 132) {
					winner = 2;
				}
			}
		} else if (first == 0) {
			//Call function to perform computer play. If computer scores more than 132,
			//computer wins and does not let player play.
			computerScore = computerStrategy(computerScore, &myRandomNum);
			if (computerScore >= 132) {
				winner = 2;
			} else {
				//Call function to perform player play. If plyaer scores more than 132,
				//player wins
				playerScore = playerStrategy(playerScore, &myRandomNum);
				if (playerScore >= 132) {
					winner = 1;
				}
			}
		}
		printf("Total player score: %d\n", playerScore);
		printf("Total computer score: %d\n", computerScore);	
		//Check if there is winner and add and subtract steak from winner and loser
		if (winner == 1) {
			playerScore = 0;
			computerScore = 0;
			playerSteak += 1;
			computerSteak -=1;
			printf("Player steak = %d\nComputer steak = %d\n" , playerSteak, computerSteak);
		} else if (winner == 2) {
			playerScore = 0;
			computerScore = 0;
			playerSteak -= 1;
			computerSteak += 1;
			printf("Player steak = %d\nComputer steak = %d\n" , playerSteak, computerSteak);
		}
		//If any player has 0 steak, end the game
		if ((playerSteak == 0) || (computerSteak == 0)) {
			printf("Player steak = %d\nComputer steak = %d\n" , playerSteak, computerSteak);
			printf("Game ended. Thanks for playing!\n");
			break;
		}
		//If there is winner, ask player if he or she wants to play again, 
		//and either start new game or end.
		if (winner != 0) {
			printf("Would you like to play again?\n");
			scanf(" %c",&b);
			if ((b >= 97) && (b <= 122)) {
                		b -= 32;
			}
			switch (b) {
				case 'Y':
					printf("Would you like to throw first?(Y\\N)\n");
					scanf(" %c", &a);
					if (a == 89 || a == 121) {
						first = 1;
					} else if (a == 78 || a == 110) {
						first = 0;
					}
					winner = 0;
					break;
				case 'N':
					loop = 0;
					printf("Player steak = %d\nComputer steak = %d\n", playerSteak, computerSteak);
					printf("Game ended. Thanks for playing!\n");
					break;
			}
		}
	} return 0;
}

int playerStrategy(int playerScore, int *Random) {
	int a = 1;
	int score = 0;
	char answer = ' ';
	printf("Player turn!\n");
	//Loop until Dooshni Ever, Khurtel Ever, or player decides to not throw
	while (a) {
		//Random value will be stored at the memory address of myRandomNum
		*Random = random()%100;
		//Check if random value is Dooshni Ever, Khurtel Ever, or other number
		if (*Random <= 16) {
			score = 0;
			printf("Dooshni Ever! Score is %d\n", score);
			break;
		} else if (*Random <= 32) {
			printf("Khurtel Ever! Score is %d\n", score);
			break;
		} else if (*Random <= 55) {
			score += 2;
			printf("Score is %d\n", score);
		} else if (*Random <= 68) {
			score += 3;
			printf("Score is %d\n", score);
		} else if (*Random <= 83) {
			score += 5;
			printf("Score is %d\n", score);
		} else if (*Random <= 92) {
			score += 10;
			printf("Score is %d\n", score);
		} else {
			score += 15;
			printf("Score is %d\n", score);
		}
		//If current score + earned score is more or equal to 132, return the value
		if ((playerScore + score) >= 132) {
			return playerScore + score;
		}
		printf("Random value is: %d\n", *Random);
		//Ask if player wants to throw again.
		//If answer is yes, loop again.
		//If answer is no, return current score + playerScore
		printf("Would you like to throw again?(Y\\N)\n");
		scanf( " %c", &answer);
		if (answer == 'N' || answer == 'n') {
			a = 0;
		}
	}
	return playerScore + score;
}

int computerStrategy(int computerScore, int *Random) {
	int score = 0;
	printf("Computer turn!\n");
	//Loop until Dooshni Ever, Khurtel Ever, or gained score over 25.
	while (score <= 25) {
		*Random = random()%100;
		//Check if random value is Dooshni Ever, Khurtel Ever, or other number
		if (*Random <= 16) {
			score = 0;
			printf("Dooshni Ever! Score is %d\n", score);
			break;
		} else if (*Random <= 32) {
			printf("Khurtel Ever! Score is %d\n", score);
			break;
		} else if (*Random <= 55) {
			score += 2;
			printf("Score is %d\n", score);
		} else if (*Random <= 68) {
			score += 3;
			printf("Score is %d\n", score);
		} else if (*Random <= 83) {
			score += 5;
			printf("Score is %d\n", score);
		} else if (*Random <= 92) {
			score += 10;
			printf("Score is %d\n", score);
		} else {
			score += 15;
			printf("Score is %d\n", score);
		}
		printf("Random value is: %d\n", *Random);
		//If current score + score earned is more or equal to 132, return the value
		if ((computerScore + score) >= 132) {
			return computerScore + score;
		}
	}
	return computerScore + score;
}

void EnterRandomSeed()
{
	int myRandomSeed;
	printf("Please enter a random number seed: ");
	scanf("%d", &myRandomSeed);
	srandom(myRandomSeed);
}
