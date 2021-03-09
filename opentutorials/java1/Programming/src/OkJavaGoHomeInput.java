import org.opentutorials.iot.DimmingLights;
import org.opentutorials.iot.Elevator;
import org.opentutorials.iot.Lighting;
import org.opentutorials.iot.Security;

import javax.swing.JOptionPane;

public class OkJavaGoHomeInput {

    // args -> parameter, 매개변수
    public static void main(String[] args) {

        // 팝업(다이얼로그) 창으로 입력받기
//        String id = JOptionPane.showInputDialog("Enter a ID");
//        String bright = JOptionPane.showInputDialog("Enter a Bright level");

        // Run Configuration에서 argument 설정하고 꺼내 쓰기
        // "JAVA APT 507" "15.0" 띄어쓰기가 구분자이며, 쌍따옴표로 각 인자를 묶음
        String id = args[0];
        String bright = args[1];

        // Elevator call
        Elevator myElevator = new Elevator(id);
        myElevator.callForUp(1);

        // Security off
        Security mySecurity = new Security(id);
        mySecurity.off();

        // Light on
        Lighting hallLamp = new Lighting(id + " / Hall Lamp");
        hallLamp.on();

        Lighting floorLamp = new Lighting(id + " / Floor Lamp");
        floorLamp.on();

        DimmingLights moodLamp = new DimmingLights(id + " Mood Lamp");
        moodLamp.setBright(Double.parseDouble(bright));
        moodLamp.on();

    }

}
