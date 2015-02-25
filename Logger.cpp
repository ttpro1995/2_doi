#include "Logger.h"
#include <sstream>

Logger::Logger(int num_of_player,int log_num)
{
	this->num_of_player = num_of_player;
	stringstream ss;
	ss << log_num;
	this->log_num = ss.str();


	init_win();
	init_card();
}

void Logger::init_win()
{
	winlogname = "winlog" + log_num + ".csv";
	winfout.open(winlogname);
	for (int i = 0; i < num_of_player; i++)
	{
		winfout << "Player ";
		winfout << i;
		if (i != (num_of_player - 1)) winfout << ",";
	}
	winfout << endl;
}

void Logger::init_card()
{
	cardlogname = "cardlog" + log_num + ".csv";
	cardfout.open(cardlogname);
	for (int i = 0; i < num_of_player; i++)
	{
		cardfout << "Player ";
		cardfout << i;
		if (i == 0) cardfout << ",,,,,,pair,";//player 0 have 6 card
		else//not player 0
			 cardfout << ",,,,,pair,";//player 1 2 3 ... have 5 card
	}
	cardfout << endl;
}

Logger::~Logger()
{
	winfout.close();
}

void Logger::MarkWinner(int winner)
{
	for (int i = 0; i < num_of_player; i++)
	{
		if (winner == i) winfout << "1";
		else winfout << "0";
		if (i != (num_of_player - 1)) winfout << ",";
	}
	winfout << endl;
}

void Logger::CardLog(string player[10][6])
{
	for (int i = 0; i < 6; i++)//player 0 have 6 cards
	{
		cardfout << player[0][i];
		cardfout << ",";
		
	}
	cardfout << CardPair(player[0], 6) << ",";

	for (int i = 1; i < num_of_player; i++)//from player 1
	{
		for (int j = 0; j < 5; j++)//each player have 5 cards
		{
			cardfout << player[i][j];
			cardfout << ",";
		}
		cardfout << CardPair(player[i],5) << ",";
	}
	cardfout << endl;//new row
	
}

int Logger::CardPair(string hand[6], int num_of_card)
{
	int pair = 0;
	for (int i = 0; i < num_of_card; i++)
		for (int j = i + 1; j < num_of_card; j++)
		{
			if (hand[i][0] == hand[j][0]) 
				pair++;  //if it is pair (3S and 3D is a pair)
		}
	return pair;
	
}