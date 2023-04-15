#include <iostream>
#include <string>
#include <ctime>
#include "Main.h"

void Get_txt(string* arr, int string_q) {
    cout << "������������� �����:" << endl;
    char tmp = arr[0].at(0);
    int k = 0;
    int start;
    while (tmp != '|') {
        tmp = arr[0].at(k);
        k++;
    }
    start = k + 1;
    for (int i = 0; i < string_q; i++) {
        cout << "|";
        if (i == 0) {
            for (unsigned int j = start; j < arr[i].length(); j++) {
                cout << arr[i].at(j);
            }
        }
        else {
            for (unsigned int j = 1; j < arr[i].length(); j++) {
                cout << arr[i].at(j);
            }
        }
        cout << "|";
        cout << endl;
    }
}

int main() {
    setlocale(0, "");
    srand(static_cast<unsigned int>(time(NULL)));
    Greeting();
    do {
        int shift = 0;
        string* arr = nullptr;
        int string_q = 0;
        string key_str = ""; // ���� ���������� ��� �������� �������
        cout << "������� �������� ��������� �����?\n1 - ��\n2 - ���" << endl;
        int choice = Check_choice(2);
        if (choice == YES) Module_tests();

        cout << "�������, ��� �� ������ �������:\n1 - ����������� ������\n2 - ������������ ������" << endl;
        choice = Check_choice(TWO_ELEMENTS);
        switch (choice) {
        case ENCRYPTION: {
            cout << "�������� ������ ����� ������\n1 - ���� � ����������\n2 - ���� �� �����" << endl;
            choice = Check_choice(TWO_ELEMENTS);
            if (choice == USER_INPUT) User_input(arr, string_q, ENCRYPTION);
            if (choice == FILE_INPUT) InputData(arr, string_q, key_str, &shift);

            cout << "��������� ������ �����?\n1 - ��\n2 - ���" << endl;
            choice = Check_choice(TWO_ELEMENTS);
            if (choice == YES) OutputData(arr, string_q, INPUT, key_str);

            cout << "�������� ����� ����������\n1 - ���� �������������� ������\n2 - ���� ������������ ���\n3 - ���� �������" << endl;
            choice = Check_choice(THREE_ELEMENTS);
            switch (choice) {

            case SHIFT: {
                cout << "������� ���� ��� �������������� ������: ";
                shift= Get_int();
                while (shift<=0) {
                    cout << "������!������� ���� ������ ����: ";
                    shift = Get_int();
                    cout << endl;
                }
                Shift_encryption(arr, string_q,shift);
                Get_txt(arr, string_q);
                break;
            }
            case XOR: {
                Xor_encryption(arr, string_q);
                Get_text(arr, string_q);
                break;
            }
            case VERNAM: {
                Vernam_encryption(arr, string_q, key_str);
                Get_text(arr, string_q);
                cout << "����: " << key_str << endl;
                break;
            }
            }
            cout << "��������� ����������?\n1 - ��\n2 - ���" << endl;
            choice = Check_choice(TWO_ELEMENTS);
            if (choice == YES) OutputData(arr, string_q, RESULTS_TMP, key_str);
            break;
        }
        case DECRYPTION: {
            static int key_index_decryption = 0;
            cout << "�������� ������ ����� ������\n1 - ���� � ����������\n2 - ���� �� �����" << endl;
            choice = Check_choice(TWO_ELEMENTS);
            if (choice == USER_INPUT) User_input(arr, string_q, DECRYPTION);
            if (choice == FILE_INPUT) InputData(arr, string_q, key_str,&shift);

            cout << "��������� ������ �����?\n1 - ��\n2 - ���" << endl;
            choice = Check_choice(TWO_ELEMENTS);
            if (choice == YES) OutputData(arr, string_q, INPUT, key_str);

            for (int count = 0; count < string_q; count++) {
#pragma warning (disable: 6011)
                string input = arr[count];
#pragma warning (default: 6011)
                char element = input[0];
                choice = Analysis_choice(element);
                switch (choice) {
                case SHIFT: {
                    Shift_decryption(input,shift);
                    cout << "�������������� ������: |";
                    string shiftStr = to_string(shift);
                    if (count==0)input.erase(0, shiftStr.length());
                    Get_string(input);
                    cout << "|" << endl;
                    break;
                }
                case XOR: {
                    Xor_decryption(input);
                    cout << "�������������� ������: |";
                    Get_string(input);
                    cout << "|" << endl;
                    break;
                }
                case VERNAM: {
                    if (key_str == "") {
                        cout << "������� ����: " << endl;
                        getline(cin, key_str);
                    }
                    Vernam_decryption(input, key_str, key_index_decryption);
                    cout << "�������������� ������: |";
                    Get_string(input);
                    cout << "|" << endl;
                    break;
                }
                default: {
                    cout << "��������� �� ����� ������������ ������ ��� ������� " << count << endl;
                    break;
                }
                }
                arr[count] = input;
                if (count == (string_q - 1)) key_index_decryption = 0;
            }
            cout << "��������� ����������?\n1 - ��\n2 - ���" << endl;
            choice = Check_choice(TWO_ELEMENTS);
            if (choice == YES) OutputData(arr, string_q, RESULTS, key_str);
            break;
        }
        }
        cout << "������� Enter, ��� ���� ����� ��������� ���������.\n" "'0' - ��� ���������� ���������." << endl;
    } while (getchar() != '0');
}