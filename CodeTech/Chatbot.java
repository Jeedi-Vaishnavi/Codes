import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
class Chatbotdemo extends JFrame{
    JFrame frame;
    JTextField textfield=new JTextField();
    JTextArea textarea=new JTextArea();
    JButton button=new JButton();
    JLabel label=new JLabel();
    Chatbotdemo()
    {
        // Create frame and customize it
     frame=new JFrame("JAVA ChatBot");
     Font myfont=new Font("Arial",Font.PLAIN,18);
     frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
     frame.setLayout(null);
     frame.setVisible(true);
     frame.setSize(400,400);
     frame.getContentPane().setBackground(Color.GRAY);
     frame.add(textarea);
     frame.add(textfield);
  
     //create textarea and customize it
    
     textarea.setSize(2000,600);
     textarea.setLocation(2,1);
     textarea.setBackground(Color.BLACK);
     textarea.setFont(myfont);
     //create textfield and customize it
      textfield.setBounds(1,605,1000,40);
      textfield.setFont(myfont);
      frame.add(button);
      label.setText("SEND"); 
      button.add(label);
      // create button and customize it
     button.setBounds(1010,605,267,40);
     
     button.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e)
        {
            if(e.getSource()==button)
            {
                String text=textfield.getText();
                textarea.setForeground(Color.GREEN);//set textarea with given color
                textarea.append("You-> "+text+"\n");
                textfield.setText("");
                //check user input and provide appropriate responses
                if(text.contains("hi"))
                {
                   reply("Hi there...How can i assist you today");
                }
                else if(text.contains("what is your name"))
                {
                    reply("I'm the chatbot");
                }
                else if(text.contains("how are you"))
                {
                    reply("I'm super fine");
                }
                else if(text.contains("what is your gender"))
                {
                    reply("I'm a Artificial chatbot.So i dont have gender");
                }
                else if(text.contains("I love you"))
                {
                    reply("I love you too");
                }
                else if(text.contains("CSE stands for"))
                {
                    reply("Computer Science and Engineering");
                }
                else if(text.contains("what does internship means"))
                {
                   reply("An internship is a temporary position where individuals gain practical work experience in a specific field or industry.An internship is a temporary position where individuals gain practical work experience in a specific field or industry");
                }
                else if(text.contains("okay bye"))
                {
                    reply("its okay bye!!! Had good time with you");
                }
                else
                {
                    reply("I Cant understand");
                }
            }
        }
     });
    }
    // Method to display chatbot responses
    public void reply(String s)
    {
        textarea.append("ChatBot->"+s+"\n");
    }
  }
public class Chatbot {
    public static void main(String[] args) {
        Chatbotdemo cb=new Chatbotdemo();
    }
}
 
   