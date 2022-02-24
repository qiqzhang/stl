#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool mycomp1(int i,int j){
    return  (i>j);
}
class mycomp2{
public:
    bool operator()(int i,int j){
        return (i>j);
    }
};
int main(){
    std::vector<int>myvector{3,1,2,5,4};
    std::nth_element(myvector.begin(),myvector.begin()+2,myvector.end());
    cout<<"第一次排序:\n";
    for(std::vector<int>::iterator it = myvector.begin();it!=myvector.end();++it)
        cout << *it << ' ';
    cout<<"第二次排序:\n";
    std::nth_element(myvector.begin(),myvector.begin()+3,myvector.end(),mycomp2());
    for(std::vector<int>::iterator it = myvector.begin();it!=myvector.end();++it)
        cout << *it << ' ';
    return 0;
}