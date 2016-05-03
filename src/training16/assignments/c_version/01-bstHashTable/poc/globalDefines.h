/**
 * @file globalDefines.h
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief Header file containing exportable methods.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#ifndef M_GLOBALDEFINES_H

/**
 * @brief Include the main header.
 */
#define M_GLOBALDEFINES_H

/**
 * @brief Tell the compiler that we want ISO C99 source, and check if the
 * system has ANSI C 99.
 */
#define ISOC99_SOURCE
#define _POSIX_C_SOURCE 199309L
#if __STDC_VERSION__ != 199901L
#error "ANSI C99 not available"
#endif

/*
 * Comment out the following to disable all asserts.
 */
/*#define NDEBUG*/

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief List Node Abstract Data Type.
 *
 * @struct listNode
 */
struct listNode
{
    /**
     * @brief Pointer to the next Node object.
     */
  struct Node *next;

    /**
     * @brief Pointer to the previous Node obkect.
     */
  struct Node *prev;

    /**
     * @brief Pointer to the Node object which contains key and value
     * fields of the current listNode instance.
     */
  struct Node *parentStructPtr;
};

/**
 * @brief Bst Node Abstract Data Type.
 *
 * @struct bstNode
 */
struct bstNode
{
    /**
     * @brief Pointer to the left Node object.
     */
  struct Node *left;

    /**
     * @brief Pointer to the right Node object.
     */
  struct Node *right;

    /**
     * @brief Pointer to the parent Node object.
     */
  struct Node *parent;

    /**
     * @brief Pointer to the Node object which contains key and value
     * fields of the current bstNode instance.
     */
  struct Node *parentStructPtr;
};

/**
 * @brief Node Abstract Data Type.
 *
 * @struct Node
 *
 * @note A node should be only of one type (i.e: either listNode or bstNode is
 * set, but not both). If you want you could use both ln and bn pointers at the
 * same time.
 */
struct Node
{
  char *key;
  char *value;

    /**
     * @brief Pointer to a listNode struct which contains listNode information.
     */
  struct listNode *ln;

    /**
     * @brief Pointer to a bstNode struct which contains bstNode information.
     */
  struct bstNode *bn;
};

/**
 * @typedef struct Node *node
 */
typedef struct Node *node;

/**
 * @typedef node *nodePtr
 */
typedef node *nodePtr;

/**
 * @typedef struct bstNode *bnode
 */
typedef struct bstNode *bnode;

/**
 * @typedef struct listNode *lnode
 */
typedef struct listNode *lnode;

/* ========================================== */

/**
 * @brief Check if any type of pointer is NULL.
 *
 * @param[in] element Any kind of pointer.
 *
 * @retval true element is NULL.
 * @retval false element is not NULL.
 */
extern bool element_null (void *element);

/**
 * @brief Allocate new space in a safe way.
 *
 * @param[in] size Total size to be allocated .
 *
 * @retval dst The pointer to the new instance of data.
 */
extern void *malloc_safe (size_t size);

/* ========================================== */

/**
 * @brief Check if the node is NULL.
 *
 * @param[in] n A pointer to a node instance.
 *
 * @retval true The node is NULL.
 * @retval false The node is not NULL.
 */
extern bool node_null (node n);

/**
 * @brief Get the key from a node.
 *
 * @param[in] n A pointer to a node instance.
 *
 * @retval node->key A memory address corresponding to the key.
 *
 * @Warning The return value can be NULL.
 */
extern char *key_get (node n);

/**
 * @brief Store the key inside a node.
 *
 * @param[in] n A pointer to a node instance.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval true The key has been stored correctly.
 * @retval false The key has not been stored because the input node was NULL.
 */
extern bool key_set (node n, char *key);

/**
 * @brief Check if two keys are equal.
 *
 * @param[in] key1 A memory address corresponding to the first key.
 * @param[in] key2 A memory address corresponding to the second key.
 *
 * @retval true The two keys are equal.
 * @retval false The two keys differ.
 */
extern bool keys_equal (char *key1, char *key2);

/**
 * @brief Check if the first key is smaller than the second.
 *
 * @param[in] key1 A memory address corresponding to the first key.
 * @param[in] key2 A memory address corresponding to the second key.
 *
 * @retval true key1 is smaller than key2.
 * @retval false key1 is not smaller than key2.
 */
extern bool keys_less (char *key1, char *key2);

/**
 * @brief Check if the first key is bigger than the second.
 *
 * @param[in] key1 A memory address corresponding to the first key.
 * @param[in] key2 A memory address corresponding to the second key.
 *
 * @retval true key1 is bigger than key2.
 * @retval false key1 is not bigger than key2.
 */
extern bool keys_greater (char *key1, char *key2);

/**
 * @brief Get the value from a node.
 *
 * @param[in] n A pointer to a node instance.
 *
 * @retval node->value A memory address corresponding to the value.
 *
 * @Warning The return value can be NULL.
 */
extern char *value_get (node n);

/**
 * @brief Store the value inside a node.
 *
 * @param[in] n A pointer to a node instance.
 * @param[in] value A memory address corresponding to the value.
 *
 * @retval true The value has been stored correctly.
 * @retval false The value has not been stored because the input node was NULL.
 */
extern bool value_set (node n, char *value);

/* ========================================== */

/**
 * @brief Create a generic new node.
 *
 * @param[in] key A memory address corresponding to the key.
 * @param[in] value A memory address corresponding to the value.
 * @param[in] type A character corresponding to the type of node to be
 * created.
 *
 * @note type can either be 'b' or 'l', for either bsts or lists.
 *
 * @retval new_node A memory address corresponding to the new node.
 *
 * @Warning The return value can be NULL.
 */
extern node node_new (char *key, char *value, char type);

/**
 * @brief Set a node object to NULL.
 *
 * @retval npt A memory address corresponding to the new instance of a nodePtr
 * object.
 *
 * @Warning The return value can be NULL.
 */
extern nodePtr nodeptr_new (void);

/* ========================================== */

#if defined M_BST_C
extern node BSTLeft (node root);

extern node BSTRight (node root);

extern node BSTParent (node root);

extern node BSTMaxElement (node root);

extern node BSTPredecessor (node root);

extern bool BSTIsLeaf (node root);

extern void BSTPrint (node root);

extern bool BSTIs (node root, char *minKey, char *maxKey);
#endif

/**
 * @brief Insert a new node in a specified BST.
 *
 * @param[in] rootPtr A pointer <TODO>
 * @param[in] key A memory address corresponding to the key.
 * @param[in] value A memory address corresponding to the value.
 *
 * @retval new_node A memory address corresponding to the new node.
 *
 * @Warning The return value can be NULL.
 */
extern node BSTInsert (nodePtr rootPtr, char *key, char *value);

/**
 * @brief Search for a node with a given key in a specified BST.
 *
 * @param[in] root A pointer to the BST.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval root A memory address corresponding to the searched node.
 *
 * @Warning The return value can be NULL.
 */
extern node BSTSearch (node root, char *key);

/**
 * @brief Delete the node with the given key in a specified BST.
 *
 * @param[in] root A pointer to the BST.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval true The node was deleted.
 * @retval false The node was not deleted.
 *
 * @note return value is false if root is empty or the specified element was 
 * not found.
 */
extern bool BSTDelete (nodePtr rootPtr, char *key);

/**
 * @brief Delete the BST starting from the specified point.
 *
 * @param[in] root A pointer to the BST.
 *
 * @retval NULL
 *
 * @note Usually this function is used to delete the whole tree.
 */
extern node BSTClear (node root);


#endif
