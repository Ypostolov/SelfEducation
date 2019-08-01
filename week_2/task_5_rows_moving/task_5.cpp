#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination)
{
    for (auto s : source)
        destination.push_back(s);
    source.clear();
}

int main()
{
    vector<string> source = { "sdf", "aaa", "bbb" };
    vector<string> destination = { "xxx" };
    MoveStrings(source, destination);
    for (auto i : source) {
        cout << i << " " << endl;
    }
    for (auto i : destination) {
        cout << i << " ";
    }
    return 0;
}