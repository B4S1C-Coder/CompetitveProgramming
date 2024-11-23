#include <utility>
#include <string>
#include <vector>
#include <iostream>

template<typename T>
void printVector(std::vector<T>& vec) {

    std::cout << "std::vector[ " << vec.size() << " ]( "; 

    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    std::cout << ")" << std::endl;
}

int main() {
    std::pair<int, std::string> p = std::make_pair(2, "some_str");
    std::cout << p.first << " " << p.second << std::endl;

    std::pair<int, std::string> another = {69, "naughty"};
    std::cout << another.first << " " << another.second << std::endl;

    std::vector<int> vec = {10, 20, 30};
    vec.push_back(40);
    vec.push_back(50);
    vec.pop_back();

    std::vector<int> naughtyVec(10, 69); // Initial size 10 with all values 69

    printVector(vec);
    printVector(naughtyVec);

    std::vector<int> nu = vec; // Copy of the vec, O(N)
    
    return 0;
}
