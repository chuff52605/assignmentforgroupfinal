#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: CSC 242
** Assignment: Assignment 5
** File: Assignment5Pt.cpp
** Description: Enter brief project description here.
**
** Author: 	Joshua Perry, Denkeis Hunter, Connor Huff, Nicholas Caceres
** Date: NOVEMBER 17, 2025
** -------------------------------------------------------------------------*/

using namespace std;

// ENCRYPTS A FILE BY SHIFITING EACH CHARACTER FORWARD BY K
void encrypt_file(ifstream& in, ofstream& out, int k)
{
    char ch;
    while (in.get(ch)) // READ EACH CHARACTER FROM THE INPUT FILE
        {
        out.put(ch + k); // WRITE THE CHRACTER TO THE OUTPUT FILE
        }
}
// DECRYPTS A FILE BY SHIFITNG EACH CHARACTER BACKWARD BY K
void decrypt_file(ifstream& in, ofstream& out, int k)
{
    char ch;
    while (in.get(ch)) // READ EACH CHARACTER FROM THE INPUT FILE
        {
        out.put(ch - k); // WRITE THE CHRACTER TO THE OUTPUT FILE
        }
}

int main()
{
    string mode; // STORES WHETHER THE END USER WANTS TI ENCRYPT OR DECRYPT
    int key; // SHIFT AMOUNT USED FOR CAESAR CIPHER
    string input;
    string output;

    // ASK END USER FOR MODE (ENC/DEC)
    cout << "Mode: " << endl;
    cin >> mode;

    // ASK END USER FOR SHIFT KEY
    cout << "Shift: " << endl;
    cin >> key;

    // OPEN INPUT AND OUTPUT FILES
    ifstream in_file("input.txt");
    ofstream out_file("output.txt");

    // IF END USER CHOSE ENCRYPTION, CALL THE ENCRYPT FUNCTION
    if (mode == "encrypt")
        {
        encrypt_file(in_file, out_file, key);
        }

    // IF END USER CHOSE DYCRYPTION, CALL THE DECRYPT FUNCTION
    if (mode == "decrypt")
        {
        decrypt_file(in_file, out_file, key);
        }
    return 0;
}