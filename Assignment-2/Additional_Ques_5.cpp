#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,0,2,3,0,4,5,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    int possibleDups=0;
    int last=n-1;

    for (int i=0; i<=last-possibleDups; i++) {
        if (arr[i]==0) {
            if (i==last-possibleDups) {
                arr[last]=0;
                last--;
                break;
            }
            possibleDups++;
        }
    }

    int i=last-possibleDups;
    for (; i>=0; i--) {
        if (arr[i]==0) {
            arr[i+possibleDups]=0;
            possibleDups--;
            arr[i+possibleDups]=0;
        } else {
            arr[i+possibleDups]=arr[i];
        }
    }

    cout << "Modified array: ";
    for (int x: arr) cout << x << " ";
    return 0;
}
