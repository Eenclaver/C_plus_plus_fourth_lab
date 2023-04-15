#pragma once
#include <string>

#define SHIFT 1
#define XOR 2
#define VERNAM 3
#define ENCRYPTION 1
#define DECRYPTION 2
#define THREE_ELEMENTS 3
#define TWO_ELEMENTS 2
#define YES 1
#define USER_INPUT 1
#define FILE_INPUT 2
#define INPUT 1
#define RESULTS_TMP 2
#define RESULTS 3

using namespace std;

int Get_int();
int Check_choice(int q_elements);
void Shift_encryption(string* arr, int string_q,int userShift);
void Shift_decryption(string& input,int shift);
void Xor_encryption(string* arr, int string_q);
void Xor_decryption(string& input);
void Vernam_encryption(string* arr, int string_q, string& key);
void Vernam_decryption(string& input, string& key, int& key_index_decryption);
void Greeting();
void Get_string(string input);
int Analysis_choice(char element);
void User_input(string*& arr, int& string_q, int mode);
void InputData(string*& arr, int& string_q, string& key_str,int* shift);
void OutputData(string* arr, int& string_q, int mode, string& key_str);
void Get_text(string* arr, int string_q);
void Module_tests();