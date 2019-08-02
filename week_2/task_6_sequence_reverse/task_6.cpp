#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Reverse(vector<int>& v)
{
    std::reverse(v.begin(), v.end());
}
int main()
{
    vector<int> numbers = {
        53, 1, 2, 6, 6, 7,
    };
    Reverse(numbers);
    for (auto it : numbers) {
        cout << it << " ";
    }
    return 0;
}