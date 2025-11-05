#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int countStudents(queue<int> students, stack<int> sandwiches) {
    int attempts = 0;  // no match rotations

    while(!students.empty() && attempts < students.size()) {
        if(students.front() == sandwiches.top()) {
            students.pop();
            sandwiches.pop();
            attempts = 0;
        }
        else {
            students.push(students.front());
            students.pop();
            attempts++;
        }
    }
    return students.size();
}

int main() {
    queue<int> students;
    stack<int> sandwiches;

    int arr1[] = {1,1,0,0};
    int arr2[] = {0,1,0,1};

    for(int x: arr1) students.push(x);
    for(int i=3;i>=0;i--) sandwiches.push(arr2[i]); // push reversed

    cout << "Students unable to eat = "
         << countStudents(students, sandwiches);
}
