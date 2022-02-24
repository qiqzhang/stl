#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    std::forward_list<int> values{1,2,3};
    values.emplace_front(4);//{4,1,2,3}
    values.emplace_after(values.before_begin(), 5); //{5,4,1,2,3}
    values.reverse();//{3,2,1,4,5}

    for (auto it = values.begin(); it != values.end(); ++it) {
        cout << *it << " ";
    }
    cout<<endl;
    //advance移动
    std::forward_list<int> values1{1,2,3,4};
    auto it = values1.begin();
    advance(it, 2);
    while (it!=values1.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout<<endl;
    return 0;
}