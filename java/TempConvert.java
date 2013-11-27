/* 		Celsius Converter
		Created by: Fig Newtons

		Practice with Java GUIs
	
*/
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class TempConvert extends JFrame
{
	// Frame dimensions
	private final int WINDOW_WIDTH = 400;
	private final int WINDOW_HEIGHT = 300;

	// Panel and panel objects
	private JPanel panel; 
	private JLabel prompt; 
	private JTextField input;
	private ButtonGroup radioBtnGroup;
	private JRadioButton fahrenheitBtn;
	private JRadioButton kelvinBtn;
	private JButton btnConvert;

	// Constructor 
	public TempConvert()
	{
		// Frame defaults 
		setTitle("Temperature Converter");
		setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// Label and text field 
		prompt = new JLabel("Enter the temperature in celsius:");
		input = new JTextField(10);

		// Radio buttons
		fahrenheitBtn = new JRadioButton("Convert to fahrenheit: ");
		fahrenheitBtn.addActionListener(new ButtonListener());

		kelvinBtn = new JRadioButton("Convert to Kelvin: ");
		kelvinBtn.addActionListener(new ButtonListener());

		// Convert button 
		btnConvert = new JButton("Convert");
		btnConvert.addActionListener(new ButtonListener());

		// Radio Button Group
		radioBtnGroup = new ButtonGroup();
		radioBtnGroup.add(fahrenheitBtn);
		radioBtnGroup.add(kelvinBtn);

		// Create panel 
		panel = new JPanel();
		panel.add(prompt);
		panel.add(input);
		panel.add(fahrenheitBtn);
		panel.add(kelvinBtn);
		panel.add(btnConvert);
		add(panel);
		
		// Make window visible 
		setVisible(true);
	}

	// Action listener 
	private class ButtonListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			// Parse user input
			String str = input.getText().trim();
			double celsius;
	
			// Input validation 
			if(str.equals("")) 
				{celsius = -274.0;}
			else
			{celsius = Double.parseDouble(str);}

			// Output
			String units = " ";			
			double result = 0.0; 
			

			// See which radio button is clicked
			if(fahrenheitBtn.isSelected() && celsius > -274)
			{
				result = (9.0 / 5) * celsius + 32;
				units = " Degrees Fahrenheit";
			}
			else if (kelvinBtn.isSelected() && celsius > -274)
			{
				result = celsius + 273; 
				units = " Kelvin";
			}
			else
			{
				result = -274;
			}

			// Convert button clicked -- display conversion
			if(e.getSource() == btnConvert)
			{	
				if(result > -274)
				{
					JOptionPane.showMessageDialog(null, result + units);
				}
				else
				{
					JOptionPane.showMessageDialog(null, "Invalid value entered.");
				}
			}
		}
	}

	// Main 
	public static void main(String[] args)
	{
		new TempConvert();
	}
}
