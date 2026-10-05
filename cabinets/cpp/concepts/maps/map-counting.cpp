#include <iostream>
#include <map>
#include <string>

int main() {
    const std::string sources[] = {
        "198.51.100.7",
        "192.0.2.10",
        "192.0.2.10",
    };

    std::map<std::string, int> sourceCounts;

    for (const std::string& source : sources) {
        sourceCounts[source] += 1;
    }

    for (const auto& entry : sourceCounts) {
        std::cout << entry.first << ": " << entry.second << '\n';
    }
}
