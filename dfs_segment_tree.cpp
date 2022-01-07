void dfs(int node) {
    used[node]=true;
    pos[node]=++sz;
    from[node]=sz;
    to[node]=sz;
    int i;
    for(i=0;i<(int)(v[node].size());i++) {
        if(!used[v[node][i]]) dfs(v[node][i]),to[node]=max(to[node],to[v[node][i]]);
    }
}

//Now pos[X] will be the index of X in the array and [ from[X];to[X] ] will be the subtree of X