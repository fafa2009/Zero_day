#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// --- 1. LINEAR SEARCH FUNCTION ---
int linearSearch(vector<int> arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// --- 2. INSERTION SORT FUNCTION ---
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// --- 3. BINARY SEARCH FUNCTION ---
int binarySearch(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 3;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (arr[mid] < target)
            low = mid + 1;

        // If target is smaller, ignore right half
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    // Define an unsorted dataset
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    int target;

    cout << "--- ALGORITHM IMPLEMENTATION ---" << endl;
    cout << "Original Data: ";
    for (int x : data) cout << x << " ";
    cout << endl;

    // --- TEST LINEAR SEARCH ---
    cout << "\n[1] Enter number to Linear Search: ";
    cin >> target;
    int lsResult = linearSearch(data, target);
    if (lsResult != -1)
        cout << "Linear Search: Found at index " << lsResult << endl;
    else
        cout << "Linear Search: Not Found" << endl;

    // --- PERFORM INSERTION SORT ---
    cout << "\n[2] Performing Insertion Sort..." << endl;
    insertionSort(data);
    cout << "Sorted Data: ";
    for (int x : data) cout << x << " ";
    cout << endl;

    // --- TEST BINARY SEARCH (Requires Sorted Data) ---
    cout << "\n[3] Enter number to Binary Search: ";
    cin >> target;
    int bsResult = binarySearch(data, target);
    if (bsResult != -1)
        cout << "Binary Search: Found at index " << bsResult << endl;
    else
        cout << "Binary Search: Not Found" << endl;

    return 0;
}