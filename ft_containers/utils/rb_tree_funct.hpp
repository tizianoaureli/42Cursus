#pragma once

#include <iostream>

namespace ft
{
    template <class NodePtr>
    bool isThisLeftC() { return(parent && this == parent->left); }	//Checks if this node is a left child
    
    template <class NodePtr>
	NodePtr tree_min(NodePtr x)
	{
		while (x->left != nullptr)
			x = x->left;
		return x;
	}

	template <class NodePtr>
	NodePtr tree_max(NodePtr x)
	{
		while (x->right != nullptr)
			x = x->right;
		return x;
	}

	template <class NodePtr>
	NodePtr next_iter(NodePtr x)
	{
		if (x->right != nullptr)
			return tree_min(x->right);
		while (!is_left_child(x))
			x = x->parent;
		return static_cast< NodePtr>(x->parent);
	}

	template <class NodePtr>
	NodePtr prev_iter(NodePtr x)
	{
		if (x->left != nullptr)
			return tree_max(x->left);
		while (x->parent != nullptr && is_left_child(x))
			x = x->parent;
		if (x->parent == nullptr)
			return x;
		return x->parent;
	}
    
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
        while(ptr != root && !ptr->parent->is_black)    //Checks if the node is not the root and if its parent is not black
        {
            if(ptr->parent->isThisLeftChild())          //If so, it checks if the parent is a left child
            {
                NodePtr y = x->parent->parent->right;   //ptr->parent(P); ptr->parent->parent(G)
                if(y != nullptr && !y->is_black)        //If the uncle(U) of ptr(Z) exists and is not black
                {
                    ptr = ptr->parent;
                    ptr->is_black = true;
                    ptr = ptr->parent;
                    ptr->is_black = ptr == root;
                    y->is_black = true;
                }
                else
                {
                    if(!ptr->isThisLeftChild())
                    {
                        ptr = ptr->parent;
                        left_rotate(ptr);
                    }
                    ptr = ptr->parent;
                    ptr->is_black = true;
                    ptr = ptr->parent;
                    ptr->is_black = false;
                    right_rotate(ptr);
                    break;
                }
            }
            else                                        //The parent(P) of ptr(Z) is a right child, then its uncle(U) is a left child
            {
                NodePtr y = ptr->parent->parent->left;
                if(y != nullptr && !y->is_black)
                {
                    ptr = ptr->parent;
                    ptr->is_black = true;
                    ptr = ptr->parent;
                    ptr->is_black = ptr == root;
                    y->is_black = true;
                }
                else
                {
                    if(ptr->isThisLeftChild())
                    {
                        ptr = ptr->parent;
                        right_rotate(ptr);
                    }
                    ptr = ptr->parent;
                    ptr->is_black = true;
                    ptr = ptr->parent;
                    ptr->is_black = false;
                    left_rotate(ptr);
                    break;
                }
            }
        }
    }

    template <class NodePtr>
    void removePtrTree(NodePtr root, NodePtr z)
    {
        /*
        y is either z, or if z has 2 children, tree_next(z).
        y will have at most one child.
        */
        NodePtr y = (z->left == nullptr || z->right == nullptr) ? z : tree_next(z);
        //x is y's possibly null single child
        NodePtr x = y->left != nullptr ? y->left : y->right;
        //w is x's possibly null uncle (will become x's sibiling)
        NodePtr w = nullptr;
        //link x to y's parent and find w
        if(x != nullptr)
            x->parent = y->parent;
        if(y->isThisLeftChild())
        {
            y->parent->left = x;
            if(y != root)
                w = y->parent->right;
            else
                root = x;
        }
        else
        {
            y->parent->right = x;
            //y can't be root if it is a right hild
            w = y->parent->left;
        }
        bool removed_black = y->is_black;
        //If z wasn't removed, do so now by splicing y for z, but copy z's color.
        //This does not impact x or w.
        if(y != z)
        {
            //z->left != nullptr but z->right might == x == nulptr
            y->parent = z->parent;
            if(z->isThisLeftChild())
                y->parent->left = y;
            else
                y->parent->right = y;
            y->left = z->left;
            y->left->parent = y;
            y->right = z->right;
            if(y->right != nullptr)
                y->right->parent = y;
            y->is_black = z->is_black;
            if(root == z)
                root = y;
        }
        // There is no need to rebalance if we removed a red, or if we removed
        // the last node.
        if(removed_black && root != nullptr)
        {
            // Rebalance:
            // x has an implicit black color (transferred from the removed y)
            //    associated with it, no matter what its color is.
            // If x is root (in which case it can't be null), it is supposed
            //    to be black anyway, and if it is doubly black, then the double
            //    can just be ignored.
            // If x is red (in which case it can't be null), then it can absorb
            //    the implicit black just by setting its color to black.
            // Since y was black and only had one child (which x points to), x
            //   is either red with no children, else null, otherwise y would have
            //   different black heights under left and right pointers.
            // if (x == root || x != nullptr && !x->is_black)
            if(x != nullptr)
                x->is_blac = true;
            else
            {
                //  Else __x isn't root, and is "doubly black", even though it may
                //  be null.  __w can not be null here, else the parent would
                //  see a black height >= 2 on the __x side and a black height
                //  of 1 on the __w side (__w must be a non-null black or a red
                //  with a non-null black child).
                while(true)
                {
                    if(x->isThisLeftC())    //if x is left child
                    {
                        if(!w->is_black)
                        {
                            w->is_black = true;
                            w->parent->is_black = false;
                            left_rotate(w->parent);
                            //x is still valid; reset root only if necessary
                            if(root == w->left)
                                root = w;
                            //reset sibiling, and it still can't be null
                            w = w->left->right;
                        }
                        //w->is_black is now true, w may have null children
                        if( (w->left == nullptr || w->left->is_black) && 
                            (w->right == nullptr || w->right->is_black) )
                        {
                            w->is_black = false;
                            x = w->parent;
                            //x can no longer be null
                            if(x == root || !x->is_black)
                            {
                                x->is_black = true;
                                break;
                            }
                            //reset sibiling, and it still can't be null
                            w = x->isThisLeftChild() ? x->parent->right : x->parent->left;
                        }
                        else    //w has a red child
                        {
                            if (w->right == nullptr || w->right->is_black)
                            {
                                //w left child is non-null and red
                                w->left->is_black = true;
                                w->is_black = false;
                                right_rotate(w);
                                // __w is known not to be root, so root hasn't changed
                                // reset sibling, and it still can't be null
                                w = w->parent;
                            }
                            // __w has a right red child, left child may be null
                            w->is_black = w->parent->is_black;
                            w->parent->is_black = true;
                            w->right->is_black = true;
                            left_rotate(w->parent);
                            break;
                        }
                    }
                    else
                    {
                        if(!w->is_black)
                        {
                            w->is_black = true;
                            w->parent->is_black = false;
                            right_rotate(w->parent);
                            // x is still valid
                            // reset root only if necessary
                            if(root == w->right)
                                root = w;
                            //reset sibiling, and it still can't be null
                            w = w->right->left;
                        }
                        //w->is_black is now true, w may have null children
                        if ((w->left == nullptr || w->left->is_black) && 
                            (w->right == nullptr || w->right->is_black))
                        {
                            w->is_black = false;
                            x = w->parent;
                            //x can no longer be null
                            if (!x->is_black || x == root)
                            {
                                x->is_black = true;
                                break;
                            }
                            //reset sibiling, and it still can't be null
                            w = x->isThisLeftC() ? x->parent->right : x->parent->left;
                        }
                        else
                        {
                            if (w->left == nullptr || w->left->is_black)
                            {
                                //w right child is non-null and red
                                w->right->is_black = true;
                                w->is_black = false;
                                left_rotate(w);
                                //w is known not to be root, so root hasn't changed
                                //reset sibiling, and it still can't be null
                                w = w->parent;
                            }
                            //w has a left red child, right child may be null
                            w->is_black = w->parent->is_black;
                            w->parent->is_black = true;
                            w->left->is_black = true;
                            right_rotate(w->parent);
                            break;
                        }
                    }
                }
            }
        }
    }

}