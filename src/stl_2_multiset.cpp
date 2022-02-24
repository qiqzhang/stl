#include <iostream>
#include <set>
#include <string>
using namespace std;
// template < class T,                        // 存储元素的类型
//            class Compare = less<T>,        // 指定容器内部的排序规则
//            class Alloc = allocator<T> >    // 指定分配器对象的类型
//            > class multiset;
int main() {
    std::multiset<int> mymultiset{1,2,2,2,3,4,5};
    cout << "multiset size = " << mymultiset.size() << endl;
    cout << "multiset count(2) =" << mymultiset.count(2) << endl;
    //向容器中添加元素 8
    mymultiset.insert(8);
    //删除容器中所有值为 2 的元素
    int num = mymultiset.erase(2);
    cout << "删除了 " << num << " 个元素 2" << endl;
    //输出容器中存储的所有元素
    for (auto iter = mymultiset.begin(); iter != mymultiset.end(); ++iter) {
        cout << *iter << " ";
    }
    return 0;
}