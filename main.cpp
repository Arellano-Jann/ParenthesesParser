#include <iostream>
bool isValid(std::string s);

int main(){
	std::cout << isValid("()") << std::endl; // true
	std::cout << isValid("()[]{}") << std::endl; // true
	std::cout << isValid("(())") << std::endl; // true
	std::cout << isValid("({})") << std::endl; // true
	std::cout << isValid("{}") << std::endl; // true
	std::cout << std::endl;
	std::cout << isValid("(]") << std::endl;
	std::cout << isValid("({)}") << std::endl;
	std::cout << isValid("((") << std::endl;
	std::cout << isValid("({}") << std::endl;
	std::cout << isValid("{") << std::endl;
	std::cout << isValid("}") << std::endl;
}


    bool isValid(std::string s) {
        bool valid = true;
        char map[] = { '(', '{', '[', ')', '}', ']' };
        int parentheses = 0;
        int curly = 0;
        int square = 0;
		int openParentheses = -1;
        int openCurly = -1;
        int openSquare = -1;
		int closedParentheses = -1;
        int closedCurly = -1;
        int closedSquare = -1;
        
        for (int i = 0; i < s.length(); i++){
            if ( s[i] == map[0] ){ openParentheses = i; parentheses++; }
            if ( s[i] == map[1] ){ openCurly = i; curly++; }
            if ( s[i] == map[2] ){ openSquare = i; square++; }
            if ( s[i] == map[3] ){ closedParentheses = i; parentheses--; }
            if ( s[i] == map[4] ){ closedCurly = i; curly--; }
            if ( s[i] == map[5] ){ closedSquare = i; square--; } // checks if all brackets get closed
            // if ( s[i] == map[3] && parentheses>0 ) parentheses--;
            // if ( s[i] == map[4] && curly>0 ) curly--;
            // if ( s[i] == map[5] && square>0 ) square--; // checks if all brackets get closed
			if (parentheses<0 || curly<0 || square<0 ) return false; // checks for incorrectly closed parentheses
            
                        
            
            
            // bool currentValidity = (parentheses == 0 && curly == 0 && square == 0);
            bool currentlyValid = (parentheses + curly + square == 0);

			if ( parentheses == 0 && i == closedParentheses && ( ((closedParentheses + openParentheses) % 2) != ((openParentheses+1) % 2)) ) return false;
			// else{ return false; }

			if ( curly == 0 && i == closedCurly && ( ((closedCurly + openCurly) % 2) != ((openCurly+1) % 2)) ) return false;
			// else{ return false; }

			if ( square == 0 && i == closedSquare && ( ((closedCurly + openSquare) % 2) != ((openSquare+1) % 2)) ) return false;
			// else{ return false; }
            // for (int j = i+1; j < s.length(); j++){
                // if (s[i] == map[3]) valid = currentlyValid;
                // if (s[i] == map[4]) valid = currentlyValid;
                // if (s[i] == map[5]) valid = currentlyValid;
            // if (s[i] == map[3]) return currentlyValid;
            // if (s[i] == map[4]) return currentlyValid;
            // if (s[i] == map[5]) return currentlyValid;
            // }
        }
        if (parentheses + curly + square > 0) return false;
        return valid;
    }
