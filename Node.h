struct Node
{
	char ch;
	int freq;
	Node* left, * right;
};

struct comp
{
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};