import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator1 implements ActionListener
{
    JFrame frame;
    JTextField textfield;
    Font myfont=new Font("Arial",Font.BOLD,30);
    JButton numberbuttons[]=new JButton[10];
    JButton funcbuttons[]=new JButton[8];
    JButton addbutton,subbutton,mulbutton,divbutton,decbutton,delbutton,eqlbutton,clrbutton;
    double num1=0,num2=0,result=0;
    JLabel label;
    char operator;
    Calculator1()
    {
        frame=new JFrame("My Calculator");
       // frame.setLayout(null);
        frame.setSize(400,500);
        frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
        JPanel panel=new JPanel(new GridLayout(4,4,10,10));
        panel.setBackground(Color.GRAY);
        addButtonsToPanel(panel);
        JPanel topPanel=new JPanel(new BorderLayout());
      topPanel.setBackground(Color.WHITE);
       label=new JLabel("Simple Calculator with JAVA");
       label.setFont(new Font("Arail",Font.BOLD,18));
       topPanel.add(label,BorderLayout.NORTH);
       textfield=new JTextField();
      // textfield.setBounds(50,25,300,50);
        textfield.setFont(myfont);
        textfield.setEditable(false);
        topPanel.add(textfield,BorderLayout.CENTER);
        frame.add(topPanel,BorderLayout.NORTH);
        frame.add(panel,BorderLayout.CENTER);
        frame.setVisible(true);
    }
    private void addButtonsToPanel(JPanel panel)
    {
        addbutton=new JButton("+");
        subbutton=new JButton("-");
        mulbutton=new JButton("*");
        divbutton=new JButton("/");
        decbutton=new JButton(".");
        eqlbutton=new JButton("=");
        clrbutton=new JButton("clear");
        delbutton=new JButton("delete");
        funcbuttons[0]=addbutton;
        funcbuttons[1]=subbutton;
        funcbuttons[2]=mulbutton;
        funcbuttons[3]=divbutton;
        funcbuttons[4]=decbutton;
        funcbuttons[5]=eqlbutton;
        funcbuttons[6]=clrbutton;
        funcbuttons[7]=delbutton;
        for(int i=0;i<8;i++)
        {
          funcbuttons[i].addActionListener(this);
          funcbuttons[i].setFont(myfont);
          funcbuttons[i].setFocusable(false);
          panel.add(funcbuttons[i]);
        }
        for(int i=1;i<=9;i++)
        {
            numberbuttons[i]=new JButton(String.valueOf(i));
            numberbuttons[i].addActionListener(this);
            numberbuttons[i].setFont(myfont);
            numberbuttons[i].setFocusable(false);
            panel.add(numberbuttons[i]);
        }
        numberbuttons[0]=new JButton(String.valueOf(0));
            numberbuttons[0].addActionListener(this);
            numberbuttons[0].setFont(myfont);
            numberbuttons[0].setFocusable(false);
            panel.add(funcbuttons[0]);
            panel.add(decbutton);
            panel.add(divbutton);

    }
      /*   delbutton.setBounds(50,430,145,50);
        clrbutton.setBounds(200,430,145,50);
        panel=new JPanel();
        panel.setBounds(50,100,300,300);
        panel.setLayout(new GridLayout(4,4,10,10));
        panel.setBackground(new Color(0,0,0,0));
       
       panel.add(numberbuttons[1]);
       panel.add(numberbuttons[2]);
       panel.add(numberbuttons[3]);
       panel.add(addbutton);
       panel.add(numberbuttons[4]);
       panel.add(numberbuttons[5]);
       panel.add(numberbuttons[6]);
       panel.add(subbutton);
       panel.add(numberbuttons[7]);
       panel.add(numberbuttons[8]);
       panel.add(numberbuttons[9]);
       panel.add(mulbutton);
       panel.add(decbutton);
       panel.add(numberbuttons[0]);
       panel.add(divbutton);
       panel.add(eqlbutton);
       frame.add(panel);
        frame.add(delbutton);
        frame.add(clrbutton);
        frame.add(label);
        frame.add(textfield);
        frame.setVisible(true);*/
    public static void main(String[] args) {
        Calculator1 cal=new Calculator1();
    }
    public void actionPerformed(ActionEvent e)
    {
       for(int i=0;i<10;i++)
       {
        if(e.getSource()==numberbuttons[i])
        {
            textfield.setText(textfield.getText().concat(String.valueOf(i)));
        }
       }
      if(e.getSource()==decbutton)
       {
        textfield.setText(textfield.getText().concat("."));
       }
       if(e.getSource()==addbutton)
       {
        num1=Double.parseDouble(textfield.getText());
        operator='+';
        textfield.setText("");
       }
       if(e.getSource()==subbutton)
       {
        num1=Double.parseDouble(textfield.getText());
        operator='-';
        textfield.setText("");
       }
       if(e.getSource()==mulbutton)
       {
        num1=Double.parseDouble(textfield.getText());
        operator='*';
        textfield.setText("");
       }
       if(e.getSource()==divbutton)
       {
        num1=Double.parseDouble(textfield.getText());
        operator='/';
        textfield.setText("");
       }
       if(e.getSource()==eqlbutton)
       {
        num2=Double.parseDouble(textfield.getText());
        switch(operator)
        {
            case '+':result=num1+num2;
                    break;
           case '-':result=num1-num2;
                    break;
           case '*':result=num1*num2;
                    break;
           case '/':result=num1/num2;
                    break;
        }
        textfield.setText(String.valueOf(result));
        num1=result;
       }
       if(e.getSource()==clrbutton)
       {
        textfield.setText("");
       }
       if(e.getSource()==delbutton)
       {
         String str=textfield.getText();
         textfield.setText(" ");
         for(int i=0;i<str.length()-1;i++)
         {
            textfield.setText(textfield.getText()+str.charAt(i));
         }
       }
    }
}
