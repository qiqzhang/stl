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
// partial sort 可直译为“部分排序”
int main(){
    std::vector<int>myvector{3,2,5,4,1,6,9,7};
    std::partial_sort(myvector.begin(),myvector.begin()+4,myvector.end());
    cout<<"第一次排序:\n";
    for(std::vector<int>::iterator it = myvector.begin();it!=myvector.end();++it)
        cout << *it << ' ';
    cout<<"第二次排序:\n";
    std::partial_sort(myvector.begin(),myvector.begin()+4,myvector.end(),mycomp2());
    for(std::vector<int>::iterator it = myvector.begin();it!=myvector.end();++it)
        cout << *it << ' ';
    
}