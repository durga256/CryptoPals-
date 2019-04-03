// hexadecimal to base64
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class number {
private:
	string hex;
	string binary;
	string base64;
	int len;

public:

	void gethex() {
		getline(cin, hex);
		len = hex.length();
	}

	void hexToBi() {
		int i = 0;

		//conversion
		while (hex[i] != '\0') {

			switch (hex[i]) {
			case '0':
				binary += "0000";
				break;
			case '1':
				binary += "0001";
				break;
			case '2':
				binary += "0010";
				break;
			case '3':
				binary += "0011";
				break;
			case '4':
				binary += "0100";
				break;
			case '5':
				binary += "0101";
				break;
			case '6':
				binary += "0110";
				break;
			case '7':
				binary += "0111";
				break;
			case '8':
				binary += "1000";
				break;
			case '9':
				binary += "1001";
				break;
			case 'a':
				binary += "1010";
				break;
			case 'b':
				binary += "1011";
				break;
			case 'c':
				binary += "1100";
				break;
			case 'd':
				binary += "1101";
				break;
			case 'e':
				binary += "1110";
				break;
			case 'f':
				binary += "1111";
				break;

			}
			i++;
		}
		len = binary.length();


		//padding
		if (len % 6 != 0) {
			i = 6 - (len % 6);
			while (i > 0) {
				binary += "0";
				i--;
			}
		}

	}

	void biTo64() {
		double sum = 0;

		for (int i = 0; i < len / 6; i++) {
			sum = 0;
			for (int j = 0; j < 6; j++) {
				sum += (binary[j + (i * 6)] - 48)*pow(2, 5 - j);
			}


			if (sum <= 25)
				base64 += (char)sum + 65;

			else if (sum >= 26 && sum <= 51)
				base64 += (char)sum + 71;
			else if (sum >= 52 && sum <= 61)
				base64 += (char)sum - 4;
			else if (sum == 62)
				base64 += "+";
			else
				base64 += "/";

		}
		cout << base64;


	}

	void display() {
		cout << binary << endl;

	}


};

int main() {
	char ch;
	number obj;
	obj.gethex();
	obj.hexToBi();
	//obj.display();
	obj.biTo64();
	cin >> ch;
	return 0;
}
