#include<iostream>
#include<algorithm>
#include<vector>
#include <string.h>
using  namespace std;

int main(){
    char stl[]="https61";
    char *p=find(stl,stl+strlen(stl),'c');
    if(p!=stl+strlen(stl)){
        cout << p << endl;
    }
    std::vector<int> myvector{10,20,30,40,50};
    std::vector<int>::iterator it;
    it = find(myvector.begin(),myvector.end(),30);
    if(it!=myvector.end())
        cout << "查找成功" <<*it;
    else
        cout << "查找失败";
    return 0;
}