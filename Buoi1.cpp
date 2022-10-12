#include <iostream>
#include <vector>
using namespace std;


bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
    // best algorithm
    //The function returns if all the 1s appear consecutively in nums. If nums does not contain any elements, please return true
    if (nums.size() == 0) return true;
    int l = 0;
    int r = nums.size() - 1;
    if (nums[l] == 1) 
        while (l < r) {
            if (nums[l] == 1 && nums[l + 1] == 1) l++;
            else return false;
        }
    if (nums[r] == 1) 
        while (l < r) {
            if (nums[r] == 1 && nums[r - 1] == 1) r--;
            else return false;
        }
    while (l < nums.size() - 1 && nums[l] != 1) l++;
    while (r > 0 && nums[r] != 1) r--;
    if (l == nums.size() - 1 || r == 0) return true;
    while (l < r) {
        if (nums[l] == 1 && nums[l + 1] == 1) l++;
        else return false;
    }
    return true;

}

int equalSumIndex(vector<int>& nums) {
    if (nums.size() == 0) return -1;
    if (nums.size() == 1) return 0;
    int l = 0;
    int r = nums.size() - 1;
    int sumL = nums[l];
    int sumR = nums[r];
    while (l < r){
        if (sumL == sumR){
            if (l + 1 == r - 1) return l + 1;
            l++;
            r--;
            sumL += nums[l];
            sumR += nums[r];
        }
        else if (sumL < sumR){
            l++;
            sumL += nums[l];
        }
        else {
            r--;
            sumR += nums[r];

        }
    }
    return -1;
}

int longestSublist(vector<string>& words) {
    // The function returns the length of the longest subarray where all words share the same first letter.
    if (words.size() == 0) return 0;
    if (words.size() == 1) return 1;
    vector<int> count(26, 0);
    for (int i = 0; i < words.size(); i++) {
        count[words[i][0] - 'a']++;
    }
    int max = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) max = count[i];
    }
    return max;
    
}

int mininumBracketAdd(string s){
    // The function returns the minimum number of brackets that need to be added to s so that the brackets are balanced.
    
}
int strLen(char* str)     
{ 
    // recursion
    if (*str == '\0') return 0;
    return 1 + strLen(str + 1);
} 

string reverseSentence(string s) {
    // recursion
    if (s.size() == 0) return "";
    int i = s.find(" ");
    if (i == -1) return s;
    return reverseSentence(s.substr(i + 1)) + " " + s.substr(0, i);

}


string multy(string s, int n){
    // recursion
    if (n == 0) return "";
    return s + multy(s, n - 1);
}

string expand(string s) {
// String "2(ab3(cde)x)" changes into "abcdecdecdexabcdecdecdex".
    if (s.size() == 0) return "";
    int i = s.find("(");
    if (i == -1) return s;
    int j = s.find(")");
    int n = s[i - 1] - '0';
    return s.substr(0, i - 1) + multy(expand(s.substr(i + 1, j - i - 1)), n) + expand(s.substr(j + 1));
}

int main(){
vector<string> words {"faction", "fight", "and", "are", "attitude"};
cout << longestSublist(words);

}
