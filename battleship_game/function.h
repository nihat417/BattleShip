#pragma once

#include"protatibe.h"

enum Color {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
	DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta,
	Yellow, White
};

//xususi

//enum Color { Black, Blue, Green, Red, Magenta, Brown, LightGray,
//	DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed,
//	LightMagenta, White };


enum Direction {
	Up = 72, Down = 80, Left = 75, Right = 77,
	Enter = 13
};

void setColor(Color text, Color background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}//reng ucun

void SetCursor(int x, int y) //x y e gore kordinat
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Coord = { x,y };
	SetConsoleCursorPosition(hStdOut, Coord); //lazimi kordinata kecid
}

void firstSee() //1ci ekrana cixan
{
	setColor(Red, Black); //esas ekr rengi
	SetCursor(50, 12);
	cout << R"( 
 _______    ______  ________  ________  __        ________         ______   __    __  ______  _______  
|       \  /      \|        \|        \|  \      |        \       /      \ |  \  |  \|      \|       \ 
| $$$$$$$\|  $$$$$$\\$$$$$$$$ \$$$$$$$$| $$      | $$$$$$$$      |  $$$$$$\| $$  | $$ \$$$$$$| $$$$$$$\
| $$__/ $$| $$__| $$  | $$      | $$   | $$      | $$__          | $$___\$$| $$__| $$  | $$  | $$__/ $$
| $$    $$| $$    $$  | $$      | $$   | $$      | $$  \          \$$    \ | $$    $$  | $$  | $$    $$
| $$$$$$$\| $$$$$$$$  | $$      | $$   | $$      | $$$$$          _\$$$$$$\| $$$$$$$$  | $$  | $$$$$$$ 
| $$__/ $$| $$  | $$  | $$      | $$   | $$_____ | $$_____       |  \__| $$| $$  | $$ _| $$_ | $$      
| $$    $$| $$  | $$  | $$      | $$   | $$     \| $$     \       \$$    $$| $$  | $$|   $$ \| $$      
 \$$$$$$$  \$$   \$$   \$$       \$$    \$$$$$$$$ \$$$$$$$$        \$$$$$$  \$$   \$$ \$$$$$$ \$$
		)";

	";";
}

void coremenu(char choise[3][30], int select) //secim menyusu 
{
	system("cls");
	for (size_t i = 0; i < 3; i++) //3 secim ucun 
	{
		SetCursor(50, i + 10);
		for (size_t p = 0; p < 30; p++) //herf sayna uyqun
		{
			if (i == select)
			{
				setColor(Black, Blue);
			}
			else
			{
				setColor(White, Black);
			}
			cout << choise[i][p]; //secimleri ekrana cixaririq
		}
	}
}

void Creatgameboards(int X)  //oyun xanalarinin cekilmesi
{
	setColor(White, Black);
	SetCursor(X, 1);
	char massv[10] = { 'A', 'B','C','D','E','F','L','M','N','Y' };
	setColor(White, Black); //herflerin rengi
	int A = 0, B = 0; //oyun meydanin duzgn cekmek ucn
	cout << "  " << massv[0]; // A herfini cxarmaq ucun 

	for (size_t i = 0; i < 12; i++) //12 setr oldqycun
	{
		if (B == 0)
		{
			SetCursor(X + 3, 1); //herflercun kursor
			B++;
		}
		else
		{
			SetCursor(X, i + 1);
		}
		for (size_t l = 0; l < 23; l++) // 23 setr olduquycun 23 defe edirik
		{
			if (i == 0 && l == 22) //1 ci setr 22 ci elementde 
			{
				cout << ' '; //reng gor kvadrt 
			}
			if (i == 0 && l > 0 && l < 10) //1ci setr ve 0-10 element arsi
			{
				cout << " " << massv[l];
			}
			else if (i > 0 && i < 11 && l == 0) //0-11  setrde 0 ci elment
			{
				setColor(White, Black);
				if (i < 10)
				{
					cout << i << ' ';
				}
				else
				{
					cout << i;
				}
			}
			else if (i == 11 || l > 20 && l < 23) //11 ci setr
			{
				if (A == 0 && i == 11) //elave kub cixmsin deye yoxlama
				{
					cout << ' ';
					A++;
				}
				setColor(Black, Black);
				cout << ' ';
			}
			else if (i > 0) //0 ci setr deilse
			{
				setColor(White, White); //xananin rengi
				cout << ' ';
			}
		}
	}
	setColor(Black, Black);
}

