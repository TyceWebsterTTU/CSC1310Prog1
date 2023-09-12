#include "text.h"

Text::Text(const char c[])
{
    textArray = new char[textLength];
    textArray = c;
}

Text::~Text()
{
    delete [] textArray;
    cout << "Text destructor: Released memory for textArray.";
}

void Text::displayText()
{
    cout << endl;
    for(int i = 0; i < textLength; i++)
    {
        cout << textArray[i];
    }
}

const char* Text::getText() const
{
    return textArray;
}

int Text::getLength() const
{
    return textLength;
}