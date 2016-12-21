#include <stdio.h>
using namespace std;
int maxHeap[300002];
int count = 0;
int parent(int i) {
  return i / 2;
}
void swapData(int i, int j) {
  int t = maxHeap[i];
  maxHeap[i] = maxHeap[j];
  maxHeap[j] = t;
}
void insert(int data) {
  int cur = count + 1;
  maxHeap[cur] = data;
  while(cur > 1 && maxHeap[cur] > maxHeap[parent(cur)]) {
    swapData(cur, parent(cur));
    cur = parent(cur);
  }
  count++;
}
int maxChild(int i) {
  if(i * 2 == count) return i * 2;
  if(maxHeap[i * 2] > maxHeap[i * 2 + 1]) {
    return i * 2;
  }
  return i * 2 + 1;
}
bool pop(int* out) {
  if(count == 0) return 0;
  int cur = count;
  *out = maxHeap[1];
  maxHeap[1] = maxHeap[count--];
  cur = 1;
  int m = maxChild(cur);
  while(m <= count && maxHeap[cur] < maxHeap[m]) {
    swapData(cur, m);
    cur = m;
    m = maxChild(m);
  }
  return 1;
}
void printHeap() {
  for(int i = 1; i <= count; i++) {
    printf("%d ", maxHeap[i]);
  }
  printf("\n");
}

main() {
  int N;
  char a;
  scanf("%d", &N);
  while(N--) {
    scanf(" %c", &a);
    switch(a) {
      case 'P': {
        int num;
        scanf("%d", &num);
        insert(num);
        break;
      }
      case 'Q': {
        int m;
        if(pop(&m)) {
          printf("%d\n", m);
        } else {
          printf("-1\n");
        }
        break;
      }
    }
  }
}
