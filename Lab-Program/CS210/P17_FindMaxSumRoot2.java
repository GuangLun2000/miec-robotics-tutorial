package MIEC_CS210;

import java.util.Scanner;

class edge {
    int v, next;
}

public class P17_FindMaxSumRoot2 {
    static int len = 0;
    static int eid = 0;
    static int ans = 0;
    static int ansu = -1;
    static int[] a = new int[100];
    static int[] p = new int[100];
    static int[] val = new int[100];
    static int[] fa = new int[100];
    static edge[] e = new edge[200];

    static void init() {
        for (int i = 0; i < 100; i++) {
            a[i] = 0;
            p[i] = -1;
        }
        for (int i = 0; i < 200; i++) {
            e[i] = new edge();
        }
    }

    static void insert(int u, int v) {
        e[eid].v = v;
        e[eid].next = p[u];
        p[u] = eid++;
    }

    static void dfs(int u, int pre) {
        int ch = 0;
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
//            System.out.println(v);
            if (v != pre) {
                ch++;
                val[v] = val[u] + a[v];
                fa[v] = u;
                dfs(v, u);
            }
        }
        if (ch == 0) {
            if (val[u] > ans) {
                ans = val[u];
                ansu = u;
            }
        }
    }

    public static void main(String[] args) {
        init();
        Scanner sc = new Scanner(System.in);
        String input1 = sc.nextLine();
        input1 = input1.replace(" ", "");
        String[] temp1 = input1.split(",");
        len = temp1.length;
        for (int i = 0; i < len; i++) {
            a[i] = Integer.parseInt(temp1[i]);
        }
        for (int i = 0; i < len; i++) {
            if (a[i] != 0) {
                if (a[2 * i + 1] != 0) {
                    insert(i, 2 * i + 1);
                    insert(2 * i + 1, i);
                }
                if (a[2 * i + 2] != 0) {
                    insert(i, 2 * i + 2);
                    insert(2 * i + 2, i);
                }
            }
        }
        val[0] = a[0];
        fa[0] = -1;
        dfs(0, -1);
        int[] s = new int[100];
        int top = 0;
        do {
            s[top++] = ansu;
            ansu = fa[ansu];
        } while (ansu != 0);
        s[top++] = 0;
        System.out.print("Max sum is ");
        System.out.print(ans);
        System.out.print(", with a path [");
        boolean st = true;
        while (top != 0) {
            if (!st) {
                System.out.print(", ");
            }
            System.out.print(a[s[--top]]);
            st = false;
        }
        System.out.print("]");
    }
}