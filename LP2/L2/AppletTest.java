import java.applet.*;
import java.awt.*;

public class AppletTest extends Applet{
    
    //init, start, stop, destroy, paint
    public void paint (Graphics g){
        g.drawString("Test", 25, 50);
    }
}