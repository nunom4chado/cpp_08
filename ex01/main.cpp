#include "Span.hpp"
#include <exception>
#include <iostream>

int main() {
    {
        Span a(5);

        a.addNumber(6);
        a.addNumber(3);
        a.addNumber(17);
        a.addNumber(9);
        a.addNumber(11);

        a.printNormal();
        a.printOrdered();

        std::cout << "shortest distance is between 9 and 11. expects " << 11 - 9
                  << " got " << a.shortestSpan() << std::endl;
        std::cout << "longest distance is between 3 and 17. expects " << 17 - 3
                  << " got " << a.longestSpan() << std::endl;
    }

    std::cout << "---------------------------" << std::endl;

    {
        try {
            Span a(5);

            a.addNumber(6);
            a.addNumber(3);
            a.addNumber(17);
            a.addNumber(9);
            a.addNumber(11);

            a.printNormal();

            a.addNumber(20); // will throw exception, span is full

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }

    std::cout << "---------------------------" << std::endl;

    {
        try {
            Span a(20000);

            for (int i = 0; i < 20000; i++)
                a.addNumber(i); // No exception because can fit all numbers

            std::cout
                << "created a span with 20000 numbers. Remove comment to print "
                   "them. You might want to redirect the output to a file!!"
                << std::endl;
            // sp.printNormal();

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }

    std::cout << "---------------------------" << std::endl;

    {
        try {
            std::vector<int> other;
            Span base(20);

            for (int i = 0; i < 10; i++)
                base.addNumber(i); // 0 1 2 3 ... 9

            for (int i = 0; i < 10; i++)
                other.push_back((i + 1) * 100); // 100 200 300 ... 1000

            base.printNormal();

            base.addRange(other.begin(), other.end());
            std::cout << "after addRange" << std::endl;

            base.printNormal();

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }

    std::cout << "---------------------------" << std::endl;

    {
        try {
            std::vector<int> other;
            Span base(19);

            for (int i = 0; i < 10; i++)
                base.addNumber(i); // 0 1 2 3 ... 9

            for (int i = 0; i < 10; i++)
                other.push_back((i + 1) * 100); // 100 200 300 ... 1000

            base.printNormal();

            std::cout << "testing with a range that doen't fit.." << std::endl;

            base.addRange(other.begin(), other.end());
            std::cout << "after addRange" << std::endl;

            base.printNormal();

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }

    std::cout << "---------------------------" << std::endl;

    {
        try {
            std::vector<int> other;
            std::cout << "try to go over max_size() of vector" << std::endl;

            std::size_t test_size = other.max_size() + 20;

            std::cout << "max_size(): " << other.max_size() << "\n"
                      << "test_size: " << test_size << std::endl;

            Span base(test_size);

            std::cout << "Note: remove comment in the constructer to see that "
                         "test_size will be reduced to max_size()"
                      << std::endl;

            std::cout << "Note: if adding number until test_size will throw "
                         "exception like "
                         "the previous test indicating span is full"
                      << std::endl;

            for (std::size_t i = 0; i < test_size; i++)
                base.addNumber(i); // No exception because can fit all numbers

        } catch (const std::exception &e) {
            std::cerr << "Expection: " << e.what() << '\n';
        }
    }

    return 0;
}