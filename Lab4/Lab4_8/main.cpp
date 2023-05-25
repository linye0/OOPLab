#include <iostream>
#include "paginate.h"

using namespace std;

int main()
{
    Paginate pager(5,13);
    for(int i=1;i<=13;++i) {
        //i当前页，13总页数
        pager.setPage(i,13).show();
    }
    cout<<"start move...."<<endl;
    pager.setPage(5,13).show();
    pager.next().show();
    pager.prev().show();
    //直接翻5页
    pager.nextN().show();
    pager.next().show();
    pager.prevN().show();
    return 0;
}
