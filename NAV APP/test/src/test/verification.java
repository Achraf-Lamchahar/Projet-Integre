package test;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class verification implements ActionListener {
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
	JTextField idtitre =  new JTextField();
	JTextField NOM =  new JTextField();
	JTextField VD =  new JTextField();
	JTextField HR =  new JTextField();
	JTextField DATE =  new JTextField();
	JTextField VA =  new JTextField();
	JTextField text7 =  new JTextField();
	JTextField text8 =  new JTextField();
	ImageIcon i1 = new ImageIcon(".//src//test//i1.png");
	ImageIcon i2 = new ImageIcon(".//src//test//name.png");
	ImageIcon i3 = new ImageIcon(".//src//test//i3.png");
	ImageIcon i4 = new ImageIcon(".//src//test//i4.png");
	ImageIcon i5 = new ImageIcon(".//src//test//location.png");
	ImageIcon date = new ImageIcon(".//src//test//date.png");
	JButton done = new JButton();
	ImageIcon donei = new ImageIcon(".//src//test//done.png");
	JButton btnRetour = new JButton();
	ImageIcon btn = new ImageIcon(".//src//test//home.png");
	ImageIcon heure = new ImageIcon(".//src//test//heure.png");
	JButton done1 = new JButton();
	
	verification(){

	//lab:
	lab.setBounds(20, 80,950, 580);
	lab.setBackground(new Color(255,110,32));
	lab.setOpaque(true);
	lab.setBorder(bordlab2);
	lab.add(idtitre);
	lab.add(NOM);
	lab.add(VD);
	lab.add(DATE);
	lab.add(HR);
	//lab.add(text7);
	//lab.add(text8);

	
	//lab.add(text8);
	lab.add(lab1);
	lab.add(lab3);
	lab.add(lab5);
	lab.add(lab6);
	lab.add(lab2);
	lab.add(lab4);
	lab.add(VA);
	lab.add(done1);
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
	idtitre.setBounds(50,110,400,40);
	idtitre.setFont(new Font("TimesRoman", Font.BOLD, 25));
	
	
	NOM.setBounds(50,220,400,40);
	NOM.setFont(new Font("TimesRoman", Font.BOLD, 25));
	
	VD.setFont(new Font("TimesRoman", Font.BOLD, 25));
	VD.setBounds(50,330,400,40);
	
	VA.setFont(new Font("TimesRoman", Font.BOLD, 25));
	VA.setBounds(50,440,400,40);	
	
	DATE.setBounds(470,110,400,40);
	DATE.setFont(new Font("TimesRoman", Font.BOLD, 25));
	
	
	HR.setBounds(470,220,400,40);
	HR.setFont(new Font("TimesRoman", Font.BOLD, 25));
	
	/*text7.setFont(new Font("TimesRoman", Font.BOLD, 25));
	text7.setBounds(470,330,400,40);
	
	text8.setFont(new Font("TimesRoman", Font.BOLD, 25));
	text8.setBounds(470,440,400,40);	*/
	//labs:
	lab1.setIcon(i1);
	lab1.setBounds(50, 50, 400, 60);
	lab1.setText("ID TITRE");
	lab1.setFont(new Font("TimesRoman", Font.BOLD, 25));
	
	
	lab3.setIcon(i2);
	lab3.setBounds(50, 160, 400, 60);
	lab3.setText("NOM PRENOM");
	lab3.setFont(new Font("TimesRoman", Font.BOLD, 25));
	
	
	lab5.setIcon(i5);
	lab5.setBounds(50, 270, 400, 60);
	lab5.setText("VILLE DEPART ");
	lab5.setFont(new Font("TimesRoman", Font.BOLD, 25));
	
	lab6.setIcon(i5);
	lab6.setBounds(50, 380, 400, 60);
	lab6.setText("VILLE ARRIVE ");
	lab6.setFont(new Font("TimesRoman", Font.BOLD, 25));
	
	lab2.setIcon(date);
	lab2.setBounds(470, 50, 400, 60);
	lab2.setText("DATE DEPART");
	lab2.setFont(new Font("TimesRoman", Font.BOLD, 25));

	lab4.setIcon(heure);
	lab4.setBounds(470, 160, 400, 60);
	lab4.setText("HORAIRE DEPART");
	lab4.setFont(new Font("TimesRoman", Font.BOLD, 25));

	
	//done:
	done.setIcon(donei);
	done.setFont(new Font("TimesRoman", Font.BOLD, 15));
	done.setText("Vérifier");
	done.setBounds(170,500,150,60);
	done.setBackground(new Color(255,231,208));
	done.setFocusable(false);
	done.addActionListener(this);
	//done1:
	done1.setIcon(donei);
	done1.setFont(new Font("TimesRoman", Font.BOLD, 15));
	done1.setText("Réserver");
	done1.setBounds(600,500,150,60);
	done1.setBackground(new Color(255,231,208));
	done1.setFocusable(false);
	done1.addActionListener(this);
	done1.setVisible(false);

	//frame:
	frame.setLayout(null);
	frame.setSize(1000,712);
	frame.setVisible(true);
	frame.add(panel);
	frame.setTitle("-- AJOUTER UN TRAIN --");
	frame.setResizable(false);
	frame.setIconImage(image.getImage());
}
	

	
	public static boolean verifier(JTextField idtitre, JTextField NOM, JTextField VD, JTextField VA,JTextField DATE,JTextField HR){                  //Function verify data titra
        try {
            Connection c = DriverManager.getConnection(
                    "jdbc:mysql://localhost/traindatabase?serverTimezone=UTC",
                    "root",
                    ""
            );

            Statement s = c.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
            ResultSet r = s.executeQuery("SELECT * FROM titres");
            ResultSetMetaData rm = r.getMetaData();
            while(r.next()) {
            	if(r.getString(1).equalsIgnoreCase(idtitre.getText()) && r.getString(2).equalsIgnoreCase(NOM.getText()) && r.getString(3).equalsIgnoreCase(VD.getText()) &&
            			r.getString(4).equalsIgnoreCase(VA.getText()) ) {
            		return true;
            	}
            }

            c.close();
            return false;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
}



	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource()==buttonRetour)
		{
			voyageur a2 = new voyageur();
			frame.dispose();
		}
		if(e.getSource()==btnRetour)
		{
			menu m = new menu();
			frame.dispose();
		}
		if(e.getSource()==done)
		{
			if(verifier(idtitre,NOM,VD,VA,DATE,HR)==true)
			{
				reserverfinal rf = new reserverfinal();
				frame.dispose();
			}
			/*else{
				
				idtitre.setText("");
				HR.setText("");
				VA.setText("");
				VD.setText("");
				DATE.setText("");
				NOM.setText("");
				
			}*/

			
		}
		
	}
}
