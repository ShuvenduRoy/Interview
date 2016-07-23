package jarvis;

import java.util.Vector;

import jarvis.Jarvis;
import jarvis.Point;

public class Jarvis {
	
	public int orientation(Point p, Point q, Point r){
		int val= (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
		
		if(val==0) return 0;
		return (val>0)?1:2;
	}
	
	void convexHull(Point points[], int n){
		if(n<3)
			return;
		Vector<Point> hull = new Vector<Point>();
		
		int l=0;
		for(int i=1;i<n; i++){
			if(points[i].x<points[l].x)
				l=i;
		}
		
		int p=l;
		int q;
		
		do{
			hull.add(points[p]);
			
			q=(p+1)%n;
			for(int i=0; i<n; i++){
				if(orientation(points[p],points[i],points[q])==2){
					q=i;
				}
			}
			p=q;
		}while(p!=l);
		
		
		for (int i = 0; i < hull.size(); i++)
	        System.out.println("(" + hull.get(i).x + ", "
	              + hull.get(i).y + ")") ;
	}
	
	public static void main(String[] args)
	{
		Jarvis hull = new Jarvis();
		Point[] points=new Point[7];
	    int point[][] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
	                      {3, 0}, {0, 0}, {3, 3}};
	    for(int i=0; i<7; i++){
	    	points[i]=new Point(point[i][0],point[i][1]);
	    }
	    int n = points.length;
	    hull.convexHull(points, n);
	}
}
