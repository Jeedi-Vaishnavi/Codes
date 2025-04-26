import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator implements ActionListener
{
    JFrame frame;
    JTextField textfield;
    Font myfont=new Font("Arial",Font.BOLD,30);
    JButton numberbuttons[]=new JButton[10];
    JButton funcbuttons[]=new JButton[11];
    JButton addbutton,subbutton,mulbutton,divbutton,expbutton,decbutton,delbutton,eqlbutton,clrbutton,negbutton,modbutton;
    double num1=0,num2=0,result=0;
    JLabel label;
    JPanel panel1;
    JPanel panel2;
    String operator;
    Calculator()
    {
        //create a frame
        frame=new JFrame("calculator");
        frame.setLayout(null);
        frame.setSize(400,500);
        frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
        frame.setBackground(Color.GRAY);
        // create a label 
       label=new JLabel("Simple Calculator with JAVA");
        label.setFont(new Font("Times New Roman",Font.BOLD,20));
        label.setBounds(50,30,300,20);
        label.setHorizontalAlignment(SwingConstants.CENTER);
        // create a textfield
       textfield=new JTextField();
       textfield.setBounds(50,70,300,50);
        textfield.setFont(myfont);
        textfield.setEditable(false);
        // create buttons to perform arithmetic operations
        addbutton=new JButton("+");
        subbutton=new JButton("-");
        mulbutton=new JButton("*");
        divbutton=new JButton("/");
        expbutton=new JButton("^");
        decbutton=new JButton(".");
        eqlbutton=new JButton("=");
        clrbutton=new JButton("clr");
        delbutton=new JButton("del");
        negbutton=new JButton("(-1)");
        modbutton=new JButton("%");
        // add  above buttons for funcbuttons array
        funcbuttons[0]=addbutton;
        funcbuttons[1]=subbutton;
        funcbuttons[2]=mulbutton;
        funcbuttons[3]=divbutton;
        funcbuttons[4]=expbutton;
        funcbuttons[5]=decbutton;
        funcbuttons[6]=eqlbutton;
        funcbuttons[7]=clrbutton;
        funcbuttons[8]=delbutton;
        funcbuttons[9]=negbutton;
        funcbuttons[10]=modbutton;
        for(int i=0;i<11;i++)
        {
          funcbuttons[i].addActionListener(this);
          funcbuttons[i].setFont(myfont);
          funcbuttons[i].setFocusable(false);
        }
        // create number buttons
        for(int i=0;i<10;i++)
        {
            numberbuttons[i]=new JButton(String.valueOf(i));
            numberbuttons[i].addActionListener(this);
            numberbuttons[i].setFont(myfont);
            numberbuttons[i].setFocusable(false);
        }
        negbutton.setBounds(50,533,100,50);
        delbutton.setBounds(150,533,100,50);
        clrbutton.setBounds(250,533,100,50);
        // create panel
        panel1=new JPanel();
        panel1.setBounds(50,150,300,300);
        panel1.setLayout(new GridLayout(4,4,10,10));
        panel1.setBackground(new Color(0,0,0,0));
       // add all buttons to the panel
       panel1.add(numberbuttons[1]);
       panel1.add(numberbuttons[2]);
       panel1.add(numberbuttons[3]);
       panel1.add(addbutton);
       panel1.add(numberbuttons[4]);
       panel1.add(numberbuttons[5]);
       panel1.add(numberbuttons[6]);
       panel1.add(subbutton);
       panel1.add(numberbuttons[7]);
       panel1.add(numberbuttons[8]);
       panel1.add(numberbuttons[9]);
       panel1.add(mulbutton);
        panel1.add(modbutton);
       panel1.add(numberbuttons[0]);
       panel1.add(divbutton);
       panel1.add(expbutton);
     //  panel.setBounds(1,1,10,10);
     // panel.setLayout(new GridLayout(1,1,10,10));
      panel2=new JPanel();
        panel2.setBounds(50,463,300,60);
        panel2.setLayout(new GridLayout(1,1,10,10));
        panel2.setBackground(new Color(0,0,0,0));
        panel2.add(decbutton);
       panel2.add(eqlbutton);
       // add components to the frame
       frame.add(panel1);
       frame.add(panel2);
       frame.add(negbutton);
        frame.add(delbutton);
        frame.add(clrbutton);
        frame.add(label);
        frame.add(textfield);
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        Calculator cal=new Calculator();
    }
    // add actions when button is clicked
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
        operator="+";
        textfield.setText("");
       }
       if(e.getSource()==subbutton)
       {
        num1=Double.parseDouble(textfield.getText());
        operator="-";
        textfield.setText("");
       }
       if(e.getSource()==mulbutton)
       {
        num1=Double.parseDouble(textfield.getText());
        operator="*";
        textfield.setText("");
       }
       if(e.getSource()==divbutton)
       {
        num1=Double.parseDouble(textfield.getText());
        operator="/";
        textfield.setText("");
       }
       if(e.getSource()==expbutton)
       {
        num1=Double.parseDouble(textfield.getText());
        operator="^";
        textfield.setText("");
       }
       if(e.getSource()==modbutton)
       {
         num1=Double.parseDouble(textfield.getText());
        operator="%";
        textfield.setText("");
       }
       if(e.getSource()==eqlbutton)
       {
        num2=Double.parseDouble(textfield.getText());
        switch(operator)
        {
            case "+":result=num1+num2;
                    break;
           case "-":result=num1-num2;
                    break;
           case "*":result=num1*num2;
                    break;
           case "/":result=num1/num2;
                    break;
           case "%":result=num1%num2;
                    break;
            case "^":result=Math.pow(num1,num2);
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
       if(e.getSource()==negbutton)
       {
        double temp=Double.parseDouble(textfield.getText());
        temp=temp*-1;
        textfield.setText(String.valueOf(temp));
       }
    }
}