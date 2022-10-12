#include <iostream>
using namespace std;
//----------------------------1----------------------------
// Implement function 
// void printArray(int n){}
// to print 0, 1, 2, ..., n (n is positive integer and has no space at the end).
// Please note that you can't using key work for, while, goto (even in variable names, comment).
// For this exercise, we have #include <iostream> and using namespace std;
void printArray(int n)
{
    if (n == 0) {
        cout << 0;
        return;
    }
    printArray(n - 1);
    cout << ", " << n;
}
//-------------------------2-------------------------------
// Given a positive number, print following a pattern without using any loop.
// Input: n = 16
// Output: 16, 11, 6, 1, -4, 1, 6, 11, 16 (has no space at the end)
// Input: n = 10
// Output: 10, 5, 0, 5, 10 (has no space at the end)
// We basically first reduce 5 one by one until we reach a negative or 0. After we reach 0 or negative, we one add 5 until we reach n.
void printPattern(int n) 
{ 
    if (n <= 0)  {
        cout << n;
        return;
    };
    cout << n << " ";
    printPattern(n - 5);
    cout << " " << n;
}
//--------------------------3----------------------------------
// Implement function
// int findMax(int* arr, int length){}
// to find the largest element using recursion (with length is the number of elements in integer array arr).
// Please note that you can't using key work for, while, goto (even in variable names, comment).
// For this exercise, we have #include <iostream> and using namespace std;
int maxOf(int a, int b)
{
    return a > b ? a : b;
}
int findMax(int *arr, int length)
{
    if (length == 1) return arr[0];
    return maxOf(arr[length - 1], findMax(arr, length - 1));
}
//--------------------------4----------------------------------
// Implement function 
// bool isPalindrome(string str){}
// to check if the given non empty string is palindrome, else not palindrome using recursion.
// In test case, for extra point, we will have some palindrome sentences (All remaining test cases are words).
bool isPal(string str, int l, int r){
    if (l >= r) return true;
    if (str[l] == ' ') return isPal(str, l + 1, r);
    if (str[r] == ' ') return isPal(str, l, r - 1);
    if (str[l] != str[r]) return false;
    return isPal(str, l + 1, r - 1);
}
bool isPalindrome(string str) 
{
    return isPal(str, 0, str.length() - 1);    
}
//--------------------------5----------------------------------
// Give two positive integers a and b, implement function
// int findGCD(int a, int b){}
// to find GCD (Greatest Common Divisor) of a and b using recursion.
int findGCD(int a, int b)
{
    if (b == 0) return a;
    return findGCD(b, a % b);
    
}
//--------------------------6----------------------------------
// String s contains lowercase letters, digits, "(" and ")", satisfying the following rules:
// - Two digits cannot be adjacent.
// - Two "(" cannot be adjacent.
// - One "(" and one ")" cannot be adjacent.
// - After any digit, there must be "(".
// - The quantities of "(" and ")" are equal.
// Change string s until new string t created, t contains only lowercase letters. These are changing rules:
// - Sub-strings with form "n(p)", can change to "pp...p" (n times p), where n is a digit and p is a string.
// - If p still contains "(", ")" or digits, continue to implement the above changing method.  
// Request: Implement function 
// expand(string s);
// Where s is a string with the above form; return the result is a string containing only lowercase letters.
// Example:
// - String "2(ab3(cde)x)" changes into "abcdecdecdexabcdecdecdex".
// - String "2(x0Có)3(z)" changes into "xxzzz".
void findIdx(string& s, int& i, int& j, const int& lgt)
{
    if (j >= lgt) return;
    if (s[j] == ')') return;
    else if (s[j] == '(') i = j;
    findIdx(s, i, ++j, lgt);
}
void repeatStr(int repeat, string& in, string& out)
{
    if (repeat <= 0) return;
    out += in;
    repeatStr(repeat - 1, in, out);
}
void copy(string& s, int i, int j, string& res)
{
    if (i > j ) return;
    res += s[i];
    copy(s, i + 1, j, res);

}
void replace(string& s, int i, int j, int lgt)
{
    string res{ "" };
    copy(s, i + 1, j - 1, res);
    string mid{ "" };
    repeatStr(s[i - 1] - '0', res, mid);
    string head{ "" };
    copy(s, 0, i - 2, head);
    string tail{ "" };
    copy(s, j + 1, lgt, tail);
    s = head + mid + tail;
}
void imply(string& s, int lgt)
{
    int i{ 0 };
    int j{ 0 };
    findIdx(s, i, j, lgt);
    if (j >= lgt) return;
    replace(s, i, j, lgt);
    lgt = s.length();
    imply(s, lgt);
}
void findStrict(string& s, int& j)
{
    if (s[j]!='\x00') return;
    else findStrict(s,--j);
}
string expand(string s) {
    int lgt{ (int)s.length() };
    imply(s, lgt);
    string res{ "" };
    lgt = s.length();
    findStrict(s,lgt);
    copy(s, 0, lgt, res);
    return res;
}
//--------------------------7----------------------------------
// Give a positive integer x, implement recursive function
// void printHailstone(int number){}
// to print the Hailstone Sequence of a given number upto 1 (no space at the end).
// Hailstone Sequences follow these rules: 
// If a number is even, divide it by 2 
// If a number is odd, multiply it by 3 and add 1.
// Example:
//  If number = 5. 5 is odd number so next number is 5*3 + 1 = 16. 16 is even number so next number is 16/2 = 8...
//  Finally, we get Hailstone sequence: 5 16 8 4 2 1.
void printHailstone(int number)
{
    if (number == 1) {
        cout << 1;
        return;
    }
    if (number % 2 == 0) {
        cout << number << " ";
        printHailstone(number / 2);
    }
    else {
        cout << number << " ";
        printHailstone(number * 3 + 1);
    }
}
//--------------------------8----------------------------------
// Function
// int myArrayToInt(char* str, int n){}
// takes a string str (which represents an positive decimal number), 
// n is the number of elements in the string as arguments and returns its value.
int myArrayToInt(char *str, int n) 
{ 
    if (n == 0) return 0;
    return (str[n - 1] - '0') + 10 * myArrayToInt(str, n - 1);
}
//--------------------------9----------------------------------
// Give two positive integers a and b, implement function
// int findLCM(int a, int b){}
// to find LCM (Lowest Common Multiple) of a and b using recursion.
int GCD(int a, int b){
    if (b == 0) return a;
    return GCD(b, a % b);
}
int findLCM(int a, int b)
{
    return a * b / findGCD(a, b);
}
//--------------------------10----------------------------------
// Given a string s consisting only of '(' and ')'.
// Your task is to implement a function with following prototype:
// int mininumBracketAdd(string s);
// The function returns the mininum number of brackets needed to be inserted to s so that the brackets are balanced.
// More info:
// A sequence of brackets is balanced when there are no unmatched brackets.
// Example: ()(()) is balanced, but ))() is not.
void imply(string& s, int& idx, int& cnt, int& lgt, int& mod) {
    if (idx == lgt) return;
    else {
        if (s[idx] == '(') imply(s, ++idx, ++cnt, lgt, mod);
        else if (cnt == 0) imply(s, ++idx, cnt, lgt, ++mod);
        else imply(s, ++idx, --cnt, lgt, mod);
    } 
}

int mininumBracketAdd(string s) {
    int cnt{0}, mod{0}, lgt{(int)s.length()}, idx{0};
    imply(s, idx, cnt, lgt, mod);
    return cnt + mod;
}
//--------------------------11----------------------------------
// Given a string s representing a sentence consisting only of a-z and A-Z and space character.
// Your task is to implement a function with following prototype:
// string reverseSentence(string s);
// The function returns the reverse sentence of sentence s.
// The testcases ensure that there is only one space character between two adjacent words, 
// and the sentences do not begin or end with any space characters.
string reverseSentence(string s) {
    if (s.size() == 0) return "";
    int i = s.find(" ");
    if (i == -1) return s;
    return reverseSentence(s.substr(i + 1)) + " " + s.substr(0, i);
}
//--------------------------12----------------------------------
// Given a string, implement function
// int strLen(char* str){}
// to calculate length of the string using recursion.
int strLen(char* str)     
{ 
    if (*str == '\0') return 0;
    return 1 + strLen(str + 1);
} 

int main(){
    cout << "hello world =))";
    return 0;
}