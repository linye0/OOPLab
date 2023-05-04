#ifndef BOOK_H
#define BOOK_H

#include <iostream>

using namespace std;

class Book
{
public:
    Book(int pages_, int curPages_ = 0): pages(pages_), curPages(curPages_) {}
    int totalPages() {
        cout << pages << " pages in total." << endl;
        return pages;
    }
    int readPages(int pages_) {
        curPages += pages_;
        cout << "read " << pages_ << " pages" << endl;
        return pages_;
    }
    int totalReadPages() {
        cout << "Having read "  << curPages << " pages in total." << endl;
        return curPages;
    }
    int remainPages() {
        cout << pages - curPages << " pages left." << endl;
        return pages - curPages;
    }
private:
    int pages;
    int curPages;
};

#endif // BOOK_H
