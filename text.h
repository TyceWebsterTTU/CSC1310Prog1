#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>
using namespace std;

class Text
{
    private:
        const char* textArray;
        int textLength;
    public:
        Text(const char c[]);
        ~Text();
        void displayText();
        const char* getText() const;
        int getLength() const;
};

#endif