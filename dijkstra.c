#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define MAX 100
int nov, noe;
int key[MAX], parent[MAX];
int w[MAX][MAX];
bool visit[MAX];
int extractmin() {
    int min = INT_MAX, pos;
    for(int i=0; i<nov; i++) {
        if(key[i]<min && visit[i] == false) {
            min = key[i];
            pos = i;
        }
    }
    return pos;
}
void dijkstra(int src) {
    for(int i=0; i<nov; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        visit[i] = false;
    }
    key[src] = 0;
    for(int i=0; i<nov; i++) {
        int u = extractmin();
        visit[u] = true;
        printf("U = %d\n",u);
        for(int j=0; j<nov; j++) {
            if(w[u][j] != 0) {
                if(visit[j] == false && key[j] > key[u]+w[u][j]) {
                    key[j] = key[u]+w[u][j];
                    parent[j] = u;
                }
            }
        }
    }
}
void mstprint(int src)  {
    for(int i=0; i<nov; i++) {
        if(i != src) {
            printf("Edges(%c-%c)->%d\n",parent[i]+65, i+65, key[i]);
        }
    }
}
void file() {
    FILE *fp;
    fp = fopen("ip_2.txt","r");
    if(fp == NULL) {
        printf("File is empty");
    }
    fscanf(fp, "%d",&nov);
    for(int i=0; i<nov; i++) {
        printf("The adjacent of the vertix %c is : ",i+65);
        for(int j=0; j<nov; j++) {
            fscanf(fp, "%d",&w[i][j]);
            if(w[i][j] != 0) {
                printf("%c, ",j+65);
            }
        }
        printf("\n");
    }
    printf("Adjacency Matrix:\n");
    for(int i=0; i<nov; i++) {
        for(int j=0; j<nov; j++) {
            printf("%3d",w[i][j]);
        }
        printf("\n");
    }
    printf("Vertices : %d\n",nov);
    fclose(fp);
}
int main() {
    file();
    int src;
    printf("Enter the starting vertex : ");
    scanf("%d",&src);
    dijkstra(src);
    mstprint(src);

    return 0;
}