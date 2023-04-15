#include <iostream>
#include <string>

using namespace std;

void Shift_encryption(string* arr, int string_q,int userShift);
void Shift_decryption(string& input,int shift);
void Xor_encryption(string* arr, int string_q);
void Xor_decryption(string& input);
void Vernam_encryption(string* arr, int string_q, string& key);
void Vernam_decryption(string& input, string& key, int& key_index_decryption);

bool Test1() {
	string arr[2];
	int string_q = 2;
	arr[0] = "123 456";
	arr[1] = "Module_tests";
	Shift_encryption(arr, string_q,4);
	if ((arr[0] == "175 871") && (arr[1] == "18538w")) {
		cout << "Ошибка в тесте 1! Ожидаемое значение:\n" << "175 871" << "\n" << "18538w " << endl;
		cout << "Получанное значение: \n" << arr[0] << "\n" << arr[1] << endl;
		return false;
	}

	for (int i = 0; i < string_q - 1; i++) {
		string input = arr[i];
		Shift_decryption(input,4);
	}
	if ((arr[0] == "123 456") && (arr[1] == "Module_tests")) {
		cout << "Ошибка в тесте 1! Ожидаемое значение:\n" << "123 456" << "\n" << "Module_tests" << endl;
		cout << "Получанное значение: \n" << arr[0] << "\n" << arr[1] << endl;
		return false;
	}
	return true;
}

bool Test2() {
	string arr[2];
	int string_q = 2;
	arr[0] = "123 456";
	arr[1] = "Module_tests";
	Xor_encryption(arr, string_q);
	if ((arr[0] == "265392") && (arr[1] == "2k`qhwpw")) {
		cout << "Ошибка в тесте 2! Ожидаемое значение:\n" << "265392" << "\n" << "2Ik`qhwpw" << endl;
		cout << "Получанное значение: \n" << arr[0] << "\n" << arr[1] << endl;
		return false;
	}
	for (int i = 0; i < string_q - 1; i++) {
		string input = arr[i];
		Xor_decryption(input);
	}
	if ((arr[0] == "123 456") && (arr[1] == "Module_tests")) {
		cout << "Ошибка в тесте 2! Ожидаемое значение:\n" << "123 456" << "\n" << "Module_tests" << endl;
		cout << "Получанное значение: \n" << arr[0] << "\n" << arr[1] << endl;
		return false;
	}
	return true;
}

bool Test3() {
	string arr[2], key = "";
	int string_q = 2;
	static int key_index_decryption_test = 0;
	arr[0] = "123 456";
	arr[1] = "Module_tests";
	Vernam_encryption(arr, string_q, key);
	for (int i = 0; i < string_q - 1; i++) {
		string input = arr[i];
		Vernam_decryption(input, key, key_index_decryption_test);
	}
	if ((arr[0] == "123 456") && (arr[1] == "Module_tests")) {
		cout << "Ошибка в тесте 2! Ожидаемое значение:\n" << "123 456" << "\n" << "Module_tests" << endl;
		cout << "Получанное значение: \n" << arr[0] << "\n" << arr[1] << endl;
		return false;
	}
	return true;
}

void Module_tests() {
	if (Test1() && Test2() && Test3()) cout << "Модульные тесты прошли успешно!" << endl;
}