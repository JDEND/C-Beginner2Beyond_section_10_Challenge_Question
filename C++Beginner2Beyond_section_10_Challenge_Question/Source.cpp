#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string encrypt(string str, int key);
string decrypt(string str, int key);

int main() {
	int temp;
	string wordy;
	getline(cin, wordy);
	cout << endl;
	cin >> temp;

	cout << wordy << endl;
	wordy = encrypt(wordy, temp);
	cout << wordy << endl;
	wordy = decrypt(wordy, temp);
	cout << wordy << endl;

	return 0;
}

string encrypt(string str, int key) {

	for (auto& i : str) {
		if(i == ' ' || i == ',' || i == '.' || i == '!' || i == '?' || i == ':' || isdigit(i)) {
			
		}
		else if (isupper(i)) {
			if (i + key > 90)
				i = ((i + key) - 25);
			else
				i += key;
		}
		else {
			if (i + key > 122)
				i = ((i + key) - 25);
			else
				i += key;

		}
	}
	return str;
}

string decrypt(string str, int key) {

	for (auto& i : str) {
		if (i == ' ' || i == ',' || i == '.' || i == '!' || i == '?' || i == ':' || isdigit(i)) {

		}
		else if (isupper(i)) {
			if (i - key < 65)
				i = ((i - key) + 25);
			else
				i -= key;
		}
		else {
			if (i - key < 97)
				i = ((i - key) + 25);
			else
				i -= key;

		}
	}
	return str;
}