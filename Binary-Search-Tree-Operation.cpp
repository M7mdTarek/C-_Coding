#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BSTNode
{
public:
	int data;
	BSTNode* left, * right;
	BSTNode(int val)//to make child= null
	{
		data = val;
		left = right = NULL;
	}
};
template <class T>
class BSTFCI
{
public:
	T* root;
	BSTFCI()//to make empty tree
	{
		root = NULL;
	}
	T* insert(T* r, int val)
	{
		if (r == NULL)//check if the tree is empty
		{
			T* newnode = new T(val);
			r = newnode;
		}
		else if (val < r->data)//check if we go to left subtree
		{
			r->left = insert(r->left, val);
		}
		else if (val >= r->data)//check if we go to right subtree
		{
			r->right = insert(r->right, val);
		}
		return r;
	}
	void insert(int val)//method to seve update into original root
	{
		root = insert(root, val);
	}
	void display_preorder(T* r)//root -> left -> right
	{
		if (r == NULL)
			return;
		cout << r->data << "\t";
		display_preorder(r->left);
		display_preorder(r->right);
	}

	int index = 0; //to count how many values we got
	int arr[20];//vector to store (values in range) into it
	void PrintRange(T* r, int low, int high)
	{		
		if (r == NULL)
			return;
		if (low == high)
			return;
		
		if (r->data >= low && r->data < high)//check if the value is in range
		{
			arr[index]= r->data;
			index++;
		}
		if (r->data > low )//check if we exceed lower limit then go to right subtree
		{
				PrintRange(r->left, low, high);			
		}		
		if (r->data < high)//check if we exceed upper limit then go to left subtree
		{
			PrintRange(r->right, low, high);			
		}	
		//--------------------sorting the vector ----------------------//
		int i, j;
		for (i = 0; i < (index - 1); i++)
		{
			for (j = 0; j < (index - i - 1); j++)
			{
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
			}
		}
	}
	void PrintRange(int low, int high)
	{
		PrintRange(root, low, high);
		//print the vector after sorting
		cout << "[ ";
		for (int i = 0; i < index; i++)
		{
			cout << arr[i] ;
			if (i < index - 1)//to print , until reach last element
				cout << " ,";
		}
		cout <<"]"<< endl;
	}
	bool sametree(BSTNode* n1, BSTNode* n2)
	{
		if (n1 == 0 && n2 == 0)
			return true;
		if (n1 == 0 || n2 == 0)
			return false;
		return(n1->data == n2->data && sametree(n1->left, n2->left) &&
			sametree(n1->right, n2->right));
	}
	
