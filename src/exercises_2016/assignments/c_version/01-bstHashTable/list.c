/**
 * @file list.c
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief List functions.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

/* Flag that defines the type of list. */
#define ITERATIVE_LIST
/*#define RECURSIVE_LIST*/

/**
 * @brief Get the successor node of the current one.
 *
 * @param[in] head A pointer to the list.
 *
 * @retval head->ln->next A memory address corresponding to the next node.
 *
 * @warning The return value can be NULL.
 */
static node LISTSuccessor (node head);

/**
 * @brief Get the previous node of the current one.
 *
 * @param[in] head A pointer to the list.
 *
 * @retval head->ln->prev A memory address corresponding to the previous node.
 *
 * @warning The return value can be NULL.
 */
static node LISTPredecessor (node head);

/**
 * @brief Function that creates a new node with the specified values in the
 * position pointed by headPtr.
 *
 * @param[in] headPtr A memory address containing the pointer to the LIST.
 * @param[in] prevNode A pointer to the previous node of the one to be
 * inserted.
 * @param[in] key A pointer to the key.
 * @param[in] key A pointer to the value.
 *
 * @retval *headPtr A pointer to the new node.
 *
 * @warning The return value can be NULL.
 */
static node LISTNewNode (nodePtr headPtr, node prevNode, char *key,
			 char *value);

/**
 * @brief Function that looks for the correct position where to insert a new
 * node.
 *
 * @param[in] head A pointer to the LIST.
 * @param[in] key A pointer to the key.
 * @param[in] value A pointer to the value.
 *
 * @retval BSTNewNode A pointer to the new node.
 *
 * @note This function is called only if the original LIST is not empty.
 *
 * @warning The return value can be NULL.
 */
static node LISTNonEmptyInsert (node head, char *key, char *value);

/**
 * @brief Function that looks (and deletes) for the correct position where to
 * delete a specified node.
 *
 * @param[in] head A pointer to the LIST.
 * @param[in] key A pointer to the key.
 * @param[in] key A pointer to the value.
 *
 * @retval true The node has been deleted.
 * @retval true The node has not deleted.
 *
 * @note return value is false if head is empty or the specified element was
 * not found.
 */
static bool LISTNonEmptyDelete (nodePtr headPtr, node head, char *key);

static node
LISTSuccessor (node head)
{
  return (node_null (head) ? NULL : head->ln->next);
}

static node
LISTPredecessor (node head)
{
  return (node_null (head) ? NULL : head->ln->prev);
}

static node
LISTNewNode (nodePtr headPtr, node prevNode, char *key, char *value)
{
  (*headPtr) = node_new (key, value, 'l');
  (*headPtr)->ln->prev = prevNode;
  (*headPtr)->ln->next = NULL;

  return *headPtr;
}

static node
LISTNonEmptyInsert (node head, char *key, char *value)
{
#if defined RECURSIVE_LIST

  if (keys_equal (key_get (head), key))
    return NULL;
  else if (!node_null (LISTSuccessor (head)))
    return (LISTNonEmptyInsert (LISTSuccessor (head), key, value));
  else
    return (LISTNewNode (&(head->ln->next), head, key, value));

#elif defined ITERATIVE_LIST

  while (!node_null (LISTSuccessor (head)))
    {
      if (keys_equal (key_get (head), key))
	return NULL;
      head = LISTSuccessor (head);
    }
  return (LISTNewNode (&(head->ln->next), head, key, value));

#endif
}

node
LISTInsert (nodePtr headPtr, char *key, char *value)
{
  if (element_null (key) || element_null (value))
    return NULL;
  else if (node_null (*headPtr))
    return (LISTNewNode (headPtr, NULL, key, value));
  else
    return (LISTNonEmptyInsert (*headPtr, key, value));
}

node
LISTSearch (node head, char *key)
{
#if defined RECURSIVE_LIST

  /* Base case: node not found. */
  if (node_null (head))
    return NULL;
  else if (keys_equal (key_get (head), key))
    return head;
  else
    return (LISTSearch (LISTSuccessor (head), key));

#elif defined ITERATIVE_LIST

  while (!node_null (head))
    {
      if (keys_equal (key_get (head), key))
	return head;

      head = LISTSuccessor (head);
    }
  /* Node not found. */
  return NULL;

#endif
}

static bool
LISTNonEmptyDelete (nodePtr headPtr, node head, char *key)
{
#if defined RECURSIVE_LIST

  /*
   * Element not found.
   */
  if (node_null (head))
    return false;

  /*
   * Element may still be in list.
   */
  else if (!keys_equal (key, key_get (head)))
    return (LISTNonEmptyDelete
	    (&(head->ln->next), LISTSuccessor (head), key));

#elif defined ITERATIVE_LIST

  while (!node_null (head) && !keys_equal (key, key_get (head)))
    {
      if (node_null (head))
	return false;

      headPtr = &(head->ln->next);
      head = LISTSuccessor (head);
    }

  /* Dummy condition. */
  if (false)
    {
    }
#endif
  /*
   * The element to delete has been found.  We now have the usual cases for a
   * double linked list without a dummy node.
   */
  else
    {
      /*
       * There is only one element in list.
       */
      if (node_null (LISTPredecessor (head))
	  && node_null (LISTSuccessor (head)))
	{
	  *headPtr = NULL;
	  node_delete (&head, 'l');
	}
      /*
       * Element to delete is at the head of the list.
       */
      else if (node_null (LISTPredecessor (head)))
	{
	  *headPtr = LISTSuccessor (head);
	  (head->ln->next)->ln->prev = NULL;
	  node_delete (&head, 'l');
	  /*
	   * Element to delete is at the tail of the list.
	   */
	}
      else if (node_null (LISTSuccessor (head)))
	{
	  (head->ln->prev)->ln->next = NULL;
	  node_delete (&head, 'l');
	  /*
	   * Element to delete is in the middle of the list.
	   */
	}
      else
	{
	  (head->ln->prev)->ln->next = LISTSuccessor (head);
	  (head->ln->next)->ln->prev = LISTPredecessor (head);
	  node_delete (&head, 'l');
	}
    }

  return true;
}

bool
LISTDelete (nodePtr headPtr, char *key)
{
  /*
   * An empty list cannot be deleted.
   */
  if (node_null (*headPtr))
    return false;
  else
    return (LISTNonEmptyDelete (headPtr, *headPtr, key));
}

node
LISTClear (node head)
{
  if (node_null (head))
    return NULL;

  LISTClear (LISTSuccessor (head));
  node_delete (&head, 'l');

  return NULL;
}

void
LISTPrint (node head)
{
  if (node_null (head))
    return;

  fprintf (stderr, "%s %s\n", key_get (head), value_get (head));
  LISTPrint (LISTSuccessor (head));
}
