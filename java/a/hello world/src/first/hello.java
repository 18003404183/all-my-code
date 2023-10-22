package first;
import java.util.Scanner;

public class hello {
    public static void main(String[] args) {
        short a = 10;
        byte b= 0;
        //表达式的类型为值的最高类型 表达式中 byte short char 是直接转化成int 处理。

        //short c = a+b;
        double c = 0.0;
        System.out.println(a+b);
        for(int i = 0;i<=10;i++){
            System.out.print(i+"\n");

        }
        int i = 10;
        System.out.println(i*1.0);
        System.out.println(i);

        int w = 10;
        int s = w++;//先把w的值付给 s 即 s = 10 后 w 变成 11
        System.out.println(s);
        s = ++w;//先加w w变成12 再将值赋给 s = 12
        System.out.println(s);
        second();
    }
    public  static  void second(){
        int a[] = new int[10];
        int b[][] =new int[10][10];
        for (int i = 0;i<10;i++){
            
            a[i] = i;
            //System.out.println(a[i]);

            for (int j = 0; j < 10; j++) {
                b[i][j] = 0;
                System.out.print(b[i][j]);
            }
            System.out.println(" ");
        }
        
      Scanner sc = new Scanner(System.in)  ;
        int box = sc.nextInt();
        System.out.println(box);
    }
}
