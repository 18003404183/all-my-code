package 类练习2封装;

public class student {
    private double score;

    public double get_score(){

        return this.score;
    }
    public void print_score(){

        System.out.println(score);
    }
    public student(double score){
        this.score = score;

    }
    public void set_score(double score){
        this.score = score;

    }
    public student(){

    }
}
