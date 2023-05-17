package test;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.border.Border;

import org.w3c.dom.events.MouseEvent;

public class admin implements ActionListener{
	
	JFrame frame = new  JFrame();
	JLabel lab = new JLabel();
	ImageIcon image = new ImageIcon(".//src//test//1.png");
	JPanel panel = new JPanel();
	Border bordlab2 = BorderFactory.createLineBorder(Color.black,4);
	Border bordtext = BorderFactory.createLineBorder(Color.black ,4);
	JButton buttonRetour = new JButton();
	JButton submit = new JButton();
	ImageIcon retour = new ImageIcon(".//src//test//home.png");
	JTextField text1 =  new JTextField();
	JTextField text2 =  new JTextField();
	JLabel lab2= new JLabel();
	JLabel lab3= new JLabel();
	JLabel lab4= new JLabel();
	JLabel lab5= new JLabel();
	JLabel lab6= new JLabel();
	JLabel lab7= new JLabel();
	JLabel lab8= new JLabel();
	JLabel lab9= new JLabel();
	ImageIcon ma = new ImageIcon(".//src//test//mail.png");
	ImageIcon ma1 = new ImageIcon(".//src//test//padlock.png");
	ImageIcon ma2 = new ImageIcon(".//src//test//global-network.png");

	JPasswordField pass =new JPasswordField();

	admin(){
		lab8.setBounds(0,70,1000,20);
		lab8.setBackground(new Color(252,110,32));
		lab8.setOpaque(true);
		//lab9:
		lab9.setText("ESPACE ADMIN");
		lab9.setForeground(new Color(252,110,32));
		lab9.setFont(new Font("Algerian", Font.BOLD, 40));
		lab9.setBounds(320,20,700,50);

		//submit
		submit.setBounds(110,350,210,50);
		submit.setText("connexion");
		submit.setBackground(Color.white);
		submit.setBorder(bordtext);
		submit.setFocusable(false);
		submit.addActionListener(this);
		submit.setFont(new Font("TimesRoman", Font.BOLD, 25));
		//lab5:
		lab5.setIcon(ma);
		lab5.setBounds(40,120,70,40);
		//lab7;
		lab7.setIcon(ma2);
		lab7.setBounds(10,20,70,70);
		//lab6;
		lab6.setIcon(ma1);
		lab6.setBounds(31,-100,70,700);

		//button de retour
		buttonRetour.setIcon(retour);
		buttonRetour.setBounds(5,5,60,50);
		buttonRetour.setBackground(new Color(252,110,32));
		buttonRetour.addActionListener(this);
		buttonRetour.setFocusable(false);
		//password
		pass.setBounds(40,290,350,40);
		pass.setFont(new Font("TimesRoman",Font.PLAIN,20));
		//pass.setBorder(bordtext);
		//lab4
		lab4.setText("PASSWORD");
		lab4.setBounds(110,200,400,100);
		lab4.setFont(new Font("Calibri", Font.PLAIN, 40));
		//lab3
		lab3.setText("USERNAME");
		lab3.setBounds(110,90,300,100);
		lab3.setFont(new Font("TimesRoman", Font.PLAIN, 40));
		//lab2:
		lab2.setText("CONNEXION");
		lab2.setFont(new Font("Algerian", Font.BOLD, 60));
		lab2.setBounds(80,5,500,100);
		//text1
		text1.setPreferredSize(new Dimension(300,50));
		text1.setBounds(40,170,350,40);
		
		//text1.setBorder(bordtext);
		text1.setFont(new Font("TimesRoman",Font.PLAIN,20));
		//lab:
		lab.setBounds(250, 150,  480, 450);
		lab.setBackground(new Color(252,110,32));
		lab.setOpaque(true);
		lab.setBorder(bordlab2);
		lab.add(lab5);
		lab.add(lab6);
		lab.add(lab7);
		lab.add(text2);
		lab.add(text1);
		lab.add(lab2);
		lab.add(lab3);
		lab.add(lab4);
		lab.add(submit);
		lab.add(pass);
		//panel:	
		panel.setBounds(0,0,1000,712);
		panel.setBackground(new Color(255,231,208));	
		panel.add(lab);
		panel.setLayout(null);
		panel.add(buttonRetour);
		panel.add(lab8);
		panel.add(lab9);
		//frame:
		frame.setLayout(null);
		frame.setSize(1000,712);
		frame.setVisible(true);
		frame.setIconImage(image.getImage());
		frame.add(panel);
		frame.setTitle("-- ESPACE ADMIN --");
		frame.setResizable(false);
		
		//variables:


	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		String mdp = new String(pass.getPassword());
		
		if(e.getSource()==buttonRetour)
		{
			menu m = new menu();
			frame.dispose();

		}
		if(e.getSource()==submit)
		{
			if(text1.getText().equals("admin") && mdp.equals("admin") )
			{
				admin1 a1 = new admin1();
				frame.dispose();
			}
			else {
				JOptionPane.showMessageDialog(null,"Ce Utilisateur n'existe pas", "Vérification",JOptionPane.WARNING_MESSAGE);
				text1.setText("");
				pass.setText("");
			}

		}
		


		
	}

}
