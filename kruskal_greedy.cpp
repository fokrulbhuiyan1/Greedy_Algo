#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//represent a weighted edge
struct Edge{
    int source, finish, weight;
};
//represent a graph
struct Graph
{   //V means vestex, E means edge
    int V, E;
    struct Edge *edge; //represent edge
};
//create a graph
struct Graph* creategraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
//subset for union-find
struct subset{
    int parent;
    int rank;
};
//find set of an element i
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}
//union of two sets of x and y
void Union(struct subset subsets[], int x, int y)
{
    int xr = find(subsets, x);
    int yr = find(subsets, y);
    //Union by Rank
    if (subsets[xr].rank < subsets[yr].rank)
        subsets[xr].parent = yr;
    else if (subsets[xr].rank > subsets[yr].rank)
        subsets[yr].parent = xr;
    //if same, then make one as root and another makes rank by one
    else
    {
        subsets[yr].parent = xr;
        subsets[xr].rank++;
    }
}
    //Compare two edges
int compare(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}


void Kruskal(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V]; //store the MST result
    int e = 0;  //used for result
    int i = 0;  //used for sorted edges
    //Sort all the edges by weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);
    //allocate memory by malloc function
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) );
    //create vestex subset
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    // Number of edges
    while (e < V - 1)
    {   //take the smallest edge.
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.source);
        int y = find(subsets, next_edge.finish);
        //if no cycle created,then insert in result
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    //print the result
    int p = 0;
    cout<<"Following are the edges in the constructed MST\n";
    for (i = 0; i < e; ++i){
        p = p+result[i].weight;
        cout<< result[i].source<<"- "<<result[i].finish<<"->"<<result[i].weight;
        cout<<endl;
    }
    cout<<"Total value: "<<p<<endl;
    return;
}
int main(){
    int V ,E;
    cout<<"Number of vertices in graph : ";
    cin>>V;
    cout<<"Number of edges in graph : ";
    cin>>E;
    struct Graph* graph = creategraph(V,E);

    for(int i=0;i<E;i++){
    cout<<"Source Node: ";
    cin>>graph->edge[i].source ;
    cout<<"Connected Node: ";
    cin>>graph->edge[i].finish ;
    cout<<"Weight of edge: ";
    cin>>graph->edge[i].weight ;
    cout<<endl;
    }

    Kruskal(graph);

    return 0;
}
