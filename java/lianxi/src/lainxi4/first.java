package lainxi4;

public class first {
    public static void main(String[] args) {
        for (int i = 1; i <9 ; i++) {
            for (int j = 1; j <9 ; j++) {
                if (j<=i){
                    System.out.print(i+"*"+j+"="+(i*j));
                }
            }
            System.out.println("");
        }
    }
}
