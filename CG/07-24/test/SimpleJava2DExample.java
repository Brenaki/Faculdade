import java.awt.*;

/**
 *
 * @author brenaki
 */

public class SimpleJava2DExample extends Frame {
    
    public SimpleJava2DExample() {
        addWindowListener(new MyFinishWindow());
    }
    
    public void paint(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.drawString("Hello world!",30,50);
    }
    
    public static void main(String[] argv) {
        SimpleJava2DExample f = new SimpleJava2DExample();
        f.setTitle("The first Java 2D program");
        f.setSize(350,80);
        f.setVisible(true);
    }
}
