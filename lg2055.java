import java.util.*;

public class lg2055 {

    public static final int INF = 0x3f3f3f3f;

    public static int n;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int tt; tt = in.nextInt();

        while (tt-->0) {
            n = in.nextInt();

            boolean[] sch = new boolean[n+1];
            Boolean[] ret = new Boolean[n+1];

            for (int i=1; i<=n; ++i) sch[i] = in.nextInt()==1;
            for (int i=1; i<=n; ++i) ret[i] = in.nextInt()==1;

            List<ArrayList<Integer>> e = new ArrayList<ArrayList<Integer>>(n+1);
            for (int i=0; i<=n; ++i) e.add(new ArrayList<Integer>());

            int need = 0;
            for (int i=1; i<=n; ++i) {
                boolean link = ! (sch[i] && ret[i]);
                if (link) ++need;
                for (int r, j=1; j<=n; ++j) {
                    r = in.nextInt();
                    if (j==i) r = 1;
                    if (r==1 && link && sch[j]) e.get(i).add(j+n);
                }
            }

            int[] m = new int[n<<1 | 1];
            int[] d = new int[n+1];

            int matching = 0;
                while (bfs(e, m, d))
                    for(int i=1; i<=n; ++i) 
                        if (d[i]==0 && dfs(i, e, m, d))
                            ++matching;

            if (matching==need)
                System.out.println("^_^");
            else
                System.out.println("T_T");
        }
    }

    public static boolean bfs(List<ArrayList<Integer>> e, int[] m, int[] d) {
        Queue<Integer> q = new LinkedList<Integer>();
        d[0] = INF;
        for (int i=1; i<=n; ++i)
            if (m[i]!=0) 
                d[i] = INF;
            else {
                d[i] = 0;
                q.add(i);
            }
        while (!q.isEmpty()) {
            int u = q.remove();
            if (d[u]<d[0]) 
                for (int v : e.get(u))
                    if (d[m[v]]==INF) {
                        d[m[v]] = d[u] + 1;
                        q.add(m[v]);
                    }
        }
        return d[0] != INF;
    }

    public static boolean dfs(int u, List<ArrayList<Integer>> e, int[] m, int[] d) {
        if (u==0) return true;
        int dt = d[u];
        d[u] = INF;
        for (int v : e.get(u))
            if (d[m[v]]==dt+1 && dfs(m[v], e, m, d)) {
                m[u] = v; m[v] = u;
                return true;
            }
        return false;
    }
}