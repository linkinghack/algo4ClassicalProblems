#pragma once

struct Heap {
    int *elements;
    int size;
    int capacity;
};

enum BigSmall {
    BIG,SMALL
};

void Sink(Heap* heap, int i, BigSmall bm);
bool IsFull(Heap* heap);
bool IsEmpty( Heap* H );

Heap* CreateMaxHeap( int MaxSize );
void InsertMaxHeap( Heap* maxheap, int item);
int DeleteMaxHeap( Heap* H);

Heap* CreateMinHeap( int MaxSize );
void InsertMinHeap( Heap* minheap, int item);
int DeleteMinHeap( Heap* H);

void BuildMinHeap(Heap* heap);
void BuildMaxHeap(Heap* heap);