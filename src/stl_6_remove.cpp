#include <iostream>
#include <deque>
#include <iterator> 
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
using namespace std;
int main(){
    // std::deque<double> samples {1.5, 2.6, 0.0, 3.1, 0.0, 0.0, 4.1, 0.0, 6.7, 0.0};
    // samples.erase(std::remove(std::begin(samples), std::end(samples), 0.0), std::end(samples));
    // std::copy(std::begin(samples),std::end(samples), std::ostream_iterator <double> {std::cout," "});
    // std::cout << std::endl;
    // // 1.5 2.6 3.1 4.1 6.7

    // std::deque<double> samples {1.5, 2.6, 0.0, 3.1, 0.0, 0.0, 4.1, 0.0, 6.7, 0.0};
    // std::vector<double> edited_samples;
    // std::remove_copy(std::begin(samples), std::end(samples), std::back_inserter(edited_samples), 0.0);
    // std::copy(std::begin(samples),std::end(samples), std::ostream_iterator <double> {std::cout," "});

    // using Name = std::pair<string, string>; // First and second name
    // std::set<Name> blacklist {Name {"Al", "Bedo"}, Name {"Ann", "Ounce"}, Name {"Jo","King"}};
    // std::deque<Name> candidates {Name{"Stan", "Down"}, Name {"Al", "Bedo"}, Name {"Dan", "Druff"},Name {"Di", "Gress"}, Name {"Ann", "Ounce"}, Name {"Bea", "Gone"}};
    // candidates.erase(std::remove_if(std::begin(candidates), std::end(candidates),[&blacklist](const Name& name) { return blacklist.count(name); }), std::end(candidates));
    // std::for_each(std::begin(candidates), std::end(candidates), [] (const Name& name){std::cout << '"' << name.first << " " << name.second << "\" ";});
    // std::cout << std::endl;  // "Stan Down" "Dan Druff" "Di Gress" "Bea Gone"

    using Name = std::pair<string, string>; // First and second name
    std::set<Name> blacklist {Name {"Al", "Bedo"}, Name {"Ann", "Ounce"}, Name{"Jo","King"}};
    std::deque<Name> candidates {Name {"Stan", "Down"}, Name { "Al", "Bedo"},Name {"Dan", "Druff"}, Name {"Di", "Gress"}, Name {"Ann", "Ounce"},Name {"Bea", "Gone"}};
    std::deque<Name> validated;
    std::remove_copy_if(std::begin(candidates) , std::end(candidates), std::back_inserter(validated), [&blacklist] (const Name& name) { return blacklist.count(name); });
    std::for_each(std::begin(validated), std::end(validated), [] (const Name& name){std::cout << '"' << name.first << " " << name.second << "\" ";});
    std::cout << std::endl;  // "Stan Down" "Dan Druff" "Di Gress" "Bea Gone"


}