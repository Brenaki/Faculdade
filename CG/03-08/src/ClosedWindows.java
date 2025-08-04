import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 *
 * @author victor
 */
public class ClosedWindows extends WindowAdapter {

    @Override
    public void windowClosing(WindowEvent e) {
       System.exit(0);
    }
    
}
