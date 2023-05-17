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

public class ajouter implements ActionListener {
	
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
	ImageIcon i2 = new ImageIcon(".//src//test//location.png");
	ImageIcon i3 = new ImageIcon(".//src//test//i3.png");
	ImageIcon i4 = new ImageIcon(".//src//test//i4.png");
	ImageIcon i5 = new ImageIcon(".//src//test//siege.png");
	ImageIcon date = new ImageIcon(".//src//test//date.png");
	JButton done = new JButton();
	ImageIcon donei = new ImageIcon(".//src//test//done.png");
	JButton btnRetour = new JButton();
	ImageIcon btn = new ImageIcon(".//src//test//home.png");
	
	ajouter(){
		//lab:
		lab.setBounds(50, 80,880, 580);
		lab.setBackground(new Color(255,110,32));
		lab.setOpaque(true);
		lab.setBorder(bordlab2);
		lab.add(text1);
		lab.add(text2);
		lab.add(text3);
		lab.add(text4);
		lab.add(text5);
		lab.add(text6);
		lab.add(text7);
		//lab.add(text8);
		lab.add(lab1);
		lab.add(lab3);
		lab.add(lab2);
		lab.add(lab4);
		lab.add(lab5);
		lab.add(lab6);
		lab.add(lab7);
		//lab.add(lab8);
		lab.add(done);
		//panel:
		panel.setBounds(0,0,1000,712);
		panel.setBackground(new Color(255,231,208));	
		panel.add(lab);
		panel.setLayout(null);
		panel.add(buttonRetour);
		panel.add(btnRetour);
		//btn:
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
		//texts:
		text1.setBounds(10,110,400,40);
		text1.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		text2.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text2.setBounds(450,110,400,40);
		
		text3.setBounds(10,220,400,40);
		text3.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text4.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text4.setBounds(450,220,400,40);
		text5.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text5.setBounds(10,330,400,40);
		text6.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text6.setBounds(450,330,400,40);
		text7.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text7.setBounds(10,440,400,40);
		
		text8.setFont(new Font("TimesRoman", Font.BOLD, 25));
		text8.setBounds(450,440,400,40);
		//labs:
		lab1.setIcon(i1);
		lab1.setBounds(10, 50, 400, 60);
		lab1.setText("ID TRAIN");
		lab1.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab2.setIcon(i2);
		lab2.setBounds(450, 50, 400, 60);
		lab2.setText("VILLE DEPART");
		lab2.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab3.setIcon(i2);
		lab3.setBounds(10, 160, 400, 60);
		lab3.setText("VILLE ARRIVE");
		lab3.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab4.setIcon(date);
		lab4.setBounds(450, 160, 400, 60);
		lab4.setText("DATE DEPART");
		lab4.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab5.setIcon(i3);
		lab5.setBounds(10, 270, 400, 60);
		lab5.setText("HORAIRE DEPART");
		lab5.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab6.setIcon(i3);
		lab6.setBounds(450, 270, 400, 60);
		lab6.setText("HORAIRE ARRIVE");
		lab6.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab7.setIcon(i4);
		lab7.setBounds(10, 380, 400, 60);
		lab7.setText("PRIX");
		lab7.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab8.setIcon(i5);
		lab8.setBounds(450, 380, 400, 60);
		lab8.setText("NOMBRE DE PLACE ");
		lab8.setFont(new Font("TimesRoman", Font.BOLD, 25));
		//done:
		done.setIcon(donei);
		done.setBounds(350,500,150,60);
		done.setBackground(new Color(255,231,208));
		done.setFocusable(false);
		done.addActionListener(this);


		//frame:
		frame.setLayout(null);
		frame.setSize(1000,712);
		frame.setVisible(true);
		frame.add(panel);
		frame.setTitle("-- VISION DES TRAINS DISPONIBLES --");
		frame.setResizable(false);
		frame.setIconImage(image.getImage());
	}
	public static void ajoutertrajet( JTextField text1, JTextField text2, JTextField text3, JTextField text4,JTextField text5,JTextField text6, JTextField text7){        //ajoutertrajet
        try {
            Connection c = DriverManager.getConnection(
                    "jdbc:mysql://localhost/traindatabase?serverTimezone=UTC",
                    "root",
                    ""
            );

            String sql = "INSERT INTO trajets(idTrain, villeDepart, villeArrive, dateDepart, horaireDepart, horaireArrive, prix) VALUES (?,?,?,?,?,?,?)";
            PreparedStatement s = c.prepareStatement(sql);
            s.setString(1, text1.getText().toString());
            s.setString(2, text2.getText().toString());
            s.setString(3, text3.getText().toString());
            s.setString(4, text4.getText().toString());
            s.setString(5, text5.getText().toString());
            s.setString(6, text6.getText().toString());
            s.setFloat(7,Float.parseFloat( text7.getText()));
            s.execute();
            JOptionPane.showMessageDialog(null,"Ce trajet a été ajouté avec succès");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource()==buttonRetour) {
			admin3 a = new admin3();
			frame.dispose();
		}
		if(e.getSource()==done)
		{
			ajoutertrajet(text1,text2,text3,text4,text5,text6,text7);
			text1.setText("");
			text2.setText("");
			text3.setText("");
			text4.setText("");
			text5.setText("");
			text6.setText("");
			text7.setText("");

		}
		if(e.getSource()==btnRetour)
		{
			menu m = new menu();
			frame.dispose();
		}
		
		
	}


}

