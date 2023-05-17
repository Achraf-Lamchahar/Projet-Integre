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

public class supprimertrain  implements ActionListener {
	
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
	ImageIcon i5 = new ImageIcon(".//src//test//siege.png");
	ImageIcon date = new ImageIcon(".//src//test//date.png");
	JButton done = new JButton();
	ImageIcon donei = new ImageIcon(".//src//test//done.png");
	JButton btnRetour = new JButton();
	ImageIcon btn = new ImageIcon(".//src//test//home.png");

	
	supprimertrain(){
		lab.setBounds(200, 150,500, 300);
		lab.setBackground(new Color(255,110,32));
		lab.setOpaque(true);
		lab.setBorder(bordlab2);
		lab.add(text1);
		//lab.add(text3);
		//lab.add(text5);
		
		//lab.add(text8);
		lab.add(lab1);
		//lab.add(lab3);
		//lab.add(lab5);
		//lab.add(lab8);
		lab.add(done);
		//panel:
		panel.setBounds(0,0,1000,712);
		panel.setBackground(new Color(255,231,208));	
		panel.add(lab);
		panel.setLayout(null);
		panel.add(buttonRetour);
		panel.add(btnRetour);
		//buttonRetour:
		buttonRetour.setIcon(retour);
		buttonRetour.setBounds(5,5,60,50);
		buttonRetour.setBackground(new Color(255,110,32));
		buttonRetour.addActionListener(this);
		buttonRetour.setFocusable(false);
		//btn:
		btnRetour.setIcon(btn);
		btnRetour.setBounds(70,5,60,50);
		btnRetour.setBackground(new Color(255,110,32));
		btnRetour.addActionListener(this);
		btnRetour.setFocusable(false);

		//texts:
		text1.setBounds(50,110,400,40);
		text1.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		
		text3.setBounds(50,220,400,40);
		text3.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		text5.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text5.setBounds(50,330,400,40);
		//labs:
		lab1.setIcon(i1);
		lab1.setBounds(50, 50, 400, 60);
		lab1.setText("ID TRAIN");
		lab1.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		
		lab3.setIcon(i2);
		lab3.setBounds(50, 160, 400, 60);
		lab3.setText("NOM DE TRAIN");
		lab3.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		
		lab5.setIcon(i5);
		lab5.setBounds(50, 270, 400, 60);
		lab5.setText("MAX DES PLACES ");
		lab5.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		
		//done:
		done.setIcon(donei);
		done.setBounds(170,200,150,60);
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
	public static void supprimertrain(JTextField text1) {
        try {
            Connection c = DriverManager.getConnection(
                    "jdbc:mysql://localhost/traindatabase?serverTimezone=UTC",
                    "root",
                    ""
            );
            
            //String idSupprimer = 
            String sql = "DELETE FROM `train` WHERE `idTrain`= ?";
            PreparedStatement s = c.prepareStatement(sql);
            s.setString(1, text1.getText().toString());
            s.execute();
            JOptionPane.showMessageDialog(null,"Ce train a été supprimé avec succès");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
		if(e.getSource()==buttonRetour)
		{
			admin2 a2 = new admin2();
			frame.dispose();
		}
		if(e.getSource()==done)
		{
			supprimertrain(text1);
			text1.setText("");
		}
		if(e.getSource()==btnRetour)
		{
			menu m = new menu();
			frame.dispose();
		}
		

	}

}
