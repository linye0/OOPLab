#ifndef PAGINATE_H
#define PAGINATE_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Paginate
{
public:
    Paginate(int firstPage, int lastPage): firstPage(firstPage), curPage(firstPage), lastPage(lastPage) {}
    Paginate& setPage(int page, int lastPage) {
        this->lastPage = lastPage;
        if (page <= lastPage) curPage = page;
        return *this;
    }
    Paginate& prev() {
        if (curPage > 1) curPage--;
        return *this;
    }
    Paginate& next() {
        if (curPage < lastPage) curPage++;
        return *this;
    }
    Paginate& nextN() {
        if (curPage + 5 <= lastPage) curPage += 5;
        return *this;
    }
    Paginate& prevN() {
        if (curPage - 5 >= 1) curPage -= 5;
        return *this;
    }
    void show() {
        cout << "上页 ";
        int group = (curPage - firstPage) / 5;
        if (lastPage - firstPage <= 5) {
            // 直接全部输出
            for (int i = firstPage; i <= lastPage; i++) {
                cout << i;
                if (i == curPage) cout << "+";
                cout << " ";
                cout << "下页" << endl;
                return;
            }
        }
        if (group == 0) {
            for (int i = firstPage; i <= 5; i++) {
                cout << i;
                if (i == curPage) cout << "+";
                cout << " ";
            }
            if (lastPage != firstPage + 5) {
                cout << "...";
            }
            cout << lastPage;
            cout << " 下页" << endl;
            return;
        }
        if (group >= 1) {
            // 不用补
            if (firstPage - 1 + (group + 1) * 5 < lastPage) {
                cout << "1 ...";
                for (int i = 0; i < 5; i++) {
                    int curPrintPage = firstPage - 1 + group * 5 + i;
                    cout << curPrintPage;
                    if (curPrintPage == curPage) cout << "+";
                    cout << " ";
                }
                if (firstPage + (group + 1) * 5 != lastPage) {
                    cout << "...";
                }
                cout << lastPage << " 下页" << endl;
            } else {
                cout<<"1 ... ";
                for(int i=lastPage - 4;i<=lastPage;i++){
                    if(i!=curPage)
                        cout<<i<<" ";
                    else
                        cout<<i<<"+ ";
                    }
                    cout<<"下页"<<endl;
            }
        }
    }
private:
    int firstPage;
    int curPage;
    int lastPage;
};

#endif // PAGINATE_H
