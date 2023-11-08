#include "MutantStack.hpp"
#include <iostream>

int main() {
    {
        std::cout << "SUBJECT TESTS" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "top:" << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size:" << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        std::cout << "iterating through the stack:" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "---------------" << std::endl;

    {
        std::cout << "TEST 1" << std::endl;
        MutantStack<int> mstack;

        std::cout << "testing empty: ";
        if (mstack.empty()) {
            std::cout << "is empty" << std::endl;
        } else {
            std::cout << "is not empty" << std::endl;
        }

        mstack.push(5);
        std::cout << "pushed one number" << std::endl;

        std::cout << "testing empty: ";
        if (mstack.empty()) {
            std::cout << "is empty" << std::endl;
        } else {
            std::cout << "is not empty" << std::endl;
        }

        std::cout << "pushed 2 numbers" << std::endl;
        mstack.push(43);
        mstack.push(22);

        std::cout << "testing size: " << mstack.size() << std::endl;

        std::cout << "push 74" << std::endl;
        mstack.push(74);
        std::cout << "top is " << mstack.top() << std::endl;
    }

    std::cout << "---------------" << std::endl;

    {
        std::cout << "TEST 2" << std::endl;
        MutantStack<int> foo, bar;

        foo.push(10);
        foo.push(20);
        foo.push(30);
        bar.push(111);
        bar.push(222);

        std::cout << "size of foo: " << foo.size() << '\n';
        std::cout << "size of bar: " << bar.size() << '\n';

        std::cout << "after swap" << '\n';
        std::swap(foo, bar);
        std::cout << "after swap" << '\n';

        std::cout << "size of foo: " << foo.size() << '\n';
        std::cout << "size of bar: " << bar.size() << '\n';
    }

    std::cout << "---------------" << std::endl;

    {
        std::cout << "TEST 3" << std::endl;
        MutantStack<int> foo;

        foo.push(10);
        std::cout << "top is: " << foo.top() << '\n';

        MutantStack<int>::iterator it = foo.begin();
        *it = 20;
        std::cout << "updated top" << '\n';

        std::cout << "top is: " << foo.top() << '\n';
    }

    std::cout << "---------------" << std::endl;

    {
        std::cout << "TEST 4" << std::endl;
        MutantStack<int> foo;

        foo.push(10);
        foo.push(20);
        foo.push(30);

        std::cout << "instanciate by copy constructer" << std::endl;
        MutantStack<int> bar(foo);

        MutantStack<int>::iterator it = bar.begin();
        MutantStack<int>::iterator ite = bar.end();
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }

        std::cout << "push 40 to bar" << std::endl;
        bar.push(40);

        std::cout << "instanciate by copy assignment" << std::endl;
        MutantStack<int> baz = bar;

        MutantStack<int>::iterator it2 = baz.begin();
        MutantStack<int>::iterator ite2 = baz.end();
        while (it2 != ite2) {
            std::cout << *it2 << std::endl;
            ++it2;
        }
    }

    return 0;
}