#include <utility>
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

template<typename T, typename U>
void printVector(std::vector<std::pair<T, U>>& vec) {

    std::cout << "std::vector[ " << vec.size() << " ]( "; 

    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << "{ " <<vec[i].first << "," << vec[i].second << "} ";
    }

    std::cout << ")" << std::endl;
}

int main() {

    std::vector<std::pair<int, int>> vec = {{42, 69}, {96, 24}};
    printVector(vec);

    // Array of vectors
    std::vector<int> vecs[3]; // 3 std::vector<int>

    // Vector of vectors
    std::vector<std::vector<int>> vecOfVecs; // Vector which stores vectors

    return 0;
}
