#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    // test1 insert
    // 使用 set 容器存储的各个键值对，要求键 key 和值 value 必须相等。
    //创建空set容器
    std::set<std::string> myset;
    //空set容器不存储任何元素
    cout << "1、myset size = " << myset.size() << endl;
    //向myset容器中插入新元素
    myset.insert("http1");
    myset.insert("http2");
    myset.insert("http3");
    cout << "2、myset size = " << myset.size() << endl;
    //利用双向迭代器，遍历myset
    for (auto iter = myset.begin(); iter != myset.end(); ++iter) {
        cout << *iter << endl;
    }
    // test2指定位置插入 
    //采用普通引用传值方式
    set<string>::iterator iter;
    string str = "http11";
    iter = myset.insert(myset.begin(),str);
    cout << "myset size = " << myset.size() << " " << *iter << endl;
    //采用右值引用传值方式
    iter = myset.insert(myset.end(),"http22");
    cout << "myset size = " << myset.size() << " " << *iter << endl;

    iter = myset.emplace_hint(myset.begin(), "http44");
    cout << "myset size = " << myset.size() << " " << *iter << endl;


    // test3 有返回值的插入 
    //准备接受 insert() 的返回值
    pair<set<string>::iterator, bool> retpair;//用来查看插入是否成功
    //采用普通引用传值方式
    retpair = myset.insert(str);
    cout << "iter->" << *(retpair.first) << " " << "bool = " << retpair.second << endl;
    //采用右值引用传值方式
    retpair = myset.insert("http22");
    cout << "iter->" << *(retpair.first) << " " << "bool = " << retpair.second << endl;
    
    // test4 有返回值的插入  emplace
    pair<set<string>::iterator,bool>ret = myset.emplace("http33");
    cout << "myset size = " << myset.size() << endl;
    cout << "ret.iter = <" << *(ret.first) << ", " << ret.second << ">" << endl;

    // test5 在 set 容器的指定位置添加键值对 emplace_hint
    set<string>::iterator iter1 = myset.emplace_hint(myset.begin(), "http44");
    cout << "myset size = " << myset.size() << endl;
    cout << *iter1 << endl;

    // test6 删除元素
    //创建并初始化 set 容器
    std::set<int>myset2{1,2,3,4,5};
    cout << "myset size = " << myset2.size() << endl;
    //1) 调用第一种格式的 erase() 方法
    int num = myset2.erase(2); //删除元素 2，myset={1,3,4,5}
    cout << "1、myset size = " << myset2.size() << endl;
    cout << "num = " << num << endl;
    //2) 调用第二种格式的 erase() 方法
    set<int>::iterator iter11 = myset2.erase(myset2.begin()); //删除元素 1，myset={3,4,5}
    cout << "2、myset size = " << myset2.size() << endl;
    cout << "iter->" << *iter11 << endl;
    //3) 调用第三种格式的 erase() 方法
    set<int>::iterator iter2 = myset2.erase(myset2.begin(), --myset2.end());//删除元素 3,4，myset={5}
    cout << "3、myset size = " << myset2.size() << endl;
    cout << "iter2->" << *iter2 << endl;

    cout << "1、myset size = " << myset2.size() << endl;
    //清空 myset 容器
    myset2.clear();
    cout << "2、myset size = " << myset2.size() << endl;



    
    return 0;
}