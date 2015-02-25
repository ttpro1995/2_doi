#pragma once
#include "Logger.h"
void Divide_Cards();
bool Check(int competitor);
void Initialize(Logger&);
bool Decision_Strategy(int competitor);
void Output();
void Shuffle();
int Loop();
int Start(Logger&);
bool Draw_Card(int competitor, int mode);
void Shuffle();
int Play(int test_case);