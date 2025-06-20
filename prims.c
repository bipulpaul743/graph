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
        // printf("key[i] = %d, i = %d\n",key[i],i);
        // printf("min = %d\n",min);
        if(key[i]<min && visit[i] == false) {
            min = key[i];
            // printf("updated min = %d\n",min);
            pos = i;
            // printf("pos = %d\n\n",pos);
        }
    }
    return pos;
}
void prims(int src) {
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
            // printf("if w[u][j] = %d, u = %d, j = %d\n",w[u][j],u,j);
            if(w[u][j] != 0) {
                // printf("if key[j] = %d, j = %d\n",key[j],j);
                // printf("if w[u][j] = %d, u = %d, j = %d\n\n",w[u][j],u,j);
                if(visit[j] == false && key[j] > w[u][j]) {
                    key[j] = w[u][j];
                    // printf("updated key[j] = %d, j = %d\n",key[j],j);
                    parent[j] = u;
                    // printf("updated parent[j] = %d, j = %d\n\n",parent[j],j);
                }
            }
        }
    }
}
void mstprint(int src)  {
    int weight = 0;
    for(int i=0; i<nov; i++) {
        if(i != src) {
            printf("Edges(%c-%c)->%d\n",parent[i]+65, i+65, key[i]);
            weight = weight+key[i];
        }
    }
    printf("Total weight = %d",weight);
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
    prims(src);
    mstprint(src);
    
    return 0;
}