#pragma once

#include <iostream>
#include <memory>
#include "rb_tree_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"
#include <map>

namespace ft
{
	enum
	{
		BLACK,
		RED
	};

	template <typename T>
	struct Node
	{
		//Member types
		typedef	T											value_type;
		typedef size_t  									size_type;
		typedef value_type*									pointer;
		typedef	value_type	const * 						const_pointer;
		typedef value_type&									reference;
		typedef	value_type	const & 						const_reference;

		Node		*left;      //Left child of the node
		Node		*right;     //Right child of the node
		Node		*parent;    //Parent of the node
		bool		color;      //Colour of the node (BLACK or RED)
		value_type	value;      //Value of the node

		//Functions
		Node(const_reference val=value_type()): left(nullptr), right(nullptr), parent(nullptr), color(RED), value(val) {}
		Node(Node const& copy): left(nullptr), right(nullptr), parent(nullptr), color(copy.color), value(copy.value) {}

		bool isThisRightC() { return(parent && this == parent->right); }								//Checks if this node is a right child
		bool isThisLeftC() { return(parent && this == parent->left); }									//Checks if this node is a left child
		bool isBlack() { return !(this->color); }														//Checks if the current node is black
		Node *gramp() { return(parent ? (parent->parent ? parent->parent : nullptr) : nullptr); }		//Returns a Node pointer of this node's grandparent
		Node *uncle() 																					//Returns a Node pointer of this node's uncle
		{
			if(gramp() != nullptr)
				if(parent->isThisLeftC())
					return(gramp()->right);
			if(gramp() != nullptr)
				if(parent->isThisRightC())
					return(gramp()->left);
			return nullptr;
		}
		Node *sibiling()																				//Returns a Node pointer of this node's sibiling
		{
			if(parent && this == parent->right)
				return (parent->left ? parent->left : nullptr);
			else if (parent && this == parent->left)
				return (parent->right ? parent->right : nullptr);
		}
	};

	//Crea la classe rb_tree, scrivi anche le funzioni di map
}
