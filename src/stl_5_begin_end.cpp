#include <iostream>     // std::cout
#include <vector>       // std::vector, std::begin, std::end
using namespace std;
int main() {
    // 1.begin end函数
    // //创建并初始化 vector 容器
    // std::vector<int> myvector{ 1,2,3,4,5 };
    // //调用 begin() 和 end() 函数遍历 myvector 容器
    // for (auto it = begin(myvector); it != end(myvector); ++it)
    //     cout << *it << ' ';

    //定义一个普通数组
    int arr[] = { 1,2,3,4,5 };
    //创建一个空 vector 容器
    vector<int> myvector;
    //将数组中的元素添加到 myvector 容器中存储
    for (int *it = begin(arr); it != end(arr); ++it)
        myvector.push_back(*it);
    //输出 myvector 容器中存储的元素
    for (auto it = myvector.begin(); it != myvector.end(); ++it)
        cout << *it << ' ';
    return 0;
}