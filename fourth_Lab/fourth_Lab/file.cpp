#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "Main.h"
#define INPUT 1

using namespace std;
using namespace filesystem;

bool Get_bool();

void Get_str(string input,string shiftStr) {
	for (unsigned int i = 1+ shiftStr.length()-1; i < input.size(); i++) {
		if (input[i] != '|') {
			if ((int)input[i] != 13) {
				cout << input[i];
			}
		}
		else {
			cout << endl;
			input.erase(i, 1);
		}
	}
}


void getArr(string* arr) {
	string tmp=*arr;
	for (unsigned int i = 1; i < arr->length(); i++)
	{
		cout << tmp[i];
		if (tmp[i] == ' ') {
			cout << endl;
		}
	}
	cout << endl;
}

void OutputData(string* arr, int& string_q, int mode, string& key_str) {
	string file_path = "";
	bool is_data_saved = false;
	do {
		cout << "Сохранить в:" << endl;
		getline(cin, file_path);

		if (ifstream(file_path)) {
			cout << "Файл уже существует." << endl;
			cout << "0 - Перезаписать существующий файл." << endl;
			cout << "1 - Повторить ввод." << endl;
			int try_another_file = Get_bool();
			if (try_another_file) {
				continue;
			}
		}

		ofstream my_file(file_path, ofstream::app); // открываем файл для добавления информации к концу файла

		error_code ec;
		if (!is_regular_file(file_path, ec)) {
			cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
			continue;
		}

		if (!my_file) {
			cout << "Запись запрещена. Повторите ввод." << endl;
			my_file.close();
			continue;
		}

		my_file.close();
		my_file.open(file_path, ofstream::trunc);

 		if (mode == SHIFT) {
			my_file << string_q << "  " << key_str << endl;
			for (int i = 0; i < string_q; i++) {
				my_file << arr[i] << endl;
			}
		}
		if (mode == XOR) {
			my_file << string_q << "  " << key_str << endl;
			for (int i = 0; i < string_q; i++) {
				my_file << arr[i] << endl;
			}
		}
		if (mode == VERNAM) {
			for (int i = 0; i < string_q; i++) {
				string line = arr[i];
				line.erase(0, 1);
				my_file << line << endl;
			}
		}
		my_file.close();
		cout << "Запись завершена." << endl;
		is_data_saved = true;
	} while (!is_data_saved);
}

void InputData(string*& arr, int& string_q, string& key_str, int* shift) {
	string file_path = "";
	string userShift = "0";
	string outpt;
	bool is_data_loaded = false;
	do {
		cout << "Загрузить из:" << endl;
		getline(cin, file_path);

		if (!ifstream(file_path)) {
			cout << "Файл не существует. Повторите ввод." << endl;
			continue;
		}

		error_code ec;
		if (!is_regular_file(file_path, ec)) {
			cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
			continue;
		}

		ifstream my_file(file_path);

		if (!my_file) {
			cout << "Загрузка запрещена. Повторите ввод." << endl;
			my_file.close();
			continue;
		}

		if (!(my_file >> string_q) || string_q <= 0) {
			cout << "Некорректное количество строк" << endl;
			my_file.close();
			continue;
		}

		bool again = false;
		arr = new string[string_q];
		getline(my_file, key_str);
		for (int i = 0; i < string_q; i++) {
			do {
				string tmp;
				getline(my_file, tmp);
				for (unsigned int j = 0; j < tmp.length(); j++) {
					if ((tmp[j] == '\t') || (tmp[j] == '\n')) {
						tmp.erase(j, 1);
					}
					if (tmp[j] == '|') {
						for (unsigned int k = 1; k < j; k++) {
							userShift += tmp[k];
							tmp.erase(j, 1);
						}
						tmp.erase(j, 1);
					}
				}
				bool ascii_checker = false;
				for (unsigned int index = 0; index < tmp.size(); index++) {
					if (tmp[index] > 126) ascii_checker = false;
					else ascii_checker = true;
				}
				if (ascii_checker == false) {
					cout << "Ошибка ввода, некорректные символы" << endl;
					continue;
				}
				arr[i] = tmp;
				outpt += tmp;
				outpt += "|";
			} while (again);
		}
		cout << "Загрузка завершена." << endl;
		cout << "Исходный массив: " << endl;
		Get_str(outpt, userShift);
		is_data_loaded = true;
		my_file.close();
	} while (!is_data_loaded);
	*shift=stoi(userShift);
}