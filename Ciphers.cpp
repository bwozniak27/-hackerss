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
        } else {
            sentence += alphabet[indicy % 26];
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
    for (size_t j = 0; j < input.length(); j++) {
        size_t count = j;
        string word = "";
        if (input[count - 1] == ' ' || count == 0) {
            while (input[count] != ' ' && count < input.length()) {
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
        } else {
        }
    }
    cout << key << ". ";
    for (size_t i = 0; i < sentence.size(); i++) {
        cout << sentence[i] << " ";
    }
    cout << endl;
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
    for (int i = 0; i < alphabet.length(); i++) {
        if (alphabet[i] == letter) {
            return i;
        }
    }
    return 0;
}

bool isASentence(vector<string> sentence) {
    for (auto i:sentence) {
        if (!find_word(i, read_words_from_file("words.txt"))) {
            return false;
        }
    }
    return true;
}

vector<string> read_words_from_file(const string &filename) {
    vector<string> words;
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        cout << "ERROR" << endl;
    }
    string tempWord = "";
    while (!fin.eof()) {
        fin >> tempWord;
        words.push_back(tempWord);
        tempWord = "";
    }
    
    return words;
}

bool find_word(string word, const vector<string> &valid_words) {
    for (size_t i = 0; i < valid_words.size(); i++) {
        if (same_strings(word, valid_words[i])) {
            return true;
        }
    }
    return false;
}

bool same_strings(string word1, string word2) {
    if (word1.length() == word2.length()) {
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}
