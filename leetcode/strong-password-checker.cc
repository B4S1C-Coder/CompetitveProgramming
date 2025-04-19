#include <string>

class Solution {
public:
    int strongPasswordChecker(std::string password) {
        int STRSIZE = password.size(), stepCount = 0, encounteredTokenCount = 0, prev = 0;
        bool caps = false, smol = false, digit = false;

        if (STRSIZE > 20) { stepCount = STRSIZE - 20; }
        else if (STRSIZE < 6) {
            return 6 - STRSIZE; 
        }

        for (const int c: password) {
            if (!digit && c >= 48 && c <= 57) {
                digit = true;
            } else if (!caps && c >= 65 && c <= 90) {
                caps = true;
            } else if (!smol && c >= 97 && c <= 122) {
                smol = true;
            }

            if (prev - c == 0) {
                encounteredTokenCount++;
            } else {
                stepCount += encounteredTokenCount;
                encounteredTokenCount = 0;
                prev = c;
            }
        }
        stepCount += (int)(!caps);
        stepCount += (int)(!smol);
        stepCount += (int)(!digit);
        return stepCount;
    }
};
