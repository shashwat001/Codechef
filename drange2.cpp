#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <deque>
#include <queue>
#include <fstream>
#include <functional>
#include <numeric>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

const int MAX_RANGE = 20;
int data[MAX_RANGE];
int max_segment_tree[2 * MAX_RANGE];
int min_segment_tree[2 * MAX_RANGE];
int added_to_interval[2 * MAX_RANGE] = {0};

void update_bruteforce(int x, int y, int z, int &smallest, int &largest) {
    for (int i = x - 1; i < y; ++i) {
        data[i] += z;       
    }

    // update min/max
    smallest = data[0];
    largest = data[0];
    for (int i = 0; i < MAX_RANGE; ++i) {
        if (data[i] < smallest) {
            smallest = data[i];
        }

        if (data[i] > largest) {
            largest = data[i];
        }
    }
}

void build_tree(int position, int left, int right) {
    if (left > right) {
        return;
    }
    else if (left == right) {
        max_segment_tree[position] = data[left];
        min_segment_tree[position] = data[left];
        return;
    }

    int middle = (left + right) / 2;
    build_tree(position * 2, left, middle);
    build_tree(position * 2 + 1, middle + 1, right);
    max_segment_tree[position] = max(max_segment_tree[position * 2], max_segment_tree[position * 2 + 1]);
    min_segment_tree[position] = min(min_segment_tree[position * 2], min_segment_tree[position * 2 + 1]);
}

void update_tree(int position, int b, int e, int i, int j, int value) {
    if (b > e || b > j || e < i) {
        return;
    }

    if (i <= b && e <= j) {
        max_segment_tree[position] += value;
        min_segment_tree[position] += value;
        added_to_interval[position] += value;
        return;
    }

    update_tree(position * 2 , b , (b + e) / 2 , i, j, value);
    update_tree(position * 2 + 1 , (b + e) / 2 + 1 , e , i, j, value);

    max_segment_tree[position] = max(max_segment_tree[position * 2], max_segment_tree[position * 2 + 1]) + added_to_interval[position]; 
    min_segment_tree[position] = min(min_segment_tree[position * 2], min_segment_tree[position * 2 + 1]) + added_to_interval[position];
}

void update(int x, int y, int value) {
    // memset(added_to_interval, 0, sizeof(added_to_interval));
    update_tree(1, 0, MAX_RANGE - 1, x - 1, y - 1, value);
}

namespace unit_test {
    void test_show_data() {
        for (int i = 0; i < MAX_RANGE; ++i) {
            cout << data[i] << ", ";
        }

        cout << endl << endl;
    }

    void test_brute_force_and_segment_tree() {
        // arrange
        int number_of_operations = 100;
        for (int i = 0; i < MAX_RANGE; ++i) {
            data[i] = i + 1;
        }

        build_tree(1, 0, MAX_RANGE - 1);

        // act
        int operation;
        int x;
        int y;
        int z;
        int smallest = 1;
        int largest = MAX_RANGE;

        // assert
        while (number_of_operations--) {
            operation = rand() % 1; 
            x = 1 + rand() % MAX_RANGE;
            y = x + (rand() % (MAX_RANGE - x + 1));
            z = 1 + rand() % MAX_RANGE;

            if (operation == 0) {
                z *= 1;
            }
            else {
                z *= -1;    
            }

            cout << "left, right, value: " << x - 1 << ", " << y - 1 << ", " << z << endl;
            update_bruteforce(x, y, z, smallest, largest);
            update(x, y, z);
            test_show_data();

            cout << "correct:\n";
            cout << "\tsmallest = " << smallest << endl;
            cout << "\tlargest = " << largest << endl;

            cout << "possibly correct:\n";
            cout << "\tsmallest = " << min_segment_tree[1] << endl;
            cout << "\tlargest = " << max_segment_tree[1] << endl;
            cout << "\n--------------------------------------------------------------\n";
            cin.get();
        }
    }
}

int main() {
    unit_test::test_brute_force_and_segment_tree();
}      
