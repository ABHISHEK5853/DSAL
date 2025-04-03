// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isValid(string str) {
            stack<char> s;
    
            for (char c : str) {
                if (c == '(' || c == '{' || c == '[') {
                    s.push(c);
                } else {
                    if (s.empty()) return false;  
    
                    char top = s.top();
                    s.pop();
    
                    switch (c) {
                        case ')': if (top != '(') return false; break;
                        case '}': if (top != '{') return false; break;
                        case ']': if (top != '[') return false; break;
                        default: return false; 
                    }
                }
            }
    
            return s.empty();
        }
    };
    