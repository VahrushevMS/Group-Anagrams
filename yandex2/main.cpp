
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <math.h>
#include<map>
#include<set>
#include<deque>
#include<algorithm>
using namespace std;
void print(set<string> s) {
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
}
void Sort(vector<char>& arr) {
    for (int i = 0;i < arr.size();i++) {
        for (int j = 0;j < arr.size();j++) {
            if ((int)arr[i] < (int)arr[j]) {
                char temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
vector<char> split(string& s) {
    vector<char> res;
    for (auto it : s) {
        res.push_back(it);
    }
    Sort(res);
    return res;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    set<string> check;
    vector<string> s;
    vector<vector<string>> b;
    int flag = 0;
    for (int i = 1;i < strs.size();i++) {
        if (strs[i] != strs[i-1]) {
            flag = 1;
        }
    }
    if (flag == 0) return { strs };
    for (int i = 0;i < strs.size();i++) {
        if (find(s.begin(), s.end(), strs[i]) == s.end() && find(check.begin(), check.end(), strs[i]) == check.end()) s.push_back(strs[i]);
        for (int j = i+1;j < strs.size();j++) {
            if (split(strs[i]) == split(strs[j])) {                
                if(find(check.begin(), check.end(), strs[j]) == check.end()) s.push_back(strs[j]);
                
                check.insert(strs[j]);
            }
            
        }
        check.insert(strs[i]);
        result.push_back(s);
        s = {};
    }
    set<vector<string>> st;
    vector<string> a = {};
    for (auto it : result) {
        if (it != a) {
            st.insert(it);
        }
    }
    result.clear();
    vector<string> c;
    for (auto it : st) {
        for (auto iter : it) {
            c.push_back(iter);
        }
        b.push_back(c);
        c.clear();
    }
    return b;
}
int main() {
    vector<string> strs = { "","b" };
    vector<vector<string>> st = groupAnagrams(strs);
    for (auto it : st) {
        for (auto iter: it) {
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << st.size();
    return 0;
}

