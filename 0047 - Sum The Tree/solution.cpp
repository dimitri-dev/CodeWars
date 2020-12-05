int sumTheTreeValues(node* root) {
  if (root == nullptr)
    return 0;
  
  int sum = root->value;
  
  if (root->left != nullptr) sum += sumTheTreeValues(root->left);
  
  if (root->right != nullptr) sum += sumTheTreeValues(root->right);
  
  return sum;
}