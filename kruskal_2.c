#include<stdio.h>
#define MAX 100
int G[MAX][MAX];
typedef struct item{
    int v1,v2,wt;
}node;
node x[MAX];
// node x[] = {{0,1,7},{0,2,8},{1,3,6},{1,2,3},{2,4,3},{2,3,4},{3,4,2},{3,5,5},{4,5,2}};
int nov, noe;
int p[20];
int mst[20][3];
int k=0;
void bubble() {
    for(int i=0; i<noe-1; i++){
        for(int j=0; j<noe-i-1; j++){
            if(x[j].wt > x[j+1].wt) {
                node temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
}
void display() {
    for(int i=0; i<noe; i++) {
        printf("(%c-%c)->%d\n",x[i].v1+65, x[i].v2+65, x[i].wt);
    }
    printf("\n");
}
int find(int v) {
    while(p[v] >= 0) {
        v = p[v];
    }
    return v;
}
void Union(int i, int j) {
    p[i] = j;
}
void kruskal() {
    int i;
    for(i=0; i<nov; i++) {
        p[i] = -1;
    }
    for(i=0; i<noe; i++) {
        if(find(x[i].v1) != find(x[i].v2)) {
            Union(x[i].v1, x[i].v2);
            mst[k][0] = x[i].v1;
            mst[k][1] = x[i].v2;
            mst[k][2] = x[i].wt;
            k++;
        }
    }
}
void printmst() {
    int weight = 0;
    printf("Minimum Spanning Tree : \n");
    for(int i=0; i<k; i++) {
        printf("(%c-%c)->%d\n",mst[i][0]+65,mst[i][1]+65,mst[i][2]);
        weight = weight + mst[i][2];
    }
    printf("Total weight = %d",weight);
}
void print_ip() {
    FILE *fp;
    fp = fopen("ip_2.txt","r");
    if(fp == NULL) {
        printf("File is empty");
    }
    fscanf(fp, "%d",&nov);
    int first = 1;
    for(int i=0; i<nov; i++) {
        printf("The adjacent of the vertix %c is : ",i+65);
        for(int j=0; j<nov; j++) {
            fscanf(fp, "%d",&G[i][j]);
            if(G[i][j] != 0) {
                if(!first){
                    printf(", ");
                }
                printf("%c",j+65);
                first = 0;
            }
        }
        printf("\n");
        first = 1;
    }
    printf("Adjacency Matrix:\n");
    for(int i=0; i<nov; i++) {
        for(int j=0; j<nov; j++) {
            printf("%3d",G[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
}
void file() {
    FILE *fp;
    fp = fopen("ip_2.txt","r");
    if(fp == NULL) {
        printf("File is empty");
    }
    fscanf(fp, "%d",&nov);
    int edgeIndex = 0;
    for (int i=0; i<nov; i++) {
        for (int j=0; j<nov; j++) {
            int weight;
            fscanf(fp, "%d", &weight);
            // data
            if (weight != 0 && i < j) {
                x[edgeIndex].v1 = i;
                x[edgeIndex].v2 = j;
                x[edgeIndex].wt = weight;
                edgeIndex++;
            }
        }
    }
    noe = edgeIndex;
    printf("Vertices : %d\n",nov);
    printf("Edges : %d\n",noe);
    fclose(fp);
}
int main() {
    print_ip();
    file();
    display();
    bubble();
    display();
    kruskal();
    printmst();

    return 0;
}