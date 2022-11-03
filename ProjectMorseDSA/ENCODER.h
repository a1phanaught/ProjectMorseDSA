#include <iostream>
#include <string>

#ifndef ENCODER_h
#define ENCODER_h
#define size 51

using namespace std;

class ENCODER {

    private:

        // These characters are sorted by their int value in ASCII.
        const string characters = "!\"\'()+,-./0123456789:;=?@ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const string morse[size] = {"-.-.--", ".-..-.", ".----.", "-.--.", "-.--.-", ".-.-.",
        "--..--", "-....-", ".-.-.-", "-..-.", "-----", ".----", "..---", "...--", "....-", ".....", "-....",
        "--...", "---..", "----.", "---...", "-.-.-.", "-...-", "..--..", ".--.-.",
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
        "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    public:
    	
    	ENCODER() {
		}

        // Binary search for target character, then return the morse equivalent of said
        // character.
        string charToMorse(char chr) {
            int l = 0, r = size-1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (characters[m] == chr)
                    return morse[m];
                if (characters[m] < chr)
                    l = m + 1;
                else
                    r = m - 1;
            }
            return "";
        }

};

#endif
