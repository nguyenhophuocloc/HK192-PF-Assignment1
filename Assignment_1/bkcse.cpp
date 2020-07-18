#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;
// TODO
const int MADBEAR = 1;
const int BANDIT = 2;
const int EVENT_SIZE = 100;
const int MAX_CHARACTER_EACH_LINE = 250;

struct knight
{
	int HP;
	int level;
	int remedy;
	int maidenkiss;
	int phoenixdown;
};

// read data from input file to corresponding variables
// return 1 if successfully done, otherwise return 0
int readFile(const char* filename, knight& theKnight, int& nEvent, int* arrEvent)
{
	const char* file_name = filename;
	FILE* f = 0;
	char* str = new char[MAX_CHARACTER_EACH_LINE];
	int num;

	f = fopen(file_name, "r");
	if (f == NULL)	//file not found || cannot read
		return 0;

	fgets(str, MAX_CHARACTER_EACH_LINE, f);
	if (feof(f))
		return 0;

	int start = 0;
	int len = strlen(str);
	// read HP
	while (start < len && str[start] == ' ')
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.HP = num;
	if (theKnight.HP < 1 || theKnight.HP > 999)
		return 0;

	// read level
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.level = num;
	if (theKnight.level < 1 || theKnight.level > 10)
		return 0;

	// read remedy
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.remedy = num;
	if (theKnight.remedy < 0 || theKnight.remedy > 99)
		return 0;

	// read maidenkiss
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.maidenkiss = num;
	if (theKnight.maidenkiss < 0 || theKnight.maidenkiss > 99)
		return 0;

	// read phoenixdown
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.phoenixdown = num;
	if (theKnight.phoenixdown < 0 || theKnight.phoenixdown > 99)
		return 0;

	// read events
	nEvent = 0;
	while (1){
		if (feof(f))
			break;
		fgets(str, MAX_CHARACTER_EACH_LINE, f);
		if (str == NULL)
			break;
		start = 0;
		len = strlen(str);
    // cout << "\'" << str << "\'" << "\t" << len << endl;
		while (start < len){
			while (start < len && (str[start] > '9' || str[start] < '0'))
				start++;
			if (start >= len)
				break;
			arrEvent[nEvent] = 0;
			while (start < len && str[start] <= '9' && str[start] >= '0'){
				arrEvent[nEvent] = arrEvent[nEvent] * 10 + str[start] - '0';
				start++;
			}
			nEvent++;
		}
    delete[] str;
	}
	fclose(f);
	return 1;
}

void display(int* nOut)
{
  if (nOut)
    cout << *nOut;
  else
    cout << "Error!";
}


// TODO

int getLevelO(int i)
{
	int b = i % 10;
	return i > 6 ? (b > 5 ? b : 5) : b;
}

int LimitHP(int &n)
{
	if (n > 999)
	{
		return 999;
	}
	return n;
}

int LimitItem(int &n)
{
	if (n > 99)
	{
		return 99;
	}
	else if (n < 0)
	{
		return 0;
	}
	return n;
}

int LimitLv(int &n)
{
	if (n > 10)
	{
		return 10;
	}
	else if (n <= 0)
	{
		return 1;
	}
	return n;
}

int LimitmaxHP(int hp, int max)
{
	if (hp >= max)
	{
		return max;
	}
	return hp;
}

int Fibonaci(int n)
{
	int fibo1 = 0, fibo2 = 1;
	int fibo = fibo1 + fibo2;
	while (fibo <= n)
	{
		fibo = fibo1 + fibo2;
		fibo1 = fibo2;
		fibo2 = fibo;
	}
	return fibo;
}

int getLance(int n)
{
	if (n % 2 != 0)
	{
		return 1;
	}
	return 0;
}

int soNT(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			sum++;
		}
	}
	if (sum == 2)
	{
		return 1;
	}
	return 0;
}

int checkDragonBlood(int n)
{
	int check = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i * i + j * j == (n - i - j) * (n - i - j))
			{
				check = 1;
				break;
			}
		}
	}
	return check;
}

