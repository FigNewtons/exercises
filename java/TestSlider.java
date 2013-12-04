/*      		Test Slider 
			Created by: FigNewtons

		Practice implementing a slider
		and using Box.Filler for formatting 
*/

import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;

public class TestSlider extends JFrame implements ActionListener, ChangeListener
{
	// Frame dimensions
	private final int WINDOW_WIDTH = 400;
	private final int WINDOW_HEIGHT = 250;

	// Slider default values 
	static final int MIN = 0;
	static final int MAX = 100;	
	static final int DEFAULT = 50;

	// Padding default dimension 
	private Dimension padding = new Dimension(5, 50);

	// Panel + components 
	private JPanel panel;
	private JSlider slider;
	private JButton button; 
	private JLabel output; 

	// Value outputed from slider when button is hit
	private int num = DEFAULT;

	//Constructor 
	public TestSlider()
	{
		// Frame defaults 
		setTitle("Test Slider");
		setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// Create label 
		output = new JLabel("Value entered: " + num);

		// Create slider
		slider = new JSlider(JSlider.HORIZONTAL, MIN, MAX, DEFAULT);
		slider.setMajorTickSpacing(10);
		slider.setMinorTickSpacing(2);
		slider.setPaintTicks(true);
		slider.setPaintLabels(true);
		slider.setPreferredSize(new Dimension(WINDOW_WIDTH - 10, WINDOW_HEIGHT / 6));
		slider.addChangeListener(this);
		
		// Create button
		button = new JButton("Submit");
		button.addActionListener(this);

		// Create panel and add components 
		panel = new JPanel();
		panel.add(output);
		panel.add(new Box.Filler(padding, padding, padding));
		panel.add(slider);
		panel.add(new Box.Filler(padding, padding, padding));
		panel.add(button);

		add(panel);
		
		setVisible(true);
	}

	// Change listener for slider 
	public void stateChanged(ChangeEvent e)
	{
		JSlider source = (JSlider)e.getSource();
		if (!source.getValueIsAdjusting())
		{
			num = (int)source.getValue();
		}

	}

	// Action listener for button 
	public void actionPerformed(ActionEvent e)
	{
		if (e.getSource() == button)
			{output.setText("Current value: " + num);}

	}

	// Main 
	public static void main(String[] args)
	{
		new TestSlider();
	}

}
