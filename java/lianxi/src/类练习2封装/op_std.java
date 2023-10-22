package 类练习2封装;

public class op_std {
    private  student student;
    private  student student1;
    public op_std(student student,student student1){
        this.student = student;
        this.student1 = student1;
    }
    public double get_nb(){

        return student.get_score()>student1.get_score()?student.get_score():student1.get_score();

    }
}
