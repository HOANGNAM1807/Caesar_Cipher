#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

string encrypt(string text, int key) { // Pass in the string to be encrypted and the key
    string result = ""; // Declare an empty string
    for (int i = 0; i < (int)text.length(); i++) { // Loop through each character of the string
        if (isalpha(text[i])) { // Check if it's a letter
            if (isupper(text[i])) // If it's uppercase...
                result += char(int(text[i] + key - 65) % 26 + 65); // A = 65
            // Convert ASCII to the 0-26 range for shifting by key
            // Then convert back to ASCII to add to the result (+65)
            else // If it's lowercase, do the same but for lowercase letters
                result += char(int(text[i] + key - 97) % 26 + 97); // a = 97
        } else 
            result += text[i]; // If it's not a letter, keep it as is
    }
    return result;
}

string decrypt(string text, int key) { // Decryption works similarly, but we subtract the key instead of adding
    string result = "";
    for (int i = 0; i < (int)text.length(); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i]))
                result += char(int(text[i] - key - 65 + 26) % 26 + 65);
            else
                result += char(int(text[i] - key - 97 + 26) % 26 + 97);
        } else 
            result += text[i];
    }
    return result;
}

void printCaesarCipherTable() { 
    int shift = 0;
    cout << setw(47) << "Corresponding Values Table" << endl;
    for (char c = 'a'; c <= 'z'; c++) {
        char ciphertext = (c + shift - 'a') % 26 + 'a';
        printf("|%-2c", c);
    }
    cout << endl;
    for (char c = 'A'; c <= 'Z'; c++) {
        char ciphertext = (c + shift - 'a') % 26 + 'a';
        printf("|%-2c", c);
    }
    cout << endl;
    for (int i = 0; i < 26; i++) {
        printf("|%-2d", i);
    }
    cout << endl;
}

void printEncryptionTable(string text, int key) {
    string enc = encrypt(text, key);
    cout << "Key: " << key << endl;
    for (int i = 0; i < (int)text.length(); i++) {
        if (islower(text[i])) {
            cout << text[i] << ":(" << int(text[i] - 97) % 26 << ")"
                 << "  -->  " << enc[i] << ":(" << int(enc[i] - 97) % 26 << ")" << endl;
        } else {
            cout << text[i] << ":(" << int(text[i] - 65) % 26 << ")"
                 << "  -->  " << enc[i] << ":(" << int(enc[i] - 65) % 26 << ")" << endl;
        }
    }
    cout << endl;
}

void printDecryptionTable(string text, int key) {
    string enc = decrypt(text, key);
    cout << "Key: " << key << endl;
    for (int i = 0; i < (int)text.length(); i++) {
        if (islower(text[i])) {
            cout << text[i] << ":(" << int(text[i] - 97) % 26 << ")"
                 << "  -->  " << enc[i] << ":(" << int(enc[i] - 97) % 26 << ")" << endl;
        } else {
            cout << text[i] << ":(" << int(text[i] - 65) % 26 << ")"
                 << "  -->  " << enc[i] << ":(" << int(enc[i] - 65) % 26 << ")" << endl;
        }
    }
    cout << endl;
}

int main() {
    while (1) {
        cout << "\n---CAESAR CIPHER---\n" << endl;
        printCaesarCipherTable();
        cout << "  1. Encrypt" << endl;
        cout << "  2. Decrypt" << endl;
        cout << "  3. Exit" << endl;

        int option = 0;
        do {
            printf("Enter choice [1-3]: ");
            scanf("%d", &option);
            while (getchar() != '\n');
            printf("\nCurrent choice is: %d\n", option);
        } while (!(option >= 1 && option <= 3));

        if (option == 1) {
            // system("cls"); // Clear screen
            cout << setw(23) << "\n___ENCRYPTION___\n";
            string text;
            cout << "\nEnter text to encrypt: ";
            getline(cin, text);
            int key;
            cout << "Shift [1-26]: ";
            cin >> key;
            cin.ignore();
            string crypted_text = encrypt(text, key);
            printEncryptionTable(text, key);
            cout << "Cipher: " << crypted_text << endl;
        } else if (option == 2) {
            // system("cls"); // Clear screen
            cout << "\n___DECRYPTION___\n" << endl;
            string text;
            cout << "\nEnter text to decrypt: ";
            getline(cin, text);
            int key;
            cout << "Shift [1-26]: ";
            cin >> key;
            cin.ignore();
            printDecryptionTable(text, key);
            cout << "Plain: " << decrypt(text, key) << endl;
        } else if (option == 3) {
            cout << "\nExit program!" << endl;
            getchar();
            exit(0);
        }
    }
}
