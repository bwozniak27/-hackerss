//
//  ciphers_tests.cpp
//  Algorithms? pt1
//
//  Created by Ben Wozniak on 1/15/20.
//  Copyright © 2020 Ben Wozniak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Ciphers.hpp"
using namespace std;


void test_pigLatinDecrypter();

void test_pigLatinEncrypter();

void test_findTheLetter();

void test_ceasarCypherEncryptor();

int main() {
    
    test_pigLatinDecrypter();
    cout << endl << endl;
    test_pigLatinEncrypter();
    cout << endl << endl;
    test_findTheLetter();
    cout << endl << endl;
    
}

void test_pigLatinDecrypter() {
    cout << "testing_pigLatinDecrypter" << endl;
    
    string input = "ellohay";
    assert(pigLatinDecrypter(input) == "hello");
    cout << "PASS 1" << endl;
}

void test_pigLatinEncrypter() {
    cout << "testing_pigLatinEncrypter" << endl;
    
    string input = "happy birthday";
    assert(pigLatinEncryptor(input) == "appyhay irthdaybay");
    cout << "PASS 1" << endl;
}

void test_findTheLetter() {
    cout << "testing_findTheLetter" << endl;
    
    char input = 'r';
    assert(findTheLetter(input) == 17);
    cout << "PASS1!" << endl;
    
    input = 'a';
    assert(findTheLetter(input) == 0);
    cout << "PASS2!" << endl;
    
    input = 'z';
    assert(findTheLetter(input) == 25);
    cout << "PASS3!" << endl;
}
