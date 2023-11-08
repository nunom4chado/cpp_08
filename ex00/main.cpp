#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::vector<int> a;

    a.push_back(10);
    a.push_back(42);
    a.push_back(7);
    a.push_back(58);
    a.push_back(39);

    {
        int target = 42;
        std::vector<int>::iterator result = easyfind(a, target);
        if (result != a.end()) {
            std::cout << target << " found in vector" << std::endl;
        } else {
            std::cout << target << " not found in vector" << std::endl;
        }
    }

    {
        int target = 500;
        std::vector<int>::iterator result = easyfind(a, target);
        if (result != a.end()) {
            std::cout << target << " found in vector" << std::endl;
        } else {
            std::cout << target << " not found in vector" << std::endl;
        }
    }

    std::cout << "-----------------" << std::endl;

    std::set<int> myset;
    std::set<int>::iterator it;

    // set some initial values:
    for (int i = 1; i <= 5; i++)
        myset.insert(i * 10); // set: 10 20 30 40 50

    it = easyfind(myset, 20);
    if (it != myset.end()) {
        std::cout << 20 << " found in set" << std::endl;
    } else {
        std::cout << 20 << " not found in set" << std::endl;
    }

    it = easyfind(myset, 42);
    if (it != myset.end()) {
        std::cout << 42 << " found in set" << std::endl;
    } else {
        std::cout << 42 << " not found in set" << std::endl;
    }

    return 0;
}