package test;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.Border;

public class menu  implements ActionListener{
	
	

	JLabel lab = new JLabel();
	JFrame frame = new JFrame();
	ImageIcon image = new ImageIcon(".//src//test//1.png");
	Border bord = BorderFactory.createLineBorder(new Color(255,231,208),4);
	Border bordlab2 = BorderFactory.createLineBorder(Color.BLACK,4);
	Border bordlab3 = BorderFactory.createLineBorder(Color.BLACK,4);
	Border bord4 = BorderFactory.createLineBorder(new Color(75,84,91),4);

	ImageIcon image1 = new ImageIcon(".//src//test//t22.png");
	JLabel lab1 = new JLabel();
	JPanel pic =new JPanel();
	JPanel panel = new JPanel();
	JButton button1 = new JButton();
	JButton button2 = new JButton();
	JButton button3 = new JButton();
	JLabel lab2 = new JLabel();
	JLabel lab3 = new JLabel();
	ImageIcon voy = new ImageIcon(".//src//test//voy2.png");
	ImageIcon admin = new ImageIcon(".//src//test//admin2.png");
	ImageIcon off = new ImageIcon(".//src//test//shtdown.png");
	JButton buttondown = new JButton();
	
	
	
	menu(){
		
		//LAB
		lab.setForeground(new Color(255,102,0));
		//lab.setBackground(Color.BLACK);
		lab.setIcon(image);		
		lab.setOpaque(true);
		lab.setBounds(150,0,200,200 );
		lab.setBorder(bord4);
		lab.setLayout(null);
		//LAB1
		lab1.setIcon(image1);
		lab1.setBounds(0,200,512,512);
		//PIC
		pic.setBounds(0, 0, 512,712 );
		pic.add(lab);
		pic.add(lab1);
		pic.setLayout(null);
		pic.setBackground(Color.white);
		//off:
		buttondown.setIcon(off);
		buttondown.setBounds(410, 2, 70, 60);
		buttondown.setBackground(new Color(255,231,208));
		buttondown.setFocusable(false);
		buttondown.addActionListener(this);
		buttondown.setBorder(bord);
		//panel
		panel.setLayout(null);
		panel.setBounds(512,0, 488, 712);
		panel.setBackground(new Color(255,231,208));
		panel.add(buttondown);
		panel.add(lab2);
		
		//lab3:
		lab3.setText("BIENVENUE CHEZ ONCF-EMI STUDENTS");
		lab3.setForeground(new Color(252,110,32));
		lab3.setFont(new Font("MV BOLI", Font.BOLD, 20));
		lab3.setBounds(0,10,450,50);
		lab3.setBorder(bordlab3);
		//lab2;
		lab2.add(lab3);
		lab2.setLayout(null);
		lab2.setBounds(15, 65, 450, 600);
		lab2.setBackground(Color.white);
		lab2.setOpaque(true);
		lab2.setBorder(bordlab2);
		lab2.add(button1);
		lab2.add(button2);
		//button2
		button2.setBackground(new Color(252,110,32));
		button2.setBounds(50,350,310,200);
		button2.setText("ESPACE ADMIN");
		button2.setForeground(Color.BLACK);
		button2.setFont(new Font("TimesRoman", Font.BOLD, 20));
		button2.setFocusable(false);
		button2.addActionListener(this);
		button2.setIcon(admin);
		button2.setBorder(bord);
		
		//Button:
		button1.setBackground(new Color(252,110,32));
		button1.setBounds(50,100,310,200);
		button1.setText("ESPACE VOYAGEUR");
		button1.setForeground(Color.BLACK);
		button1.setFont(new Font("TimesRoman", Font.BOLD, 20));
		button1.setFocusable(false);
		button1.addActionListener(this);
		button1.setIcon(voy);
		button1.setBorder(bord);
		//FRAME
		frame.setLayout(null);
		frame.setIconImage(image.getImage());
		frame.setSize(1000,712);		
		frame.setVisible(true);
		frame.getContentPane().setBackground(Color.white);
		frame.setTitle("--Réservation du train--");
		frame.add(pic); 
		frame.setResizable(false);
		frame.add(panel);
		
	}


	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub

				if(e.getSource()==button1) {
				voyageur util1 = new voyageur();
				frame.dispose();
				}
				if (e.getSource()==button2)
				{
					admin admin1 = new admin();
					frame.dispose();
				}
				if(e.getSource()==buttondown)
				{
					frame.dispose();
				}
		
		
		}

		}