int main(int argc, char** argv)
{
    if (argc < 2) return 1;
    const char* filename = argv[1];;

   struct knight theKnight;
   int nEvent; //number of events
   int* arrEvent = new int[EVENT_SIZE]; // array of events
   int* nOut;                           // final result
   int i;

	readFile(filename, theKnight, nEvent, arrEvent);
	int N;
	nOut = &N;
	int maxHP = theKnight.HP;
	int index = 1;
	int small = -1, frog = -1;
	int preLv;
	int sword, amor = 0;
	int meet_pricess = -1; //chua gap cong chua
	int res;			   // quay lui
	int wing = 0;
	int meet_Odin = 0;
	int thunder = 0; //Odin power
	int isArthur = 0;
	int isLancelot = 0;
	int skillLance;
	int isPaladin = 0;
	int isDragonKnight = 0;
	int DragonSword = 0; //power
	if (maxHP == 999)
	{
		isArthur = 1;
	}
	if (maxHP == 888)
	{
		isLancelot = 1;
	}
	if (soNT(maxHP) == 1)
	{
		isPaladin = 1;
	}
	if (isLancelot == 0 && checkDragonBlood(theKnight.HP) == 1)
	{
		isDragonKnight = 1;
	}
	for (i = 0; i < nEvent; i++)
	{
		if (theKnight.HP <= 0)
		{
			if (theKnight.phoenixdown == 0)
			{
				N = -1;
				goto label;
			}
		}
		if (meet_pricess == 1)
		{
			if (res - 1 < 0)
			{
				N = theKnight.HP + theKnight.level + theKnight.remedy + theKnight.maidenkiss + theKnight.phoenixdown;
				goto label;
			}
		}
		int theEvent = arrEvent[i];
		if (meet_pricess == 1)
		{
			theEvent = arrEvent[res - 1];
		}
		//cout << theEvent << endl;
		switch (theEvent)
		{
		case 0:
			//Bowser va tra cong chua
			if (small == 1)
			{
				small = -1;
				theKnight.HP *= 5;
				theKnight.HP = LimitmaxHP(theKnight.HP, maxHP);
			}
			if (frog == 1)
			{
				frog = -1;
				theKnight.level = preLv;
			}
			N = theKnight.HP + theKnight.level + theKnight.remedy + theKnight.maidenkiss + theKnight.phoenixdown;
			goto label;

		case 1:
			//deal with MadBear here
			if (((theKnight.level > getLevelO(index) || sword == 8) && sword != 10) || thunder > 0 || isArthur == 1 || (isLancelot == 1 && getLance(theKnight.level) == 1) || isPaladin == 1 || (isDragonKnight == 1 && DragonSword == 1))
			{
				theKnight.level++;
				theKnight.level = LimitLv(theKnight.level);
			}
			else if (theKnight.level < getLevelO(index) || sword == 10)
			{
				if (amor == 0)
				{
					theKnight.HP = theKnight.HP - (1 * getLevelO(index) * 10);
				}
				if (theKnight.HP <= 0)
				{
					if (theKnight.phoenixdown == 0)
					{
						N = -1;
						goto label;
					}
					else if (theKnight.phoenixdown > 0)
					{
						theKnight.phoenixdown--;
						theKnight.HP = maxHP;
						small = -1;
						frog = -1;
					}
				}
			}
			break;

		case 2:
			//deal with Bandit here
			if (((theKnight.level > getLevelO(index) || sword == 8) && sword != 10) || thunder > 0 || isArthur == 1 || (isLancelot == 1 && getLance(theKnight.level) == 1) || isPaladin == 1 || (isDragonKnight == 1 && DragonSword == 1))
			{
				theKnight.level++;
				theKnight.level = LimitLv(theKnight.level);
			}
			else if (theKnight.level < getLevelO(index) || sword == 10)
			{
				if (amor == 0)
				{
					theKnight.HP = theKnight.HP - (1.5 * getLevelO(index) * 10);
				}
				if (theKnight.HP <= 0)
				{
					if (theKnight.phoenixdown == 0)
					{
						N = -1;
						goto label;
					}
					else if (theKnight.phoenixdown > 0)
					{
						theKnight.phoenixdown--;
						theKnight.HP = maxHP;
						small = -1;
						frog = -1;
					}
				}
			}
			break;
		case 3: //Lupin
			if (((theKnight.level > getLevelO(index) || sword == 8) && sword != 10) || thunder > 0 || isArthur == 1 || (isLancelot == 1 && getLance(theKnight.level) == 1) || isPaladin == 1 || (isDragonKnight == 1 && DragonSword == 1))
			{
				theKnight.level++;
				theKnight.level = LimitLv(theKnight.level);
			}
			else if (theKnight.level < getLevelO(index) || sword == 10)
			{
				if (amor == 0)
				{
					theKnight.HP = theKnight.HP - (4.5 * getLevelO(index) * 10);
				}
				if (theKnight.HP <= 0)
				{
					if (theKnight.phoenixdown == 0)
					{
						N = -1;
						goto label;
					}
					else if (theKnight.phoenixdown > 0)
					{
						theKnight.phoenixdown--;
						theKnight.HP = maxHP;
						small = -1;
						frog = -1;
					}
				}
			}
			break;
		case 4: //Elf
			if (((theKnight.level > getLevelO(index) || sword == 8) && sword != 10) || thunder > 0 || isArthur == 1 || (isLancelot == 1 && getLance(theKnight.level) == 1) || isPaladin == 1 || (isDragonKnight == 1 && DragonSword == 1))
			{
				theKnight.level++;
				theKnight.level = LimitLv(theKnight.level);
			}
			else if (theKnight.level < getLevelO(index) || sword == 10)
			{
				if (amor == 0)
				{
					theKnight.HP = theKnight.HP - (6.5 * getLevelO(index) * 10);
				}
				if (theKnight.HP <= 0)
				{
					if (theKnight.phoenixdown == 0)
					{
						N = -1;
						goto label;
					}
					else if (theKnight.phoenixdown > 0)
					{
						theKnight.phoenixdown--;
						theKnight.HP = maxHP;
						small = -1;
						frog = -1;
					}
				}
			}
			break;
		case 5: //Troll
			if (((theKnight.level > getLevelO(index) || sword == 8) && sword != 10) || thunder > 0 || isArthur == 1 || (isLancelot == 1 && getLance(theKnight.level) == 1) || isPaladin == 1 || (isDragonKnight == 1 && DragonSword == 1))
			{
				theKnight.level++;
				theKnight.level = LimitLv(theKnight.level);
			}
			else if (theKnight.level < getLevelO(index) || sword == 10)
			{
				if (amor == 0)
				{
					theKnight.HP = theKnight.HP - (8.5 * getLevelO(index) * 10);
				}
				if (theKnight.HP <= 0)
				{
					if (theKnight.phoenixdown == 0)
					{
						N = -1;
						goto label;
					}
					else if (theKnight.phoenixdown > 0)
					{
						theKnight.phoenixdown--;
						theKnight.HP = maxHP;
						small = -1;
						frog = -1;
					}
				}
			}
			break;
		case 6: //Shaman & small
			if (small == -1 || frog == -1 || thunder == 0)
			{
				if (((theKnight.level > getLevelO(index)) && sword != 10) || isArthur == 1 || (isLancelot == 1 && getLance(theKnight.level) == 1) || isPaladin == 1 || (isDragonKnight == 1 && DragonSword == 1))
				{
					theKnight.level += 2;
					theKnight.level = LimitLv(theKnight.level);
				}
				else if (theKnight.level < getLevelO(index) || sword == 10)
				{
					if (amor == 0)
					{
						if (theKnight.HP < 5)
						{
							theKnight.HP = 1;
						}
						else
						{
							theKnight.HP /= 5;
						}
					}
					if (theKnight.remedy >= 1)
					{
						theKnight.remedy--;
						theKnight.HP *= 5;
						theKnight.HP = LimitmaxHP(theKnight.HP, maxHP);
					}
					else if (theKnight.remedy <= 0)
					{
						small = 4;
					}
				}
			}
			break;
		case 7: //Vaj & frog
			if (small == -1 || frog == -1 || thunder == 0)
			{
				if (((theKnight.level > getLevelO(index)) && sword != 10) || isArthur == 1 || (isLancelot == 1 && getLance(theKnight.level) == 1) || isPaladin == 1 || (isDragonKnight == 1 && DragonSword == 1))
				{
					theKnight.level += 2;
					theKnight.level = LimitLv(theKnight.level);
				}
				else if (theKnight.level < getLevelO(index) || sword == 10)
				{
					preLv = theKnight.level;
					theKnight.level = 1;
					if (theKnight.maidenkiss >= 1)
					{
						theKnight.maidenkiss--;
						theKnight.level = preLv;
					}
					else if (theKnight.maidenkiss <= 0)
					{
						frog = 4;
					}
				}
			}
			break;
		case 8: //Exbur
			if (DragonSword == 0)
			{
				sword = 8;
			}
			break;
		case 9: //Mythir
			amor = 1;
			break;
		case 10: //Expoor
			if (thunder == 0 && isArthur == 0 && (isLancelot == 0 || (isLancelot == 1 && getLance == 0)) && isPaladin == 0 && isDragonKnight == 0)
			{
				if (theKnight.level < 5)
				{
					sword = 10;
				}
			}
			break;
		case 11: //MushMario
			theKnight.HP += 50;
			theKnight.HP = LimitmaxHP(theKnight.HP, maxHP);
			break;
		case 12: //Fibo
			theKnight.HP = Fibonaci(theKnight.HP);
			theKnight.HP = LimitmaxHP(theKnight.HP, maxHP);
			break;
		case 13: //MushGhost
			if (thunder == 0 || isPaladin == 0 || (isDragonKnight == 1 && DragonSword == 1) || amor == 0)
			{
				if (theKnight.HP < 51)
				{
					theKnight.HP = 1;
				}
				else
				{
					theKnight.HP -= 50;
				}
			}
			break;
		case 14: //Mushknight
			maxHP += 50;
			if (maxHP > 999)
			{
				maxHP = 999;
			}
			theKnight.HP = maxHP;
			break;
		case 15:
			if (small != -1)
			{
				small == -1;
				theKnight.HP *= 5;
				theKnight.HP = LimitmaxHP(theKnight.HP, maxHP);
			}
			else
			{
				theKnight.remedy++;
				theKnight.remedy = LimitItem(theKnight.remedy);
			}
			break;
		case 16:
			if (frog != -1)
			{
				frog = -1;
				theKnight.level = preLv;
			}
			else
			{
				theKnight.maidenkiss++;
				theKnight.maidenkiss = LimitItem(theKnight.maidenkiss);
			}
			break;
		case 17:
			theKnight.phoenixdown++;
			theKnight.phoenixdown = LimitItem(theKnight.phoenixdown);
			break;
		case 18: //Merlin
			small = 0;
			frog = 0;
			theKnight.level++;
			theKnight.level = LimitLv(theKnight.level);
			theKnight.HP = maxHP;
			break;
		case 19: //vuc Abyss
			if (thunder == 0 || (isDragonKnight == 1 && DragonSword == 1))
			{
				if (theKnight.level < 7)
				{
					N = -1;
					goto label;
				}
			}
			break;
		case 20: //gap cong chua Guinerver
			if (meet_pricess != 1)
			{
				meet_pricess = 1;
				res = index;
				nEvent += index;
			}
			break;
		case 21: //Doi canh Wing
			wing = 1;
			if (index + 3 > nEvent || meet_pricess == 1)
			{
				N = theKnight.HP + theKnight.level + theKnight.remedy + theKnight.maidenkiss + theKnight.phoenixdown;
				goto label;
			}
			for (int j = 1; j <= 3; j++)
			{
				if ((arrEvent[i + j] == 20) || (arrEvent[i + j] == 0))
				{
					N = theKnight.HP + theKnight.level + theKnight.remedy + theKnight.maidenkiss + theKnight.phoenixdown;
					goto label;
				}
			}
			break;
		case 22: //Odin
			if (meet_Odin == 0 && thunder == 0)
			{
				thunder = 4;
				meet_Odin = 1;
			}
			break;
		case 23: //Dragon Sword
			if (isDragonKnight == 1)
			{
				DragonSword = 1;
				sword = 0;
			}
			break;
		case 99: //gap BOSS Bowser
			if (isArthur == 1 || isLancelot == 1 || (isPaladin == 1 && theKnight.level > 8) || (theKnight.level == 10 && sword != 10) || (isDragonKnight == 1 && DragonSword == 1) || thunder > 0)
			{
				theKnight.level = 10;
			}
			else
			{
				N = -1;
				goto label;
			}
			break;
		}
		if (small > 0)
		{
			small--;
		}
		if (small == 0)
		{
			small = -1;
			theKnight.HP *= 5;
			theKnight.HP = LimitmaxHP(theKnight.HP, maxHP);
		}
		if (frog > 0)
		{
			frog--;
		}
		if (frog == 0)
		{
			frog = -1;
			theKnight.level = preLv;
		}
		index++;
		//khi da gap cong chua
		if (meet_pricess == 1)
		{
			res--;
		}
		if (wing == 1)
		{
			wing = 0;
			index += 3;
			i += 3;
			if (meet_Odin == 1 && thunder > 0)
			{
				thunder = 0;
			}
		}
		if (meet_Odin == 1)
		{
			if (thunder > 0)
			{
				thunder--;
			}
		}
	}
	N = theKnight.HP + theKnight.level + theKnight.remedy + theKnight.maidenkiss + theKnight.phoenixdown;
label:
	// TODO
    display(nOut);
	return 0;
}