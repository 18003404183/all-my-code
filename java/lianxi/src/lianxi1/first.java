package lianxi1;
import java.util.Scanner;
import java.util.Random;

public class first {
    public static void main(String[] args) {
        Scanner sc =new  Scanner(System.in);
        Random r = new Random();
        int a[] = new int[5];
        int c = r.nextInt(a.length);
        for (int i = 0; i < a.length; i++) {
            a[i] = sc.nextInt();
        }
        int temp;
        for (int i = 0; i < a.length; i++) {
            temp = a[i];
            a[i] = a[c];
            a[c] = temp;}
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }
}
