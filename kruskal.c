#include<stdio.h>
typedef struct item{
    int v1,v2,wt;
}node;
node x[] = {{0,1,7},{0,2,8},{1,3,6},{1,2,3},{2,4,3},{2,3,4},{3,4,2},{3,5,5},{4,5,2}};
int nov = 6;
int noe = 9;
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
        printf("(%c-%c)->%d\n",x[i].v1+65,x[i].v2+65,x[i].wt);
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
    for(int i=0; i<k; i++) {
        printf("(%c-%c)->%d\n",mst[i][0]+65,mst[i][1]+65,mst[i][2]);
        weight = weight + mst[i][2];
    }
    printf("Total weight = %d",weight);
}

int main() {
    display();
    bubble();
    display();
    kruskal();
    printmst();

    return 0;
}