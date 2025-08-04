import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.HeadlessException;
import java.awt.geom.Ellipse2D;
import java.awt.geom.GeneralPath;
import java.awt.geom.Rectangle2D;

/**
 *
 * @author victor
 */
public class Robot extends Frame {
    
    /**
     * @throws HeadlessException 
     */
    public Robot() throws HeadlessException {
        addWindowListener(new ClosedWindows());
    }
    
    /**
     * 
     * @param g the graphics for paint in screen
     */
    public void paint(Graphics g){
        Graphics2D g2d = (Graphics2D) g;
        
        GeneralPath gp = new GeneralPath();
        
        // Antenna
        gp.moveTo(400, 90);
        gp.lineTo(400, 70);
        gp.quadTo(350, 50, 420, 50);
        Rectangle2D.Double antenna_base = new Rectangle2D.Double(375,90,50,10);
        Ellipse2D.Double antenna_circle = new Ellipse2D.Double(420,45,10,10);
        
        gp.append(antenna_circle, false);
        gp.append(antenna_base, false);
        
        // Head
        Rectangle2D.Double head = new Rectangle2D.Double(340,100,120,100);
        
        gp.append(head, false);
            // Screen
            Rectangle2D.Double screen = new Rectangle2D.Double(350,110,100,80);
        
        gp.append(screen, false);
        
        // Face
            // Left eye
            gp.moveTo(365, 145);
            gp.quadTo(380, 125, 395, 145);
            
            // Right eye
            gp.moveTo(405, 145);
            gp.quadTo(420, 125, 435, 145);
            
            // Mouth
            gp.moveTo(380, 165);
            gp.curveTo(390, 185, 410, 185, 420, 165);
        
        // Body
        Rectangle2D.Double body = new Rectangle2D.Double(350,200,100,150);
        
        gp.append(body, false);
            
            // Health Check
            Rectangle2D.Double rectangle_health_check = new Rectangle2D.Double(360,210,80,70);
            gp.moveTo(360, 245);
            gp.lineTo(365, 245);
            gp.lineTo(375, 225);
            gp.lineTo(385, 245);
            gp.lineTo(390, 235);
            gp.lineTo(395, 265);
            gp.lineTo(400, 245);
            gp.lineTo(410, 245);
            gp.lineTo(415, 228);
            gp.lineTo(420, 245);
            gp.lineTo(425, 265);
            gp.lineTo(430, 235);
            gp.lineTo(435, 245);
            gp.lineTo(440, 245);
            
            gp.append(rectangle_health_check, false);
            
            // Buttons
            Ellipse2D.Double left_button = new Ellipse2D.Double(360,290,20,20);
            Ellipse2D.Double middle_button = new Ellipse2D.Double(390,290,20,20);
            Ellipse2D.Double right_button = new Ellipse2D.Double(420,290,20,20);
            
            gp.append(left_button, false);
            gp.append(middle_button, false);
            gp.append(right_button, false);
            
            // Input
            gp.moveTo(380, 320);
            gp.lineTo(360, 320);
            gp.lineTo(370, 330);
            gp.lineTo(430, 330);
            gp.lineTo(440, 320);
            gp.lineTo(380, 320);
            gp.moveTo(380,325);
            gp.lineTo(420, 325);
            
        // Arm
            // Left Arm
                // Up
                gp.moveTo(350, 200);
                gp.lineTo(305, 335);
                // Down
                gp.moveTo(350, 225);
                gp.lineTo(325, 335);
                // Hand
                Rectangle2D.Double left_hand = new Rectangle2D.Double(305,335,20,10);
                gp.append(left_hand, false);
                
            // Right Arm
                // Up
                gp.moveTo(450, 200);
                gp.lineTo(495, 335);
                // Down
                gp.moveTo(450, 225);
                gp.lineTo(475, 335);
                // Hand
                Rectangle2D.Double right_hand = new Rectangle2D.Double(475,335,20,10);
                gp.append(right_hand, false);
                
        // Legs
            // Left Leg
            Rectangle2D.Double left_leg = new Rectangle2D.Double(350,350,25,150);

            gp.append(left_leg, false);

            // Right Leg
            Rectangle2D.Double right_leg = new Rectangle2D.Double(425,350,25,150);

            gp.append(right_leg, false);
            
        g2d.draw(gp);
    }
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Robot r = new Robot();
        r.setTitle("Robot - Trabalho Computação Gráfica");
        r.setSize(800,600);
        r.setVisible(true);
    }
    
}
