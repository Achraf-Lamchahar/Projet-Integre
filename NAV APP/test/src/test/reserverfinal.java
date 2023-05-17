package test;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.Border;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


import net.proteanit.sql.DbUtils;

import javax.swing.JScrollPane;
import javax.swing.JTable;

public class reserverfinal implements ActionListener {


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
	JTextField VD =  new JTextField();
	JTextField VA =  new JTextField();
	JTextField DATE =  new JTextField();
	JTextField HR =  new JTextField();
	JTextField ID =  new JTextField();
	JTextField NOM =  new JTextField();
	JTextField text7 =  new JTextField();
	JTextField text8 =  new JTextField();
	ImageIcon i1 = new ImageIcon(".//src//test//i1.png");
	ImageIcon i2 = new ImageIcon(".//src//test//train.png");
	ImageIcon i3 = new ImageIcon(".//src//test//i3.png");
	ImageIcon i4 = new ImageIcon(".//src//test//i4.png");
	ImageIcon i5 = new ImageIcon(".//src//test//location.png");
	ImageIcon date = new ImageIcon(".//src//test//date.png");
	JButton done = new JButton();
	JButton res = new JButton();
	ImageIcon donei = new ImageIcon(".//src//test//done.png");
	JButton btnRetour = new JButton();
	ImageIcon btn = new ImageIcon(".//src//test//home.png");
	ImageIcon heure = new ImageIcon(".//src//test//heure.png");
	private JTable table;



	
	reserverfinal(){
		//lab:
		lab.setBounds(10, 60,480, 610);
		lab.setBackground(new Color(255,110,32));
		lab.setOpaque(true);
		lab.setBorder(bordlab2);
		lab.add(VD);
		lab.add(VA);
		lab.add(HR);
		lab.add(DATE);
		lab.add(ID);

		//lab.add(text8);
		lab.add(lab1);
		lab.add(lab3);
		lab.add(lab5);
		lab.add(lab4);
		lab.add(done);
		lab.add(lab2);
		lab.add(res);
		lab.add(lab2);
		//panel:
		panel.setBounds(0,0,1000,712);
		panel.setBackground(new Color(255,231,208));	
		panel.add(lab);
		panel.setLayout(null);
		panel.add(buttonRetour);
		panel.add(btnRetour);
		panel.add(NOM);
		panel.add(lab8);
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
		VD.setBounds(50,60,400,40);
		VD.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		
		VA.setBounds(50,170,400,40);
		VA.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		DATE.setFont(new Font("TimesRoman", Font.BOLD, 25));
		DATE.setBounds(50,280,400,40);
		
		HR.setFont(new Font("TimesRoman", Font.BOLD, 25));
		HR.setBounds(50,380,400,40);
		
		
		ID.setBounds(50,480,400,40);
		ID.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		NOM.setBounds(540,50,400,40);
		NOM.setFont(new Font("TimesRoman", Font.BOLD, 25));

		
		
		
		//labs:
		
		lab1.setIcon(i5);
		lab1.setBounds(50, 5, 400, 60);
		lab1.setText("VILLE DEPART");
		lab1.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		
		lab3.setIcon(i5);
		lab3.setBounds(50, 110, 400, 60);
		lab3.setText("VILLE ARRIVE");
		lab3.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab5.setIcon(date);
		lab5.setBounds(50, 220, 400, 60);
		lab5.setText("DATE DEPART ");
		lab5.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab4.setIcon(heure);
		lab4.setBounds(50, 320, 400, 60);
		lab4.setText("HORAIRE DEPART ");
		lab4.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
		lab2.setIcon(i1);
		lab2.setBounds(50, 420, 400, 60);
		lab2.setText("ID TITRE");
		lab2.setFont(new Font("TimesRoman", Font.BOLD, 25));
		
	
		lab8.setBounds(540, 2, 400, 60);
		lab8.setText("NOM PRENOM");
		lab8.setFont(new Font("TimesRoman", Font.BOLD, 25));

		

		//done:
		done.setIcon(donei);
		done.setText("AFFICHER");
		done.setBounds(50,540,150,60);
		done.setBackground(new Color(255,231,208));
		done.setFocusable(false);
		done.addActionListener(this);
		//res
		res.setIcon(donei);
		res.setBounds(250,540,150,60);
		res.setBackground(new Color(255,231,208));
		res.setFocusable(false);
		res.addActionListener(this);
		res.setText("RESERVER");
		res.disable();

		//frame:
		frame.getContentPane().setLayout(null);
		frame.setSize(1000,712);
		frame.setVisible(true);
		frame.getContentPane().add(panel);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(510, 100, 456, 526);
		panel.add(scrollPane);
		
		table = new JTable();
		scrollPane.setViewportView(table);
		scrollPane.setBorder(bordlab2);
		frame.setTitle("-- AJOUTER UN TRAIN --");
		frame.setResizable(false);
		frame.setIconImage(image.getImage());
	}
	 public static void afficher(JTable table , JTextField VD, JTextField VA,JTextField DATE,JTextField HR){
	        try {
	            Connection c = DriverManager.getConnection(
	                    "jdbc:mysql://localhost:3306/traindatabase",
	                    "root",
	                    ""
	            );
	            String sql="select * from trajets where villeDepart like \'"+VD.getText()+"\' and "
	            		+ "villeArrive = \'"+VA.getText()+"\' and dateDepart = \'"+DATE.getText()+"\' and HoraireDepart >= \'"+HR.getText()+"\';";
	            Statement s = c.createStatement();
	           //
	            ResultSet result = s.executeQuery(sql);

	            table.setModel(DbUtils.resultSetToTableModel(result));
	            
	            
	            c.close();
	            
	        } catch (SQLException e) {
	            throw new RuntimeException(e);
	        }
	 }
	 
	 
	 public static void reserver(JTextField ID, JTextField NOM, JTextField VD, JTextField VA,JTextField DATE,JTextField HR){
         try {
             Connection c = DriverManager.getConnection(
                     "jdbc:mysql://localhost/traindatabase?serverTimezone=UTC",
                     "root",
                     ""
             );

             Statement s = c.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
             ResultSet r = s.executeQuery("SELECT nbUtlisations FROM titres where idTitre = \'" +ID.getText()+"\' ;");
             
             int nbUtilisations;
             while(r.next()) {
            	 nbUtilisations= r.getInt(1);
            	 if(nbUtilisations<=2) {
               	  //ajout d'une ligne dans la table ticket
                    String sql1 = "INSERT INTO `ticket`(`NomPrenom`, `villeDepart`, `villeArrive`, `dateDepart`, `horaireDepart`) VALUES (?,?,?,?,?) ;";
                    PreparedStatement s1 = c.prepareStatement(sql1);
                    s1.setString(1, NOM.getText().toUpperCase());
                    s1.setString(2, VD.getText().toUpperCase());
                    s1.setString(3, VA.getText().toUpperCase());
                    s1.setString(4, DATE.getText().toUpperCase());
                    s1.setString(5, HR.getText().toUpperCase());
                    s1.execute();

                    JOptionPane.showMessageDialog(null, "Reservation effectuee avec succes. Preparez votre valise!");
                }
                else {
              	  JOptionPane.showMessageDialog(null,"Vous avez depasse le nombre de reservations autorise par ce titre de permissions");
                   
                }
             }
             
             }catch(Exception e) {
            	 JOptionPane.showMessageDialog(null,"Une erreur est survenue lors de la reservation. Veuillez reessayer."+e);
             }
     }
             
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource()==done)
		{
			afficher(table,VD,VA,DATE,HR);
			res.enable();
		}
		if(e.getSource()==buttonRetour)
		{
			menu m = new menu();
			frame.dispose();
		}
		if(e.getSource()==btnRetour)
		{
			
			verification v = new verification();
			frame.dispose();
		}
		if(e.getSource()==res)
		{
			reserver(ID,NOM,VD,VA,DATE,HR);
		}
		
	}
}
