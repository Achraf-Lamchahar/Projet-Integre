package test;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.Border;

import net.proteanit.sql.DbUtils;

import javax.swing.JScrollPane;
import javax.swing.JTable;

public class admin2 implements ActionListener {
	
	JLabel lab = new JLabel();
	JFrame frame = new JFrame();
	Border bordlab2 = BorderFactory.createLineBorder(Color.black,4);
	JPanel panel = new JPanel();
	JButton buttonRetour = new JButton();
	ImageIcon image = new ImageIcon(".//src//test//1.png");
	ImageIcon retour = new ImageIcon(".//src//test//return.png");
	ImageIcon delete1 = new ImageIcon(".//src//test//delete.png");
	ImageIcon add = new ImageIcon(".//src//test//add.png");
	ImageIcon vision = new ImageIcon(".//src//test//vision1.png");
	JButton ajouter = new JButton();
	JButton afficher = new JButton();
	JButton delete = new JButton();
	JLabel lab1 = new JLabel();
	JLabel lab2= new JLabel();
	JLabel lab3 = new JLabel();
	JLabel lab4 = new JLabel();
	JLabel lab5= new JLabel();
	JLabel lab6 = new JLabel();
	private final JScrollPane scrollPane = new JScrollPane();
	private final JTable table = new JTable();
	JButton btnRetour = new JButton();
	ImageIcon btn = new ImageIcon(".//src//test//home.png");

	admin2(){
		//lab5:
		lab5.setBounds(0,70,1000,20);
		lab5.setBackground(new Color(255,110,32));
		lab5.setOpaque(true);
		//lab4:
		lab4.setText("Manipulation Des Trains");
		lab4.setForeground(new Color(255,110,32));
		lab4.setFont(new Font("Algerian", Font.BOLD, 40));
		lab4.setBounds(200,20,700,50);
		//lab:
		lab.setBounds(20, 150,400, 400);
		lab.setBackground(new Color(255,110,32));
		lab.setOpaque(true);
		lab.setBorder(bordlab2);
		lab.add(afficher);
		lab.add(ajouter);
		lab.add(delete);
		//panel:
		panel.setBounds(0,0,1000,712);
		panel.setBackground(new Color(255,231,208));	
		panel.add(lab);
		panel.setLayout(null);
		panel.add(buttonRetour);
		panel.add(lab4);
		panel.add(lab5);
		panel.add(btnRetour);
		//buttonRetour:
		buttonRetour.setIcon(retour);
		buttonRetour.setBounds(5,5,60,50);
		buttonRetour.setBackground(new Color(255,110,32));
		buttonRetour.addActionListener(this);
		buttonRetour.setFocusable(false);
		//afficher:
		lab1.setIcon(vision);
		lab1.setBounds(15,5,500,70);
		lab1.setText("-- Voir Les Trains --");
		lab1.setFont(new Font("TimesRoman", Font.BOLD, 25));
		lab1.setForeground(new Color(255,102,0));
		afficher.add(lab1);
		afficher.setHorizontalAlignment(JLabel.LEFT);
		afficher.setHorizontalTextPosition(JLabel.RIGHT);
		afficher.setBounds(20,50,350,80);
		afficher.setBackground(Color.white);
		afficher.addActionListener(this);
		afficher.setFocusable(false);
		afficher.setLayout(null);
		//ajouter
		lab3.setIcon(add);
		lab3.setBounds(15,5,500,70);
		lab3.setText("-- Ajouter Un Train  --");
		lab3.setFont(new Font("TimesRoman", Font.BOLD, 25));
		lab3.setForeground(new Color(255,102,0));
		ajouter.add(lab3);
		ajouter.setBounds(20,150,350,80);
		ajouter.setBackground(Color.white);
		ajouter.addActionListener(this);
		ajouter.setFocusable(false);
		ajouter.setLayout(null);
		//btn
		btnRetour.setIcon(btn);
		btnRetour.setBounds(70,5,60,50);
		btnRetour.setBackground(new Color(255,110,32));
		btnRetour.addActionListener(this);
		btnRetour.setFocusable(false);

		//vision des trajets :
		lab2.setIcon(delete1);
		lab2.setBounds(1,5,500,70);
		lab2.setText("--  Supprimer Un Train  --");
		lab2.setFont(new Font("TimesRoman", Font.BOLD, 25));
		lab2.setForeground(new Color(255,110,32));
		delete.add(lab2);
		delete.setHorizontalAlignment(JLabel.LEFT);
		delete.setHorizontalTextPosition(JLabel.RIGHT);
		delete.setBounds(20,250,350,80);
		delete.setBackground(Color.white);
		delete.addActionListener(this);
		delete.setFocusable(false);
		delete.setLayout(null);
		//frame:
		frame.getContentPane().setLayout(null);
		frame.setSize(1000,712);
		frame.setVisible(true);
		frame.getContentPane().add(panel);
		scrollPane.setBounds(460, 150, 507, 397);
		panel.add(scrollPane);
		scrollPane.setViewportView(table);
		scrollPane.setBorder(bordlab2);
		frame.setTitle("-- Manipulation des Trains --");
		frame.setResizable(false);
		frame.setIconImage(image.getImage());


		
	}
	public  void afficherTrains(JTable table){       //finished
        try {
            Connection c = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/traindatabase",
                    "root",
                    ""
            );
            String sql="select * from train";
            Statement stmt = c.createStatement();
            ResultSet result = stmt.executeQuery(sql);
           //
            table.setModel(DbUtils.resultSetToTableModel(result));
            
            c.close();
            
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    
	}


	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource()==buttonRetour) {
			admin1 a = new admin1();
			frame.dispose();
		}
		if(e.getSource()==afficher)
		{
			afficherTrains(table);
		}
		if(e.getSource()==ajouter)
		{
			ajouterTrain tr= new ajouterTrain();
			frame.dispose();
		}
		if(e.getSource()==delete)
		{
			supprimertrain st = new supprimertrain();
			frame.dispose();
		}
		if(e.getSource()==btnRetour)
		{
			menu m = new menu();
			frame.dispose();
		}

	}


	
	
}
