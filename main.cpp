#include <iostream>

int main(){

}


    bool isValid(std::string s) {
        bool valid = true;
        char map[] = {'(', '{', '[', ')', '}', ']'};
        int parentheses = 0;
        int curly = 0;
        int square = 0;
        
        for (int i = 0; i < s.length(); i++){
            if ( s[i] == map[0] ) parentheses++;
            if ( s[i] == map[1] ) curly++;
            if ( s[i] == map[2] ) square++;
            // if ( s[i] == map[3] ) parentheses--;
            // if ( s[i] == map[4] ) curly--;
            // if ( s[i] == map[5] ) square--; // checks if all brackets get closed
            if ( s[i] == map[3] && parentheses>0 ) parentheses--;
            if ( s[i] == map[4] && curly>0 ) curly--;
            if ( s[i] == map[5] && square>0 ) square--; // checks if all brackets get closed
            
                        
            
            
            // bool currentValidity = (parentheses == 0 && curly == 0 && square == 0);
            bool currentlyValid = (parentheses + curly + square == 0);
            // for (int j = i+1; j < s.length(); j++){
                // if (s[i] == map[3]) valid = currentlyValid;
                // if (s[i] == map[4]) valid = currentlyValid;
                // if (s[i] == map[5]) valid = currentlyValid;
            if (s[i] == map[3]) return currentlyValid;
            if (s[i] == map[4]) return currentlyValid;
            if (s[i] == map[5]) return currentlyValid;
            // }
        }
        if (parentheses + curly + square > 0) return false;
        return valid;
    }
