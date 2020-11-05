#include<iostream>
using namespace std;
const int s = 5;
class node
{
public:
	int data;
	node* right;
	node* left;
	node()
	{
		data = 0;
		right = NULL;
		left = NULL;
	}
};
class Binary_Search_Tree
{
public:
	node* root;
	int check;
	Binary_Search_Tree()
	{
		root = NULL;
		check = 0;
	}
	node* get_root()
	{
		return root;
	}
	int get_check()
	{
		return check;
	}
	void insertion(int val)
	{
		node* ptr = new node;
		ptr->data = val;
		if (root == NULL)
		{
			root = ptr;
			cout << " Node Inserted on Root " << endl;
			return;
		}
		else
		{
			node* temp = root;
			while (temp != NULL)
			{
				if (temp->data == ptr->data)
				{
					cout << " This Data already Exists! " << endl;
					return;
				}
				else if (ptr->data < temp->data && temp->left == NULL)
				{
					temp->left = ptr;
					cout << " Node inserted to the Left! " << endl;
					return;
				}
				else if (ptr->data < temp->data)
				{
					temp = temp->left;
				}
				else if (ptr->data > temp->data && temp->right == NULL)
				{
					temp->right = ptr;
					cout << " Node inserted to the Right! " << endl;
					return;
				}
				else if (ptr->data > temp->data)
				{
					temp = temp->right;
				}
			}
		}
	}
	void Search(int num)
	{
		cout << "-----------Searching---------- " << endl;
		int count = 0;
		if (root == NULL)
		{
			cout << " Tree is Empty " << endl;
			return;
		}
		else
		{
			node* temp = root;
			node* ptr = NULL;
			while (temp != NULL)
			{
				count++;
				if (temp->data == num)
				{
					cout << " Data Found on " << count << " Iteration " << endl;
					ptr = temp;
					break;
				}
				else if (num < temp->data)
				{
					temp = temp->left;
				}
				else if (num > temp->data)
				{
					temp = temp->right;
				}
			}
			if (ptr == NULL)
			{
				cout << " Data Not Exists " << endl;
			}
		}
	}
	void Traverse_Inorder(node* r)
	{
		if (r == NULL)
		{
			return;
		}
		Traverse_Inorder(r->left);
		cout << r->data << "__ ";
		Traverse_Inorder(r->right);
	}
	void Traverse_PreOrder(node* r)
	{
		if (r == NULL)
		{
			return;
		}
		cout << r->data << "__";
		Traverse_PreOrder(r->left);
		Traverse_PreOrder(r->right);
	}
	void Traverse_PostOrder(node* r)
	{
		if (r == NULL)
		{
			return;
		}
		Traverse_PostOrder(r->left);
		Traverse_PostOrder(r->right);
		cout << r->data << "__ ";
	}
	void Display(node* r, int space)
	{
		if (r == NULL)
		{
			return;
		}
		space = space + s;
		Display(r->right, space);
		cout << endl;
		for (int i = s; i < space; i++)
		{
			cout << " ";
		}
		cout << r->data << endl;
		Display(r->left, space);
	}
	node* nodeOnRight(node* r)
	{
		node* temp = r;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}
	node* Delete_node(node* r, int val)
	{
		if (r == NULL)
		{
			return r;
		}
		else if (val < r->data)
		{
			r->left = Delete_node(r->left, val);
		}
		else if (val > r->data)
		{
			r->right = Delete_node(r->right, val);
		}
		else
		{
			check++;
			if (r->left == NULL)
			{
				node* temp = r->right;
				delete r;
				return temp;
			}
			else if (r->right == NULL)
			{
				node* temp = r->left;
				delete r;
				return temp;
			}
			else
			{
				node* ptr = nodeOnRight(r->right);
				r->data = ptr->data;
				r->right = Delete_node(r->right, ptr->data);
			}
		}
		return r;
	}
};
int main()
{
	Binary_Search_Tree t1;
	int val;
	char choice;
	int a = 0, b = 0;
	int space = 0;
	while (a != -1)
	{
		cout << "1. Insert " << endl;
		cout << "2. Delete " << endl;
		cout << "3. Search " << endl;
		cout << "4. Traverse " << endl;
		cout << "5. Display " << endl;
		cout << endl << " Enter: ";
		cin >> choice;
		if (choice == '1')
		{
			cout << "Enter Value to Insert: ";
			cin >> val;
			t1.insertion(val);
		}
		else if (choice == '2')
		{
			cout << " Enter the Data You want to Delete: ";
			cin >> val;
			if (t1.Delete_node(t1.get_root(), val) != NULL && t1.get_check() > 0)
			{
				cout << " Your Data has been Deleted " << endl;
			}
			else
			{
				cout << " Your Data Does not Exists " << endl;
			}

		}
		else if (choice == '3')
		{
			cout << "Enter Value to Search: ";
			cin >> val;
			t1.Search(val);
		}
		else if (choice == '4')
		{
			while (b != -1)
			{
				cout << "1- In-Order " << endl;
				cout << "2- Pre-Order " << endl;
				cout << "3- Post-Order " << endl;
				cout << endl << "Enter: ";
				cin >> choice;
				if (choice == '1')
				{
					t1.Traverse_Inorder(t1.get_root());
				}
				else if (choice == '2')
				{
					t1.Traverse_PreOrder(t1.get_root());
				}
				else if (choice == '3')
				{
					t1.Traverse_PostOrder(t1.get_root());
				}
				else
				{
					cout << endl;
				}
				cout << "Enter -1 to Quit: ";
				cin >> b;
			}
		}
		else if (choice == '5')
		{
			cout << endl;
			t1.Display(t1.get_root(), space);
		}
		else
		{
			cout << " Invalid " << endl;
		}
		cout << " Enter -1 to Quit: ";
		cin >> a;
	}
	return 0;
}
