import java.util.*;

class Edge {
    public int u, v, w;

    public Edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
}

public class Main {

    public static int n, m;
    public static ArrayList<Edge> e = new ArrayList<Edge>();
    public static int[] fa, r;

    public static Boolean cmp(Edge a, Edge b) {
        return a.w > b.w;
    }

    public static int find(int x) {
        if (fa[x]==x) return x;
        int t = fa[x];
        fa[x] = find(fa[x]);
        r[x] ^= r[t];
        return fa[x];
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        for (int u,v,w,i=1; i<=m; ++i) {
            u = in.nextInt();
            v = in.nextInt();
            w = in.nextInt();
            e.add(new Edge(u, v, w));
        }

        Collections.sort(e, new Comparator<Edge>() {
            public int compare(Edge lhs, Edge rhs) {
                return lhs.w > rhs.w ? -1 : (lhs.w < rhs.w) ? 1 : 0;
            }
        });

        fa = new int[n+1];
        r  = new int[n+1];
        for (int i=0; i<n; ++i) {
            fa[i] = i;
            r[i] = 0;
        }

        int ans = 0;
        for (Edge p : e) {
            int fu = find(p.u), fv = find(p.v);
            if (fu==fv) 
                if ((r[p.u]^r[p.v])==0) {
                    ans = p.w;
                    break;
                } else {}
            else {
                fa[fu] = fv;
                r[fu] = 1 ^ r[p.v] ^ r[p.u];
            }
        }
        System.out.println(ans);
    }
};