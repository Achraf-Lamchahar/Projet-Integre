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
import javax.swing.JTable;
import javax.swing.border.Border;

import net.proteanit.sql.DbUtils;
import javax.swing.JScrollPane;


public class voyageur implements ActionListener {
	
	JFrame frame =new JFrame();
	JLabel lab = new JLabel();
	JPanel panel = new JPanel();
	ImageIcon image = new ImageIcon(".//src//test//1.png");
	Border bordlab2 = BorderFactory.createLineBorder(Color.black,4);
	Border bordtable = BorderFactory.createLineBorder(new Color(255,231,208),4);
	JButton buttonRetour = new JButton();
	JButton buttonReservation = new JButton();
	JButton buttonVision = new JButton();
	/*JButton buttonRetour = new JButton();
	JButton buttonRetour = new JButton();
	JButton buttonRetour = new JButton();
	JButton buttonRetour = new JButton();*/
	ImageIcon retour = new ImageIcon(".//src//test//home.png");
	ImageIcon vision = new ImageIcon(".//src//test//vision1.png");
	ImageIcon booking = new ImageIcon(".//src//test//booking.png");
	JLabel lab1 = new JLabel();
	JLabel lab2 = new JLabel();
	JLabel lab3 = new JLabel();
	JLabel lab4 = new JLabel();
	JLabel lab5 = new JLabel();
	private final JScrollPane scrollPane = new JScrollPane();
	private JTable table_1;


	voyageur(){
		//lab5:
		lab5.setBounds(0,70,1000,20);
		lab5.setBackground(new Color(255,110,32));
		lab5.setOpaque(true);
		//lab4:
		lab4.setText("ESPACE VOYAGEURs");
		lab4.setForeground(new Color(255,110,32));
		lab4.setFont(new Font("Algerian", Font.BOLD, 40));
		lab4.setBounds(300,20,700,50);
	
		lab.setBounds(2, 200,450, 400);
		lab.setBackground(new Color(255,110,32));
		lab.setOpaque(true);
		lab.setBorder(bordlab2);
		lab.add(buttonReservation);
		lab.add(buttonVision);
		//panel:
		panel.setBounds(0,0,1000,712);
		panel.setBackground(new Color(255,231,208));	
		panel.add(lab);
		panel.setLayout(null);
		panel.add(buttonRetour);
		panel.add(lab4);
		panel.add(lab5);
		//button de retour
		buttonRetour.setIcon(retour);
		buttonRetour.setBounds(5,5,60,50);
		buttonRetour.setBackground(new Color(252,110,32));
		buttonRetour.addActionListener(this);
		buttonRetour.setFocusable(false);
		//buttonReservation:
		lab1.setIcon(booking);
		lab1.setBounds(5,20,500,70);
		lab1.setText("-- Réserver un siège  --");
		lab1.setFont(new Font("TimesRoman", Font.BOLD, 25));
		lab1.setForeground(new Color(255,110,32));
		buttonReservation.add(lab1);
		buttonReservation.setHorizontalAlignment(JLabel.LEFT);
		buttonReservation.setHorizontalTextPosition(JLabel.RIGHT);
		buttonReservation.setBounds(10,200,430,100);
		buttonReservation.setBackground(Color.white);
		buttonReservation.addActionListener(this);
		buttonReservation.setFocusable(false);
		buttonReservation.setLayout(null);
		//buttonVision:
		
		lab3.setIcon(vision);
		lab3.setBounds(5,20,500,70);
		lab3.setText("-- Voir les trains disponibles --");
		lab3.setFont(new Font("TimesRoman", Font.BOLD, 25));
		lab3.setForeground(new Color(255,110,32));
		buttonVision.add(lab3);
		buttonVision.setBounds(10,80,430,100);
		buttonVision.setBackground(Color.white);
		buttonVision.addActionListener(this);
		buttonVision.setFocusable(false);
		buttonVision.setLayout(null);
		//frame:
		frame.getContentPane().setLayout(null);
		frame.setSize(1000,712);
		frame.setVisible(true);
		frame.getContentPane().add(panel);
		scrollPane.setBounds(462, 200, 510, 400);
		
		panel.add(scrollPane);
		
		table_1 = new JTable();
		scrollPane.setViewportView(table_1);
		//scrollPane.setBorder(bordtable);
		frame.setTitle("-- ESPACE VOYAGEUR --");
		frame.setResizable(false);
		frame.setIconImage(image.getImage());

		
		
	}
	public  void afficherTrajets(JTable table){       //finished
        try {
            Connection c = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/traindatabase",
                    "root",
                    ""
            );
            String sql="select * from trajets";
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
		if(e.getSource()==buttonRetour)
		{
			menu m1 = new menu();
			frame.dispose();
		}
		if(e.getSource()==buttonVision)
		{
			
			afficherTrajets(table_1);
			
			
		}
		if(e.getSource()==buttonReservation)
		{
			verification r1 = new verification();
			frame.dispose();
		}
		
}
}
