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

/*
 * SHIFT A SINGLE LETTER BY "K" POSITIONS (CIPHER), AND WRAPS AROUND WITHIN
 * "A-Z" OR "a-z". IT ALSO PRESERVES CASE.  NON-LETTER CHARACTERS ARE RETURNED UNCHANGED.
 */

char shift_letter(char c, int k)
{
    // NORMALIZE SHIFT OR VERY LARGE OR NEGATIVE SHIFTS WILL WORK.
    k = ((k % 26)+ 26) % 26;

    if (c >= 'A' && c <= 'Z')
    {
        char base ='A';
        return char (base + ((c - base + k) % 26));
    }
    else if (c >= 'a' && c <= 'z')
    {
        char base = 'a';
        return char (base + ((c - base + k) % 26));
    }
    else
    {
        // NON-LETTER: LEAVE CHANGED
        return c;
    }
}

// ENCRYPTS A FILE BY SHIFTING EACH CHARACTER FORWARD BY K
void encrypt_file (ifstream& in, ofstream& out, int k)
{
    char ch;
    while (in.get(ch)) // READ EACH CHARACTER FROM THE INPUT FILE
        {
            out.put(shift_letter(ch, k)); // WRITE THE SHIFTED CHARACTER TO THE OUTPUT FILE
        }
}

// DECRYPTS A FILE BY SHIFTING EACH CHARACTER BACKWARD BY K
void decrypt_file(ifstream& in, ofstream& out, int k)
{
    char ch;
    while (in.get(ch)) // READ EACH CHARACTER FROM THE INPUT FILE
        {
        out.put(ch - k); // WRITE THE CHARACTER TO THE OUTPUT FILE
        }
}

int main()
{
    string mode; // STORES WHETHER THE END USER WANTS TI ENCRYPT OR DECRYPT
    int key; // SHIFT AMOUNT USED FOR CAESAR CIPHER


    // ASK END USER FOR MODE (ENC/DEC)
    cout << "Enter Mode (encrypt/decrypt): ";
    cin >> mode;

    // ASK END USER FOR SHIFT KEY
    cout << "Enter a Shift Value (integer): ";
    cin >> key;

    /* OPEN INPUT AND OUTPUT FILES + ERROR MSGS!
     *"cerr" is basically the same as "cout" but for error messages. I saw it in a Youtube video.
     */

    ifstream in_file("input.txt");
    if (!in_file)
        {
            cerr << "Error in opening input file!" << endl;
        }

    ofstream out_file("output.txt");
    if (!out_file)
        {
        cerr << "Error in opening output fil!e" << endl;
        }

    // CHOOSING THE MODE MODE: ENCRYPT or DECRYPT
    if (mode == "encrypt")
        {
            encrypt_file(in_file, out_file, key);
        }
    else if (mode == "decrypt")
        {
        decrypt_file(in_file, out_file, key);
        }
    else
        {
        cerr << "Error! Please type 'encrypt' or decrypt' to continue!" << endl;
        return 1;
        }
    return 0;
}