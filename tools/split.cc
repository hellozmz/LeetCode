#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(const string& str, vector<string>& result, const string& sep) {
    if (sep.empty()) {
        return;
    }
    size_t pos1 = 0, pos2 = 0;
    pos2 = str.find(sep);

    while (pos2 != string::npos) {
        cout << pos2 << endl;
        result.emplace_back(str.substr(pos1, pos2-pos1));
        pos1 = pos2 + sep.size();
        pos2 = str.find(sep, pos1);
    }

    if (pos1 != string::npos) {
        result.emplace_back(str.substr(pos1));
    }

    return;
}

int main() {
    string test = "hello world";
    string sep = ",";
    vector<string> result;
    split(test, result, sep);
    for (auto& item : result) {
        cout << item << endl;
    }
    return 0;
}