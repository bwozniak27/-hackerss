//
//  Ciphers.hpp
//  Algorithms? pt1
//
//  Created by Ben Wozniak on 1/15/20.
//  Copyright © 2020 Ben Wozniak. All rights reserved.
//

#ifndef Ciphers_hpp
#define Ciphers_hpp

#include <stdio.h>
#include <string>


std::string pigLatinEncryptor(std::string input);

std::string pigLatinDecrypter(std::string input);

std::string ceasarCypherEncryptor(std::string input);

std::string findTheWord(std::string);

void ceasarCypherDecryptor(std::string input, int key);

void sentenceGenerator(std::string input);

int findTheLetter(char letter);

void menu(int &choice);

void menu2(int &choice2);

void cyphers(int choice, int choice2);

bool isASentence(std::vector<std::string> sentence);





#endif /* Ciphers_hpp */
