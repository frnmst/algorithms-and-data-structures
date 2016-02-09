/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef ADT_H
#define ADT_H
#include "adt.h"
#endif


/* Init the list with a dummy node that points himself */
void initDoubleLinkedList( headPointer hp )
{
    /* insert a dummy node */
    *hp = malloc( sizeof( struct graphElement ) );

    /* setup his next and prec pointers to itself */
    ( *hp )->next = ( *hp );
    ( *hp )->prev = ( *hp );

    return;
}

/* Calculante list length, if only the dummy node is present,
 * than length( head ) == 0;
 */
int lengthDoubleLinkedList( headPointer hp )
{
    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;

    int size = 0;

    while ( succNode != refToDummy ) {
        succNode = succNode->next;
        size = size + 1;
    }

    return size;
}

/* Tells if the list is EMPTY using lenght() */
boolean isDoubleLinkedListEmpty( headPointer hp )
{
    return lengthDoubleLinkedList( hp ) == 0 ? true : false;
}

nodePointer searchVertex( char *nameToSearch, headPointer hp )
{

    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;
    nodePointer foundNode = EMPTY;


    /* Begin scan */
    while ( succNode != refToDummy ) {
        if ( strcmp( succNode->name, nameToSearch ) == 0 ) {
            foundNode = succNode;
        }
        succNode = succNode->next;
    }

    return foundNode;
}

nodePointer searchEdge( nodePointer fromNode, nodePointer toNode,
                        headPointer hp )
{

    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;
    nodePointer foundNode = EMPTY;

    /* Begin scan */
    while ( succNode != refToDummy ) {
        if ( ( succNode->fromNode == fromNode )
             && ( succNode->toNode == toNode ) ) {
            foundNode = succNode;
        }
        succNode = succNode->next;
    }

    return foundNode;
}

/* Insert a vertex before the dummy node */
nodePointer newVertex( char *name, headPointer hp )
{
    nodePointer foundVertex;
    nodePointer dummy = *hp;
    nodePointer newNode;



    /* every edge node in list must have an atomic value  */
    foundVertex = searchVertex( name, hp );
    if ( foundVertex != EMPTY ) {
        printf( "The vertex \"%s\" already exists! Pay Attention!\n\n",
                name );
        return foundVertex;
    }

    /* allocate memory for the node */
    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* Insert vetex name.  */
    newNode->name = name;

    newNode->edgeListOut = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( newNode->edgeListOut );

    newNode->edgeListIn = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( newNode->edgeListIn );

    /* Fix list pointers.  */
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return newNode;
}

/* Insert an edge before the dummy node */
nodePointer newEdge( weight w, nodePointer fromNode, nodePointer toNode,
                     headPointer hp )
{
    nodePointer foundEgde;
    nodePointer dummy = *hp;
    nodePointer newNode;

    /* every edge node in list must have an atomic value */
    foundEgde = searchEdge( fromNode, toNode, hp );
    if ( foundEgde != EMPTY ) {
        printf
            ( "The edge from \"%s\" to \"%s\" already exists! Pay Attention!\n\n",
              fromNode->name, toNode->name );
        return foundEgde;
    }


    /* allocate memory for the node */
    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* Insert edge info.  */
    newNode->w = w;
    newNode->fromNode = fromNode;
    newNode->toNode = toNode;

    /* Fix list pointers.  */
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return newNode;
}

nodePointer connectVertex( headPointer edgehp,
                           nodePointer fromNode, nodePointer toNode,
                           weight w )
{
    nodePointer edgeP;

    edgeP = newEdge( w, fromNode, toNode, edgehp );

    /* from -> out && to -> In.  */
    insertEdgeInList( edgeP, fromNode->edgeListOut );
    insertEdgeInList( edgeP, toNode->edgeListIn );

    return edgeP;
}

void insertEdgeInList( nodePointer np, headPointer hp )
{
    nodePointer dummy = *hp;
    nodePointer newNode;


    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    newNode->edgeAddr = np;

    /* fix list pointers */
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return;
}

void printNodeEdges( headPointer hp )
{
    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;

    if ( isDoubleLinkedListEmpty( hp ) ) {
        printf( "No edges\n" );
        return;
    }

    while ( succNode != refToDummy ) {
        printf( "%d ", ( succNode->edgeAddr )->w );
        succNode = succNode->next;
    }
    printf( "\n" );

    return;
}
