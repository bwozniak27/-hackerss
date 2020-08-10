//
//  main.cpp
//  Algorithms? pt1
//
//  Created by Ben Wozniak on 12/29/19.
//  Copyright © 2019 Ben Wozniak. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Ciphers.hpp"
using namespace std;



int main() {
    int choice = 0;
    int choice2 = 0;
    
    
    menu(choice);
    cout << endl << endl;
    while (choice < 1 || choice > 3) {
        cout << "Enter a valid choice --> ";
        menu(choice);
    }
    if (choice != 3) {
        menu2(choice2);
        cout << endl << endl;
        while (choice2 < 1 || choice2 > 3) {
            cout << "Enter a valid choice --> ";
            menu2(choice2);
        }
        cyphers(choice, choice2);
        cout << endl << endl;
    }

    
    return 0;
}

void cyphers(int choice, int choice2) {
    string input;
    if (choice == 1) {
        if (choice2 == 1) {
            cout << "Pig Latin Encryptor!" << endl;
            cout << "Input a sentence: ";
            cin.get();
            getline(cin, input);
            cout << "Encrypted sentence: " << pigLatinEncryptor(input) << endl;
        } else if (choice2 == 2) {
            cout << "Pig Latin Decryptor!" << endl;
            cout << "Input a word: ";
            cin >> input;
            cout << "Decrypted word: " << pigLatinDecrypter(input) << endl;
        }
    } else if (choice == 2) {
        if (choice2 == 1) {
            ifstream fin;
            fin.open("ceasarcypher.txt");
            cout << "Ceasar Cypher Encryptor" << endl;
            getline(fin, input, '.');
            cout << "Encrypted sentence: " << ceasarCypherEncryptor(input) << endl;
            fin.close();
        } else if (choice2 == 2) {
            ifstream fin;
            fin.open("ceasarcypher.txt");
            cout << "Ceasar Cypher Decryptor" << endl;
            getline(fin, input, '.');
            cout << "Decrypted sentences: " << endl;
            string input2 = ceasarCypherEncryptor(input);
            cout << "sentence: " << input2 << "." << endl;
            ceasarCypherDecryptor(input2);
            fin.close();
        }
    }
}


