#include <iostream>

using namespace std;

#include "Book.h"

int main()
{
    Book book(100);
    book.totalPages();
    book.totalReadPages();
    book.readPages(50);
    book.totalReadPages();
    book.remainPages();
    return 0;
}
