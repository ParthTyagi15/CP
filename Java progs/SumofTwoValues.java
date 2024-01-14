import java.util.*;

public class SumofTwoValues {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            int x = sc.nextInt();

            int[] values = new int[n];
            for (int i = 0; i < n; i++) {
                values[i] = sc.nextInt();
            }

            HashMap<Integer, Integer> mp = new HashMap<>();

            for (int i = 0; i < n; i++) {
                if (mp.containsKey(x - values[i])) {
                    System.out.println((i + 1) + " " + mp.get(x - values[i]));
                    return;
                }
                mp.put(values[i], i + 1);
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
