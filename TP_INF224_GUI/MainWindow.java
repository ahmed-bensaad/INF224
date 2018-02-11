import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import java.util.ArrayList;


public class MainWindow extends JFrame {
	private static final long serialVersionUID = 1L;
	private JTextArea textArea;
	private JTextField textField,textField2;
	private JRadioButton buttonPhoto;
	private JRadioButton buttonVideo;
	private JRadioButton buttonFilm;
	private JRadioButton buttonGroup;
	private JButton buttonSend;
	private ButtonGroup bg;
	private JTabbedPane tabbedPanel;
	private JPanel panelAdd;
	private JPanel panelDelete;
	private JPanel panelFind;
	private JPanel panelInsert;
	private JPanel panelPlay;
	private JScrollPane scrollPane;
	private JMenu menu;
	private JMenuBar menuBar;
	private MenuButton endMenuButton;

	private int nb_chapters;

	private String action = "Add";
	private String type = "";
	private String fileName = "";
	private String path;

	private Client client;
	private String request, response;

	private boolean success=true;

	public MainWindow() {
		client = null;

		try {
			client = new Client("localhost", 3331);
		}
		catch (Exception e) {
			System.err.println("Client: Couldn't connect to "+"localhost"+":"+3331);
			System.exit(1);
		}

		System.out.println("Client connected to "+"localhost"+":"+3331);


		this.setTitle("TP INF224");
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


		textArea = new JTextArea(30, 40);
		textField = new JTextField("Enter file name", 20);
		textField2 = new JTextField("Enter group name", 20);
		scrollPane = new JScrollPane(textArea);
		buttonPhoto = new JRadioButton("Image");
		buttonVideo = new JRadioButton("Video");
		buttonFilm = new JRadioButton("Film");
		buttonGroup = new JRadioButton("Group");
		buttonSend = new JButton("Send request");
		tabbedPanel = new JTabbedPane();
		panelAdd = new JPanel();
		panelDelete = new JPanel();
		panelFind = new JPanel();
		panelPlay = new JPanel();
		panelInsert = new JPanel();
		menu = new JMenu("Menu");
		menuBar = new JMenuBar();
		endMenuButton = new MenuButton("Quitter");


		bg = new ButtonGroup();
		bg.add(buttonPhoto);
		bg.add(buttonVideo);
		bg.add(buttonFilm);
		bg.add(buttonGroup);


		this.setPanel();
		this.setTabbedPanel();
		this.setButtonListeners();

		this.setTabbedPanelListeners();


		this.getContentPane().add(tabbedPanel, BorderLayout.SOUTH);
		this.getContentPane().add(scrollPane, BorderLayout.CENTER);
		this.pack();
		this.setVisible(true);
	}

	private void setPanel() {
		panelAdd.setName("Add");
		panelDelete.setName("Delete");
		panelFind.setName("Find");
		panelPlay.setName("Play");
		panelInsert.setName("Insert");


		panelAdd.add(buttonPhoto);
		panelAdd.add(buttonVideo);
		panelAdd.add(buttonFilm);
		panelAdd.add(buttonGroup);
		panelAdd.add(textField);
		panelAdd.add(buttonSend);
	}

	private void setTabbedPanel() {
		tabbedPanel.add(panelAdd, 0);
		tabbedPanel.add(panelDelete, 1);
		tabbedPanel.add(panelFind, 2);
		tabbedPanel.add(panelPlay, 3);
		tabbedPanel.add(panelInsert,4);
	}

	/*private void setMenu() {
		menu.add(endMenuButton);
	}

	private void setMenuBar() {
		menuBar.add(menu);
		menuBar.setVisible(true);
	}*/

