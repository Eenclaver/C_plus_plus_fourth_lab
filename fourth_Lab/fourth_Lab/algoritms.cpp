#include <iostream>
#include <string>
#include <regex>

using namespace std;

double Get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		while (getchar() != '\n');
		cin.clear();
		cout << "Введите число." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}


int Check_choice(int q_elements) {
	regex r;
	if (q_elements == 2) r = "^[12]$";
	if (q_elements == 3) r = "^[123]$";
	string input;
	int choice = 0;
	bool again = false;
	do {
		getline(cin, input);
		if (regex_match(input.c_str(), r)) {
			choice = stoi(input);
			again = false;
		}
		else {
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
			again = true;
		}
	} while (again == true);
	return choice;
}


int Get_int() {
	int val = 0;
	std::cin >> val;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Некорректное значение!" << std::endl << "Введите корректное значение:";
		std::cin >> val;
	}
	std::cin.ignore(INT_MAX, '\n');
	return val;
}

void Get_string(string input) {
	for (unsigned int i = 1; i < input.size(); i++) {
		cout << input[i];
	}
}

int Analysis_choice(char element) {
	if (element == '1') return 1;
	if (element == '2') return 2;
	if (element == '3') return 3;
	return -1;
}

bool Get_bool() {
	bool input = false;
	cin >> input;
	while (cin.fail()) {
		while (getchar() != '\n');
		cin.clear();
		cout << "Введите число." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}

void User_input(string*& arr, int& string_q, int mode) {
	if (mode == 0) {
		cout << "Введите текст латинскими буквами, для завершения ввода введите пустую строку" << endl;
		string* arr_tmp;
		string line = " ";
		string tmp;
		string_q = 1;
		int new_string_q = 1;

		getline(cin, tmp);
		line += tmp;
		arr = new string[string_q];
		arr[string_q - 1] = line;

		while (true) {
			getline(cin, tmp);
			bool again = false;
			for (unsigned int i = 0; i < tmp.size(); i++) {
				if (tmp[i] > 126) again = false;
			}
			if (again == false) {
				cout << "Ошибка ввода, попробуйте еще раз" << endl;
				continue;
			}
			if (tmp != "") {
				string input = " ";
				input += tmp;

				new_string_q = string_q + 1;
				arr_tmp = new string[new_string_q];

				for (int i = 0; i < string_q; i++) {
					arr_tmp[i] = arr[i];
				}
				arr_tmp[new_string_q - 1] = input;

				string_q = new_string_q;
				arr = new string[string_q];
				for (int i = 0; i < string_q; i++) {
					arr[i] = arr_tmp[i];
				}
			}
			else break;
		}
		cout << "Ввoд завершен" << endl;
	}
	else {
		cout << "Введите текст латинскими буквами, для завершения ввода введите пустую строку" << endl;
		string* arr_tmp;
		string line;
		string_q = 1;
		int new_string_q = 1;

		getline(cin, line);
		arr = new string[string_q];
		arr[string_q - 1] = line;

		while (true) {
			getline(cin, line);
			if (line != "") {

				new_string_q = string_q + 1;
				arr_tmp = new string[new_string_q];

				for (int i = 0; i < string_q; i++) {
					arr_tmp[i] = arr[i];
				}
				arr_tmp[new_string_q - 1] = line;

				string_q = new_string_q;
				arr = new string[string_q];
				for (int i = 0; i < string_q; i++) {
					arr[i] = arr_tmp[i];
				}
			}
			else break;
		}
		cout << "Ввoд завершен" << endl;
	}
}

void Get_text(string* arr, int string_q) {
	cout << "Зашифрованный текст:" << endl;
	for (int i = 0; i < string_q; i++) {
		cout << "|";
		for (unsigned int j = 1; j < arr[i].length(); j++) {
			if ((int)arr[i].at(j) != 13) cout << arr[i].at(j);
		}
		cout << "|";
		cout << endl;
	}
}