#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
bool comp(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> nb) {
    string ans = "";
    vector<string> t;
    for (auto num : nb)
        t.push_back(to_string(num));
    sort(t.begin(), t.end(), comp);
    if (t.at(0) == "0") return "0";
    for (auto val : t)
        ans += val;
    return ans;
}