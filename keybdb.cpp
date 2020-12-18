#include "keybdb.h"

KeyBDB::KeyBDB( Print &print ) {
    printer = &print; //operate on the adress of print
    receivedChar = '\0';
    lastChar = '\0';
    newData = false;
    buffIdx = 0;
}

void KeyBDB::clear() {
    printer->print("\r                                                              \r");
}

// void KeyBDB::clprint(string msg) {
//     clear(); 
//     printer->print("")
// }

void KeyBDB::test() {
    printer->println("Hello library with serial connectivity!");
}

void KeyBDB::recvOneChar() {
    if (Serial.available() > 0) {
        lastChar = receivedChar;
        receivedChar = Serial.read();
        newData = true;
    }
}

void KeyBDB::showNewData() {
    if (newData == true) {
        clear();
        printer->print("Last command: ");
        printer->print(receivedChar);
        newData = false;
    }
}

void KeyBDB::readByBuffer() {
    if (!newData)
        return;

    if (receivedChar != '\n' && buffIdx < KEYBDB_BUFF) {
        receivedBuff[buffIdx] = receivedChar;
        buffIdx++;
    }
    else if (receivedChar != '\n' && buffIdx == KEYBDB_BUFF) {
        printer->print("Buffer exceeded! (clearing buffer)");
        buffIdx = 0;
        receivedBuff[buffIdx] = '\0';
    }
    else {
        receivedBuff[buffIdx] = '\0';
        clear();
        printer->print("You entered: ");
        printer->print(receivedBuff);
        buffIdx = 0;
        receivedBuff[buffIdx] = '\0';
        newData = false;
    }
}


