import java.util.*;

public class lg1197 {

    static ArrayList<ArrayList<Integer>> e = new ArrayList<ArrayList<Integer>>();

    static int cc;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, m, k;

        n = in.nextInt(); m = in.nextInt();

        for (int i=0; i<=n; ++i)
            e.add(new ArrayList<Integer>());

        for (int u,v,i=0; i<m; ++i) {
            u = in.nextInt(); v = in.nextInt();
            ++u; ++v;
            e.get(u).add(v);
            e.get(v).add(u);
        }

        k = in.nextInt();

        boolean[] st = new boolean[n+1];
        Arrays.fill(st, true);
        ArrayList<Integer> del = new ArrayList<Integer>();
        for (int x,i=0; i<k; ++i) {
            x = in.nextInt();
            ++x;
            del.add(x);
            st[x] = false;
        }

        int[] fa = new int[n+1];
        for (int i=1; i<=n; ++i) fa[i] = i;

        cc = 0;
        for (int u=1; u<=n; ++u)
            if (st[u]) {
                ++cc;
                for (int v : e.get(u))
                    if (st[v])
                        merge(fa, u, v);
            }
        ArrayList<Integer> ans = new ArrayList<Integer>();
        ans.add(cc);
        for (int i=del.size()-1; i>=0; --i) {
            ++cc;
            st[del.get(i)] = true;
            for (int v : e.get(del.get(i)))
                if (st[v])
                    merge(fa, del.get(i), v);
            ans.add(cc);
        }

        for (int i=ans.size()-1; i>=0; --i) 
            System.out.println(ans.get(i));
    }

    static int find(int[] fa, int x) {
        return (fa[x]==x) ? x : (fa[x]=find(fa, fa[x]));
    }

    static void merge(int[] fa, int u, int v) {
        int fu=find(fa, u), fv=find(fa, v);
        if (fu!=fv) {
            fa[fu] = fv;
            --cc;
        }
    }
}