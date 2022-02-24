#include <iostream>     // std::cout
#include <algorithm>    // std::search_n
#include <vector>       // std::vector
using namespace std;
//以普通函数的形式定义一个匹配规则
bool mycomp1(int i, int j) {
    return (i%j == 0);
}
//以函数对象的形式定义一个匹配规则
class mycomp2 {
public:
    bool operator()(const int& i, const int& j) {
        return (i%j == 0);
    }
};
// first、last：都为正向迭代器，其组合 [first, last) 用于指定查找范围（也就是上面例子中的序列 A）；
// count、val：指定要查找的元素个数和元素值，以上面的序列 B 为例，该序列实际上就是 3 个元素 4，其中 count 为 3，val 为 4；
// pred：用于自定义查找规则。该规则实际上是一个包含 2 个参数且返回值类型为 bool 的函数（第一个参数接收[first, last) 范围内的元素，第二个参数接收 val）。函数定义的形式可以是普通函数，也可以是函数对象。
int main() {
    int a[] = { 1,2,3,4,4,4,1,2,3,4,4,4 };
    //调用第一种语法格式,查找 myvector 容器中第一个 {4,4,4}
    int * it = search_n(a, a+12, 3, 4);
    if (it != a+12) {
        cout << "one：" << it - a << ",*it = " << *it << endl;
    }
    vector<int> myvector{1,2,4,8,3,4,6,8};
    //调用第二种语法格式，以自定义的 mycomp2 作为匹配规则，查找 myvector 容器中和 {16,16,16} 满足 mycomp2 规则的序列
    vector<int>::iterator iter = search_n(myvector.begin(), myvector.end(), 3, 2, mycomp2());
    if (iter != myvector.end()) {
        cout << "two：" << iter - myvector.begin() << ",*iter = " << *iter;
    }
    return 0;
}