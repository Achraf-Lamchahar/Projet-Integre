package test;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class supprimertrajet implements ActionListener{

	JLabel lab = new JLabel();
	JFrame frame = new JFrame();
	Border bordlab2 = BorderFactory.createLineBorder(Color.black,4);
	JPanel panel = new JPanel();
	JButton buttonRetour = new JButton();
	ImageIcon image = new ImageIcon(".//src//test//1.png");
	ImageIcon retour = new ImageIcon(".//src//test//return.png");
	ImageIcon delete = new ImageIcon(".//src//test//delete.png");
	ImageIcon add = new ImageIcon(".//src//test//add.png");
	ImageIcon vision = new ImageIcon(".//src//test//vision1.png");
	JLabel lab1 = new JLabel();
	JLabel lab2= new JLabel();
	JLabel lab3 = new JLabel();
	JLabel lab4 = new JLabel();
	JLabel lab5= new JLabel();
	JLabel lab6 = new JLabel();
	JLabel lab7 = new JLabel();
	JLabel lab8 = new JLabel();
	JTextField text1 =  new JTextField();
	JTextField text2 =  new JTextField();
	JTextField text3 =  new JTextField();
	JTextField text4 =  new JTextField();
	JTextField text5 =  new JTextField();
	JTextField text6 =  new JTextField();
	JTextField text7 =  new JTextField();
	JTextField text8 =  new JTextField();
	ImageIcon i1 = new ImageIcon(".//src//test//i1.png");
	ImageIcon i2 = new ImageIcon(".//src//test//train.png");
	ImageIcon i3 = new ImageIcon(".//src//test//i3.png");
	ImageIcon i4 = new ImageIcon(".//src//test//i4.png");
	ImageIcon i5 = new ImageIcon(".//src//test//location.png");
	ImageIcon date = new ImageIcon(".//src//test//date.png");
	JButton done = new JButton();
	ImageIcon donei = new ImageIcon(".//src//test//done.png");
	JButton btnRetour = new JButton();
	ImageIcon btn = new ImageIcon(".//src//test//home.png");
	ImageIcon heure = new ImageIcon(".//src//test//heure.png");



	
	supprimertrajet(){
		//lab:
		lab.setBounds(200, 30,500, 620);
		lab.setBackground(new Color(255,110,32));
		lab.setOpaque(true);
		lab.setBorder(bordlab2);
		lab.add(text1);
		lab.add(text3);
		lab.add(text5);
		lab.add(text4);
		//lab.add(text8);
		lab.add(lab1);
		lab.add(lab3);
		lab.add(lab5);
		lab.add(lab4);
		lab.add(done);
		lab.add(text2);
		lab.add(lab2);
		//panel:
		panel.setBounds(0,0,1000,712);
		panel.setBackground(new Color(255,231,208));	
		panel.add(lab);
		panel.setLayout(null);
		panel.add(buttonRetour);
		panel.add(btnRetour);
		//buttonRetour:
		buttonRetour.setIcon(btn);
		buttonRetour.setBounds(5,5,60,50);
		buttonRetour.setBackground(new Color(255,110,32));
		buttonRetour.addActionListener(this);
		buttonRetour.setFocusable(false);
		//btn:
		btnRetour.setIcon(retour);
		btnRetour.setBounds(70,5,60,50);
		btnRetour.setBackground(new Color(255,110,32));
		btnRetour.addActionListener(this);
		btnRetour.setFocusable(false);
		//texts:
		text1.setBounds(50,60,400,40);
		text1.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		
		text3.setBounds(50,170,400,40);
		text3.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		text5.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text5.setBounds(50,280,400,40);
		
		text4.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text4.setBounds(50,380,400,40);
		
		text2.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text2.setBounds(50,480,400,40);
		
		//labs:
		
		lab1.setIcon(i1);
		lab1.setBounds(50, 5, 400, 60);
		lab1.setText("ID TRAIN");
		lab1.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		
		lab3.setIcon(i5);
		lab3.setBounds(50, 110, 400, 60);
		lab3.setText("VILLE DEPART");
		lab3.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab5.setIcon(i5);
		lab5.setBounds(50, 220, 400, 60);
		lab5.setText("VILLE ARRIVE ");
		lab5.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab4.setIcon(date);
		lab4.setBounds(50, 320, 400, 60);
		lab4.setText("DATE DEPART ");
		lab4.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab2.setIcon(heure);
		lab2.setBounds(50, 420, 400, 60);
		lab2.setText("HORAIRE");
		lab2.setFont(new Font("TimesRoman", Font.BOLD, 25));

		//done:
		done.setIcon(donei);
		done.setBounds(170,530,150,60);
		done.setBackground(new Color(255,231,208));
		done.setFocusable(false);
		done.addActionListener(this);


		//frame:
		frame.setLayout(null);
		frame.setSize(1000,712);
		frame.setVisible(true);
		frame.add(panel);
		frame.setTitle("-- AJOUTER UN TRAIN --");
		frame.setResizable(false);
		frame.setIconImage(image.getImage());
	}
	
	public static void supprimertrajet( JTextField text1, JTextField text2, JTextField text3, JTextField text4,JTextField text5){    
         try {
             Connection c = DriverManager.getConnection(
                     "jdbc:mysql://localhost/traindatabase?serverTimezone=UTC",
                     "root",
                     ""
             );
             String sql = "DELETE FROM trajets WHERE idTrain= ? and villeDepart=? and villeArrive= ? and dateDepart = ? and  horaireDepart = ?";
             PreparedStatement s = c.prepareStatement(sql);
             s.setString(1, text1.getText().toString());
             s.setString(2, text2.getText().toString());
             s.setString(3, text3.getText().toString());
             s.setString(4, text4.getText().toString());
             s.setString(5, text5.getText().toString());
             s.execute();
             JOptionPane.showMessageDialog(null,"Ce trajet a été supprimé avec succès");
         } catch (SQLException e) {
             throw new RuntimeException(e);
             
         }
     }


	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource()==done)
		{
			supprimertrajet(text1,text3,text5,text4,text2);
		}
		if(e.getSource()==buttonRetour)
		{
			admin3 a3 = new admin3();
			frame.dispose();
			text1.setText("");
			text3.setText("");
			text5.setText("");
			text4.setText("");
			text2.setText("");
			
		}
		if(e.getSource()==btnRetour)
		{
			menu m = new menu();
			frame.dispose();
		}
		
	}
}
