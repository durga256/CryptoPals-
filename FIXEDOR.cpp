// hexadecimal to base64
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class number {
private:
	string hex;



public:
	string binary;
	int len=0;
	void gethex() {
		getline(cin, hex);

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
		 //len = binary.length();
		}
	int binarylen()
	{
		len = binary.length();
		return len;
	}


	void display() {
		for (int i = 0; i < len; i++)
		{
			cout << binary[i]<<" ";
		}
		cout << endl;
	}
	void binarytohex() {
		int i, j;
		double sum = 0;
		for (i = 0; i < len / 4; i++) {
			sum = 0;
			for (j = 0; j < 4; j++) {
				if (binary[j + (i * 4)] == 49)
				sum += pow(2, (3 - j));
			}

			if (sum <= 9) {
				cout << sum ;
			}
			else
			{
				sum -= 10;
				cout << (char)('a' + sum) ;
             }

		}

	}


}obj1,obj2,obj;

void xord() {
	int i;
	for (i = 0; i < obj1.binarylen(); i++) {
		if ((obj1.binary[i] == 49 || obj2.binary[i] == 49) && obj2.binary[i]!= obj1.binary[i])
		{
			//cout << obj1.binary[i] << " " << obj2.binary[i] << endl;
            obj.binary += "1";
			//cout << obj.binary[i]<<endl;
		}
		else
		{
			//cout << obj1.binary[i] << " " << obj2.binary[i]<<endl;
			obj.binary += "0";
			//cout << obj.binary[i]<<endl;
		}

	}
}


int main() {
	char ch;

	obj1.gethex();
	obj2.gethex();
	obj1.hexToBi();
    obj2.hexToBi();
	//obj1.display();
	//obj2.display();
	xord();
	obj.binarylen();
	//obj.display();
	obj.binarytohex();

	cin >> ch;
	return 0;
}
