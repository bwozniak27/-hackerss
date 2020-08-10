//
//  Ciphers.cpp
//  Algorithms? pt1
//
//  Created by Ben Wozniak on 1/15/20.
//  Copyright © 2020 Ben Wozniak. All rights reserved.
//

#include "Ciphers.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

string pigLatinDecrypter(string input) {
    string word = "";
    int counter = 0;
    for (int i = static_cast<int>(input.length()) - 1; i > 0; i--) {
        counter++;
        if (counter == 3) {
            word = input[i];
        }
    }
    for (int i = 0; i < input.size() - 3; i++) {
        word += input[i];
    }
    return word;
}

string pigLatinEncryptor(string input) {
    string letter = "";
    string sentence = "";
    
    for (int i = 0; i < input.length(); i++) {
        if (i == 0 || input[i - 1] == ' ') {
            letter = input[i];
        } else if (input[i] == ' ') {
            sentence += letter;
            sentence += "ay ";
        } else if (i == input.length() - 1) {
            sentence += input[i];
            sentence += letter;
            sentence += "ay";
        } else {
            sentence += input[i];
        }
    }
    
    return sentence;
}

string ceasarCypherEncryptor(string input) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    srand( static_cast<unsigned int>(time(nullptr)));
    int num = rand() % 26;
    string sentence = "";
    for (int i = 0; i < input.length(); i++) {
        char l = tolower(input[i]);
        int indicy = findTheLetter(l) + num;
        if (l == ' ') {
            sentence += " ";
        } else if (indicy > alphabet.length()) {
            sentence += alphabet[indicy - 25];
        } else {
            sentence += alphabet[indicy];
        }
    }
    return sentence;
}

void sentenceGenerator(string input) {
    for (int i = 0; i < 26; i++) {
        ceasarCypherDecryptor(input, i);
    }
}

void ceasarCypherDecryptor(string input, int key) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string word;
    vector<string> sentence = {};
    for (size_t j = 0; j < input.size(); j++) {
        size_t count = j;
        string word = "";
        if (input[count - 1] == ' ' || count == 0) {
            while (input[count] != ' ' && input[count] != '.') {
                char l = tolower(input[count]);
                int indicy = findTheLetter(l) - key;
                if (indicy < 0) {
                    word += alphabet[indicy + 26];
                } else {
                    word += alphabet[indicy];
                }
                count++;
            }
            sentence.push_back(word);
        }
    }
    cout << key << ". ";
    for (size_t i = 0; i < sentence.size(); i++) {
        cout << sentence[i] << " ";
    }
    cout << "." << endl;
    if (isASentence(sentence)) {
        cout << endl << "FOUND THE KEY (" << key << ")" << endl;
    }
}


void menu(int &choice) {
    cout << "Welcome to cyphers!" << endl;
    cout << "Please select an option: " << endl;
    cout << "(1) Pig Latin" << endl;
    cout << "(2) Ceasar Cypher" << endl;
    cout << "(3) Quit" << endl;
    cout << "Choice --> ";
    cin >> choice;
}

void menu2(int &choice2) {
    cout << "Please select an option" << endl;
    cout << "(1) Encrypt" << endl;
    cout << "(2) Decrypt" << endl;
    cout << "Choice --> ";
    cin >> choice2;
}

int findTheLetter(char letter) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int numLetter = 0;
    for (int i = 0; i < alphabet.length(); i++) {
        if (alphabet[i] == letter) {
            numLetter = i;
        }
    }
    return numLetter;
}

bool isASentence(vector<string> sentence) {
    
    
    return false;
}
