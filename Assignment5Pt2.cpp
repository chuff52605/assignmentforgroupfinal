#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void encrypt_file(ifstream& in, ofstream& out, int k) {
    char ch;
    while (in.get(ch)) {
        out.put(ch + k);
        }
 
}

void decrypt_file(ifstream& in, ofstream& out, int k) {
    char ch;
    while (in.get(ch)) {
        out.put(ch - k);
    }

}

int main() {

    string mode;
    int key;
    string input;
    string output;
    cout << "Mode: " << endl;
    cin >> mode;
    cout << "Shift: " << endl;
    cin >> key;
    ifstream in_file("input.txt");
    ofstream out_file("output.txt");
    if (mode == "encrypt") {
        encrypt_file(in_file, out_file, key);
         }
    if (mode == "decrypt") { 
        decrypt_file(in_file, out_file, key);
            }

    return 0;
  
}