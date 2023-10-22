package 类lianxi;

public class init {
    public static void main(String a[]){

        laptop h = new laptop();
        h.name = "天选4";
        h.gpu = 4060;
        h.prise = 8500;

        System.out.println(h.name+h.prise+h.gpu );
        h.return_position();

    }
}