void paintshippos(int mas[12][24], int x, int numcolor) { //gemiler yerlewmiw halda xerite

	for (size_t i = 1; i < 11; i++) //10 setr oldqycun
	{
		int y = 1 + i; //x-2 y-2 
		SetCursor(x, y);

		for (size_t g = 2; g < 22; g++)  //20 sutun ucn
		{
			if (mas[i][g] == 2)
			{
				setColor(LightGray, LightGray);
			}
			else if (mas[i][g] == 3)
			{
				setColor(LightMagenta, LightMagenta);
			}
			else if (mas[i][g] >= 4)
			{
				setColor(Color(numcolor), Color(numcolor)); //bzm gemiler qara reqb ag
			}
			else
			{
				setColor(White, White); //eks halda ag reng xertenin ici
			}
			cout << " "; //bowdq renge gore kvadra olur
		}
		cout << "\n";
	}
}

void wordGame(int num)
{
	char words[10][40] = { "Reqibin sirasi","Reqib vura bilmedi", "reqib vurdu", "Reqib qalib geldi!", "Sizin gedis" , "Siz vura bilmediniz", "Siz vurdunuz", "Siz qalib geldiniz!",
		"**********************", "Sen vurdun yeniden vur" };

	SetCursor(22, 15);
	setColor(Black, Black);
	for (size_t i = 0; i < 25; i++)
	{
		cout << words[9][i];
		cout << words[9][i];
	}
	SetCursor(22, 15);
	if (num >= 0 && num < 4)
	{
		setColor(Red, Black);
	}
	else
	{
		setColor(Green, Black);
	}
	for (size_t i = 0; i < 30; i++)
	{
		cout << words[num][i];
	}
}

void explosion(Ships* creatship, int shippos[12][24], int plus, int& end) //geminin vrlmasi qalib seclm
{
	int A = 0; //vrlmw geminin etrafinin reng
	int B = 13; //lazimi gemini gosteren 
	int C = 0; //vrlmw gemi sayi 10 olanda qutarir
	bool alive = false;
	for (size_t n = 13; n > 3; n--) //gemijnin nomrelernin maasvde olmasn yoxlrq
	{
		for (size_t i = 1; i < 11; i++) //setr setr
		{
			for (size_t r = 2; r < 22; r++)
			{
				if (shippos[i][r] == n) //massvde gemnin olp lmamasna baxrq
				{
					alive = true;
					i = 11;
					break;
				}
			}
		}
		if (alive == false) //taplmasa vurlb
		{
			creatship[B - n + plus].alive = false; //gemi mehv edlib
		}
		else
		{
			alive = false; //novbeti gemni yoxlamaq ucun
		}
	}

	//qalibin mueyyenlewmesi
	for (size_t i = plus; i < 10 + plus; i++) //butun gemlern vrlmasn yoxlama
	{
		if (i == 0 || i == 10) //4 deneli ucun
		{
			A = 0; //duzgn ceklmesi ucun 0 edry
		}
		else if (i == 1 || i == 2 || i == 11 || i == 12)  //3 deneli
		{
			A = 1;
		}
		else if (i > 2 && i < 6 || i > 12 && i < 16)  //2 deneli
		{
			A = 2;
		}
		else {  //1 deneli

			A = 3;
		}
		if (creatship[i].alive == false)
		{
			if (creatship[i].horizontal == true)
			{
				for (size_t q = 0; q < 3; q++) //bir birbirne yaxn durmasn die
				{
					for (size_t w = 0; w < creatship[i].desck * 3 + A; w++)
					{
						shippos[creatship[i].y - 2 + q][creatship[i].x - 4 + w] = 2; //2 li massvde yoxlanw ucn (2 vurlmadi)
					}
				}
				for (size_t g = 0; g < 2 * creatship[i].desck; g++) //vrlmw gemni secmey ucun
				{
					shippos[creatship[i].y - 1][creatship[i].x - 2 + g] = 3; //3 - vrlb
				}
			}
			else if (creatship[i].horizontal == false) {
				for (size_t q = 0; q < creatship[i].desck + 2; q++)
				{
					for (int w = -4; w < 2; w++)
					{
						shippos[creatship[i].y - 2 + q][creatship[i].x + w] = 2;
					}
				}
				for (int g = 0; g < creatship[i].desck; g++) {
					for (int n = -2; n < 0; n++)
					{
						shippos[creatship[i].y - 1 + g][creatship[i].x + n] = 3;
					}
				}
			}
			C++;//novbeti gemi
		}
	}
	if (C == 10 && plus == 0) //butun gemilerimiz vrlbsa
	{
		end = 1;
	}
	else if (C == 10 && plus == 10)
	{
		end = 2;
	}
	else
	{
		C = 0; //vrlmw gemler 0 lanr
	}
}

