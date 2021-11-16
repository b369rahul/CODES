#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <queue>
using namespace std;

class StackWithMax {
    vector<int> stack;
    vector<int> m;
  public:

    void Push(int value) {
        stack.push_back(value);
        if(m.empty())m.push_back(value);
        else m.push_back(max(value,m.back()));
    }

    void Pop() {
        assert(stack.size());
        m.pop_back();
        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        return m.back();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}