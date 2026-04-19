#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
typedef struct Node Node;

int main() {
    // int hash[10] = {0};
    // int keys[] = {12,4,9,18,13,30,1};
    // for(int i = 0; i < 7; i++) {
    //     int index = keys[i]%10;
    //     hash[index] = keys[i];
    // }
    // for(int i = 0; i < 10; i++) {
    //     cout << hash[i] << " ";
    // }

    //Hashing
    // int hash[10] = {0};
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     int key;
    //     cin >> key;
        
    //     int index = key%10;
    //     hash[index] = key;
    // }
    // for(int i = 0; i < 10; i++) {
    //     cout << hash[i] << " ";
    // }

    //Linear Probing
    // int hash[10];
    // for(int i = 0; i < 10; i++) {
    //     hash[i] = -1;
    // }
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     int key;
    //     cin >> key;

    //     int index = key%10;
    //     int j = 0;

    //     while(hash[(index+j)%10] != -1) {
    //         j++;
    //     }
    //     hash[(index+j)%10] = key;
    // }
    // for(int i = 0; i < 10; i++) {
    //     cout << hash[i] << " ";
    // }

    //Quadratic Probing
    // int hash[10];
    // for(int i = 0; i < 10; i++) {
    //     hash[i] = -1;
    // }
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     int key;
    //     cin >> key;

    //     int index = key%10;
    //     int j = 0;

    //     while(hash[(index+j*j)%10] != -1) {
    //         j++;
    //     }

    //     hash[(index+j*j)%10] = key;
    // }
    // for(int i = 0; i < 10; i++) {
    //     cout << hash[i] << " ";
    // }

    //Double Hashing
    // int hash[10];
    // for(int i = 0; i < 10; i++) {
    //     hash[i] = -1;
    // }
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     int key;
    //     cin >> key;

    //     int h1 = key%10;
    //     int h2 = 7 - key%7;
    //     int j = 0;

    //     while(hash[(h1 + j*h2)%10] != -1) {
    //         j++;
    //     }
    //     hash[(h1 + j*h2)%10] = key;
    // }
    // for(int i = 0; i < 10; i++) {
    //     cout << hash[i] << " ";
    // }

    //Chaining
    // Node* hash[10];
    // for(int i = 0; i < 10; i++) {
    //     hash[i] = NULL;
    // }
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     int key;
    //     cin >> key;
        
    //     int index = key%10;

    //     Node* newNode = new Node(key);

    //     if(hash[index] == NULL) {
    //         hash[index] = newNode;
    //     } else {
    //         Node* temp = hash[index];
    //         while(temp->next != NULL) {
    //             temp = temp->next;
    //         }
    //         temp->next = newNode;
    //     }
    // }
    // for(int i = 0; i < 10; i++) {
    //     Node* temp = hash[i];
    //     cout << i << " -> ";
    //     while(temp != NULL) {
    //         cout << temp->data << " ";
    //         temp = temp->next;
    //     }
    //     cout << endl;
    // }

    //Sorted Chaining
    // Node* hash[10];
    // for(int i = 0; i < 10; i++) {
    //     hash[i] = NULL;
    // }
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     int key;
    //     cin >> key;

    //     int index = key%10;

    //     Node* newNode = new Node(key);

    //     if(hash[index] == NULL || hash[index]->data > key) {
    //         newNode->next = hash[index];
    //         hash[index] = newNode;
    //     } else {
    //         Node* temp = hash[index];
    //         while(temp->next != NULL && temp->next->data < key) {
    //             temp = temp->next;
    //         }
    //         newNode->next = temp->next;
    //         temp->next = newNode;
    //     }
    // }
    // for(int i = 0; i < 10; i++) {
    //     cout << i << " -> ";
    //     Node* temp = hash[i];
    //     while(temp) {
    //         cout << temp->data << " ";
    //         temp = temp->next;
    //     }
    //     cout << endl;
    // }

    //Largest subarray with equal 0s and 1s
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mpp;
    int sum = 0;
    int max = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            sum = sum - 1;
        } else if(arr[i] == 1) {
            sum = sum + 1;
        }

        if(sum == 0) {
            max = i + 1;
        }

        if(mpp.find(sum) != mpp.end()) {
            int len = i - mpp[sum];
            if(len > max) {
                max = len;
            }
        } else {
            mpp[sum] = i;
        }
    }

    cout << max;
    return 0;
}