#include "text.h"

Text::Text(const char* c)
{
    textLength = strlen(c);
    char* temp = new char[textLength + 1];
    strcpy(textArray, c);
    this->textArray = temp;
}

Text::~Text()
{
    delete [] textArray;

    cout << "Text destructor: Released memory for textArray.";
}

void Text::displayText()
{
        cout << textArray;
}

const char* Text::getText() const
{
    return textArray;
}

int Text::getLength() const
{
    return textLength;
}