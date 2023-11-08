#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

// https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators

template <typename T>
class MutantStack : public std::stack<T> {
  public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &src) : std::stack<T>(src) {}
    MutantStack &operator=(const MutantStack &rhs) {
        if (this != &rhs) {
            std::stack<T>::operator=(rhs);
        }
        return *this;
    }
    ~MutantStack() {}

    // the default container for stack is std::deque, check refence link bellow
    typedef typename std::deque<T>::iterator iterator;

    // c is a protected member function of stack
    // https://en.cppreference.com/w/cpp/container/stack

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

#endif /* MUTANTSTACK_HPP */
