//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
        Node* reverse(Node* head) {
        Node* prev = nullptr;
        while (head != nullptr) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        // if(head == nullptr) return true;
        
        // vector<int>ans;
        
        // Node *temp = head;
        
        // while(temp != nullptr){
        //     ans.push_back(temp->data);
        //     temp = temp->next;
        // }
        
        // int i = 0;
        // int j = ans.size() - 1;
        
        // while(i <= j){
        //     if(ans[i] != ans[j]){
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }
        
        // return true;
        
        if (head == nullptr || head->next == nullptr) return true;
        
        Node *first = head;
        Node *slow = head;
        
        
        while(first != nullptr && first->next != nullptr){
            first = first->next->next;
            slow = slow->next;
        }
        
        Node* secondHalf = reverse(slow);

        Node *firstHalf = head;
        Node *tempSecond = secondHalf;
        
        while(tempSecond != nullptr){
            if(firstHalf->data != tempSecond->data){
                return false;
            }
            
            firstHalf = firstHalf->next;
            tempSecond = tempSecond->next;
        }
        
        return true;
        
        
    }
};



//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends