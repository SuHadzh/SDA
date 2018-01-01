#include <iostream>
using namespace std;

template <class T>
struct node
{
	T inf;
	node<T> *left, *right;
};

template <class T>
class BinTree {
private:
	node<T>* root;
	void DeleteBinTree(node<T>* &) const;
	void Copy(node<T> * &, node<T>* const&) const;
	void CopyBinTree(BinTree<T> const&);
	void pr(const node<T> *) const;
	void CreateBinTree(node<T> * &) const;

public:
	BinTree();
	BinTree(BinTree<T> const&);
	BinTree& operator=(BinTree<T> const&);
	~BinTree();
	T RootBinTree() const;
	BinTree<T> LeftBinTree() const;
	BinTree<T> RightBinTree() const;
	node<T>* GetRoot();
	bool empty() const;
	void print() const;
	void Create();
	void Create3(T, BinTree<T>, BinTree<T>);
};

template <class T>
BinTree<T>::BinTree() {
	root = NULL;
}

template <class T>
BinTree<T>::~BinTree() {
	DeleteBinTree(root);
}

template <class T>
BinTree<T>::BinTree(BinTree<T> const& r)
{
	CopyBinTree(r);
}

template <class T>
BinTree<T>& BinTree<T>::operator=(BinTree<T> const& r) {
	if (this != &r)
	{
		DeleteBinTree(root);
		CopyBinTree(r);
	}
	return *this;
}

template <class T>
void BinTree<T>::DeleteBinTree(node<T>* &p) const {
	if (p)
	{
		DeleteBinTree(p->left);
		DeleteBinTree(p->right);
		delete p;
		p = NULL;
	}
}

template <class T>
void BinTree<T>::CopyBinTree(BinTree<T> const& r) {
	Copy(root, r.root);
}

template <class T>
void BinTree<T>::Copy(node<T> * & pos, node<T>* const & r) const {
	pos = NULL;
	if (r)
	{
		pos = new node<T>;
		pos->inf = r->inf;
		Copy(pos->left, r->left);
		Copy(pos->right, r->right);
	}
}

template <class T>
bool BinTree<T>::empty() const {
	return root == NULL;
}

template <class T>
T BinTree<T>::RootBinTree() const {
	return root->inf;
}

template <class T>
node<T>* BinTree<T>::GetRoot() {
	return root;
}

template <class T>
BinTree<T> BinTree<T>::LeftBinTree() const {
	BinTree<T> t;
	Copy(t.root, root->left);
	return t;
}

template <class T>
BinTree<T> BinTree<T>::RightBinTree() const {
	BinTree<T> t;
	Copy(t.root, root->right);
	return t;
}

template <class T>
void BinTree<T>::pr(const node<T>*p) const {
	if (p)
	{
		pr(p->left);
		cout << p->inf << " ";
		pr(p->right);
	}
}

template <class T>
void BinTree<T>::print() const {
	pr(root);
}

template <class T>
void BinTree<T>::Create3(T x, BinTree<T> l, BinTree<T> r) {
	root = new node<T>;
	root->inf = x;
	Copy(root->left, l.root);
	Copy(root->right, r.root);
}

template <class T>
void BinTree<T>::CreateBinTree(node<T>* & pos) const{
	T x;
	char c;
	cout << "root: ";
	cin >> x;

	pos = new node<T>;
	pos->inf = x;
	pos->left = NULL;
	pos->right = NULL;

	cout << "left BinTree of: " << x << " y/n? ";
	cin >> c;
	if (c == 'y')
	{
		CreateBinTree(pos->left);
	}

	cout << "right BinTree of: " << x << " y/n? ";
	cin >> c;
	if (c == 'y')
	{
		CreateBinTree(pos->right);
	}
}

template <class T>
void BinTree<T>::Create() {
	CreateBinTree(root);
}

int main()
{
	BinTree<int> binTree;
	binTree.Create();
	binTree.print();

	return 0;
}