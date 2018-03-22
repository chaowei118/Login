import java.io.*;

public class NBody{
	public static int readPlanetNum(String file)
	{
		In in = new In(file);
		int num = in.readInt();
		return num;	
	}
	
	public static double readRadius(String file)
	{
		In in = new In(file);
		//FileReader in = new FileReader(file);
		//LineNumberReader reader = new LineNumberReader(in);
		//String s;
		int num = in.readInt();
		double radius = in.readDouble();
		
		//reader.setLineNumber(2);
		//s = reader.readLine();
		return radius;
	}
	
	public static Planet[] readPlanets(String file)
	{
		In in = new In(file);
		int num = in.readInt();
		double radius = in.readDouble();
		Planet[] planet = new Planet[num];
		
		for(int i = 0; i < num; ++i)
		{
			planet[i] = new Planet();
			planet[i].xxPos = in.readDouble();
			planet[i].yyPos = in.readDouble();
			planet[i].xxVel = in.readDouble();
			planet[i].yyVel = in.readDouble();
			planet[i].mass = in.readDouble();
			planet[i].imgFileName = in.readString();
		}
		return planet;
	}

	public static void main(String[] args)
	{
		double T = Double.parseDouble(args[0]);
		double dt = Double.parseDouble(args[1]);
		String filename = args[2];
		int num_planet = NBody.readPlanetNum(filename);
		double radius = NBody.readRadius(filename);
		Planet[] planets = NBody.readPlanets(filename);
		String imgToDraw = "./images/starfield.jpg";
		
		StdDraw.setScale(-radius, radius);
		StdDraw.clear();
		StdDraw.picture(0, 0, imgToDraw);
		
		for(int i = 0;i < num_planet; ++i)
		{
			planets[i].draw();
		}
		StdDraw.show();
		
		StdDraw.enableDoubleBuffering();
		
		double time = 0.0;
		while(time < T)
		{
			double[] xForces = new double[num_planet];
			double[] yForces = new double[num_planet];

			for(int i = 0;i < num_planet; ++i)
			{
				xForces[i] = planets[i].calcNetForceExertedByX(planets);
				yForces[i] = planets[i].calcNetForceExertedByY(planets);	
			}
			
			for(int i = 0;i < num_planet; ++i)
			{
				planets[i].update(dt, xForces[i], yForces[i]);
			}
			
			StdDraw.picture(0, 0, imgToDraw);		
			for(int i = 0;i < num_planet; ++i)
			{
				planets[i].draw();
			}
			StdDraw.show();
			StdDraw.pause(10);
			
			time += dt;
		}
		
		StdOut.printf("%d\n", num_planet);
		StdOut.printf("%.2e\n", radius);
		for (int i = 0; i < num_planet; i++) 
		{
			StdOut.printf("%11.4e %11.4e %11.4e %11.4e %11.4e %12s\n",
						  planets[i].xxPos, planets[i].yyPos, planets[i].xxVel,
					      planets[i].yyVel, planets[i].mass, planets[i].imgFileName);   
		}
	}
}