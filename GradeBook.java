/* Sample Grade Book
   Created by: FigNewtons
   Date: November 1, 2013

   Practicing with classes and arrays
*/
import java.util.ArrayList;
import java.util.Scanner;

public class GradeBook
{
	private ArrayList<String> names = new ArrayList<>();
	private char[] letterGrades;
	private double[][] testScores;
	private double[] testAverage;

	Scanner input = new Scanner(System.in);

	//----------------- Constructor ------------------
	public GradeBook(int students, int tests)
	{
		this.letterGrades = new char[students];
		this.testScores = new double[students][tests];
		this.testAverage = new double[students];

		for (int i = 0; i < students; i++)
			{
				setName(i);
				setScores(i, tests);
				testAverage[i] = calcAverage(i, tests);
				setLetter(i, this.getAverage(i));
			}

	}

	//------------------- Accesors -------------------
	public String getName(int subscript)
	{
		return names.get(subscript);
	}

	public double getAverage(int subscript)
	{
		return testAverage[subscript];
	}

	public char getLetter(int subscript)
	{
		return letterGrades[subscript];
	}

	//------------------- Mutators -------------------
	public void setName(int subscript)
	{
		System.out.print("Enter the student's name: ");
		String name = input.nextLine();
		names.add(subscript, name);
	}

	public void setScores(int subscript, int tests)
	{

		for (int index = 0; index < tests; index++)
			{
				double score; 

				do
				{
					System.out.print("Enter test score #" + (index+1) + " :");	
					score = input.nextDouble();
					testScores[subscript][index] = score;
				}
				while(!(score>= 0 && score <=100 ));	
			}

		input.nextLine();
	} 

	public void setAverage(int subscript, double average)
	{
		testAverage[subscript] = average;
	}

	public void setLetter(int subscript, double average)
	{
		if (average >= 90)
			letterGrades[subscript] = 'A';
		else if (average >= 80)
			letterGrades[subscript] = 'B';
		else if (average >= 70)	
			letterGrades[subscript] = 'C';
		else if (average >= 60)	
			letterGrades[subscript] = 'D';
		else
			letterGrades[subscript] = 'F';	
	}

	//------------------ Methods -------------------
	public double calcAverage(int subscript, int tests)
	{
		double sum = 0;
		for (int index = 0; index < tests; index++)
		{
			sum += testScores[subscript][index];
		}

		return (sum/tests);
	}


	// --------- MAIN: PROGRAM BEGINS HERE ---------
	public static void main(String[] args)
	{
		Scanner keyboard = new Scanner(System.in);

		//Prompt number of students
		System.out.print("How many students do you have? ");
		int students = keyboard.nextInt();
	
		//Prompt number of tests taken	
		System.out.print("How many tests have they taken? ");
		int tests = keyboard.nextInt();

		// Create gradebook
		GradeBook grades = new GradeBook(students,tests);	

		for (int i = 0; i < students; i++)
		{
			System.out.println("\nStudent Name: " + grades.getName(i) + "\nTest Average: " + grades.getAverage(i) + "\nLetter Grade: " + grades.getLetter(i));
		}
	}

}
