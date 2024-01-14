import java.util.*;
import java.io.*;

public class MissingCoinSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        long ans = 1;
        for (int i = 0; i < n && arr[i] <= ans; i++) {
            ans += arr[i];
        }
        System.out.println(ans);
    }
}