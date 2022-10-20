Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 104
1 ≤ Data on Node ≤ 103
  
  // C++ program to return first node of loop
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

// Function to detect first node of loop
// in a linked list that may contain loop
bool detectLoop(Node* head)
{
	
	// If the head is null we will return false
	if (!head)
		return 0;
	else {
	
		// Traversing the linked list
		// for detecting loop
		while (head) {
			// If loop found
			if (head->key == -1) {
				return true;
			}
		
			// Changing the data of visited node to any
			// value which is outside th given range here it
			// is supposed the given range is (1 <= Data on
			// Node <= 10^3)
			else {
				head->key = -1;
				head = head->next;
			}
		}
		// If loop not found return false
		return 0;
	}
}

/* Driver program to test above function*/
int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	/* Create a loop for testing(5 is pointing to 3) */
	head->next->next->next->next->next = head->next->next;

	bool found = detectLoop(head);
	cout << found << endl;
	return 0;
}


