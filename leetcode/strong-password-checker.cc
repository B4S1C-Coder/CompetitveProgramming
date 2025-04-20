#include <string>
#include <iostream>

class Solution {
public:
    int strongPasswordChecker(std::string password) {
        int STRSIZE = password.size(), stepCount = 0, encounteredTokenCount = 0, prev = 0;
        bool caps = false, smol = false, digit = false, anyIncStep = false;

        if (STRSIZE > 20) { stepCount = STRSIZE - 20; }
        else if (STRSIZE < 6) {
            return 6 - STRSIZE;
        }

        std::cout << "stepCount after STRSIZE = " << stepCount << "\n";

        for (const int c: password) {
            std::cout << "-------------------\n";
            if (!digit && c >= 48 && c <= 57) {
                digit = true;
            } else if (!caps && c >= 65 && c <= 90) {
                caps = true;
            } else if (!smol && c >= 97 && c <= 122) {
                smol = true;
            }

            if (prev - c == 0) {
                std::cout << "Same token " << c << " char = " << (char)c << "\n";
                encounteredTokenCount++;
                std::cout << "encounteredTokenCount = " << encounteredTokenCount << "\n";
                if (encounteredTokenCount % 3 == 0) {
                    stepCount++;
                }

                anyIncStep = true;

                // std::cout << "encounteredTokenCount = " << encounteredTokenCount << "\n";
                std::cout << "stepCount = " << stepCount << "\n";
            } else {
                std::cout << "Different Token, now: " << c << " char = " << (char)c << " Prev = " << prev << " char = " << (char)prev << "\n";
                std::cout << "encounteredTokenCount = " << encounteredTokenCount << "\n";

   //             if (encounteredTokenCount >= 2) {
   //                 stepCount += (3 - encounteredTokenCount);
   //             }

                encounteredTokenCount = 1;
                prev = c;

                std::cout << "stepCount = " << stepCount << "\n";
            }

            std::cout << "-------------------\n";
        }

//        if (encounteredTokenCount >= 2) {
//            stepCount += (3 - encounteredTokenCount);
 //       }

        std::cout << "stepCount before flag addition = " << stepCount << "\n";

        if (stepCount == 0) {
            stepCount += (int)(!caps);
            stepCount += (int)(!smol);
            stepCount += (int)(!digit);
        }

        stepCount += (int)(!anyIncStep);

        std::cout << "stepCount after flag addition = " << stepCount << "\n";
        return stepCount;
    }
};

