#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool mycomp1(int i,int j){
    return (i%j==0);
}

class mycomp2{
public:
    bool operator()(const int& i,const int& j){
        return (i%j==0);
    }
};

int main(){
    vector<int> myvector{ 1,2,3,4,8,12,18,1,2,3 };
    int myarr[] = {1,2,3};
    vector<int>::iterator it=find_end(myvector.begin(),myvector.end(),myarr,myarr+3);
    if (it != myvector.end()) {
        cout << "最后一个{1,2,3}的起始位置为：" << it - myvector.begin() << ",*it = " << *it << endl;
    }
    int myarr2[] = { 2,3,4 };
    //调用第二种语法格式
    it = find_end(myvector.begin(), myvector.end(), myarr2, myarr2 + 3, mycomp2());
    if (it != myvector.end()) {
        cout << "最后一个{2,3,4}的起始位置为：" << it - myvector.begin() << ",*it = " << *it;
    }
}