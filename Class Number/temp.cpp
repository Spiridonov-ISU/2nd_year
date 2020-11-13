#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Number {
private:
	vector<int> num;
	int num_system;

	int charToInt(char c) {
		if (c >= '0' && c <= '9' && (c - '0') < this->num_system) {
			return c - '0';
		}
		else {
			if (c >= 'A' && c <= 'Z' && (c - 'A') < this->num_system) {
				return c - 'A' + 10;
			}
			else {
				return -1;
			}
		}
	}

	char intToChar(int c) {
		if (c >= 0 && c <= 9) {
			return c + '0';
		}
		else {
			return c + 'A' - 10;
		}
	}


	int nextNumber(int final) {
		int temp = 0;
		for (int i = 0; i < this->num.size(); i++) {
			temp = temp * this->num_system + this->num[i];
			num[i] = temp / final;
			temp = temp % final;
		}
		return temp;
	}

	bool is_zero() {
		for (int i = 0; i < this->num.size(); i++) {
			if (num[i] != 0) {
				return false;
			}
		}
		return true;
	}

public:
	Number(string user_num, int user_num_system) {
		this->num_system = user_num_system;
		for (int i = 0; i < user_num.length(); i++) {
			this->num.push_back(charToInt(user_num[i]));
		}
	}

	string convertTo(int final) {
		vector<int> temp;
		do {
			temp.push_back(this->nextNumber(final));
		} while (!this->is_zero());

		string sTemp = "";
		for (int i = temp.size() - 1; i >= 0; i--) {
			sTemp += intToChar(temp[i]);
		}
		return sTemp;
	}
};

int main()
{
	Number num1("15", 10);
	cout << num1.convertTo(2) << endl;
}