#include <iostream>
#include <string>
#include <fstream>

#include "MORSE.h"
#include "QUEUE.h"
#include "ENCODER.h"

using namespace std;

/*
    This code initialises morse code to ./morseFile/{FILE NAME}
    
    Create a "morseFile" folder along with this .cpp file before execution
    to ensure that the program runs properly.

    Version : C++11
    Compiler: mingw-64
    IDE     : VSCode
*/

// translates morse to string
string morseToString(string morse) {
    MORSE m;
    string translated = "";
    QUEUE morseQueue;
    char letter = '\0';
    for (int i = 0; i < morse.length(); i++) {
        while (morse[i] != ' ' && morse[i] != '\0') {
            if (morse[i] == '.' || morse[i] == '-') morseQueue.enqueue(morse[i]);
            else if (morse[i] != '\0') return "";
            i++;
        }
        letter = m.morseEval(morseQueue);
        if (letter != '\0') translated += letter;
        else if (morse[i] == ' ');
        else return "";
        if (morse[i] == ' ' && morse[i+1] == ' ') {
            translated += " ";
            i++;
        }
    }
    return translated;
}

// this function will create (if said file does not exist) and write
// morse code to it
void writeFile(string morse) {
    string fileName;
    cout << "Enter file name (ex. file.txt): ";
    getline(cin, fileName);
    string filePath = "./morseFile/" + fileName;
    const char *path=filePath.c_str();
    ofstream file(path); //open in constructor
    string data(morse);
    file << data;
}

// this function will output the morse code from stated file into
// the terminal output
void readFile() {
    string fileName, message;
    cout << "Enter file to read message from (ex. file.txt): ";
    getline(cin, fileName);
    string filePath = "./morseFile/" + fileName;
    const char *path=filePath.c_str();
    ifstream file;
    file.open(filePath);
    if(file) {
        cout<< "Reading from " << fileName << endl;
        while (getline (file, message)) {
            // Output the text from the file
            cout << message << endl;
        }
    } else {
        cout<<"File doesn't exist";
   }
}

// this function will output both the message and it's morse equivalent to
// the terminal
void readFileAndEval() {
    string fileName, message;
    cout << "Enter file to read message from (ex. file.txt): ";
    getline(cin, fileName);
    string filePath = "./morseFile/" + fileName;
    const char *path=filePath.c_str();
    ifstream file;
    file.open(filePath);
    if(file) {
        cout<< "Reading from " << fileName << endl;
        while (getline (file, message)) {
            // Output the text from the file
            cout << "Morse code: " << message << endl
                 << "Translated: " << morseToString(message) << endl;
        }
    } else {
        cout<<"File doesn't exist";
   }
}

// encode a text into morse
string textToMorse(string message) {
    ENCODER encode;
    string morse = "";
    for (int i = 0; i < message.length(); i++) {
        if (message[i] != ' ')
            morse += encode.charToMorse(toupper(message[i])) + " ";
        else if (message[i] == ' ')
            morse += " ";
        else
            return "";
    } 
    return morse;
}

int main() {

    string morse, message;
    char choice;

    do {

        cout << "\nMenu: "
             << "\n\t1. Send Morse Message"
             << "\n\t2. Receive Morse Message"
             << "\n\t3. Print Letters and Morse Code"
             << "\n\t4. Translate Text Into Morse Code"
             << "\n\t5. Exit"
             << "\nSelect an instruction: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                cout << "Write morse code to be sent: ";
                getline(cin, morse);
                message = morseToString(morse);
                if (message == "") {
                    cout << "Cannot identify morse code!";
                    break;
                }
                cout << "The morse code you just sent translates into: "
                     << message
                     << "\nDo you want to save it? (y/n): ";
                cin >> choice;
                cin.ignore();
                if (choice == 'y') writeFile(morse);
                break;
            case '2':
                readFile();
                break;
            case '3':
                readFileAndEval();
                break;
            case '4':
                cout << "Write a message to be translated to morse code: ";
                getline(cin, message);
                morse = textToMorse(message);
                if (morse == "") {
                    cout << "Invalid character(s) detected!";
                    break;
                }
                cout << morse << "\nDo you want to store this morse code? (y/n): ";
                cin >> choice;
                cin.ignore();
                if (choice == 'y') writeFile(morse);
                break;
            case '5':
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != '5');

    return 0;
}
