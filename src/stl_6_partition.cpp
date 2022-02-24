#include <iostream>     // std::cout
#include <algorithm>    // std::partition
#include <vector>       // std::vector
using namespace std;
//以普通函数的方式定义partition()函数的筛选规则
bool mycomp(int i) { return (i % 2) == 0; }
//以函数对象的形式定义筛选规则
class mycomp2 {
public:
    bool operator()(const int& i) {
        return (i%2 == 0);
    }
};
int main() {
    std::vector<int> myvector{1,2,3,4,5,6,7,8,9};
    std::vector<int>::iterator bound;
    //以 mycomp2 规则，对 myvector 容器中的数据进行分组
    bound = std::partition(myvector.begin(), myvector.end(), mycomp2());
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\nbound = " << *bound << endl;

    std::vector<int> myvector1{1,2,3,4,5,6,7,8,9};
    std::vector<int>::iterator bound1;
    //以 mycomp2 规则，对 myvector 容器中的数据进行分组
    bound1 = std::stable_partition(myvector1.begin(), myvector1.end(), mycomp);
    for (std::vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\nbound1 = " << *bound;
    return 0;
}





