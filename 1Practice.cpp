#include <iostream>
#include <map>

int main() {
    // create a map of string keys and integer values
    std::map<std::string, int> m;

    // add some key-value pairs to the map
    m["apple"] = 5;
    m["banana"] = 3;
    m["cherry"] = 8;

    // access the value associated with a key
    std::cout << "Value of apple: " << m["apple"] << std::endl;

    // modify the value associated with a key
    m["banana"] = 10;

    // print the key-value pairs in the map
    std::cout << "Map: ";
    for (auto i : m) {
        std::cout << i.first << "=" << i.second << " ";
    }
    std::cout << std::endl;

    return 0;
}