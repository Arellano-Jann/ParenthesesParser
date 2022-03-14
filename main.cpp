#include <iostream>
#include <stack>
bool isValid(std::string s);

int main(){
	std::cout << isValid("()") << std::endl; // true
	std::cout << isValid("()[]{}") << std::endl; // true
	std::cout << isValid("({})") << std::endl; // true
	std::cout << isValid("{}") << std::endl; // true
    std::cout << isValid("({})()") << std::endl; // true
    std::cout << isValid("((()))()()()") << std::endl; // true
    std::cout << isValid("({})()[]") << std::endl; // true
	std::cout << isValid("(())") << std::endl; // true
	std::cout << std::endl;
	std::cout << isValid("(]") << std::endl;
	std::cout << isValid("({)}") << std::endl;
	std::cout << isValid("((") << std::endl;
	std::cout << isValid("({}") << std::endl;
	std::cout << isValid("{") << std::endl;
	std::cout << isValid("}") << std::endl;
    std::cout << isValid("((()))()()(") << std::endl; // true
}

bool isValid(std::string s) {
    std::stack<char> openBrackets;
    if (s.length() % 2 == 1) return false;
    for (int i = 0; i < s.length(); i++){
        switch (s[i]){
            case '(':
                openBrackets.push(s[i]); break;
            case '{':
                openBrackets.push(s[i]); break;
            case '[':
                openBrackets.push(s[i]); break;
            case ')':
                if (openBrackets.empty()) return false;
                else if (openBrackets.top() == '(') openBrackets.pop();
                else return false;
                break;
            case '}':
                if (openBrackets.empty()) return false;
                else if (openBrackets.top() == '{') openBrackets.pop();
                else return false;
                break;
            case ']':
                if (openBrackets.empty()) return false;
                else if (openBrackets.top() == '[') openBrackets.pop();
                else return false;
                break;
        }
    }
    if (openBrackets.empty()) return true;
    return false;
}


// //Recusive Implementation
// bool isValid(std::string s) {
//         if (s.length() % 2 == 1) return false;
//         bool valid = true;
//         char map[] = { '(', '{', '[', ')', '}', ']' };
//         int parentheses = 0;
//         int curly = 0;
//         int square = 0;
// 		// int openParentheses = -1;
//         // int openCurly = -1;
//         // int openSquare = -1;
// 		// int closedParentheses = -1;
//         // int closedCurly = -1;
//         // int closedSquare = -1;
        
//         int closerType = -1;
//         int closer = 0;
//         std::string insideParentheses = "";
//         bool addToString = false;

//         // if ( s[0] == map[0] ){ openParentheses = 0; parentheses++; }
//         // if ( s[0] == map[1] ){ openCurly = 0; curly++; }
//         // if ( s[0] == map[2] ){ openSquare = 0; square++; }
//         switch(s[0]){
//             case '(': 
//                 parentheses++; closerType = 3; break;
//             case '{': 
//                 curly++; closerType = 4; break;
//             case '[': 
//                 square++; closerType = 5; break;
//         }
        
//         for (int i = s.length()-1; i > 0; i--){ // cuts off first letter
            
//             if (!addToString && s[i] == closerType){ // cuts off last letter
//                 closer = i;
//                 addToString = true;
//             }
//             else{ return false; } // ending parentheses not found
//             if (addToString){
//                 insideParentheses.insert(0, 1, s[i]); // string& insert (size_t pos, size_t n, char c);
//             }
        
//             if ( s[i] == map[0] ){ parentheses++; }
//             if ( s[i] == map[1] ){ curly++; }
//             if ( s[i] == map[2] ){ square++; }
//             if ( s[i] == map[3] ){ parentheses--; }
//             if ( s[i] == map[4] ){ curly--; }
//             if ( s[i] == map[5] ){ square--; } // checks if all brackets get closed

// 			if (parentheses<0 || curly<0 || square<0 ) return false; // checks for incorrectly closed parentheses
//         }
//         valid = (parentheses + curly + square == 0);
//         if (valid && closer != 1){ // checks if "()" edge cases
//             isValid(insideParentheses);
//         }
//         else { return false; } // checks for correct number of parentheses
//         // if (parentheses + curly + square > 0) return false; // not sure if this works w this implementation
//         if (closer < s.length()-1){
//             isValid(s.substr(closer+1, std::string::npos));
//         }
//         return true;
//     }

    // Standard Looping
    // bool isValid(std::string s) {
    //     bool valid = true;
    //     char map[] = { '(', '{', '[', ')', '}', ']' };
    //     int parentheses = 0;
    //     int curly = 0;
    //     int square = 0;
	// 	int openParentheses = -1;
    //     int openCurly = -1;
    //     int openSquare = -1;
	// 	int closedParentheses = -1;
    //     int closedCurly = -1;
    //     int closedSquare = -1;
        
    //     for (int i = 0; i < s.length(); i++){
    //         // if ( s[i] == map[0] ){ parentheses++; }
    //         // if ( s[i] == map[1] ){ curly++; }
    //         // if ( s[i] == map[2] ){ square++; }
    //         // if ( s[i] == map[3] ){ parentheses--; }
    //         // if ( s[i] == map[4] ){ curly--; }
    //         // if ( s[i] == map[5] ){ square--; } // checks if all brackets get closed

    //         if ( s[i] == map[0] ){ openParentheses = i; parentheses++; }
    //         if ( s[i] == map[1] ){ openCurly = i; curly++; }
    //         if ( s[i] == map[2] ){ openSquare = i; square++; }
    //         if ( s[i] == map[3] ){ closedParentheses = i; parentheses--; }
    //         if ( s[i] == map[4] ){ closedCurly = i; curly--; }
    //         if ( s[i] == map[5] ){ closedSquare = i; square--; } // checks if all brackets get closed

    //         // if ( s[i] == map[3] && parentheses>0 ) parentheses--;
    //         // if ( s[i] == map[4] && curly>0 ) curly--;
    //         // if ( s[i] == map[5] && square>0 ) square--; // checks if all brackets get closed

	// 		if (parentheses<0 || curly<0 || square<0 ) return false; // checks for incorrectly closed parentheses

            
    //         // bool currentValidity = (parentheses == 0 && curly == 0 && square == 0);
    //         bool currentlyValid = (parentheses + curly + square == 0);
            
    //         for ( )

    //         // // only executes if current index is a closing parentheses that incorrectly closes
	// 		// if ( parentheses == 0 && i == closedParentheses && ( ((closedParentheses + openParentheses) % 2) != ((2*openParentheses+1) % 2)) ) return false;
	// 		// // else{ return false; }

	// 		// if ( curly == 0 && i == closedCurly && ( ((closedCurly + openCurly) % 2) != ((2*openCurly+1) % 2)) ) return false;
	// 		// // else{ return false; }

	// 		// if ( square == 0 && i == closedSquare && ( ((closedCurly + openSquare) % 2) != ((2*openSquare+1) % 2)) ) return false;
	// 		// // else{ return false; }

    //         // for (int j = i+1; j < s.length(); j++){
    //             // if (s[i] == map[3]) valid = currentlyValid;
    //             // if (s[i] == map[4]) valid = currentlyValid;
    //             // if (s[i] == map[5]) valid = currentlyValid;
    //         // if (s[i] == map[3]) return currentlyValid;
    //         // if (s[i] == map[4]) return currentlyValid;
    //         // if (s[i] == map[5]) return currentlyValid;
    //         // }
    //     }
    //     if (parentheses + curly + square > 0) return false;
    //     return valid;
    // }
