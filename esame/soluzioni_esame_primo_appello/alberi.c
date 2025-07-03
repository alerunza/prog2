int sumX(IntTree tree) {
    
    if(tree==NULL) return 0;
    if(tree->left==NULL && tree->right==NULL){
        if(tree->parent==NULL)return tree->data;
        
        if((tree->parent->left==tree && tree->parent->right==NULL)||(tree->parent->right==tree && tree->parent->left==NULL)){
            return tree->data;
        }else{
            return 0;
        }
    }
    
    return sumX(tree->left)+sumX(tree->right);
    
}