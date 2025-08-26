#include <iostream>   // for input and output
#include <string>
using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int num) {
    string binary = "";
    if (num == 0) return "0";
    while (num > 0) {
        int digit = num % 2;
        binary = char(digit + '0') + binary;  // convert digit to character
        num = num / 2;
    }
    return binary;
}

// Function 2: Binary to Decimal
int binaryToDecimal(string bin) {
    int decimal = 0;
    int power = 1; // start with 2^0

    for (int i = bin.length() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

// Function 3: Decimal to Hexadecimal
string decimalToHexadecimal(int num) {
    string hex = "";
    char hexDigits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    if (num == 0) return "0";
    while (num > 0) {
        int digit = num % 16;
        hex = hexDigits[digit] + hex;
        num = num / 16;
    }
    return hex;
}

// Function 4: Hexadecimal to Decimal
int hexadecimalToDecimal(string hex) {
    int decimal = 0;
    int power = 1; // 16^0

    for (int i = hex.length() - 1; i >= 0; i--) {
        char ch = hex[i];
        int value;

        if (ch >= '0' && ch <= '9') {
            value = ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            value = ch - 'A' + 10;
        } else if (ch >= 'a' && ch <= 'f') {
            value = ch - 'a' + 10;
        } else {
            cout << "Invalid hexadecimal digit." << endl;
            return -1;
        }

        decimal += value * power;
        power *= 16;
    }
    return decimal;
}

int main() {
    int choice;

    {
        cout << "\n==== MENU ====" << endl;
        cout << "1. Decimal to Binary" << endl;
        cout << "2. Binary to Decimal" << endl;
        cout << "3. Decimal to Hexadecimal" << endl;
        cout << "4. Hexadecimal to Decimal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 1) {
            int num;
            cout << "Enter a decimal number: ";
            cin >> num;
            cout << "Binary: " << decimalToBinary(num) << endl;
        }
        else if (choice == 2) {
            string bin;
            cout << "Enter a binary number: ";
            cin >> bin;
            cout << "Decimal: " << binaryToDecimal(bin) << endl;
        }
        else if (choice == 3) {
            int num;
            cout << "Enter a decimal number: ";
            cin >> num;
            cout << "Hexadecimal: " << decimalToHexadecimal(num) << endl;
        }
        else if (choice == 4) {
            string hex;
            cout << "Enter a hexadecimal number: ";
            cin >> hex;
            cout << "Decimal: " << hexadecimalToDecimal(hex) << endl;
        }
        else if (choice == 5) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
