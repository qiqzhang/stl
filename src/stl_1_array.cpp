#include <iostream>
#include <array>
using namespace std;

// if values is constexpr
// constexpr std::array<int, 4> values{4, 2, 3, 1};
// 该关键字告诉编译器，函数中不会发生异常,这有利于编译器对程序做更多的优化。
// 如果在运行时，noexecpt函数向外抛出了异常（如果函数内部捕捉了异常并完成处理，这种情况不算抛出异常），程序会直接终止，调用std::terminate()函数，该函数内部会调用std::abort()终止程序。

// template<typename T, size_t N>
// constexpr std::array<T, N> print_array(const std::array<T, N>& values) noexcept
// {

// }
template<typename T,size_t N>
std::array<T,N> print_array(const std::array<T,N> values){
    if(!values.empty()){
            for(auto val=values.begin();val<values.end();val++){
                std::cout << *val << " ";
            }
            std::cout << "" << std::endl;
        }
    return values;
}
int main()
{
// test1
    std::array<int,4> values;
    for (int i=0;i<values.size();i++){
        // values.at(i)=i;
        values[i]=i;//conatain[index]
    }
    print_array(values);

    std::cout << values[3] << std::endl;
    // std::cout << get<3>(values) << std::endl;

// test2
    std::array<int,5>values2{1,2,3,4,5};
    int h=1;
    auto first = values.cbegin();
    auto last = values.cend();
    while (first!=last)
    {
        cout << *first <<" ";
        ++first;
    }
//  test3 
//  内存布局连续
    std::array<std::array<int,2>,2> values3{11,12,10,11};
    // values3[0][0]=3;
    // values3[0][1]=3;
    // {{10,2},{2,3}};
    std::cout << "" << std::endl;
    print_array(values3[0]);
    print_array(values3[1]);
    std::cout << "" << std::endl;
}