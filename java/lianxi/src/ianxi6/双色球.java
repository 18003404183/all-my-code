package ianxi6;

import java.util.Random;
import java.util.Scanner;

//获取用户输入
//生成中奖号码
//判断中奖情况
public class 双色球 {
    public static void main(String[] args) {
        int user_numbers[] = user_input();
        print_numbers(user_numbers);
        int luck_numbers[] = get_lucky_number();
        print_numbers(luck_numbers);
        judge_price(user_numbers,luck_numbers);
    }
    public static  int[] user_input(){
        int user_numbers[] = new int[7];
        Scanner in = new Scanner(System.in);
        for (int i = 0; i <user_numbers.length-1 ; i++) {
            System.out.println("选择第"+(i+1)+"个红球");
            int in_number = in.nextInt();
            if(in_number >=1&&in_number<=33&&judje_exit(user_numbers,in_number)) {
                user_numbers[i] = in_number;
            }else{
                System.out.println("sb");
                i -=1;
            }

            }
        System.out.println("输入篮球号码");
        int blue_number = in.nextInt();
        if (blue_number >= 1&&blue_number<=16) {
            user_numbers[user_numbers.length-1] = blue_number;
        }
        else {
            System.out.println("输入错误");
        }
        return  user_numbers;
        }

    public static boolean judje_exit(int numbers[],int number) {
        for (int i = 0; i < numbers.length; i++) {
            if (number == numbers[i]) {
                return false;
            }

        }
        return true;
    }
    public static void print_numbers(int numbers[]){
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i]+",");
        }
        System.out.println(" ");
    }
    public static int[] get_lucky_number(){
        int lucky_numbers []= new int[7];
        Random r_number = new Random();
        for (int i = 0; i < lucky_numbers.length-1; i++) {
            int luck_number = r_number.nextInt(1,34);
            if(judje_exit(lucky_numbers,luck_number)){
                lucky_numbers[i] = luck_number;
            }else{ i-=1;}
        }
        int luck_number = r_number.nextInt(1,17);
        lucky_numbers[lucky_numbers.length-1] = luck_number;
        return  lucky_numbers;
    }
    public static void judge_price(int user_numbers[],int lucky_numbers[]){
        int count []= new int[2];
        for (int i = 0; i < user_numbers.length-1; i++) {
            if(!judje_exit(lucky_numbers, user_numbers[i])){
                count[0] += 1;
            }
            if (user_numbers[user_numbers.length-1] == lucky_numbers[lucky_numbers.length-1]) {
                count[1] += 1;
            }
            if (count[0] == 6&&count[1] == 1) {
                System.out.println("一等奖");
                return;
            } else if (count[0] == 6&&count[1] == 0) {
                System.out.println("二等奖");
                return;
            } else if (count[0] == 5&&count[1] == 1) {
                System.out.println("三等奖");
                return;
            } else if (count[0] == 4&&count[1] == 1||count[0] == 5&&count[1] == 0) {
                System.out.println("四等奖");
                return;
            } else if (count[0] == 3&&count[1] == 1||count[0] == 4&&count[1] == 0) {
                System.out.println("五等奖");
                return;
            } else if (count[0] <= 2&&count[1] == 1) {
                System.out.println("六等奖");
                return;
            }
            else System.out.println("抱歉");
            return;
        }
    }
}
