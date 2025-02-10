class Solution {
public:
    string clearDigits(string s) {
       while (true) {
        bool digit_found = false;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                digit_found = true;
                for (int j = i - 1; j >= 0; --j) {
                    if (!isdigit(s[j])) {
                        s.erase(i, 1);
                        s.erase(j, 1);
                        break;
                    }
                }
                if (!digit_found) {
                    s.erase(i, 1);
                }
                break;
            }
        }
        if (!digit_found) {
            break;
        }
    }
    return s;
    }
};