#include <iostream>
#include "paginate.h"

using namespace std;

int main()
{
    Paginate pager(5,13);
    for(int i=1;i<=13;++i) {
        //i��ǰҳ��13��ҳ��
        pager.setPage(i,13).show();
    }
    cout<<"start move...."<<endl;
    pager.setPage(5,13).show();
    pager.next().show();
    pager.prev().show();
    //ֱ�ӷ�5ҳ
    pager.nextN().show();
    pager.next().show();
    pager.prevN().show();
    return 0;
}
