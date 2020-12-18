#include <Arduino.h>
#include <string>

#ifndef KEYBDB_H
#define KEYBDB_H

#define KEYBDB_BUFF 32

class KeyBDB {
    public:
        //pass a reference to a Print object
        KeyBDB( Print &print );
        void clear();
        // void clprint(string message);
        void test();
        void recvOneChar();
        void showNewData();
        void readByBuffer();

        char receivedChar;
        char lastChar;
        char receivedBuff[KEYBDB_BUFF];
        boolean newData;
    private:
        Print* printer;
        int buffIdx;
};


#endif