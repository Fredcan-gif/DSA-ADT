#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// initVHeap
void initVHeap(VHeap *test_heap){
    for(int i = 0; i < MAX_SIZE - 1; i++){
        test_heap->H[i].next = i + 1;
    }
    test_heap->H[MAX_SIZE - 1].next = -1;
    test_heap->avail = 0;
}

// alloc
int alloc(VHeap *test_heap){
    if(test_heap->avail == -1){
        return -1;
    }
    int idx = test_heap->avail;
    test_heap->avail = test_heap->H[idx].next;
    return idx;
}

// dealloc
void dealloc(VHeap *test_heap, int idx){
    test_heap->H[idx].next = test_heap->avail;
    test_heap->avail = idx;
}

// insertArticle
int insertArticle(VHeap *test_heap, int *test_L, Article art, int pos){
    static int nextId = 1;
    int newNode = alloc(test_heap);
    if(newNode == -1){
        printf("Error: Heap is full. Cannot insert new article.\n");
        return 0; 
    }
    
    art.id = nextId++;
    test_heap->H[newNode].article = art;
    test_heap->H[newNode].next = -1;
    
    if(*test_L == -1){
        *test_L = newNode;
    }else if(pos == 0){
        test_heap->H[newNode].next = *test_L;
        *test_L = newNode;
    }else if(pos == -1){
        int curr = *test_L;
        while(test_heap->H[curr].next != -1){
            curr = test_heap->H[curr].next;
        }
        test_heap->H[curr].next = newNode;
    }else{
        int curr = *test_L, prev = -1, i = 0;
        while(curr != -1 && i < pos){
            prev = curr;
            curr = test_heap->H[curr].next;
            i++;
        }
        if(prev != -1){
            test_heap->H[newNode].next = curr;
            test_heap->H[prev].next = newNode;
        }
    }
    return 1;
}

// viewArticles
void viewArticles(VHeap test_heap, int test_L){
    if(test_L == -1){
        printf("The knowledge base is empty.\n");
        return;
    }
    printf("\n--- List of Articles ---\n");
    int curr = test_L;
    while (curr != -1){
        printf("ID: %d | Title: %s\n", test_heap.H[curr].article.id, test_heap.H[curr].article.title);
        curr = test_heap.H[curr].next;
    }
    printf("------------------------\n\n");
}

// searchArticle
void searchArticle(VHeap test_heap, int test_L, int non_existent_id){
    int curr = test_L;
    while(curr != -1){
        if(test_heap.H[curr].article.id == non_existent_id){
            printf("\n--- Article Found ---\n");
            printf("ID: %d\n", test_heap.H[curr].article.id);
            printf("Title: %s\nContent: %s\n", test_heap.H[curr].article.title, test_heap.H[curr].article.content);
            printf("---------------------\n\n");
            return;
        }
        curr = test_heap.H[curr].next;
    }
    printf("Article with ID %d not found.\n", non_existent_id);
    printf("\n");
}

// deleteArticle
int deleteArticle(VHeap *test_heap, int *test_L, int id){
    int curr = *test_L, prev = -1;
    while (curr != -1){
        if(test_heap->H[curr].article.id == id){
            if(prev == -1){
                *test_L = test_heap->H[curr].next;
                printf("Article with ID %d deleted successfully.\n\n", test_heap->H[curr].article.id);
            }else {
                test_heap->H[prev].next = test_heap->H[curr].next;
                printf("Article with ID %d deleted successfully.\n\n", test_heap->H[curr].article.id);
            }
            dealloc(test_heap, curr);
            return -1;
        }
        prev = curr;
        curr = test_heap->H[curr].next;
    }
    printf("Article with ID %d not found.\n\n", id);
    return 0;
}
