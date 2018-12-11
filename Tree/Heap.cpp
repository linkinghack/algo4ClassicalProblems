#include <iostream>
#include <climits>
#include "Heap.hpp"

/* 创建大顶堆*/
Heap* CreateMaxHeap( int MaxSize ) {
    Heap* maxheap = new Heap;
    maxheap->elements = new int[MaxSize+1];

    maxheap->size = 0;
    maxheap->capacity = MaxSize;
    maxheap->elements[0] = INT_MAX; // 便于操作
}

/* 创建小顶堆*/
Heap* CreateMinHeap( int MaxSize ) {
    Heap* minheap = new Heap;
    minheap->elements = new int[MaxSize+1];

    minheap->size = 0;
    minheap->capacity = MaxSize;
    minheap->elements[0] = INT_MIN; // 便于操作
}

/* 将一个非严格的堆调整为小顶堆*/
void BuildMinHeap( Heap* heap ) {
    int sinkjudge = heap->size / 2; // 第一个存在子结点的结点位置
    for(; sinkjudge > 0; sinkjudge--) { // 一次往前进行一次下沉操作
        Sink(heap, sinkjudge, BIG);
    }
}

/* 将一个非严格的堆调整为小顶堆*/
void BuildMaxHeap( Heap* heap ) {
    int sinkjudge = heap->size / 2; // 第一个存在子结点的结点位置
    for(; sinkjudge > 0; sinkjudge--) { // 依次往前进行一次下沉操作
        Sink(heap, sinkjudge, SMALL);
    }
}

// for build heap
void Sink(Heap* heap, int i, BigSmall bm){
    if(i<=0) return;

    int child, parent;
    int temp = heap->elements[i];
    if(bm == BIG) {
        // 大值下沉
        for( parent = i; parent * 2 <= H->size; parent=child) {
            child = parent * 2; // 先测试左子结点
            if ( (child != H->size) && 
                (H->elements[child] > H->elements[child+1]) )
                child++; // 测试右子结点
            // child已指向 左右 子结点中的较小者
            if ( temp <= H->elements[child] ) break; // 当前位置比左右子结点都小，位置已找到
            else // 将子结点上提
                H->elements[parent] = H->elements[child];
        }
        heap->elements[child] = temp;
    }else {
        // 小值下沉
        for( parent = i; parent * 2 <= H->size; parent=child) {
            child = parent * 2; // 先测试左子结点
            if ( (child != H->size) && 
                (H->elements[child] < H->elements[child+1]) )
                child++; // 测试右子结点
            // child已指向 左右 子结点中的较大者
            if ( temp >= H->elements[child] ) break; // 当前位置比左右子结点都大，位置已找到
            else // 将子结点上提
                H->elements[parent] = H->elements[child];
        }
        heap->elements[child] = temp;
    }
}

/*大顶堆插入操作
 * O(log N)
 */
void InsertMaxHeap( Heap* maxheap, int item) {
    int i;
    if ( IsFull(maxheap) ) {
        std::cout<<"Heap full..."<<std::endl;
        return;
    }
    
    i = ++ maxheap->size;

    // 插入始终按照层序递增的方式添加进入完全二叉树
    // 故从elements[size] 开始
    // 从添加位置开始不断向上浮动，以保证满足大顶堆大小约束
    // 使用数组层序保存的完全二叉树，父节点位置为 i/2
    for( ; maxheap->elements[i/2] < item; i/=2){
        // 若在存储中没有elements[0] 号位的哨兵
        // 循环条件还应该 && i>1
        maxheap->elements[i] = maxheap->elements[i/2]; 
    }

    maxheap->elements[i] = item; // 找到合适位置，落下待插入数据
}

/*小顶堆插入操作
 * O(log N)
 */
void InsertMinHeap( Heap* minheap, int item) {
    int i;
    if ( IsFull(minheap) ) {
        std::cout<<"Heap full..."<<std::endl;
        return;
    }
    
    i = ++ minheap->size;

    for( ; minheap->elements[i/2] > item; i/=2){
        minheap->elements[i] = minheap->elements[i/2]; 
    }

    minheap->elements[i] = item; // 找到合适位置，落下待插入数据
}

int DeleteMaxHeap( Heap* H) {
    int parent, child;
    int MaxItem, temp;
    if ( IsEmpty(H) ) {
        std::cout<<"heap empty..."<<std::endl;
        return;
    }

    MaxItem = H->elements[1]; // 保存待删除数据
    temp = H->elements[H->size--]; // 即将被上提的层序最后元素

    // 下沉操作,为temp找一个合适的落脚位置
    for( parent = 1; parent * 2 <= H->size; parent=child) {
        child = parent * 2; // 先测试左子结点
        if ( (child != H->size) && 
            (H->elements[child] < H->elements[child+1]) )
            child++; // 测试右子结点
        // child已指向 左右 子结点中的较大者
        if ( temp >= H->elements[child] ) break; // 当前位置比左右子结点都大，位置已找到
        else // 将子结点上提
            H->elements[parent] = H->elements[child];
    }

    H->elements[parent] = temp;
    return MaxItem;
}

int DeleteMinHeap( Heap* H ) {
    int parent, child;
    int MinItem, temp;
    if ( IsEmpty(H) ) {
        std::cout<<"heap empty..."<<std::endl;
        return;
    }

    MinItem = H->elements[1]; // 保存待删除数据
    temp = H->elements[H->size--]; // 即将被上提的层序最后元素

    for( parent = 1; parent * 2 <= H->size; parent=child) {
        child = parent * 2; // 先测试左子结点
        if ( (child != H->size) && 
            (H->elements[child] > H->elements[child+1]) )
            child++; // 测试右子结点

        if ( temp <= H->elements[child] ) break; 
        else // 将子结点上提
            H->elements[parent] = H->elements[child];
    }

    H->elements[parent] = temp;
    return MinItem;
}

bool IsEmpty( Heap* H ) {
    if(H->size <= 0)
        return true;
    else return false;
}

bool IsFull(Heap* heap){
    if(heap->size >= heap->capacity)
        return true;
    else
        return false;
}