#include <iostream>     // std::cout
#include <algorithm>    // std::partition_copy
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
// first、last：都为输入迭代器，其组合 [first, last) 用于指定该函数处理的数据区域；
// result_true：为输出迭代器，其用于指定某个存储区域，以存储满足筛选条件的数据；
// result_false：为输出迭代器，其用于指定某个存储区域，以存储满足筛选条件的数据；
// pred：用于指定筛选规则，其本质就是接收一个具有 1 个参数且返回值类型为 bool 的函数。注意，该函数既可以是普通函数，还可以是一个函数对象。
int main() {
    vector<int> myvector{ 1,2,3,4,5,6,7,8,9 };
    int b[10] = { 0 }, c[10] = { 0 };
    //以 mycomp 规则，对 myvector 容器中的数据进行分组，这里的 mycomp 还可以改为 mycomp2()，即以 mycomp2 为筛选规则
    pair<int*, int*> result= partition_copy(myvector.begin(), myvector.end(), b, c, mycomp);
    cout << "b[10]：";
    for (int *p = b; p < result.first; p++) {
        cout << *p << " ";
    }
    cout << "\nc[10]：";
    for (int *p = c; p < result.second; p++) {
        cout << *p << " ";
    }
    return 0;
}