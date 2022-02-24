#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool mycomp(int c1,int c2){
    return (c2%c1==0);
}

class mycomp2{
public:
    bool operator()(const int& c1,const int& c2){
        return (c2%c1==0);
    }
};
int main(){
    char url[] = "httpstl";
    char ch[] = "pstl";
    //调用第一种语法格式，找到 url 中和 "stl" 任一字符相同的第一个字符
    char *it = find_first_of(url, url + 27, ch, ch + 4);
    if (it != url + 27) {
        cout << "*it = " << *it << '\n';
    }
    vector<int> myvector{ 5,7,3,9 };
    int inter[] = { 4,6,8 };
    //调用第二种语法格式，找到 myvector 容器中和 3、5、7 任一元素有 c2%c1=0 关系的第一个元素
    vector<int>::iterator iter = find_first_of(myvector.begin(), myvector.end(), inter, inter + 3, mycomp2());
    if (iter != myvector.end()) {
        cout << "*iter = " << *iter;
    }
}