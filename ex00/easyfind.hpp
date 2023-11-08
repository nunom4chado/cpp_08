#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find

// https://stackoverflow.com/questions/11275444/c-template-typename-iterator

template <typename T>
typename T::iterator easyfind(T &container, int target) {

    typename T::iterator it;

    it = std::find(container.begin(), container.end(), target);
    return it;
}

#endif /* EASYFIND_HPP */
