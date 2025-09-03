import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 *
 * @author brenaki
 */
public class MyFinishWindows extends WindowAdapter {

    @Override
    public void windowClosing(WindowEvent e) {
        super.windowClosing(e);
        System.exit(0);
    }
    
}
