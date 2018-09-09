#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    int n = 10;
    int last;

    vector<int> v;
    vector<string> result;
    int mins = 0, hours = 0;
    string ans = "";
public:
    void backTrace(int k, int start) {
        int i = 0;
        if (k < this->last) {
            if (start < n && (this->last - k) <= (n - start)) {
                v.push_back(start);
                backTrace(k + 1, start + 1);
                v.pop_back();
                backTrace(k, start + 1);
            } else {
                return;
            }
        } else {
            mins = 0;
            hours = 0;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] < 6)
                    mins += (1 << v[i]);
                else hours += (1 << v[i] - 6);
            }
            if (mins > 59 || hours > 11)
                return;
            ans = "";
            ans += to_string(hours);
            ans += ":";
            ans += to_string(mins / 10) + to_string(mins % 10);

            this->result.push_back(ans);
        }
    }

    vector<string> readBinaryWatch(int num) {
        this->last = num;
        backTrace(0, 0);
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    auto vList = s.readBinaryWatch(3);
    for (int i = 0; i < vList.size(); i++) {
        cout << vList[i] << endl;
    }
    return 0;
}