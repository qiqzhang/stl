#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
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
    vector<int> myvector{ 3,1,2,4 };
    list<int> mylist{ 5,1,2,3,4 };
    //调用第 2 种语法格式的 is_sorted() 函数，该判断语句会得到执行
    if (!is_sorted(myvector.begin(), myvector.end(),mycomp2())) {
        cout << "开始对 myvector 容器排序" << endl;
        //对 myvector 容器做降序排序
        sort(myvector.begin(), myvector.end(),mycomp2());
        //输出 myvector 容器中的元素
        for (auto it = myvector.begin(); it != myvector.end(); ++it) {
            cout << *it << " ";
        }
    }
   
    //调用第一种语法格式的 is_sorted() 函数，该判断语句得不到执行
    if (!is_sorted(mylist.begin(), mylist.end())) {
        cout << "开始对 mylist 排序" << endl;
        //......
    }
    return 0;
}