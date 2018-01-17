package MainPackage;

import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainWindow extends JFrame {
	
	private static final long serialVersionUID = 1L;
	JButton button1,button2,button3;
	JTextArea textArea = new JTextArea(10,10);
	
	
	public static void main(String argv[]) {
		 new MainWindow();
		 } 
	
	public MainWindow() {
		
	    
	    this.setLayout(new BorderLayout());

		
		button1=new JButton("Button1");
		button2=new JButton("Button2");
		button3=new JButton("Button3");
		
		JPanel pane=new JPanel();
		pane.setLayout(new BoxLayout(pane,BoxLayout.PAGE_AXIS));
		
		
		JScrollPane scroll=new JScrollPane(textArea);
		
		
	    pane.add(button1);
	    pane.add(button2);
	    pane.add(button3);
	    
	    
	    add(pane,BorderLayout.EAST);    
	    add(scroll, BorderLayout.CENTER);

		
		button1.addActionListener(new Button1Listener());
		button2.addActionListener(new Button2Listener());
		button3.addActionListener(new Button3Listener());
		
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		pack();
		setVisible(true);
		
	}
	


class Button1Listener implements ActionListener{

	@Override
	public void actionPerformed(ActionEvent e) {
		textArea.append("Button1 Clicked \n");
		
	}
}

class Button2Listener implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent e) {
			textArea.append("Button2 Clicked \n");
			
		}
	
}

class Button3Listener implements ActionListener{

	@Override
	public void actionPerformed(ActionEvent e) {
		textArea.append("Button3 Clicked \n");
		
	}

}





}
