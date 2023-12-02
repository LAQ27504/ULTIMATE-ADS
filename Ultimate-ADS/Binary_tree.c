#include <stdio.h>
#include <stdlib.h>

typedef struct Tree_node {
    int value;
    struct Tree_node *Parent;
    struct Tree_node *Left;
    struct Tree_node *Right; 
}Tree;

Tree* init_Node(int value){
    Tree *new_node = (Tree*)malloc(sizeof(Tree));
    new_node->value = value;
    new_node->Left = NULL;
    new_node->Right = NULL;
    new_node->Parent = NULL;
    return new_node;
}

int is_Root(Tree *t){
    return t->Left != NULL || t->Right != NULL;
}

int is_Leaf(Tree *t){
    return t->Left == NULL && t->Right == NULL;
}

Tree* get_Parent(Tree *t){
    return t->Parent;
}

Tree* get_Right(Tree *t){
    return t->Right;
}

Tree* get_Left(Tree *t){
    return t->Left;
}

Tree* insert_node(Tree *t, int value, Tree *p){
    if (t == NULL){
        t = init_Node(value);
        t->Parent = p;
        return t;
    }
    if (value <= t->value){
        t->Left = insert_node(t->Left, value, t);
    }
    else{
        t->Right = insert_node(t->Right, value, t);
    }
    return t;
}

void remove_node(Tree *t, int value){
    if (t == NULL){
        return;
    }

    if (t->value == value){
        if (is_Leaf(t) && t->Parent->Right == t){
            t->Parent->Right = NULL;
            free(t);
            return;
        }
        else if (is_Leaf(t) && t->Parent->Left == t){
            t->Parent->Left = NULL;
            free(t);
            return;
        }
        if (t->Left == NULL && t->Parent->Right == t){
            t->Parent->Right = t->Right;
            free(t);
            return;
        }
        else if (t->Left == NULL && t->Parent->Left == t){
            t->Parent->Left = t->Right;
            free(t);
            return;
        }
        else if (t->Right == NULL && t->Parent->Right == t){
            t->Parent->Right = t->Left;
            free(t);
            return;
        }
        else if (t->Right == NULL && t->Parent->Left == t){
            t->Parent->Left = t->Left;
            free(t);
            return;
        }
        Tree *temp = t->Left;
        while(temp->Right != NULL){
            temp = temp->Right;
        }
        t->value = temp->value;
        if (temp->Left != NULL){
            temp->Parent->Right = temp->Left;
        }
        else{
            temp->Parent->Right = temp->Right;
        }
        
        free(temp);
        return;
    }
    remove_node(t->Left, value);
    remove_node(t->Right, value);
}

void display_tree_pre_order(Tree *t){
    if (t == NULL){
        return;
    }
    printf("%d ", t->value);
    display_tree_pre_order(t->Left);
    display_tree_pre_order(t->Right);
}

void display_tree_in_order(Tree *t){
    if (t == NULL){
        return;
    }
    display_tree_in_order(t->Left);
    printf("%d ", t->value);
    display_tree_in_order(t->Right);
}

void display_tree_post_order(Tree *t){
    if (t == NULL){
        return;
    }
    display_tree_post_order(t->Left);
    display_tree_post_order(t->Right);
    printf("%d ", t->value);
}

int main(){
    Tree *mytree;
    mytree = init_Node(8);
    insert_node(mytree, 4, mytree); 
    insert_node(mytree, 10, mytree); 
    insert_node(mytree, 2, mytree); 
    insert_node(mytree, 6, mytree); 
    insert_node(mytree, 9, mytree); 
    insert_node(mytree, 4, mytree); 
    insert_node(mytree, 10, mytree); 
    insert_node(mytree, 2, mytree); 
    insert_node(mytree, 6, mytree); 
    insert_node(mytree, 5, mytree); 
    display_tree_in_order(mytree);
    printf("\n");
    remove_node(mytree, 8);
    display_tree_in_order(mytree);
}