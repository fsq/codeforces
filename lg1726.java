import java.util.*;

public class lg1726 {

    public static void dfs(int x, List<ArrayList<Integer>> e, 
                           boolean[] vis, ArrayList<Integer> a) {
        vis[x] = true;
        for (int v : e.get(x))
            if (!vis[v])
                dfs(v, e, vis, a);
        a.add(x);
    }

    public static boolean smaller(ArrayList<Integer> a, ArrayList<Integer> b) {
        for (int i=0; i<a.size(); ++i)
            if (a.get(i)<b.get(i))
                return true;
            else if (a.get(i)>b.get(i))
                return false;
            return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n, m;
        n = in.nextInt();
        m = in.nextInt();

        List<ArrayList<Integer>> e  = new ArrayList<ArrayList<Integer>>(n+1);
        List<ArrayList<Integer>> et = new ArrayList<ArrayList<Integer>>(n+1);

        for (int i=0; i<=n; ++i) {
            e.add(new ArrayList<Integer>());
            et.add(new ArrayList<Integer>());
        }

        for (int a,b,t,i=1; i<=m; ++i) {
            a = in.nextInt(); b = in.nextInt(); t = in.nextInt();
            if (t==1) {
                e.get(a).add(b);
                et.get(b).add(a);
            } else {
                e.get(a).add(b); e.get(b).add(a);
                et.get(a).add(b); et.get(b).add(a);
            }
        }

        ArrayList<Integer> ord = new ArrayList<Integer>();
        boolean[] vis = new boolean[n+1];
        for (int i=1; i<=n; ++i) 
            if (!vis[i])
                dfs(i, e, vis, ord);

        Arrays.fill(vis, false);
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for (int i=ord.size()-1; i>=0; --i)
            if (!vis[ord.get(i)]) {
                ArrayList<Integer> cc = new ArrayList<Integer>();
                dfs(ord.get(i), et, vis, cc);
                Collections.sort(cc);
                if (cc.size()>ans.size() || 
                        (cc.size()==ans.size() && smaller(cc, ans)))
                    ans = cc;
            }
        System.out.println(ans.size());
        for (int x : ans) 
            System.out.print(x+" ");
    }
}