	private void setButtonListeners() {
		ActionListener buttonListener = new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				if (buttonPhoto.isSelected())
					type = "image";
				else if (buttonVideo.isSelected())
					type = "video";
				else if (buttonFilm.isSelected())
					type = "film";
				else if (buttonGroup.isSelected())
					type = "group";
			}
		};
		buttonPhoto.addActionListener(buttonListener);
		buttonVideo.addActionListener(buttonListener);
		buttonFilm.addActionListener(buttonListener);
		buttonGroup.addActionListener(buttonListener);

		ActionListener sendButtonListener = new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				if (((tabbedPanel.getSelectedIndex() == 0) || (tabbedPanel.getSelectedIndex() == 1)) && ((!buttonPhoto.isSelected()) && (!buttonVideo.isSelected()) && (!buttonFilm.isSelected()) && (!buttonGroup.isSelected()))) {
					JOptionPane.showMessageDialog(null, "Choose file type", "Warning", JOptionPane.WARNING_MESSAGE);
				}
				else if (textField.getText().compareTo("Enter file name") == 0) {
					JOptionPane.showMessageDialog(null, "Choose file name", "Warning", JOptionPane.WARNING_MESSAGE);
				}

				else {
					fileName = textField.getText();
					if (tabbedPanel.getSelectedIndex() == 0){
						request = action + " " + type ;
						if(!buttonGroup.isSelected()){
						path = JOptionPane.showInputDialog(null, "Enter file path:", "Path");
						 request += " " + fileName+" "+path;
						}
						if (buttonPhoto.isSelected()){
						String longitude = JOptionPane.showInputDialog(null, "Enter longitude:", "0");
				        String latitude = JOptionPane.showInputDialog(null, "Enter latitude:", "0");
				       	try{
						int longe=Integer.parseInt(longitude);
						int lat=Integer.parseInt(latitude);
						}
						catch(Exception e1){
							success=false;
						}

				        request+=" "+longitude+" "+latitude;
					}
						else if (buttonVideo.isSelected()){
							String duration = JOptionPane.showInputDialog(null, "Enter video duration:", "0");
							try{
							int nb_chapters=Integer.parseInt(duration);
							request+=" "+duration;
							}
							catch(Exception e2){
								success=false;
						}						
						}
						else if (buttonFilm.isSelected()){
							int duration = 0;
							String nbr_chapters = JOptionPane.showInputDialog(null, "Enter the number of chapters:", "0");
							try{
						 	nb_chapters=Integer.parseInt(nbr_chapters);
							}catch(Exception e3){
								success=false;
							}
							if (success){
							JPanel myPanel = new JPanel();
							ArrayList<JTextField> durations= new ArrayList<JTextField>();
							for (int i=0;i<nb_chapters;i++){
      						myPanel.add(new JLabel("Duration of chapter "+(i+1)));
      						durations.add(new JTextField(5));	
      						myPanel.add(durations.get(i));
							}
						      	int result = JOptionPane.showConfirmDialog(null, myPanel, 
               				"Please Enter chapters duration", JOptionPane.OK_CANCEL_OPTION);
							if (result == JOptionPane.OK_OPTION) {
							for (int i=0;i<nb_chapters;i++){
								duration+=Integer.parseInt((durations.get(i)).getText());
							}
							request+=" "+duration+" "+nbr_chapters;
							for (int i=0;i<nb_chapters;i++){
								try{
								request+=" "+(durations.get(i)).getText();
								}
								catch(Exception e4){
									success=false;
									}
								}
							}
						}
						
						else{
							request="";
					}
				}
				}

					
					else if (tabbedPanel.getSelectedIndex() == 1)
						request = action + " " + type + " " + fileName;
					else if(tabbedPanel.getSelectedIndex()==4){
						request = action + " " + textField.getText()+ " " + textField2.getText();
					}
					else
						request = action + " " + fileName;
					textArea.append(">>>>>> Requête : " + request + '\n');

					if(success){
					response = client.send(request);
					response=response.replace(";","\n");
					}
					else{
					response="Error: Invalid Input. Request not sent";
					}
					textArea.append(">>> Réponse : " + response + '\n' + '\n');
					textField.setText("Enter file name");
					bg.clearSelection();

				}
			}
		};
		buttonSend.addActionListener(sendButtonListener);
	}

	private void setTabbedPanelListeners() {
		tabbedPanel.addChangeListener(new ChangeListener() {
			@Override
			public void stateChanged(ChangeEvent e) {
				switch(tabbedPanel.getSelectedIndex()){
				case 0:
					action = "Add";
					textField.setColumns(20);
					textField.setText("Enter file name");
					bg.clearSelection();
					panelAdd.add(buttonPhoto);
					panelAdd.add(buttonVideo);
					panelAdd.add(buttonFilm);
					panelAdd.add(buttonGroup);
					panelAdd.add(textField);
					panelAdd.add(buttonSend);
					break;
				case 1: 
					action = "Delete";
					textField.setColumns(20);
					textField.setText("Enter file name");
					bg.clearSelection();
					panelDelete.add(buttonPhoto);
					panelDelete.add(buttonVideo);
					panelDelete.add(buttonFilm);
					panelDelete.add(buttonGroup);
					panelDelete.add(textField);
					panelDelete.add(buttonSend);
					break;
				case 2:
					action = "Find";
					textField.setColumns(40);
					textField.setText("Enter file name");
					panelFind.add(textField);
					panelFind.add(buttonSend);
					break;
				case 3:
					action = "Play";
					textField.setText("Enter file name");
					textField.setColumns(40);
					panelPlay.add(textField);
					panelPlay.add(buttonSend);
					break;
				case 4:
					action="Insert";
					textField.setText("Enter file name");
					textField2.setText("Enter group name");
					textField.setColumns(20);
					textField2.setColumns(20);
					panelInsert.add(textField);
					panelInsert.add(textField2);
					panelInsert.add(buttonSend);
					break;


				}
			}
		});
	}

}
