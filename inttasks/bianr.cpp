#include <iostream>

using namespace std;

int binary_search(int arr[], int n, int target) {
    int left = 0, right = n-1;
    while(left<=right){
        int mid = (left + right) / 2;
        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] > target) right = mid - 1;
        else {
            left = mid + 1;
        }
    }

}

int main() {
    return 0;
}