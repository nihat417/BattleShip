#include <iostream> 
#include <time.h> 
#include <windows.h> 
#include <conio.h> 

using namespace std;

#include"model.h"
#include"function.h"



int main()
{
	setlocale(LC_ALL, "AZE");
	SetConsoleTitleA("Battle ship");

	srand(time(0));

	firstSee();

	Sleep(1500);

	char choisetext[3][30] = { "avtomatik secim","oyun haqqda","cixis" };
	int change = 0;//secimin baslanmasi

	coremenu(choisetext, change);
	menuSit(choisetext, change);


}