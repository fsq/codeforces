import java.util.*;

class Node {
    public ArrayList<Integer> N;
    public int e, p, h;
    public Node() {
        h = e = p = 0;
        N = new ArrayList<Integer>();
    }
}

public class lg1345 {
    static int n, m, s, t, INF;
    static int[][] f = new int[303][303];
    static int[][] c = new int[303][303];
    static Node[]  V = new Node[303];

    public static void link(int u, int v, int cap) {
        c[u][v] = cap;
        V[u].N.add(v);
        V[v].N.add(u);
    }

    public static int cf(int u, int v) {
        return c[u][v] - f[u][v] + f[v][u];
    }

    public static void _push(int u, int v, int c) {
        f[u][v] += c;
        V[u].e -= c;
        V[v].e += c;
    }

    public static void push(int u, int v) {
        int fl = Math.min(V[u].e, cf(u, v));
        if (f[v][u]>0) _push(v, u, -fl);
              else     _push(u, v, fl);   
    }

    public static void relabel(int u) {
        V[u].h = n << 1;
        for (int v : V[u].N)
            if (cf(u, v)>0)
                V[u].h = Math.min(V[u].h, V[v].h+1);
    }

    public static void discharge(int u) {
        for (Node N=V[u]; N.e>0; )
            if (N.p==N.N.size()) {
                relabel(u);
                N.p = 0;
            } else {
                int v = N.N.get(N.p);
                if (V[v].h+1==N.h && cf(u, v)>0)
                    push(u, v);
                else
                    ++N.p;
            }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        s = in.nextInt();
        t = in.nextInt();
        INF = n;
        for (int i=1; i<=(n<<1); ++i) V[i] = new Node();

        for (int u,v,i=1; i<=m; ++i) {
            u = in.nextInt(); v = in.nextInt();
            link(u+n, v, INF);
            link(v+n, u, INF);
        }
        for (int i=1; i<=n; ++i) {
            int cap = i==s || i==t ? INF : 1;
            c[i][i+n] = c[i+n][i] = cap;
            V[i].N.add(i+n); V[i+n].N.add(i);
        }
        t += n;
        n <<= 1;
        V[s].h = n;
        for (int v : V[s].N) _push(s, v, c[s][v]);

        LinkedList<Integer> ls = new LinkedList<Integer>();
        for (int i=1; i<=n; ++i)
            if (i!=s && i!=t)
                ls.add(i);
        for (Iterator<Integer> it=ls.iterator(); it.hasNext(); ) {
            int u = it.next(), h = V[u].h;
            discharge(u);
            if (V[u].h != h) {
                it.remove();
                ls.addFirst(u);
                it = ls.iterator();
                it.next();
            }
        }

        System.out.println(V[t].e);
    }
}