package sb;

import  javax.swing.*;

public class window  extends  JFrame{
                public void initWindow(){

                    this.setSize(600,850);
                    this.setVisible(true);
                    this.setLocationRelativeTo(null);
                    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


                }
                public window(){

                    initWindow();

                }

    public static void main(String[] args) {
        window window = new window();
    }
}


