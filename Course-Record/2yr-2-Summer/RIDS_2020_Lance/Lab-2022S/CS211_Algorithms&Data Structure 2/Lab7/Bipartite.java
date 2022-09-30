
import java.util.*;
import java.lang.*;
import java.io.*;

class Bipartite
{
    // This code is created by Hanlin Cai in 2022/06/24

    public static int V ; // (without knowing the sets U and V in advance)

    public static boolean isBipartite(int G[][])
    {
        int colorArray[] = new int[V];
        // For connected graph 连接图
        for (int i = 0; i < V; ++i)
            colorArray[i] = -1;

        // For disconnected graph 非连接图
        for (int i = 0; i < V; i++)
            if (colorArray[i] == -1)
                if (isBipartiteUtil(G, i, colorArray)
                        == false)
                    return false;

        return true;
    }

    public static boolean isBipartiteUtil(int G[][], int src, int colorArray[]) {

        colorArray[src] = 1;

        // BFS traversal
        LinkedList<Integer> q = new LinkedList<Integer>();
        q.add(src);

        while (!q.isEmpty()) {

            int u = q.getFirst();
            q.pop();

            if (G[u][u] == 1)
                return false;

            for (int v = 0; v < V; ++v) {
                // An edge from u to v exists and destination v is not colored
                if (G[u][v] == 1 && colorArray[v] == -1) {
                    colorArray[v] = 1 - colorArray[u];
                    q.push(v);
                }
                // An edge from u to v exists and destination v is colored with same color as u
                else if (G[u][v] == 1 && colorArray[v] == colorArray[u]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main (String[] args)
    {
        int G[][] = {
                {0, 1, 0, 1},
                {1, 0, 1, 0},
                {0, 1, 0, 1},
                {1, 0, 1, 0}
        };
        Bipartite b = new Bipartite();
        if (b.isBipartite(G))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}

// CS211 Experiment 07 Bipartite Graph
// This code is created by Hanlin Cai in 2022/06/24
// MU number : 20122161
// FZU number: 832002117