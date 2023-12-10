#include <bits/stdc++.h>
#include <boost/chrono.hpp>
#include <lib/algorithm/sort.hpp>

namespace ch = boost::chrono;

std::array<int, 10> a;

int main(int argc, char *argv[]) {
    std::cout << ch::system_clock::time_point();
    for(auto &i : a){
        std::cin >> i;
    }
    oitl::sort(a.begin(), a.end());
    for(auto i : a){
        std::cout << i << ' ';
    }
    return 0;
}