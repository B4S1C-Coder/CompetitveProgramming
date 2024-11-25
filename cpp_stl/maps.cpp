#include <map>
#include <string>
#include <iostream>

template<typename T, typename U>
void printMap(std::map<T, U>& _map) {
    std::cout << "Size: " << _map.size() << std::endl;

    for (auto& pr: _map) {
        // pr.first ---> O(log(n))
        std::cout << pr.first << " ---> " << pr.second << std::endl;
    }
}

int main() {
    std::map<int, std::string> myMap; // Key-Value pair stored sorted acc to keys
    myMap[1] = "Koi Khelne nahi aaya :("; // Each such step is O(log(n))
    myMap[3] = "Sab bimaar h ;[";
    myMap[5] = "Iss hi baat par Lifebuoy use kro :D";

    myMap.insert({8, "Something"});
    myMap.insert(std::make_pair(9, "Nothing"));

    std::map<int, std::string>::iterator it;

    for (it = myMap.begin(); it != myMap.end(); it++) {
        std::cout << it->first << " : " << it->second << std::endl;
        it->second = "damn"; // Map will get modified
    }

    for (it = myMap.begin(); it != myMap.end(); it++) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    printMap(myMap);

    auto itd = myMap.find(7); // Returns iterator for specified key, myMap.end if not found

    if (itd == myMap.end()) {
        std::cout << "Not found" << std::endl;
    } else {
        std::cout << "Found" << std::endl;
    }

    return 0;
}
