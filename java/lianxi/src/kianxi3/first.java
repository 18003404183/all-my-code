package kianxi3;

import java.util.Random;

public class first {

    public static void main(String[] args) {
        int a[] = {10100,1000,10000000,112156};
        a(a);
    }
    public static void a(int a[]){
        Random r = new Random();
        for (int i = 0; i < a.length; i++) {
            int n = r.nextInt(a.length);
            int temp = a[i];
            a[i] = a[n];
            a[n] = temp;
        }
        for (int i = 0; i < a.length; i++) {
            System.out.println("a"+(i+1)+"is"+a[i]);

        }
    }

}
