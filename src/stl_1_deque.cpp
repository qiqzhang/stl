#include <iostream>
#include <deque>
#include <array>
using namespace std;
class testDemo
{
public:
    testDemo(int num) :num(num) {
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "调用拷贝构造函数" << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "调用移动构造函数" << endl;
    }
    testDemo& operator=(const testDemo& other);
private:
    int num;
};
testDemo& testDemo::operator=(const testDemo& other) {//deque 比vector多了这个东西
    this->num = other.num;
    return *this;
}
int main()
{
//  test1 初始化一个空deque容量
    deque<int>d;
    //向d容器中的尾部依次添加 1，2,3
    d.push_back(1); //{1}
    d.push_back(2); //{1,2}
    d.push_back(3); //{1,2,3}
    //向d容器的头部添加 0 
    d.push_front(0); //{0,1,2,3}
    
    //调用 size() 成员函数输出该容器存储的字符个数。
    // printf("元素个数为：%d\n", d.size());
    std::cout << d.size() << std::endl;
   
    //使用迭代器遍历容器
    for (auto i = d.begin(); i < d.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
//  test2 反向迭代器遍历容器
    deque<int>d1{1,2,3,4,5};
    for (auto i = d1.rbegin(); i < d1.rend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
//  test3 遍历容器
    deque<int> d2{ 1,2,3,4,5 };
    //从元素 2 开始遍历
    auto first = d2.begin() + 1;
    //遍历至 5 结束（不包括 5）
    auto end = d2.end() - 1;
    while (first < end) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
//  test4 增加与删除容器
    deque<int>d3;
    //调用push_back()向容器尾部添加数据。
    d3.push_back(2); //{2}
    //调用pop_back()移除容器尾部的一个数据。
    d3.pop_back(); //{}
    //调用push_front()向容器头部添加数据。
    d3.push_front(2);//{2}
    //调用pop_front()移除容器头部的一个数据。
    d3.pop_front();//{}
    //调用 emplace 系列函数，向容器中直接生成数据。
    d3.emplace_back(2); //{2}
    d3.emplace_front(3); //{3,2}
    //emplace() 需要 2 个参数，第一个为指定插入位置的迭代器，第二个是插入的值。
    d3.emplace(d3.begin() + 1, 4);//{3,4,2}
    for (auto i : d3) {
        cout << i << " ";
    }
    cout << endl;
    //erase()可以接受一个迭代器表示要删除元素所在位置
    //也可以接受 2 个迭代器，表示要删除元素所在的区域。
    d3.erase(d3.begin());//{4,2}
    d3.erase(d3.begin(), d3.end());//{}，等同于 d.clear()

//  test5 插入
    std::deque<int> d4{ 1,2 };
    //第一种格式用法
    d4.insert(d4.begin() + 1, 3);//{1,3,2}
    //第二种格式用法
    d4.insert(d4.end(), 2, 5);//{1,3,2,5,5}
    //第三种格式用法
    std::array<int,3>test1{7,8,9};
    d4.insert(d4.end(), test1.begin(), test1.end());//{1,3,2,5,5,7,8,9}
    //第四种格式用法
    d4.insert(d4.end(), { 10,11 });//{1,3,2,5,5,7,8,9,10,11}
    for (int i = 0; i < d4.size(); i++) {
        cout << d4[i] << " ";
    }
//  test6 
    // emplace和insert
    cout << "emplace:" << endl;
    std::deque<testDemo> demo1;
    demo1.emplace(demo1.begin(), 2);
    cout << "insert:" << endl;
    std::deque<testDemo> demo2;
    demo2.insert(demo2.begin(), 2);
   
    //emplace_front和push_front
    cout << "emplace_front:" << endl;
    std::deque<testDemo> demo3;
    demo3.emplace_front(2);
    cout << "push_front:" << endl;
    std::deque<testDemo> demo4;
    demo4.push_front(2);
    //emplace_back()和push_back()
    cout << "emplace_back:" << endl;
    std::deque<testDemo> demo5;
    demo5.emplace_back(2);
    cout << "push_back:" << endl;
    std::deque<testDemo> demo6;
    demo6.push_back(2);
    return 0;
}