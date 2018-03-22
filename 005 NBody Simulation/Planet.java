public class Planet{
	public double xxPos;
	public double yyPos;
	public double xxVel;
	public double yyVel;
	public double mass;
	public String imgFileName;
	public static final double G = 6.67e-11;
	
	public Planet(double xP, double yP, double xV, double yV, double m, String img)
	{
		xxPos = xP;
		yyPos = yP;
		xxVel = xV;
		yyVel = yV;
		mass = m;
		imgFileName = img;
	}
	public Planet(Planet P)
	{
		xxPos = P.xxPos;
		yyPos = P.yyPos;
		xxVel = P.xxVel;
		yyVel = P.yyVel;
		mass = P.mass;
		imgFileName = P.imgFileName;
	}
	public Planet()
	{
		xxPos = 0.0;
		yyPos = 0.0;
		xxVel = 0.0;
		yyVel = 0.0;
		mass = 0.0;
		imgFileName = "";
	}
	
	public double calcDistance(Planet P)
	{
		double result;
		result = (this.xxPos - P.xxPos) * (this.xxPos - P.xxPos) + (this.yyPos - P.yyPos) * (this.yyPos - P.yyPos);
		result = Math.sqrt(result);
		return result;
	}
	
	public double calcForceExertedBy(Planet P)
	{
		double result, distance;
		distance = this.calcDistance(P);
		result = G * this.mass * P.mass / (distance * distance);
		return result;	
	}
	
	public double calcForceExertedByX(Planet P)
	{
		double result, force, distance;
		distance = this.calcDistance(P);
		force = this.calcForceExertedBy(P);
		if(this.xxPos < P.xxPos)
		{
			result = (P.xxPos - this.xxPos) * force / distance;
			return result;
		}
		else
		{
			result = (this.xxPos - P.xxPos) * force / distance;
			return -result;
		}	
	}
	
	public double calcForceExertedByY(Planet P)
	{
		double result, force, distance;
		distance = this.calcDistance(P);
		force = this.calcForceExertedBy(P);
		if(this.yyPos < P.yyPos)
		{
			result = (P.yyPos - this.yyPos) * force / distance;
			return result;
		}
		else
		{
			result = (this.yyPos - P.yyPos) * force / distance;
			return -result;
		}	
	}
	
	public double calcNetForceExertedByX(Planet[] all)
	{
		double sum_result = 0.0;
		for(int i = 0; i < all.length; ++i)
		{
			if(!all[i].equals(this))
				sum_result += this.calcForceExertedByX(all[i]);	
		}
		return sum_result;
	}
	
	public double calcNetForceExertedByY(Planet[] all)
	{
		double sum_result = 0.0;
		for(int i = 0; i < all.length; ++i)
		{
			if(!all[i].equals(this))
				sum_result += this.calcForceExertedByY(all[i]);	
		}
		return sum_result;
	}
	
	public void update(double dt, double fX, double fY)
	{
		double a_x = 0.0, a_y = 0.0;
		
		a_x = fX / mass;
		a_y = fY / mass;
		xxVel = xxVel + a_x * dt;
		yyVel = yyVel + a_y * dt;
		xxPos = xxPos + xxVel * dt;
		yyPos = yyPos + yyVel * dt;	
	}

	public void draw()
	{
		StdDraw.picture(xxPos, yyPos, "./images/" + imgFileName);
	}
} 