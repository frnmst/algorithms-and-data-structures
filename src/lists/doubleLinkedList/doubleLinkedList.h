/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "../adt/adt.h"

/* Definitions.  */

#define EMPTYLIST EMPTY

/* New datatype.  */

typedef struct node physicalNode;

/* nodePointer is a pointer to struct physicalNode */
typedef pointerToNode nodePointer;

/* headPointer is a pointer to type nodePointer */
typedef referenceToNodePointer headPointer;

/* Function Prototypes.  */
void initDoubleLinkedList( headPointer hp );
int lengthDoubleLinkedList( headPointer hp );
boolean isDoubleLinkedListEmpty( headPointer hp );
void insertNodeInHead( element el, headPointer hp );
void insertNodeInQueue( element el, headPointer hp );
void printDoubleLinkedList( headPointer hp );


/* all this function have to consider the dummy node. */
element extractNodeInHead( headPointer hp );
element extractNodeInQueue( headPointer hp );
element extractNodeInMiddle( headPointer hp, nodePointer np );
headPointer freeDoubleLinkedList( headPointer hp );
