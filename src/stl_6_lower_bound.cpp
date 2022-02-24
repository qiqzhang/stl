#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound
#include <vector>       // std::vector
using namespace std;
//以普通函数的方式定义查找规则
bool mycomp(int i,int j) { return i>j; }

//以函数对象的形式定义查找规则
class mycomp2 {
public:
    bool operator()(const int& i, const int& j) {
        return i>j;
    }
};

int main() {
    int a[5] = { 1,2,3,4,5 };
    //从 a 数组中找到第一个不小于 3 的元素
    int *p = lower_bound(a, a + 5, 3);
    cout << "*p = " << *p << endl;

    vector<int> myvector{ 4,5,3,1,2 };
    //根据 mycomp2 规则，从 myvector 容器中找到第一个违背 mycomp2 规则的元素
    vector<int>::iterator iter = lower_bound(myvector.begin(), myvector.end(),3,mycomp2());
    cout << "*iter = " << *iter;
    return 0;
}