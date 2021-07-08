//
// Created by jonng on 4/11/2021.
//

#include "TextChar.h"

TextChar::TextChar() : TextChar('?'){ }
TextChar::TextChar(std::string aString) : TextChar(aString[0]) { }
TextChar::TextChar(char aChar) {
    setString(aChar);
}
bool operator == (const TextChar& char1, const TextChar& char2) {
    return (char1.getString() == char2.getString());
}
std::ostream& operator << (std::ostream& outs, const TextChar& aTextChar) {
    outs << static_cast<std::string>(aTextChar.getString());
    return outs;
}