void infoAboutgame() {
	system("cls");


	FILE* fPtr;
	fopen_s(&fPtr, "my_file.txt", "r");
	char* buffer = new char[100];

	if (fPtr != nullptr) {
		SetCursor(10, 5);
		while (fgets(buffer, 100, fPtr) != nullptr) {
			cout << buffer;
		}
		fclose(fPtr);
	}
}

void randomplace(Ships* creatship, int shipsposion[12][24], int plus) {
	int y, x, ship = plus; //x,y kord ship gemi nomresi
	while (ship < plus + 10) //10 gemi yerlewmesi ucun
	{
		creatship[ship].horizontal = 0 + rand() % 2; //random eded veririy
		y = 2 + rand() % 9, x = (1 + rand() % 9) * 2; //random kordinat oyun boardi icinde
		if (creatship[ship].horizontal == false && y + creatship[ship].desck >= 13)
			//yern deywmesey donen zaman boardi kecb kecmedyn yoxlyrq
		{
			y -= y + creatship[ship].desck - 12;
		}
		else if (creatship[ship].horizontal == true && x + creatship[ship].desck * 2 >= 24)

		{
			x -= (x + creatship[ship].desck * 2) - 22;
		}
		if (creatship[ship].horizontal == true && shipsposion[y - 1][x] == 0 && shipsposion[y - 1][x + creatship[ship].desck * 2 - 2] == 0)
			//horizontal olub olmadqn yoxlyrq ve qoylacaq yerde baswqa maneninn olmamasna baxrq
		{
			creatship[ship].x = x + 2, creatship[ship].y = y; //geminin goyertelerin yadda saxlrq
			for (size_t q = 0; q < 3; q++) //asagidaki kodu 3 defe yerne yetry cunki geminin etrafi seclmelidi nbir birne yapwq olmasn
			{
				for (size_t w = 1; w < creatship[ship].desck * 3 + 1; w++)
				{
					shipsposion[y - 2 + q][x - 3 + w] = 1;  //vrlmams gemnin vrlmw hissesi
				}
			}
			for (int g = 0; g < 2 * creatship[ship].desck; g++) //vrlmw gemini secmey ucun
			{
				shipsposion[y - 1][x + g] = 13 - ship + plus;  //reqemleri yoxlyan 2 li masvde deyeri deywry 4-13 (geminin nomreleri)
			}
			ship++;
		}
		if (creatship[ship].horizontal == false && shipsposion[y - 1][x] == 0 && shipsposion[y + creatship[ship].desck - 2][x] == 0)
			// horizontal olb olmamasn yoxlrq ve orada bir seyn olb olmmasna baxrq
		{
			creatship[ship].x = x + 2, creatship[ship].y = y;//her geminin 1 ci xanasn yadda saxlrq
			for (size_t q = 0; q < creatship[ship].desck + 2; q++)
			{
				for (size_t w = 0; w < 6; w++)
				{
					shipsposion[y - 2 + q][x - 2 + w] = 1;
				}
			}
			for (int g = 0; g < creatship[ship].desck; g++)
			{
				for (int n = 0; n < 2; n++)
				{
					shipsposion[y - 1 + g][x + n] = 13 - ship + plus;
				}
			}
			ship++;
		}
	}
}

void creatShips(Ships* creatship) {
	for (size_t i = 0; i < 20; i++) //opwi 20 gemi var deye 20 defe iterasiya
	{
		if (i == 0 || i == 10) //4 deneli gemiler ucun
		{
			creatship[i].desck = 4;
		}
		else if (i > 0 && i <= 2 || i > 10 && i <= 12)
		{
			creatship[i].desck = 3;
		}
		else if (i > 2 && i <= 5 || i > 12 && i <= 15)
		{
			creatship[i].desck = 2;
		}
		else if (i > 5 && i <= 9 || i > 15 && i <= 19)
		{
			creatship[i].desck = 1;
		}
	}
}

