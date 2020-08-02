#include <bits/stdc++.h> 
using namespace std; 
#define N 1024 
  
int tree[N][N];  
struct treeNode 
{ 
    int par;   
    int depth; 
    int size;   
    int pos_segbase; 
    int chain; 
} node[N]; 
  
struct Edge 
{ 
    int weight; 
    int deeper_end; 
} edge[N]; 
  
struct segmentTree 
{ 
    int base_array[N], tree[6*N]; 
} s; 
  

void addEdge(int e, int u, int v, int w) 
{ 
    tree[u-1][v-1] = e-1; 
    tree[v-1][u-1] = e-1; 
    edge[e-1].weight = w; 
} 

void dfs(int curr, int prev, int dep, int n) 
{ 
    node[curr].par = prev; 
    node[curr].depth = dep; 
    node[curr].size = 1; 
    for (int j=0; j<n; j++) 
    { 
        if (j!=curr && j!=node[curr].par && tree[curr][j]!=-1) 
        { 
            edge[tree[curr][j]].deeper_end = j; 
            dfs(j, curr, dep+1, n); 
            node[curr].size+=node[j].size; 
        } 
     } 
} 
  
void hld(int curr_node, int id, int *edge_counted, int *curr_chain, 
         int n, int chain_heads[]) 
{ 
 
    if (chain_heads[*curr_chain]==-1) 
        chain_heads[*curr_chain] = curr_node; 
  
    node[curr_node].chain = *curr_chain; 
  
    node[curr_node].pos_segbase = *edge_counted; 
  
    s.base_array[(*edge_counted)++] = edge[id].weight; 
  
    int spcl_chld = -1, spcl_edg_id; 
    for (int j=0; j<n; j++) 
      if (j!=curr_node && j!=node[curr_node].par && tree[curr_node][j]!=-1) 
        if (spcl_chld==-1 || node[spcl_chld].size < node[j].size) 
           spcl_chld = j, spcl_edg_id = tree[curr_node][j]; 
  
    if (spcl_chld!=-1) 
      hld(spcl_chld, spcl_edg_id, edge_counted, curr_chain, n, chain_heads); 
  
    for (int j=0; j<n; j++) 
    { 
      if (j!=curr_node && j!=node[curr_node].par && j!=spcl_chld && tree[curr_node][j]!=-1) 
      { 
        (*curr_chain)++; 
        hld(j, tree[curr_node][j], edge_counted, curr_chain, n, chain_heads); 
      } 
    } 
} 
  

int construct_ST(int i, int j, int si) 
{ 
    
    if (i == j-1) 
    { 
        s.tree[si] = s.base_array[i]; 
        return s.base_array[i]; 
    } 
  
    int mid = (i + j)/2; 
    s.tree[si] =  max(construct_ST(i, mid, si*2), 
                      construct_ST(mid, se, si*2+1)); 
    return s.tree[si]; 
} 
  

int update_ST(int i, int j, int a, int b, int val) 
{ 
  
    if(i > b || j <= b);  
    else 
    	if(i == b && i == j-1)
    		s.tree[a] = val; 
	    else
	    { 
	        int mid = (i + j)/2; 
	        s.tree[a] =  max(update_ST(i, mid, a*2, b, val), 
	                         update_ST(mid, j, a*2+1, b, val)); 
	    } 
  
    return s.tree[a]; 
} 
 
   // update_ST(0, n, 1, node[edge[e].deeper_end].pos_segbase, val); 
  
 int LCA(int u, int v, int n) 
{ 
    int LCA_aux[n+5]; 
    if (node[u].depth < node[v].depth) 
       swap(u, v); 
  
    memset(LCA_aux, -1, sizeof(LCA_aux)); 
  
    while (u!=-1) 
    { 
        LCA_aux[u] = 1; 
        u = node[u].par; 
    } 
    while (v) 
    { 
        if (LCA_aux[v]==1)break; 
        v = node[v].par; 
    } 
  
    return v; 
} 
  
int RMQ(int i, int j, int a, int b, int index) 
{ 
    
    if (a <= i && b >= j-1) 
        return s.tree[index]; 
      if (j-1 < a || i > b) 
        return -1; 
      int mid = (i + j)/2; 
    return max(RMQUtil(i, mid, a, b, 2*index), 
               RMQUtil(mid, j, a, b, 2*index+1)); 
} 

int crawl_tree(int u, int v, int n, int chain_heads[]) 
{ 
    int chain_u, chain_v = node[v].chain, ans = 0; 
  
    while (true) 
    { 
        chain_u = node[u].chain; 
        if (chain_u==chain_v) 
        { 
            if (u==v);  
            else
              ans = max(RMQ(0, n, node[v].pos_segbase+1, node[u].pos_segbase, 1), 
                        ans); 
            break; 
        } 
        else
        { 
            ans = max(ans, 
                      RMQ(0, n, node[chain_heads[chain_u]].pos_segbase, 
                          node[u].pos_segbase, 1)); 
  
            u = node[chain_heads[chain_u]].par; 
        } 
    } 
  
    return ans; 
} 
  
void maxEdge(int u, int v, int n, int chain_heads[]) 
{ 
    int lca = LCA(u, v, n); 
    int ans = max(crawl_tree(u, lca, n, chain_heads), 
                  crawl_tree(v, lca, n, chain_heads)); 
    printf("%d\n", ans); 
} 
void change(int e, int val, int n) 
{ 
    update_ST(0, n, 1, node[edge[e].deeper_end].pos_segbase, val); 
}
int main() 
{ 
    memset(tree, -1, sizeof(tree)); 
  
    int n = 11; 
    addEdge(1, 1, 2, 13); 
    addEdge(2, 1, 3, 9); 
    addEdge(3, 1, 4, 23); 
    addEdge(4, 2, 5, 4); 
    addEdge(5, 2, 6, 25); 
    addEdge(6, 3, 7, 29); 
    addEdge(7, 6, 8, 5); 
    addEdge(8, 7, 9, 30); 
    addEdge(9, 8, 10, 1); 
    addEdge(10, 8, 11, 6); 
    int root = 0, parent_of_root=-1, depth_of_root=0; 
    dfs(root, parent_of_root, depth_of_root, n); 
  
    int chain_heads[N]; 
  
    memset(chain_heads, -1, sizeof(chain_heads)); 
    int edge_counted = 0; 

    int curr_chain = 0; 

    hld(root, n-1, &edge_counted, &curr_chain, n, chain_heads); 

    construct_ST(0, edge_counted, 1); 

    int u = 11, v  = 9; 
    cout << "Max edge between " << u << " and " << v << " is "; 
    maxEdge(u-1, v-1, n, chain_heads); 
  

    change(8-1, 28, n); 
  
    cout << "After Change: max edge between " << u << " and "
         << v << " is "; 
    maxEdge(u-1, v-1, n, chain_heads); 
  
    v = 4; 
    cout << "Max edge between " << u << " and " << v << " is "; 
    maxEdge(u-1, v-1, n, chain_heads); 
  
    // Change value of edge number 5 (index 5-1) to 22 
    change(5-1, 22, n); 
    cout << "After Change: max edge between " << u << " and "
         << v << " is "; 
    maxEdge(u-1, v-1, n, chain_heads); 
  
    return 0; 
} 
