#include <iostream>     // std::cout
#include <algorithm>    // std::partition_point
#include <vector>       // std::vector
using namespace std;
//以普通函数的方式定义筛选规则
bool mycomp(int i) { return (i % 2) == 0; }
//以函数对象的形式定义筛选规则
class mycomp2 {
public:
    bool operator()(const int& i) {
        return (i % 2 == 0);
    }
};
int main(){
    vector<int> myvector{2,4,6,8,1,3,5,7,9};
    vector<int>::iterator iter = partition_point(myvector.begin(),myvector.end(),mycomp);
    // 输出第一组的数据
    // 而该元素为 myvector 容器中第一个不符合 mycomp 规则的元素
    for(auto it=myvector.begin();it!=iter;++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
    for(auto it=iter;it!=myvector.end();++it)
        cout << *it << " ";
    cout << "\n*iter = " << *iter;
    return 0;
}