package lianxi;
import java.util.Random;
import java.util.Scanner;
import java.util.random.RandomGenerator;

public class first {

    public static void main(String[] args) {
        int max = 10;
        Random r = new Random();
        int data = r.nextInt(0,100);
        Scanner in = new Scanner(System.in);
        int a = 0;
        int cont = 0;
        while(a != data&&cont < max){
            if(cont == max){
                System.out.println("die");
            }
                a = in.nextInt();
                if(a == data){System.out.println("yeah");break;}
                else if(a>data){
                    System.out.println("da");
                }
                else {
                    System.out.println("xiao");
                }
                 cont +=1;
                }

        }


    }


