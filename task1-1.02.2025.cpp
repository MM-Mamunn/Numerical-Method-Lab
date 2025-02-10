#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string str;
    getline(cin, str);  // Reading input string
    stringstream ss(str);
    int num;
    vector<int> arr;

    while (ss >> num) {
        arr.push_back(num);  // Adding each integer to the vector
    }

    cout << arr.size() << endl;  // Printing the size of the vector
    return 0;
}
