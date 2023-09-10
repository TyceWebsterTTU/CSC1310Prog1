#include "text.h"

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