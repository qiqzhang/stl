#include <iostream>     // std::cout
#include <algorithm>    // std::adjacent_find
#include <vector>       // std::vector
using namespace std;
//以创建普通函数的形式定义一个查找规则
bool mycomp1(int i, int j) {
    return (i == j);
}
//以函数对象的形式定义一个查找规则
class mycomp2{
public:
    bool operator()(const int& _Left, const int& _Right){
        return (_Left == _Right);
    }
};
int main() {
    std::vector<int> myvector{ 5,20,5,30,30,20,10,10,20 };
    //调用第一种语法格式
    std::vector<int>::iterator it = adjacent_find(myvector.begin(), myvector.end());
    if (it != myvector.end()) {
        cout << "one : " << *it << '\n';
    }
    //调用第二种格式，也可以使用 mycomp1 剩余部分
    it = adjacent_find(++it, myvector.end(), mycomp2());
    if (it != myvector.end()) {
        cout << "two : " << *it;
    }
    return 0;
}