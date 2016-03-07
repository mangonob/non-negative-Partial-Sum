//
//  main.cpp
//  non-negative Partial Sum
//
//  Created by ManGo on 16/3/7.
//  Copyright © 2016年 ManGo. All rights reserved.
//

#include <stdio.h>
#define MAX 10000000

int n, head, rear, ans;

int q[MAX];
int a[MAX];

void enqueue(int i) {
    while(head <= rear && a[q[rear]] >= a[i]) rear --;
    q[++rear] = i;
}

void dequeue(int i) {
    if (q[head] < i - n + 1) head++;
}

int main(int argc, const char * argv[]) {
    while(scanf("%d", &n), n != 0) {
        head = 0; rear = -1; ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            a[i + n] = a[i];
        }
        
        for (int i = 2; i <= 2 * n; i++) a[i] += a[i - 1];
        for (int i = 1; i < n ; i++) {
            enqueue(i);
        }
        
        for (int i = n ; i < 2 * n; i++) {
            enqueue(i);
            dequeue(i);
            
            if(a[q[head]] - a[i - n] >= 0) ans ++;
        }
        
        printf("%d\n", ans);
    }
    
    
    return 0;
}
