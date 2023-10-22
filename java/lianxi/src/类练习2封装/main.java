package 类练习2封装;

public class main {
    public  static void main(String args[]){
        student wwb = new student(10.0);
        wwb.print_score();
        wwb.set_score(100.0);
        wwb.print_score();
        student sb = new student();
        System.out.println(sb);
        op_std teaccher = new op_std(wwb,sb);
        double a = teaccher.get_nb();
        System.out.println(a);
    }
}
