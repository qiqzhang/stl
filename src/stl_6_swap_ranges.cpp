#include <iostream>     // std::cout
#include <algorithm>    // std::search_n
#include <vector>   
#include <iterator> 
#include <list>
using namespace std;
int main(){
    using Name = std::pair<string, string>; // First and second name
    std::vector<Name> people {Name{"Al", "Bedo" }, Name { "Ann", "Ounce"}, Name{"Jo","King"}};
    std::list<Name> folks {Name{"Stan", "Down"}, Name{"Dan","Druff"},Name {"Bea", "Gone"}};
    std::swap_ranges(std::begin(people), std::begin(people) + 2, ++std::begin(folks));
    std::for_each(std::begin(people), std::end(people),[](const Name& name) {std::cout << '"' << name.first << " " << name.second << "\" ";});
    std::cout << std::endl; // "Dan Druff" "Bea Gone" "Jo King"
    std::for_each (std::begin (folks) , std::end (folks) ,[] (const Name& name){std::cout << '"' << name.first << " " << name.second << "\" "; });
    std::cout << std::endl;// "Stan Down" "Al Bedo" "Ann Ounce"
}