package jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;


public class first {

    public static void main(String[] args)  throws  Exception{
        String url = "jdbc:mysql:///lianxi1";
        String user_name = "root";
        String password = "1234";
        Connection connect = DriverManager.getConnection(url,user_name,password);
        Statement stmt = connect.createStatement();
        String sql = "select * from student";
        ResultSet rt = stmt.executeQuery(sql);
        student st = new student();
        List<student> ww = new ArrayList<>();
        while (rt.next()){
            int id = rt.getInt(1);
            String name = rt.getString(2);
            int age = rt.getInt(3);
            String add = rt.getString(4);
            st.set_id(id);
            st.set_addr(add);
            st.set_age(age);
            st.set_name(name);
            System.out.println(id);
            System.out.println(name);
            System.out.println(age);
            System.out.println(add);
            System.out.println("-------------------------------------------------------------");
            ww.add(st);

        }
        student a = ww.get(0);
        System.out.println(a);
        stmt.close();
        connect.close();
    }

}
