void connectTwoNode(struct Node *node1, struct Node *node2) {
    if (!node1 || !node2) return;
    node1->next = node2;
    connectTwoNode(node1->left, node1->right);
    connectTwoNode(node2->left, node2->right);
    connectTwoNode(node1->right, node2->left);
}

struct Node* connect(struct Node* root) {
	if (!root) return NULL;
    connectTwoNode(root->left, root->right);
    return root;
}