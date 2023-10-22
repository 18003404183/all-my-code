package lianxi5;

public class sanjiao {
    public static void main(String[] args) {
        int flag = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 7; j++) {
                if(j>=(7-flag)/2&&j<7-(7-flag)/2){
                    System.out.print("*");
                }
                else {
                    System.out.print("  ");
                }
            }
            System.out.println("");
            flag += 2;
        }
    }
}
