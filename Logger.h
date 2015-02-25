#pragma once
#include <fstream>
using namespace std;

/*
Log winner 
output: A csv file name winlog0.csv, winlog1.csv ...
Column name is number of player, from player 0 to num_of_player -1
Each row will be each match
if player win, 1, else 0

ex:
Player 0,Player 1,Player 2,Player 3,Player 4
0,0,0,1,0
0,0,1,0,0

player 3 win first match then player 2 win second match
*/
/*
Log pair
input: a string array of player hand
player[10][6]
output: A csv file
player 0: 7 column, which 
		6 column are card on his hand
		7th column is number of pair he have

from player 1 have 6 column, which 
			5 column are card on his hand
			6th column is number of pair he have

ex
Player 0,,,,,,pair,Player 1,,,,,pair,Player 2,,,,,pair,Player 3,,,,,pair,Player 4,,,,,pair,
1a,2b,3c,4d,5e,6f,0,1a,2b,1c,4d,5e,1,1a,2b,3c,4d,5e,0,1a,2b,3c,4d,5e,0,1a,2b,3a,4d,5e,0,


from the data above
player 0 have 6 card which is 1a,2b,3c,4d,5e,6f
player 0 will have 0 pair
player 1 have 1a,2b,1c,4d,5e
player 1 have 1 pair

*/

class Logger
{
private:
	string log_num;

	//log winner for each round
	ofstream winfout;
	string winlogname;
	void init_win();

	//log card of each player each round
	ofstream cardfout;
	void init_card();
	string cardlogname;
	int CardPair(string hand[6], int num_of_card);//player 0 have 6 card, else 5 card

	int num_of_player;
public:
	//num_of_player is number of player
	//log_num is name of log. 
	//ex: log_num=1, log will name winlog1.csv and cardlog1.csv
	Logger(int num_of_player,int log_num);

	~Logger();

	//winlog
	//input: position of winner, from 0 
	void MarkWinner(int winner);

	//cardlog
	//input : string player [10][6]
	void CardLog(string player[10][6]);

};

