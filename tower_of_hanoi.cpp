#include<iostream>
using namespace std;

void towerOfHanoi(int n, char source, char dest, char med) {

    if(n == 0) {
        return;
    }

    towerOfHanoi(n-1, source, med, dest);
    cout << "Move disk " << n << " from pole " << source << " to pole " << dest << endl;

    towerOfHanoi(n-1, med, dest, source); 
}

int main() {
     int num;
     cout << "Enter the number of disks: ";
     cin >> num;

     towerOfHanoi(num, 'A', 'C', 'B');
}