#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


bool isPossible(int n, int m, vector<int>& arr, long long int mid) {
    int dayCount = 1;
    long long int timeCount = 0;

    for (int i = 0; i < m; i++) {
        if (timeCount + arr[i] <= mid) {
            timeCount += arr[i];
        } else {
            dayCount++;
            if (dayCount > n || arr[i] > mid) {
                return false;
            } else {
                timeCount = arr[i];
            }
        }
    }
    return true;
}

long long int ayushGivesNinjatest(int n, int m, vector<int>& time) {
    long long int s = 0;
    long long int sum = accumulate(time.begin(), time.end(), 0LL); // Calculate sum of time values

    long long int e = sum;
    long long int ans = -1;

    while (s <= e) {
        long long int mid = s + (e-s) / 2;
        if (isPossible(n, m, time, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of students: ";
    cin >> n;
    cout << "Enter the number of questions: ";
    cin >> m;

    vector<int> time(m);
    cout << "Enter the time taken for each question: ";
    for (int i = 0; i < m; i++) {
        cin >> time[i];
    }

    long long int result = ayushGivesNinjatest(n, m, time);
    cout << "The minimum possible time to complete the test: " << result << endl;

    return 0;
}
