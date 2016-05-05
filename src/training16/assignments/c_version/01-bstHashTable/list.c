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

static node LISTSuccessor (node head);
static node LISTPredecessor (node head);
static node LISTNewNode (nodePtr headPtr, node prevNode, char *key,
			 char *value);
static node LISTNonEmptyInsert (node head, char *key, char *value);
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
  if (keys_equal (key_get (head), key))
    return NULL;
  else if (!node_null (LISTSuccessor (head)))
    return (LISTNonEmptyInsert (LISTSuccessor (head), key, value));
  else
    return (LISTNewNode (&(head->ln->next), head, key, value));
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
  if (node_null (head))
    return NULL;
  else if (keys_equal (key_get (head), key))
    return head;
  else
    return (LISTSearch (LISTSuccessor (head), key));
}

static bool
LISTNonEmptyDelete (nodePtr headPtr, node head, char *key)
{
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
	  free (head);
	}
      /*
       * Element to delete is at the head of the list.
       */
      else if (node_null (LISTPredecessor (head)))
	{
	  *headPtr = LISTSuccessor (head);
	  (head->ln->next)->ln->prev = NULL;
	  free (head);
	  /*
	   * Element to delete is at the tail of the list.
	   */
	}
      else if (node_null (LISTSuccessor (head)))
	{
	  (head->ln->prev)->ln->next = NULL;
	  free (head);
	  /*
	   * Element to delete is in the middle of the list.
	   */
	}
      else
	{
	  (head->ln->prev)->ln->next = LISTSuccessor (head);
	  (head->ln->next)->ln->prev = LISTPredecessor (head);
	  free (head);
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
  head = NULL;
  free (head);

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
