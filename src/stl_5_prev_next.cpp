#include <iostream>     // std::cout
#include <iterator>     // std::advance
#include <vector>
#include <list>
using namespace std;
int main() {
    // // 1.advance
    // //创建一个 vector 容器
    // vector<int> myvector{ 1,2,3,4 };
    // //it为随机访问迭代器，其指向 myvector 容器中第一个元素
    // vector<int>::iterator it = myvector.begin();
    // //输出 it 迭代器指向的数据
    // cout << "移动前的 *it = " << *it << endl;

    // //借助 advance() 函数将 it 迭代器前进 2 个位置
    // advance(it, 2);
    // cout << "移动后的 *it = " << *it << endl;
    // // 2.prev左侧为正值，右侧为负值
    //创建并初始化一个 list 容器
    // std::list<int> mylist{ 1,2,3,4,5 };
    // std::list<int>::iterator it = mylist.end();
    // //获取一个距离 it 迭代器 2 个元素的迭代器，由于 2 为正数，newit 位于 it 左侧
    // auto newit = prev(it, 2);
    // cout << "prev(it, 2) = " << *newit << endl;
   
    // //n为负数，newit 位于 it 右侧
    // it = mylist.begin();
    // newit = prev(it, -2);
    // cout << "prev(it, -2) = " << *newit;

    // // 3.next
    //创建并初始化一个 list 容器
    std::list<int> mylist{ 1,2,3,4,5 };
    std::list<int>::iterator it = mylist.begin();
    //获取一个距离 it 迭代器 2 个元素的迭代器，由于 2 为正数，newit 位于 it 右侧
    auto newit = next(it, 2);
    cout << "next(it, 2) = " << *newit << endl;
   
    //n为负数，newit 位于 it 左侧
    it = mylist.end();
    newit = next(it, -2);
    cout << "next(it, -2) = " << *newit;

    return 0;
}