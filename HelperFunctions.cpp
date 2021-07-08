//
// Created by jonng on 6/1/2021.
//

#include "HelperFunctions.h"

bool HelperFunctions::isNumber(std::string aString) {
    bool decimalPlaceUsed = false;
    int i = 0;
    if (aString.empty())
        return false;
    if(aString[0] == '-') {
        ++i;
    }
    for(; i < aString.length(); ++i) {
        if(aString[i] == '.') {
            if(decimalPlaceUsed)
                return false;
            decimalPlaceUsed = true;
        }
        else if(!isdigit(aString[i]))
            return false;
    }
    return true;
}
