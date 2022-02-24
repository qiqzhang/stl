#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
//  test1 向容器中添加新键值对
    std::cout << "test1" << std::endl;
    //创建空 umap 容器
    unordered_map<string, string> umap1;
    //向 umap 容器添加新键值对
    umap1.emplace("Python教程", "http1");//效率比insert高效
    umap1.emplace("Java教程", "http2");
    umap1.emplace("Linux教程", "http3");
    //输出 umap 存储键值对的数量
    cout << "umap size = " << umap1.size() << endl;
    //使用迭代器输出 umap 容器存储的所有键值对
    for (auto iter = umap1.begin(); iter != umap1.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

//  test2 （未成功）
//  unordered_map 容器过程（尤其是向容器中添加新键值对）中，一旦当前容器的负载因子超过最大负载因子（默认值为 1.0），
//  该容器就会适当增加桶的数量（通常是翻一倍），并自动执行 rehash() 成员方法，重新调整各个键值对的存储位置（此过程又称“重哈希”），此过程很可能导致之前创建的迭代器失效
    //创建 umap 容器
    unordered_map<int, int> umap;
    //向 umap 容器添加 50 个键值对
    for (int i = 1; i <= 50; i++) {
        umap.emplace(i, i);
    }
    //获取键为 49 的键值对所在的范围
    auto pair1 = umap.equal_range(49);
    //输出 pair 范围内的每个键值对的键的值
    for (auto iter = pair1.first; iter != pair1.second; ++iter) {
        cout << iter->first <<" ";
    }
    cout << endl;

    //手动调整最大负载因子数??(无法使用)
    // umap.max_load_factor(3.0);
    //手动调用 rehash() 函数重哈希
    // umap.rehash(10);
    //重哈希之后，pair 的范围可能会发生变化
    for (auto iter = pair1.first; iter != pair1.second; ++iter) {
        cout << iter->first << " ";
    }

//  test3 获取元素 4 cases
    // 1.
    string str = umap1["Java教程"];
    cout << endl;
    cout << str << endl;

    // 2.
    //创建空 umap 容器
    // unordered_map<string, string> umap;
    umap1.clear();
    //[] 运算符在 = 右侧
    str = umap1["STL教程"];
    //[] 运算符在 = 左侧
    umap1["C教程"] = "http11";
   
    for (auto iter = umap1.begin(); iter != umap1.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

    // 3.
    str = umap1.at("C教程");
    cout << str << endl;

    // 4.find
    //创建 umap 容器
    unordered_map<string, string> umap2{
        {"Python教程","http21"},
        {"Java教程","http22"},
        {"Linux教程","http23"} };
    //查找成功
    unordered_map<string, string>::iterator iter = umap2.find("Python教程");
    cout << iter->first << " " << iter->second << endl;
    //查找失败
    unordered_map<string, string>::iterator iter2 = umap2.find("GO教程");
    if (iter2 == umap2.end()) {
        cout << "当前容器中没有以\"GO教程\"为键的键值对" << endl;
    }

//  test4 insert
    // 以普通方式传递参数
    // pair<iterator,bool> insert ( const value_type& val );
    // //以右值引用的方式传递参数
    // template <class P>
    //     pair<iterator,bool> insert ( P&& val );

    //创建空 umap 容器
    unordered_map<string, string> umap41;
    //构建要添加的键值对
    std::pair<string, string>mypair("STL教程", "http41");
    //创建接收 insert() 方法返回值的迭代器类型变量
    // unordered_map<string, string>::iterator iter;
    //调用第一种语法格式
    iter = umap41.insert(umap41.begin(), mypair);
    cout << "iter -> " << iter->first <<" " << iter->second << endl;
   
    //调用第二种语法格式
    iter = umap41.insert(umap41.begin(),std::make_pair("Python教程", "http42"));
    cout << "iter -> " << iter->first << " " << iter->second << endl;

//  test5 emplace() emplace_hint()方法
    unordered_map<string,string>umap51;
    pair<unordered_map<string,string>::iterator,bool>ret2;
    ret2=umap51.emplace("ruby教程","http51");
    cout << "bool" << ret2.second << endl;
    cout << "iter -> " << ret2.first->first << " " << ret2.first->second<< endl;

    unordered_map<string,string>::iterator iter51;
    iter51 = umap51.emplace_hint(umap51.begin(),"numpy教程","http51");
    cout << "iter ->" << iter51->first << " " << iter51->second << endl;
    for (auto iter = umap51.begin(); iter != umap51.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

//  test6 删除元素
    umap51.erase(umap51.begin());
    for(auto iter=umap51.begin();iter!=umap51.end();++iter){
        cout << "ret delete = " << iter->first << " " << iter->second << endl;
    }

    umap51.emplace("UNIX教材","http54");
    umap51.emplace("torch","http55");
    unordered_map<string,string>::iterator first = umap51.begin();
    unordered_map<string,string>::iterator end = umap51.end();
    auto ret = umap51.erase(first,first);
    for(auto iter=umap51.begin();iter!=umap51.end();++iter){
        cout << "ret delete2 = " << iter->first << " " << iter->second << endl;
    }
    umap51.clear();
    for(auto iter=umap51.begin();iter!=umap51.end();++iter){
        cout << "ret delete3 = " << iter->first << " " << iter->second << endl;
    }
    
    // cout << ret->first << ret->second << endl;

    return 0;
}