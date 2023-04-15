#include <iostream>
#include <string>

#define A_CODE 65
#define Z_CODE 90
#define a_CODE 97
#define z_CODE 122
#define ZERO_CODE 48
#define NINE_CODE 57
#define Q_ENG_LETTERS 26
#define Q_NUMBERS 10



using namespace std;
int Get_int();

void Shift_encryption(string* arr, int string_q,int userShift) {
    int shift = userShift;
    string tmp = "1";
    
    for (int count = 0; count < string_q; count++) {
        string input = arr[count];
        for (int i = 0; i < static_cast<int>(input.size()); i++) {
            int element = input[i];
            if ((element >= A_CODE) && (element <= A_CODE)) {
                element += shift;
                if (element > Z_CODE) element -= Q_ENG_LETTERS;
            }
            if ((element >= a_CODE) && (element <= z_CODE)) {
                element += shift;
                if (element > z_CODE) element -= Q_ENG_LETTERS;
            }
            if ((element >= ZERO_CODE) && (element <= NINE_CODE)) {
                element += shift;
                while (!(element <= NINE_CODE))
                    element -= Q_NUMBERS;
            }
            input[i] = static_cast<char>(element);
        }
        if (count == 0) {
            input = to_string(userShift)+"|" +tmp + input;
        }
        input = tmp + input;
        arr[count] = input;
    }
}

void Shift_decryption(string& input,int userShift) {
    int shift = userShift;
    for (int i = 1; i < static_cast<int>(input.size()); i++) {
        int element = input[i];
        if ((element >= A_CODE) && (element <= A_CODE)) {
            element -= shift;
            if (element < A_CODE) element += Q_ENG_LETTERS;
        }
        if ((element >= a_CODE) && (element <= z_CODE)) {
            element -= shift;
            if (element < a_CODE) element += Q_ENG_LETTERS;
        }
        if ((element >= ZERO_CODE) && (element <= NINE_CODE)) {
            element -= shift;
            while (!(element >= ZERO_CODE))
                element += Q_NUMBERS;
        }
        input[i] = static_cast<char>(element);
    }
}

void Xor_encryption(string* arr, int string_q) {
    int key = 4;
    string tmp = "2";
    for (int count = 0; count < string_q; count++) {
        string input = arr[count];
        for (int i = 0; i < static_cast<int>(input.size()); i++) {
            input[i] ^= static_cast<int>(key);
        }
        input = tmp + input;
        arr[count] = input;
    }
}

void Xor_decryption(string& input) {
    int key = 4;
    for (int i = 1; i < static_cast<int>(input.size()); i++) {
        input[i] ^= static_cast<int>(key);
    }
}

void Vernam_encryption(string* arr, int string_q, string& key) {
    static int key_index_incryption = 0;
    string tmp = "3";
    for (int count = 0; count < string_q; count++) {
        string input = arr[count];
        int length = static_cast<int>(input.size());
        for (int i = 0; i < length; i++) {
            key += a_CODE + (rand() % Q_ENG_LETTERS);
            input[i] = (input[i] ^ key[key_index_incryption]) + 30;
            key_index_incryption++;
        }
        input = tmp + input;
        arr[count] = input;
        if (count == (string_q - 1)) key_index_incryption = 0;
    }
}

void Vernam_decryption(string& input, string& key, int& key_index_decryption) {
    if (key_index_decryption == 0) {
        key_index_decryption++;
        key_index_decryption++;
    }
    for (unsigned int i = 1; i < input.size(); i++) {
        char element = (input[i] - 30) ^ key[key_index_decryption];
        input[i] = element;
        key_index_decryption++;
    }
}