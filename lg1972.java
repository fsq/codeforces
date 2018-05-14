import java.util.*;

public class lg1972 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n; n = in.nextInt();
        int[] a = new int[n+1];
        for (int i=1; i<=n; ++i) a[i] = in.nextInt();

        int m; m = in.nextInt();

        int[][] q = new int[m][3];
        for (int i=0; i<m; ++i) {
            q[i][0] = in.nextInt();
            q[i][1] = in.nextInt();
            q[i][2] = i;
        }

        Arrays.sort(q, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[1], b[1]);
            }
        });

        int[] s = new int[n+1];
        int[] ans = new int[m];
        int[] pre = new int[1000007];

        for (int r=1, i=0; i<q.length; ++i) {
            for (; r<=q[i][1]; ++r) { 
                if (pre[a[r]]!=0) 
                    update(s, pre[a[r]], -1);
                update(s, pre[a[r]]=r, 1);
            }
            ans[q[i][2]] = sum(s, q[i][1]) - sum(s, q[i][0]-1);
        }

        for (int x : ans) System.out.println(x);
    }

    static int lowbit(int x) { return x & -x; }

    static void update(int[] s, int p, int v) {
        for (; p<s.length; p+=lowbit(p)) s[p] += v;
    }

    static int sum(int[] s, int i) {
        int ret = 0;
        for (; i>0; i-=lowbit(i)) ret += s[i];
        return ret;
    }
}