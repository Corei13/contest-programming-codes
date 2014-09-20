struct TarjanSCC {
    int n;
    int index, totalComponents;
    VVI adj, components;
    VI idx, componentOf, st, low;
    VB inStack;
    
    TarjanSCC (int n): n(n), adj(n) {}

    void addEdge (int a, int b) {
        adj[a].push_back(b);
    }

    void DFS (int v) {
        idx[v] = index;
        low[v] = index;
        index += 1;
        st.push_back(v);
        inStack[v] = true;

        for (auto w: adj[v]) {
            if (idx[w] == -1) {
                DFS(w);
                low[v] = min(low[v], low[w]);
            } else if (inStack[w]) {
                low[v] = min(low[v], low[w]);                
            }
        }

        if (low[v] == idx[v]) {
            int w;
            components.push_back(VI());
            do {
                w = st.back();
                st.pop_back();
                inStack[w] = false;
                componentOf[w] = totalComponents;
                components[totalComponents].push_back(w);
            } while (w != v);
            totalComponents++;
        }
    }

    void buildSCC () {
        index = 0, totalComponents = 0;
        idx = VI(n,-1), low = VI(n), componentOf = VI(n), inStack = VB(n, false);
        st.clear();
        
        for (int i = 0; i < n; i++) if (idx[i] == -1) {
            DFS(i);
        }
    }
};

struct TopSort {
    int n;
    VVI adj;
    VI sorted;

    TopSort (int n): n(n), adj(n) {}

    void addEdge (int a, int b) {
        adj[a].push_back(b);
    }

    void dfs (int u, VB &marked) {
        if (marked[u]) {
            return;
        }
        for (auto v: adj[u]) {
            dfs(v, marked);
        }
        marked[u] = true;
        sorted.push_back(u);
    }

    void sort () {
        VB marked(n, false);
        sorted.clear();

        for (int i = 0; i < n; ++i) {
            dfs(i, marked);
        }
    }
};