	bool isSubTree(BSTNode* t1, BSTNode* t2)
	{
		if (t2 == 0)
			return true;
		if (t1 == 0)
			return false;
		if (sametree(t1, t2))
			return true;
		return isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
	}
	bool isSubTree(BSTFCI* t1, BSTFCI* t2)
	{
		return isSubTree(t1->root, t2->root);
	}
	int getmax(int n1, int n2)
	{
		if (n1 > n2) return n1;
		else return n2;
	}
	int getheight(BSTNode* r)
	{
		if (r == NULL)
			return 0;
		return(1 + getmax(getheight(r->left), getheight(r->right)));
	}
	bool isBalance(BSTNode* r)
	{
		if (r == NULL)
			return true;
		int left_h = getheight(r->left);
		int right_h = getheight(r->right);
		if (abs(left_h - right_h) <= 1 && isBalance(r->right) && isBalance(r->left))
			return true;
		return false;

	}
};
int main()
{
	cout << "\t \t \t \t \t^-^Hello to Tree Problem^-^ \n \n";
	int choice;
	do
	{
		
		cout <<"\n choose from the menu ^-^ \n"<<"1 - display 5 test cases for subtree checking \n" 
			<< "2 - display 5 test cases for print value in range  \n"
			<< "3 - display 5 test cases for balance checking  \n"
			<< "4 - exit :(  \n"
			<< "enter your choice : ";
		cin >> choice;
		if (choice==1)
		{
			BSTFCI<BSTNode>* test1 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test2 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test3 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test4 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test5 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test6 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test7 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test8 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test9 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test10 = new BSTFCI<BSTNode>;
			//test1
			cout << "\n \t \t \t \t \t test case 1 \n";
			test1->insert(3);
			test1->insert(4);
			test1->insert(5);
			test1->insert(1);
			test1->insert(2);
			cout << "the first tree is \n";
			test1->display_preorder(test1->root);
			test2->insert(1);
			test2->insert(2);
			cout << "\n the second tree is \n";
			test2->display_preorder(test2->root);
			if (test1->isSubTree(test1, test2))
				cout << "\n the second tree is sub tree from the first \n";
			else
				cout << "\n the second tree is not sub tree from the first \n";
			//test2
			cout << "\n \t \t \t \t \t test case 2 \n";
			test3->insert(3);
			test3->insert(4);
			test3->insert(5);
			test3->insert(1);
			test3->insert(2);
			cout << "the first tree is \n";
			test3->display_preorder(test3->root);
			test4->insert(4);
			test4->insert(5);
			cout << "\n the second tree is \n";
			test4->display_preorder(test2->root);
			if (test3->isSubTree(test3, test4))
				cout << "\n the second tree is sub tree from the first \n";
			else
				cout << "\n the second tree is not sub tree from the first \n";
			//test3
			cout << "\n \t \t \t \t \t test case 3 \n";
			test5->insert(3);
			test5->insert(4);
			test5->insert(5);
			test5->insert(1);
			test5->insert(2);
			cout << "the first tree is \n";
			test5->display_preorder(test5->root);
			test6->insert(4);
			test6->insert(5);
			test6->insert(1);
			cout << "\n the second tree is \n";
			test6->display_preorder(test6->root);
			if (test5->isSubTree(test5, test6))
				cout << "\n the second tree is sub tree from the first \n";
			else
				cout << "\n the second tree is not sub tree from the first \n";

			//test4
			cout << "\n \t \t \t \t \t test case 4 \n";
			test7->insert(9);
			test7->insert(4);
			test7->insert(5);
			test7->insert(12);
			test7->insert(16);
			test7->insert(20);
			cout << "the first tree is \n";
			test7->display_preorder(test7->root);
			test8->insert(12);
			test8->insert(16);
			test8->insert(20);
			cout << "\n the second tree is \n";
			test8->display_preorder(test8->root);
			if (test7->isSubTree(test7, test8))
				cout << "\n the second tree is sub tree from the first \n";
			else
				cout << "\n the second tree is not sub tree from the first \n";
			//test5
			cout << "\n \t \t \t \t \t test case 5 \n";
			test9->insert(9);
			test9->insert(4);
			test9->insert(5);
			test9->insert(12);
			test9->insert(16);
			test9->insert(20);
			cout << "the first tree is \n";
			test9->display_preorder(test9->root);
			test10->insert(4);
			test10->insert(5);
			test10->insert(1);
			cout << "\n the second tree is \n";
			test10->display_preorder(test10->root);
			if (test9->isSubTree(test9, test10))
				cout << "\n the second tree is sub tree from the first \n";
			else
				cout << "\n the second tree is not sub tree from the first \n";
		}
		else if (choice == 2)
		{
			BSTFCI<BSTNode>* test1 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test2 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test3 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test4 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test5 = new BSTFCI<BSTNode>;
			//test1
			cout << "\n \t \t \t \t \t test case 1 \n";
			test1->insert(5);
			test1->insert(3);
			test1->insert(2);
			test1->insert(1);
			test1->insert(4);
			test1->insert(7);
			test1->insert(9);
			test1->insert(8);
			test1->insert(10);
			cout << "the  tree is \n";
			test1->display_preorder(test1->root);
			cout << "\n the values in range are : ";
			test1->PrintRange(3, 6);
			
			//test2
			cout << "\n \t \t \t \t \t test case 2 \n";
			test2->insert(5);
			test2->insert(3);
			test2->insert(2);
			test2->insert(1);
			test2->insert(4);
			test2->insert(7);
			test2->insert(9);
			test2->insert(8);
			test2->insert(10);
			cout << "the  tree is \n";
			test2->display_preorder(test2->root);
			cout << "\n the values in range are : ";
			test2->PrintRange(8, 15);
			//test3
			cout << "\n \t \t \t \t \t test case 3 \n";
			test3->insert(5);
			test3->insert(3);
			test3->insert(2);
			test3->insert(1);
			test3->insert(4);
			test3->insert(7);
			test3->insert(9);
			test3->insert(8);
			test3->insert(10);
			cout << "the  tree is \n";
			test3->display_preorder(test3->root);
			cout << "\n the values in range are : ";
			test3->PrintRange(6, 6);
			//test4
			cout << "\n \t \t \t \t \t test case 4 \n";
			test4->insert(9);
			test4->insert(4);
			test4->insert(5);
			test4->insert(12);
			test4->insert(16);
			test4->insert(20);
			cout << "the  tree is \n";
			test4->display_preorder(test4->root);
			cout << "\n the values in range are : ";
			test4->PrintRange(10, 20);
			//test5
			cout << "\n \t \t \t \t \t test case 5 \n";
			test5->insert(90);
			test5->insert(10);
			test5->insert(50);
			test5->insert(70);
			test5->insert(20);
			cout << "the  tree is \n";
			test5->display_preorder(test5->root);
			cout << "\n the values in range are : ";
			test5->PrintRange(10, 100);
		}
		else if (choice == 3)
		{
			BSTFCI<BSTNode>* test1 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test2 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test3 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test4 = new BSTFCI<BSTNode>;
			BSTFCI<BSTNode>* test5 = new BSTFCI<BSTNode>;
			//test1
			cout << "\n \t \t \t \t \t test case 1 \n";
			test1->insert(90);
			test1->insert(10);
			test1->insert(100);
			test1->insert(70);
			cout << "the  tree is \n";
			test1->display_preorder(test1->root);
			if (test1->isBalance(test1->root))
				cout << "\n the  tree is balanced \n";
			else
				cout << "\n the  tree is not balanced \n";
			//test2
			cout << "\n \t \t \t \t \t test case 2 \n";
			test2->insert(90);
			test2->insert(10);
			test2->insert(100);
			test2->insert(150);
			cout << "the  tree is \n";
			test2->display_preorder(test2->root);
			if (test2->isBalance(test2->root))
				cout << "\n the  tree is balanced \n";
			else
				cout << "\n the  tree is not balanced \n";
			//test3
			cout << "\n \t \t \t \t \t test case 3 \n";
			test3->insert(100);
			test3->insert(150);
			test3->insert(50);
			test3->insert(70);
			test3->insert(80);
			cout << "the  tree is \n";
			test3->display_preorder(test3->root);
			if (test3->isBalance(test3->root))
				cout << "\n the  tree is balanced \n";
			else
				cout << "\n the  tree is not balanced \n";
			//test4
			cout << "\n \t \t \t \t \t test case 4 \n";
			test4->insert(10);
			test4->insert(15);
			test4->insert(20);
			cout << "the  tree is \n";
			test4->display_preorder(test4->root);
			if (test4->isBalance(test4->root))
				cout << "\n the  tree is balanced \n";
			else
				cout << "\n the  tree is not balanced \n";
			//test5
			cout << "\n \t \t \t \t \t test case 5 \n";
			test5->insert(10);
			test5->insert(5);
			test5->insert(6);
			test5->insert(4);
			test5->insert(11);
			test5->insert(12);
			cout << "the  tree is \n";
			test5->display_preorder(test5->root);
			if (test5->isBalance(test5->root))
				cout << "\n the  tree is balanced \n";
			else
				cout << "\n the  tree is not balanced \n";
		}
		else
		{
			break;
		}
	} while (true);
	return 0;
}


