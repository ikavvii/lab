package challenges;

import java.util.Scanner;

class Circle {
    static int count;
    private final int radius;
    private final int sno;
    private double area;

    Circle () {
        count++;
        sno = count;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter radius: ");
        radius = sc.nextInt();
        sc.close();
    }

    Circle (int radius) {
        sno = ++count;
        this.radius= radius;
        CArea();
    }

    private void CArea() {
        area = Math.PI * radius * radius;
    }

    void display() {
        CArea();
        System.out.println("Sno: " + sno + "| " + "Radius: " + radius + "| " + "Area: " + String.format("%.2f", area));
    }

    public String toString() {
        return "\nSno: " + sno + "\nRadius: " + radius + "\nArea: " + String.format("%.2f", area) + "\nTotal objects: " + count;
    }
}

public class AOB {
    public static void main(String[] args) {
        Circle circle = new Circle();
        circle.display();

        Circle[] circles = new Circle[5];
        for(int i = 0; i < circles.length; i++) {
            circles[i] = new Circle(i+1);
            
            System.out.println(circles[i]);
        }
    }
}