void menuSit(char variant[3][30], int T, int  A = 0) {

	Ships* creatship = new Ships[20];
	creatShips(creatship);
	int shipsposion[12][24] = { 0 };//oyunu izlemey ucn
	int othershipsposion[12][24] = { 0 };

	int key = 1, up = 0, down = 0, y = 2, x = 2, xx = 37, yy = 2, overgame = 0;
	bool startgame = false, yourturn = false;

	do
	{
		key = _getch();
		switch (key)
		{
		case Up:
			if (y > 0)
			{
				y--;
				T = y; //secilmw bend
				coremenu(variant, T);
			}
			break;
		case Down:
			if (y < 2)
			{
				y++;
				T = y;
				coremenu(variant, T);
			}
			break;
		case Enter:
			do
			{
				switch (T)
				{
				case 0:
					A++; //dovri sonlandrmaq ucn b
					y++;
					startgame = true;
					break;
				case 1:
					A++;
					y++;
					infoAboutgame();
				case 2:
					A++;
					y++;
					exit(0);
				}
			} while (key != Enter);
		}
	} while (A < 1);
	system("cls");
	if (startgame == true) {
		Creatgameboards(0);
		randomplace(creatship, shipsposion, 0);
		paintshippos(shipsposion, 2, 0);
	}
	Sleep(20);
	Creatgameboards(35); //oyun xeritesi yaradrq
	randomplace(creatship, othershipsposion, 10); //rebcun random
	paintshippos(othershipsposion, 37, 15); //reqbcun yerlewdrme
	do
	{
		if (yourturn == true)
		{
			do
			{
				x = xx, y = yy; //kursorun yern yadda saxlamaq ucun
				paintshippos(othershipsposion, 37, 15); //gemi olan xeriteni yazrq
				setColor(DarkGray, DarkGray); //gemininn rengi
				SetCursor(x, y);
				cout << "  "; //2 bowdq cunk iki bowdq 1 xanad
				key = _getch();
				switch (key)
				{
				case Left:
					if (x > 38) //oyun meydani daxlnde olmasycun
					{
						x -= 2; //2 dene cunki bir xana 2 bowdq
						xx = x; //kursorn vezyt yadda saxlyrq
					}
					break;
				case Right:
					if (x < 55)
					{
						x += 2;
						xx = x;
					}
					break;
				case Up:
					if (y > 2)
					{
						y--;
						yy = y;
					}
					break;
				case Down:
					if (y < 11)
					{
						y++;
						yy = y;
					}
					break;
				case Enter:
					if (othershipsposion[y - 1][x - 35] >= 4) //vurdqmz yerde geminin olb olmamasna baxrq
					{
						for (size_t i = 0; i < 2; i++)
						{
							othershipsposion[y - 1][x - 35 + i] = 3;
							explosion(creatship, othershipsposion, 10, overgame); //vrlmasn yoxlrq
							cout << "\a";
						}
						wordGame(9);
						Sleep(500);
					}
					else if (othershipsposion[y - 1][x - 35] < 2) //vrdqmz yerde hecneyoxdsa
					{
						for (size_t i = 0; i < 2; i++)
						{
							othershipsposion[y - 1][x - 35 + i] = 2;
						}
						Sleep(500);
						wordGame(5);
						yourturn = false;
					}
					break;
				}
			} while (key != Enter);
		}
		if (yourturn == false)
		{
			Sleep(500);
			wordGame(0);
			paintshippos(shipsposion, 2, 0);
			Sleep(500);
			x = (2 + rand() % 10) * 2, y = 2 + rand() % 10;
			if (shipsposion[y - 1][x - 1] >= 4)
			{
				for (size_t i = 0; i < 2; i++)
				{
					shipsposion[y - 1][x - 2 + i] = 3;
					explosion(creatship, shipsposion, 0, overgame);
				}
				wordGame(2);
				Sleep(500);
			}
			else if (shipsposion[y - 1][x - 1] <= 2)
			{
				for (size_t i = 0; i < 2; i++)
				{
					shipsposion[y - 1][x - 2 + i] = 2;
				}
				wordGame(1);
				Sleep(500);
				yourturn = true;
			}
		}
	} while (overgame == 0);
	if (overgame == 2)
	{
		wordGame(7);
	}
	else
	{
		wordGame(3);
	}
	Sleep(500000);
}
