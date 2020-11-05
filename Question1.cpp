#include<iostream>
using namespace std;
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
class Binary_Tree
{
	node* root;
	int s;
	int check;
	int count;
public:
	Binary_Tree()
	{
		root = NULL;
		s = 5;
		check = 0;
		count = 0;
	}
	int get_check()
	{
		return check;
	}
	node* get_root()
	{
		return root;
	}
	void Insert_left(int val)
	{
		node* ptr = new node;
		ptr->data = val;
		if (root == NULL)
		{
			root = ptr;
			cout << " Data Inserted on Root " << endl;
		}
		else
		{
			node* temp = root;
			while (temp->left != NULL)
			{
				if (temp->data == val)
				{
					cout << " Duplicate Data not allowed " << endl;
					return;
				}
				temp = temp->left;
			}
			temp->left = ptr;
			cout << " Data Inserted to the Left! " << endl;
		}
	}
	void Insert_Right(int val)
	{
		node* ptr = new node;
		ptr->data = val;
		if (root == NULL)
		{
			root = ptr;
			cout << " Data Inserted on Root " << endl;
		}
		else
		{
			node* temp = root;
			while (temp->right != NULL)
			{
				if (temp->data == val)
				{
					cout << " Duplicate Data not allowed " << endl;
					return;
				}
				temp = temp->right;
			}
			temp->right = ptr;
			cout << " Data Inserted to the Right! " << endl;
		}
	}
	void Traverse_InOrder(node* r)
	{
		if (r == NULL)
		{
			return;
		}
		Traverse_InOrder(r->left);
		cout << r->data << "__";
		Traverse_InOrder(r->right);
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
		cout << r->data << "__";
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
		cout << r->data;
		Display(r->left, space);
	}
	void Find(node* r, int val)
	{
		count++;
		check++;
		if (r == NULL)
		{
			return;
		}
		if (val == r->data)
		{
			cout << "Data Found on " << count << " Iteration " << endl;
			return;
		}
		Find(r->right, val);
		Find(r->left, val);
	}
	node* replace(node* r)
	{
		node* temp = r;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		return temp;
	}
	node* Delete_(node* r, int val)
	{
		if (r == NULL)
		{
			return r;
		}
		r->left = Delete_(r->left, val);
		if (val == r->data)
		{
			check++;
			if (r->right == NULL)
			{
				node* temp = r->left;
				delete r;
				return temp;
			}
			else if (r->left == NULL)
			{
				node* temp = r->right;
				delete r;
				return temp;
			}
			else
			{
				node* temp = replace(r->right);
				r->data = temp->data;
				r->right = Delete_(r->right, temp->data);
			}
		}
		r->right = Delete_(r->right, val);
		return r;
	}
	node* Delete_left(node* r, int val)
	{
		if (r == NULL)
		{
			return r;
		}
		r->left = Delete_left(r->left, val);
		if (val == r->data)
		{
			check++;
			if (r->right == NULL)
			{
				node* temp = r->left;
				delete r;
				return temp;
			}
			else if (r->left == NULL)
			{
				node* temp = r->right;
				delete r;
				return temp;
			}
			else
			{
				node* temp = replace(r->right);
				r->data = temp->data;
				r->right = Delete_(r->right, temp->data);
			}
		}
		return r;
	}
	node* Delete_right(node* r, int val)
	{
		if (r == NULL)
		{
			return r;
		}
		r->right = Delete_right(r->right, val);
		if (val == r->data)
		{
			check++;
			if (r->right == NULL)
			{
				node* temp = r->left;
				delete r;
				return temp;
			}
			else if (r->left == NULL)
			{
				node* temp = r->right;
				delete r;
				return temp;
			}
			else
			{
				node* temp = replace(r->right);
				r->data = temp->data;
				r->right = Delete_(r->right, temp->data);
			}
		}
		return r;
	}
};
int main()
{
	Binary_Tree t1;
	int val;
	char choice;
	int a = 0, b = 0;
	int space = 0;
	while (a != -1)
	{
		cout << "1. Insert " << endl;
		cout << "2. Insert Right" << endl;
		cout << "3. Insert Left" << endl;
		cout << "4. Delete " << endl;
		cout << "5. Delete Right" << endl;
		cout << "6. Delete Left" << endl;
		cout << "7. Find " << endl;
		cout << "8. Traverse " << endl;
		cout << "9. Display " << endl;
		cout << endl << " Enter: ";
		cin >> choice;
		if (choice == '1')
		{
			/*cout << "Enter Value to Insert: ";
			cin >> val;
			t1.Insert(val);*/
			cout << " Insert Function is only Pending thing " << endl;
		}
		else if (choice == '2')
		{
			cout << "Enter Value to Insert at Right: ";
			cin >> val;
			t1.Insert_Right(val);
		}
		else if (choice == '3')
		{
			cout << "Enter Value to Insert at Left: ";
			cin >> val;
			t1.Insert_left(val);
		}
		else if (choice == '4')
		{
			cout << " Enter the Data You want to Delete: ";
			cin >> val;
			if (t1.Delete_(t1.get_root(), val) != NULL && t1.get_check() > 0)
			{
				cout << " Your Data has been Deleted " << endl;
			}
			else
			{
				cout << " Your Data Does not Exists " << endl;
			}

		}
		else if (choice == '5')
		{
			cout << " Enter the Data You want to Delete from Right: ";
			cin >> val;
			if (t1.Delete_right(t1.get_root(), val) != NULL && t1.get_check() > 0)
			{
				cout << " Your Data has been Deleted " << endl;
			}
			else
			{
				cout << " Your Data Does not Exists " << endl;
			}

		}
		else if (choice == '6')
		{
			cout << " Enter the Data You want to Delete from Left: ";
			cin >> val;
			if (t1.Delete_left(t1.get_root(), val) != NULL && t1.get_check() > 0)
			{
				cout << " Your Data has been Deleted " << endl;
			}
			else
			{
				cout << " Your Data Does not Exists " << endl;
			}

		}
		else if (choice == '7')
		{
			cout << "Enter Value to Search: ";
			cin >> val;
			t1.Find(t1.get_root(), val);
		}
		else if (choice == '8')
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
					t1.Traverse_InOrder(t1.get_root());
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
		else if (choice == '9')
		{
			cout << endl;
			t1.Display(t1.get_root(), space);
			cout << endl << endl;
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