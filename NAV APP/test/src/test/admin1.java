package test;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.Border;

public class admin1 implements ActionListener{
	
	
	JLabel lab = new JLabel();
	JFrame frame = new JFrame();
	Border bordlab2 = BorderFactory.createLineBorder(Color.black,4);
	JPanel panel = new JPanel();
	JButton buttonRetour = new JButton();
	ImageIcon image = new ImageIcon(".//src//test//1.png");
	ImageIcon retour = new ImageIcon(".//src//test//return.png");
	ImageIcon tran = new ImageIcon(".//src//test//train.png");
	ImageIcon traj = new ImageIcon(".//src//test//trajet.png");
	JButton train = new JButton();
	JButton trajet = new JButton();
	JButton delete = new JButton();
	JLabel lab1 = new JLabel();
	JLabel lab2= new JLabel();
	JLabel lab3 = new JLabel();
	JLabel lab4 = new JLabel();
	JLabel lab5= new JLabel();
	JLabel lab6 = new JLabel();
	JButton btnRetour = new JButton();
	ImageIcon btn = new ImageIcon(".//src//test//home.png");

	
	admin1(){
		lab5.setBounds(0,70,1000,20);
		lab5.setBackground(new Color(255,110,32));
		lab5.setOpaque(true);
		//lab4:
		lab4.setText("ESPACE ADMIN");
		lab4.setForeground(new Color(255,110,32));
		lab4.setFont(new Font("Algerian", Font.BOLD, 40));
		lab4.setBounds(320,20,700,50);

		//lab:
		lab.setBounds(180, 150,600, 400);
		lab.setBackground(new Color(255,110,32));
		lab.setOpaque(true);
		lab.setBorder(bordlab2);
		lab.add(train);
		lab.add(trajet);
		//panel:
		panel.setBounds(0,0,1000,712);
		panel.setBackground(new Color(255,231,208));	
		panel.add(lab);
		panel.setLayout(null);
		panel.add(buttonRetour);
		panel.add(lab4);
		panel.add(lab5);
		panel.add(btnRetour);
		//btn
		btnRetour.setIcon(btn);
		btnRetour.setBounds(70,5,60,50);
		btnRetour.setBackground(new Color(255,110,32));
		btnRetour.addActionListener(this);
		btnRetour.setFocusable(false);

		//buttonRetour:
		buttonRetour.setIcon(retour);
		buttonRetour.setBounds(5,5,60,50);
		buttonRetour.setBackground(new Color(255,110,32));
		buttonRetour.addActionListener(this);
		buttonRetour.setFocusable(false);
		//afficher:
		lab1.setIcon(traj);
		lab1.setBounds(30,5,500,70);
		lab1.setText("--  Manipulation Des Trajets --");
		lab1.setFont(new Font("TimesRoman", Font.BOLD, 25));
		lab1.setForeground(new Color(255,110,32));
		trajet.add(lab1);
		trajet.setHorizontalAlignment(JLabel.LEFT);
		trajet.setHorizontalTextPosition(JLabel.RIGHT);
		trajet.setBounds(20,220,550,100);
		trajet.setBackground(Color.white);
		trajet.addActionListener(this);
		trajet.setFocusable(false);
		trajet.setLayout(null);
		//ajouter
		lab3.setIcon(tran);
		lab3.setBounds(30,5,500,70);
		lab3.setText("-- Manipulation Des Trains  --");
		lab3.setFont(new Font("TimesRoman", Font.BOLD, 25));
		lab3.setForeground(new Color(255,110,32));
		train.add(lab3);
		train.setBounds(20,80,550,100);
		train.setBackground(Color.white);
		train.addActionListener(this);
		train.setFocusable(false);
		train.setLayout(null);	
		//frame:
		frame.setLayout(null);
		frame.setSize(1000,712);
		frame.setVisible(true);
		frame.add(panel);
		frame.setTitle("-- VISION DES TRAINS DISPONIBLES --");
		frame.setResizable(false);
		frame.setIconImage(image.getImage());


		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource()==buttonRetour)
		{
			admin a1 = new admin();
			frame.dispose();
		}
		if(e.getSource()==train)
		{
			admin2 a2 =new admin2();
			frame.dispose();
		}
		if(e.getSource()==trajet)
		{
			admin3 a3 = new admin3();
			frame.dispose();
		}
		if(e.getSource()==btnRetour)
		{
			menu m = new menu();
			frame.dispose();
		}

		
	}

	


	
	
}


