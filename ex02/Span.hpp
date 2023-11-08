#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Span {
  private:
    std::vector<int> _items;
    Span(); // ocf

  public:
    Span(unsigned int maxsize);
    Span(const Span &src);            // ocf
    ~Span();                          // ocf
    Span &operator=(const Span &rhs); // ocf

    void addNumber(int nbr);
    void addRange(std::vector<int>::iterator begin,
                  std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();

    void printNormal();
    void printOrdered();

    class SpanFullException : public std::exception {
        virtual const char *what() const throw();
    };

    class NotEnoughItemsException : public std::exception {
        virtual const char *what() const throw();
    };
};

#endif /* SPAN_HPP */
