#include <vector>
#include <iostream>
#include <utility>

int main() {

    // vec.begin() ---> v[0], vec.end() ---> next to last i.e. v[v.size()], last is v[v.size() - 1]
    std::vector<int> vec = {12, 56, 69, 42};
    // Iterators are pointer-like
    std::vector<int>::iterator it = vec.begin();
    
    // there is a difference between it++ and it+1
    // it++ ---> next iterator, it+1 ---> next location
    // However, in case of vectors there behaviour is identical
    for (it = vec.begin(); it != vec.end(); it++) {
        std::cout << (*it) << std::endl; // element of vec
    }

    // Equivalent but concise
    for (auto itD = vec.begin(); itD != vec.end(); itD++) {
        std::cout << (*itD) << std::endl;
    }

    std::vector<std::pair<int, int>> vecP = { {12, 56}, {69, 42} };
    std::vector<std::pair<int, int>>::iterator itP = vecP.begin();

    for (itP = vecP.begin(); itP != vecP.end(); itP++) {
        std::cout << itP->first << " " << itP->second << std::endl;
    }

    // Range based loops, temp is a copy of the value in the vector
    for (std::pair<int, int> temp: vecP) {
        std::cout << temp.first << " " << temp.second << std::endl;
        temp.first++; // vecP not modified
    }

    // Range based loops, temp is a reference to the value in the vector
    for (std::pair<int, int>& temp: vecP) {
        std::cout << temp.first << " " << temp.second << std::endl;
        temp.first++; // vecP modified
    }

    for (std::pair<int, int> temp: vecP) {
        std::cout << temp.first << " " << temp.second << std::endl;
    }

    return 0;
}
