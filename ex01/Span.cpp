#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int maxsize) { this->_items.reserve(maxsize); }

Span::Span(const Span &src) : _items(src._items) {}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        this->_items = rhs._items;
    }

    return *this;
}

void Span::addNumber(int nbr) {
    if (this->_items.size() >= this->_items.capacity())
        throw Span::SpanFullException();

    this->_items.push_back(nbr);
}

void Span::addRange(std::vector<int>::iterator begin,
                    std::vector<int>::iterator end) {
    if (this->_items.size() + std::distance(begin, end) >
        this->_items.capacity())
        throw Span::SpanFullException();

    this->_items.insert(this->_items.end(), begin, end);
}

int Span::shortestSpan() {
    if (this->_items.size() < 2)
        throw Span::NotEnoughItemsException();

    std::vector<int>::iterator it;

    std::vector<int> copy(this->_items);
    std::sort(copy.begin(), copy.end());

    int shortest = abs(*(copy.begin() + 1) - *copy.begin());

    for (it = copy.begin(); it != copy.end() - 1; ++it) {
        if (abs(*(it + 1) - *it) < shortest) {
            shortest = abs(*(it + 1) - *it);
        }
    }
    return shortest;
}

int Span::longestSpan() {
    if (this->_items.size() < 2)
        throw Span::NotEnoughItemsException();

    int min = *std::min_element(this->_items.begin(), this->_items.end());
    int max = *std::max_element(this->_items.begin(), this->_items.end());

    return abs(max - min);
}

const char *Span::SpanFullException::what() const throw() {
    return ("Span is full");
}

const char *Span::NotEnoughItemsException::what() const throw() {
    return ("Not enough items in the Span");
}

/* -------------------------------------------------------------------------- */
/*                            Functions for testing                           */
/* -------------------------------------------------------------------------- */
void printItem(int n) { std::cout << " " << n; }

void Span::printNormal() {
    std::cout << "Span Organized: [";
    for_each(this->_items.begin(), this->_items.end(), printItem);
    std::cout << " ]" << std::endl;
}

void Span::printOrdered() {
    std::vector<int> copy(this->_items);
    std::sort(copy.begin(), copy.end());

    std::cout << "Span Organized: [";
    for_each(copy.begin(), copy.end(), printItem);
    std::cout << " ]" << std::endl;
}