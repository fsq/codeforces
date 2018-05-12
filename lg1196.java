import java.util.*;

public class lg1196 {

    static int[] fa = new int[30007];
    static int[] sz = new int[30007];
    static int[] rk = new int[30007];

    static int find(int x) {
        if (fa[x]==x) return x;
        int f = fa[x];
        fa[x] = find(fa[x]);
        rk[x] += rk[f];
        return fa[x];
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Arrays.fill(sz, 1);
        for (int i=1; i<=30000; ++i) fa[i] = i;
        
        int t;
        t = in.nextInt();

        String c;
        int x, y;
        while (t-->0) {
            c = in.next();
            x = in.nextInt();
            y = in.nextInt();
            int fx = find(x), fy = find(y);
            if (c.compareTo("M")==0) {
                fa[fx] = fy;
                rk[fx] = sz[fy];
                sz[fy] += sz[fx];
            } else {
                if (fx!=fy) {
                    System.out.println("-1");
                    continue;
                } else {
                    System.out.println(Math.abs(rk[x]-rk[y])-1);
                }
            }
        }
    }
}