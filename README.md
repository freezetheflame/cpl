# The preparation for CPL FINALS
***by scotchingice 2022-23 cpl SE test***
>今年我把已经解禁的情报重新列举在这里，重点保真，但是我们还是侧重于考察能力，也就是说考察具体的某些内容的题目几乎没有，复习这些内容可能可以让你做得更快一点，把时间留给最后的 T3 或 T4。
>T1 会考察一种课上讲过或提及过的排序方法（选择排序、冒泡排序、插入排序、归并排序中的一趟归并 之一）。
>T2 会从平时的 OJ 作业 3-for-a-while 、5-function、7-data-types 中选择一道作业题（除去 7 的 C 题 倒水游戏）改编。
>同学们可以猜猜 T3 考什么。
>T4 依然是指针 + 链表，可以结合 10-Struct & 11-Linkedlist 及最后一次题解提到的内容复习。
>期末机试不考察递归。
>---
>                   from SA
下面主要罗列总结一些思想方法和封装好的代码块

1.merge_sort的merge和sort
```
void merge(int l, int mid, int r) {
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if ((j > r && i <= mid) || (i <= mid && a[i] <= a[j])) {
            b[k] = a[i++];
        }
        else {
            b[k] = a[j++];
        }
    }
    for (int k = l; k <= r; ++k) {
        a[k] = b[k];
    }
}
```
```
void mergeSort(int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, r);
}
```
2.swap的指针使用（其实很简单）
```
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
```
3.选择排序核心部分
```
for (int i = 1; i < n; ++i) {
        int minx = a[i], minpos = i;//每次都从无序位i开始找最小的丢到i+1位
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] < minx) {
                minx = a[j];
                minpos = j;
            }
        }
        swap(&a[minpos], &a[i]);
    }
```
4.插入排序
```
for (int i = 2; i <= n; ++i) {
    int key = a[i], j = i - 1;
    while (a[j] > key && j >= 1) {
         a[j + 1] = a[j];
         --j;
    }
    a[j + 1] = key;
}
```
5.链表的基本操作
```
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// 初始化链表头
Node* initList() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}
//注：根据需求修改链表NODE结构体的内容
// 添加元素到链表末尾
void add(Node* head, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    Node* p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = node;
}

// 删除链表中指定元素
void removeNode(Node* head, int data) {
    Node* p = head;
    while (p->next) {
        if (p->next->data == data) {
//or strcmp if data is a string
            Node* q = p->next;
            p->next = q->next;
            free(q);
            return;
        }
        p = p->next;
    }
}

// 在指定位置插入元素
void insert(Node* head, int index, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    Node* p = head;
    int i = 0;
    while (p->next && i < index) {
        p = p->next;
        i++;
    }
    node->next = p->next;
    p->next = node;
}

// 打印链表中的所有元素
void printList(Node* head) {
    Node* p = head->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 释放链表内存
void freeList(Node* head) {
    Node* p = head;
    while (p) {
        Node* q = p->next;
        free(p);
        p = q;
    }
}
```