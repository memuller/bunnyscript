class MullereriamError extends Exception{}

public class Parameters {
    static float area, per;
    static float[] lado = new float[3];
    public static void main(String args[]){
        for(int i = 0; i < args.length; i++){
            try {
                lado[i] = Float.parseFloat(args[i]);
            } catch(Exception e) {
                System.out.println("só números plz");
            } 
        }
        
        if (args.length == 3){
            area = Area.triangulo(lado[0], lado[1], lado[2]);
        } else if (args.length == 2) {
            area = Area.retangulo(lado[0], lado[1]);
        } else {
                area = Area.circunferencia(lado[0]);
        }
        
        System.out.println(area);
    }
}



class Area{
    static float area, per, l1, l2, l3;
    static float pi = 3;
    public static float triangulo(float l1, float l2, float l3)
    {
        per = l1 + l2 + l3;
        area=per*(per-l1)*(per-l2)*(per-l3);
        return area;
    }
    
    public static float retangulo(float l1, float l2)
    {
        area=l1*l2;
        return area;
    }
    
    public static float circunferencia(float l1){
        area = 2*pi*l1;
        return area;
    }
}