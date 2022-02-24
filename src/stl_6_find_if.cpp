#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector
using namespace std;
//自定义一元谓词函数
bool mycomp(int i) {
    return ((i % 2) == 1);
}
//以函数对象的形式定义一个 find_if() 函数的查找规则
class mycomp2 {
public:
    bool operator()(const int& i) {
        return ((i % 2) == 1);
    }
};
int main() {
    vector<int> myvector{ 4,2,5,3,1,3,5 };
    //调用 find_if() 函数，并以 IsOdd() 一元谓词函数作为查找规则
    vector<int>::iterator it = find_if(myvector.begin(), myvector.end(), mycomp2());
    cout << "*it = " << *it << endl;
    //调用 find_if_not() 函数，并以 mycomp() 一元谓词函数作为查找规则
    it = find_if_not(myvector.begin(), myvector.end(), mycomp);
    cout << "*it = " << *it << endl;
    return 0;
}
