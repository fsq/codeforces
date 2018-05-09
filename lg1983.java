import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, m;

        n = in.nextInt();
        m = in.nextInt();

        int[][] a = new int[n+1][n+1];

        for (int nn,i=1; i<=m; ++i) {
            ArrayList<Integer> s = new ArrayList<Integer>();
            nn = in.nextInt();
            for (int x,j=0; j<nn; ++j) {
                x = in.nextInt();
                s.add(x);
            }

            ArrayList<Integer> t = new ArrayList<Integer>();
            for (int j=s.get(0)+1; j<s.get(s.size()-1); ++j) 
                if (Collections.binarySearch(s, j)<0)
                    t.add(j);

            for (int x : s)
                for (int y : t)
                    a[x][y] = 1;
        }

        int[] f = new int[n+1];
        int ans = 0;
        for (int i=1; i<=n; ++i) 
            ans = Math.max(ans, dp(a, f, i));

        System.out.println(ans);
    }

    public static int dp(int[][] a, int[] f, int x) {
        if (f[x]!=0) return f[x];
        f[x] = 1;
        for (int y=1; y<a.length; ++y)
            if (a[x][y]==1)
                f[x] = Math.max(f[x], dp(a, f, y)+1);
        return f[x];
    }
};