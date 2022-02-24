#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<numeric>
#include<iterator>
 
#include <cctype>
#include <string>
using namespace std;
int main()
{
    using Points = std::pair<double, double>; // pair<x,y> defines a point
    std::vector<Points> hexagon {{1,2}, {2,1}, {3,1}, {4,2}, {3,3}, {2,3}, {1,2}};
    std::vector<double> segments; // Stores lengths of segments
    std::transform (std::begin (hexagon),std::end(hexagon)-1, std::begin (hexagon) + 1, std::back_inserter(segments),[](const Points p1, const Points p2){return std::sqrt((p1.first-p2.first)*(p1.first-p2.first) +(p1.second - p2.second)*(p1.second - p2.second)); });
    std::cout << "Segment lengths: ";
    std::copy(std::begin(segments), std::end(segments),std::ostream_iterator<double> {std::cout," "});
    std::cout << std::endl;
    std::cout << "Hexagon perimeter: "<< std::accumulate(std::begin(segments), std::end(segments), 0.0) << std::endl;


    // 2.一元大写
    std::string str = "Hello, World!";
    cout << str << endl;
    // toupper
    std::string strUpper(str.length(), ' ');
    std::transform(str.begin(), str.end(), strUpper.begin(), ::toupper);
    cout << strUpper << endl;
    // tolower
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str << endl;

    // 二元相加
    std::vector<int> v1 = {10, 20, 30, 40, 50};
    std::vector<int> v2 = { 1, 2, 3, 4, 5 };
    std::vector<int> result(5);
    std::transform(v1.begin(), v1.end(), v2.begin(), result.begin(), std::plus<int>());
    for (int i : result) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;


}