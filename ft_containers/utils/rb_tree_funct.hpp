#pragma once

#include <iostream>

namespace ft
{
    template <class NodePtr>
    bool isThisLeftC() { return(parent && this == parent->left); }	//Checks if this node is a left child
    
    template <class NodePtr>
    void left_rotate(NodePtr ptr)       //Does a left-rotate of a node
    {
        NodePtr y = ptr->right;
        ptr->right = y->left;
        if(ptr->right != nullptr)
            ptr->right->parent = ptr;
        y->parent = ptr->parent;
        if(ptr->isThisLeftC())
            if(ptr->parent != nullptr)
                ptr->parent->left = y;
        else
            ptr->parent->right = y;
        y->left = ptr;
        ptr->parent = y;
    }

    template <class NodePtr>
    void right_rotate(NodePtr ptr)      //Does a right-rotate of a node
    {
        NodePtr y = ptr->left;
        ptr->left = y->right;
        if(ptr->left != nullptr)
            ptr->left->parent = ptr;
        y->parent = ptr->parent;
        if(ptr->isThisLeftC())
            ptr->parent->left = y;
        else
            ptr->parent->right = y;
        y->right = ptr;
        ptr->parent = y; 
    }

    /*
        This function is called only when ptr is not the root.
        Rebalance _root after attaching ptr to a leaf.
    */
    template <class NodePtr>
    void balance_after_insert(NodePtr root, NodePtr ptr)
    {
        
    }

    template <class NodePtr>
    void removePtrTree(NodePtr root, NodePtr ptr)
    {

    }

}