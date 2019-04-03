//Single XOR
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class number
{
private:
	char resultkey;
	string hex;
	string inputbinary, binarykey, finalbinary, resultstr,finalstr;
	int hextodecimal[100], finalascii[100], scoreofall[100] = {},score;
	int lenhex = 0, lenbin = 0, lenhextodecimal = 0, lenfinalascii = 0, lenfinalbinary = 0, maxscore = 0;
public:
	void gethex()
	{
		getline(cin, hex);
		lenhex = hex.length();
	}
	void hextobinary()
	{ //hex to index
		int i = 0;
		for (i = 0; i < lenhex; i++)
		{
			if (hex[i] >= 48 && hex[i] <= 57)
				hextodecimal[i] = hex[i] - 48;
			else if (hex[i] >= 97 && hex[i] <= 102)
				hextodecimal[i] = hex[i] - 87;
		}
		lenhextodecimal = i;
		/*for (i = 0; i < lenhextodecimal; i++)
		{
			cout << " " << hextodecimal[i];
		}*/
		//decimal to binary
		for (i = 0; i < lenhextodecimal; i++)
		{
			int current = hextodecimal[i];
			for (int j = 0; j < 4; j++)
			{
				if (pow(2, 3 - j) <= current)
				{
					inputbinary += '1';
					current -= pow(2, 3 - j);
				}
				else
				{
					inputbinary += '0';
				}
			}
		}
		lenbin = inputbinary.length();
		//cout << inputbinary << endl;
	}
	void valuetobinaryforkey(int value)
	{
		int current = value;
		binarykey = "";
		for (int i = 0; i < 8; i++)
		{
			if (pow(2, 7 - i) <= current)
			{
				binarykey += '1';
				current -= pow(2, 7 - i);
			}
			else
			{
				binarykey += '0';
			}
		}
		//cout << (char)value << " : " ;
	}
	void findkey()
	{
		for (int i = 32; i <= 127; i++)
		{
			valuetobinaryforkey(i);
			xord();
			finalbinarytoascii();
			asciitochar();
			scoreofall[i-32]=scoring();
			if (scoreofall[i - 32] > maxscore)
			{
				resultkey = (char)i;
				resultstr = finalstr;
				maxscore = scoreofall[i - 32];
			}
		}
	}

	void xord()
	{
		int i, k = 0;
		finalbinary = "";
		for (i = 0; i < lenbin; i++)
		{
			if ((inputbinary[i] == 49 || binarykey[k] == 49) && inputbinary[i] != binarykey[k])
			{
				finalbinary += '1';
			}
			else
			{
				finalbinary += '0';
			}
			if (k == 7)
			{
				k -= 7;
			}
			else
			{
				k++;
			}
		}
		lenfinalbinary = finalbinary.length();
	}
	void finalbinarytoascii()
	{
		int i = 0;
		finalascii[100] = {};
		for (i = 0; i < lenfinalbinary / 8; i++)
		{
			int sum = 0;
			for (int j = 0; j < 8; j++)
			{
				if (finalbinary[j + i * 8] == 49)
				{
					sum += pow(2, 7 - j);
				}
			}
			finalascii[i] = sum;
		}
		lenfinalascii = i;
	}

	void asciitochar()
	{
		finalstr = "";
		for (int i = 0; i < lenfinalascii; i++)
		{
			finalstr += (char)finalascii[i];
		}
		//cout << finalstr << endl;
	}

	int scoring()
	{
		score = 0;
			for (int j = 0; j < finalstr.length(); j++)
			{
				switch (finalstr[j])
				{
				case 'e':
					score += 25;
					break;
				case 'E':
					score += 24;
					break;
				case 't':
					score += 23;
					break;
				case 'T':
					score += 22;
					break;
				case 'a':
					score += 21;
					break;
				case 'A':
					score += 20;
					break;
				case 'o':
					score += 19;
					break;
				case 'O':
					score += 18;
					break;
				case 'i':
					score += 17;
					break;
				case 'I':
					score += 16;
					break;
				case 'n':
					score += 15;
					break;
				case 'N':
					score += 14;
					break;
				case ' ':
					score += 13;
					break;
				case 's':
					score += 12;
					break;
				case 'S':
					score += 11;
					break;
				case 'h':
					score += 10;
					break;
				case 'H':
					score += 9;
					break;
				case 'r':
					score += 8;
					break;
				case 'R':
					score += 7;
					break;
				case 'd':
					score += 6;
					break;
				case 'D':
					score += 5;
					break;
				case 'l':
					score += 4;
					break;
				case 'L':
					score += 3;
					break;
				case 'u':
					score += 2;
					break;
				case 'U':
					score += 1;
					break;




				}
			}
			//cout << score << endl;
			return score;
		}
	void display()
	{
		cout << endl;
		cout <<"Key : " <<resultkey << ", Result String :  " <<  resultstr;
	}
} obj1;
int main()
{
	char ch;
	obj1.gethex();
	obj1.hextobinary();
	obj1.findkey();
	obj1.display();

	cin >> ch;
	return 0;
}
