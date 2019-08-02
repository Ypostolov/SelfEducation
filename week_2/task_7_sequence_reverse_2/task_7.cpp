#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Reversed(const vector<int>& input)
{
    auto seq = input;
    for (int i = 0; i < seq.size() / 2; ++i) {
        auto tmp = seq[i];
        seq[i] = seq[seq.size() - 1 - i];
        seq[seq.size() - 1 - i] = tmp;
    }
    return seq;
}

int main()
{
    vector<int> numbers = {
        25, 34, 5, 7, 12, 3
    };
    Reversed(numbers);
    for (auto it : numbers) {
        cout << it << " ";
    }
    return 0;
}