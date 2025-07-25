import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 *
 * @author brenaki
 */
public class MyFinishWindow extends WindowAdapter {

    @Override
    public void windowClosing(WindowEvent e) {
        super.windowClosing(e);
        System.exit(0);
    }

    @Override
    public void windowClosed(WindowEvent e) {
        super.windowClosed(e);
        System.exit(0);
    }
    
}
