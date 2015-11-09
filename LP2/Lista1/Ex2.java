class Ex2 {
    public static void main (String[] args){
        
        String st0, st1, st2;
        double dRaio, dBase, dAltura, dL1, dL2, dL3;
        
        
        if (argsSemErro(args) == true){
            if (args.length == 1){
                dRaio=Double.parseDouble(args[0]);
                System.out.println("A área do círculo é: " + calcula(dRaio) + " unidades de área.");
            } else if (args.length == 2){
                //st0=args[0];
                //st1=args[1];
                dBase=Double.parseDouble(args[0]);
                dAltura=Double.parseDouble(args[1]);   
                
                System.out.println("A área do retângulo é: " + calcula(dBase, dAltura) + " unidades de área.");
            } else {
                dL1=Double.parseDouble(args[0]);
                dL2=Double.parseDouble(args[1]);
                dL3=Double.parseDouble(args[2]); 
        
        
                System.out.println("A área do triângulo é: " + calcula(dL1, dL2, dL3) + " unidades de área.");
                System.out.println("O triângulo é " + classificaTriang(dL1, dL2, dL3) + ".");
            }
        }
    }
    
    
    static double calcula(Double raio){
        return Math.PI*Math.pow(raio, 2);
    }
    
    static double calcula(Double l1, Double l2, Double l3){
        double spe=0, quaseArea=0;
        
        spe = (l1+l2+l3)/2.0;
        quaseArea = (spe*(spe-l1)*(spe-l2)*(spe-l3));
        return Math.pow(quaseArea, 0.5);
    }
    
    static double calcula(Double base, Double altura){
        return base*altura;
    }
    
    static String classificaTriang(Double l1, Double l2, Double l3){
        String tipo;
        
        if ((l1==l2) && (l1==l3)){
            tipo = "Equilátero";
        } else if ((l1==l2) ^ (l1==l3)){
            tipo = "Isósceles";
        } else {
            tipo = "Escaleno";
        }
        
        return tipo;
    }
    
    static boolean argsSemErro(String[] args){
        
        boolean bool = true;
        int i=0;
        
        if (args.length == 0){
            System.out.println("Número de argumentos insuficiente");
            bool = false;
        }
        
        if (args.length > 3){
            System.out.println("Número de argumentos excessivo");
            bool = false;
        }
        
        for(i=0; i < args.length; i++){
            if(ehNumerico(args[i]) == false){
                System.out.println("Argumento não-numérico");
                bool = false;
            }
        }
        
        return bool;
    }
    
    static boolean ehNumerico(String arg){
       
       boolean is_numeric = true;
       
       try{
           Double.parseDouble(arg); 
           
       } catch(NumberFormatException e){ 
           is_numeric = false;
       }
       
       return is_numeric;
       
    }
    
}