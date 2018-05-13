import java.util.*;

public class lg1801 {

    static int sz = 1;
    static Queue<Integer> fst = new PriorityQueue<Integer>(10, new Comparator<Integer>() {
        @Override
        public int compare(Integer a, Integer b) {
            return b.compareTo(a);
        }
    });

    static Queue<Integer> snd = new PriorityQueue<Integer>();

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int n, m;
        n = in.nextInt(); m = in.nextInt();

        int[] a = new int[n];
        int[] b = new int[m];

        for (int i=0; i<n; ++i) a[i] = in.nextInt();
        for (int i=0; i<m; ++i) b[i] = in.nextInt();

        for (int j=0,i=0; j<m; ) {
            while (i<b[j]) {
                if (fst.isEmpty() || a[i]<=fst.peek()) 
                    fst.add(a[i]);
                else      
                    snd.add(a[i]);
                ++i;
            }

            while (fst.size()>sz) snd.add(fst.poll());
            while (fst.size()<sz) fst.add(snd.poll());

            System.out.println(fst.peek());
            ++j;
            ++sz;
        }
    }
}