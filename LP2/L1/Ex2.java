/* Exercício 2:
Fazer um programa que calcule a área de 3 tipos de figuras, círculos, retângulos e triângulos dependendo da entrada recebida, e imprima seus valores de acordo.
 Caso a figura for um círculo é passado o raio do circulo
 Caso a figura for um retângulo é passado base e altura
 Caso for um triângulo o comprimento dos lados do Triângulo serão passadas
Os valores devem ser passados como argumentos de linha de comando, valores com tipo real.
Você vai identificar o tipo de figura com base no número de argumentos passados.
O cálculo da área deve ser feito em um método de classe, chamado calcula.
private static real calcula(real r)
private static real calcula(real b, double a)
private static real calcula(real l1, real l2, real l3)
Chame estes métodos para fazer os cálculos (tornando o programa mais modular).
No caso de ser um triângulo, classifique se ele é: equilátero, isósceles ou escaleno. Para isso crie um outro método estático e use o mesmo.
Utilize técnicas de criticas de dados e/ou tratamento de exceções para capturar problemas de entrada: número insuficiente de argumentos, 
número de excessivo de argumentos, argumentos que não sejam convertíveis para real [argumento(s) inválido(s)], argumentos que não formam um triângulo.

Exemplos de execução:
>java Ex1 1.3
A area do circulo e’: XXX unidades de area.

>java Ex1 3.0 4.0 5.0
A area do triangulo e': XXX unidades de área.
O triangulo e' isosceles.

>java Ex1
Número de argumentos insuficiente     ok

>java Ex1 0 1 3.7 9.5
Número de argumentos excessivo        ok

>java Ex1 a 0 0xD
1o argumento, “a”, nao é numero       ok
3o argumento, “0xD”, nao é numero     ok

Para esta experiência, o programa principal também pode ser codificado todo no método main (sabendo que isso não é incentivado), como na Figura 1. 
Mas outros métodos serão chamados, a partir do main, como já colocado no enunciado. */

class Ex2 {
    public static void main (String[] args){
        
        String st0, st1, st2;
        double dRaio, dBase, dAltura, dL1, dL2, dL3;
        
        
        if (argsSemErro(args) == true){
            if (args.length == 1){
                //st0=args[0];
                dRaio=Double.parseDouble(args[0]);
                System.out.println("A área do círculo é: " + calcula(dRaio) + " unidades de área.");
            } else if (args.length == 2){
                //st0=args[0];
                //st1=args[1];
                dBase=Double.parseDouble(args[0]);
                dAltura=Double.parseDouble(args[1]);   
                
                System.out.println("A área do retângulo é: " + calcula(dBase, dAltura) + " unidades de área.");
            } else {
                //st0=args[0];
                //st1=args[1];
                //st2=args[2];
                dL1=Double.parseDouble(args[0]);
                dL2=Double.parseDouble(args[1]);
                dL3=Double.parseDouble(args[2]); 
        
        
                System.out.println("A área do triângulo é: " + calcula(dL1, dL2, dL3) + " unidades de área.");
                System.out.println("O triângulo é " + classificaTriang(dL1, dL2, dL3) + ".");
            }
        }
        
        /*
        error: no suitable method found for calcula(String[])
        (actual argument String[] cannot be converted to String by method invocation conversion)
        
        você está passando como parâmetro deste método um array de strings. mas você não definiu o método como recebendo um
        array de strings. não saquei bem o que está tentando fazer.
        mas enfim, o método recebe os argumentos que você definiu que ele recebe, e definiu ele como recebendo uma string, ou duas strings,
        ou três strings. não um array de strings, que é o que está passando.
        
        basicamente não vai mudar muito a hora de invocar os métodos - só vai mudar o nome. irá continuar usando boa parte do código abaixo,
        que você comentou por algum motivo.
        

            terminou? good. agora faça o seguinte (é útil para o próximo exercício).
            vê ali que tem o método que criou para checar se uma string é numérica, right?
            tente refazer este método usando tratamento de exceções. 
            tipo, o que acontece se você tentar dar Double.parseDouble("não-número"); ?
            vai dar erro - uma exception de classe NumberFormatException, que me lembre.
            ou seja, você pode simplesmente tentar converter o parâmetro usando parseDouble
            e capturar esta exceção - caso seja capturda, sabe que a conversão falhou e
            que o parâmetro não é um número.
            
            você pode capturar exceções usando 
            try{
                //coisas
            } catch(ClasseDaExcecao e){
                //coisas caso dê erro
            }
        */
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
       //kay. vamos então
       // -- TENTAR converter a string passada para double
       // -- CAPTURAR um erro, caso aconteça
       // -- caso aconteça, sabemos que a string não é um número válido por algum motivo
       // -- caso não capture nenhum erro, é válida
       
       // pense sempre desta forma para exceptions, okay - por isso o try{}catch(){}.
       // você TENTA fazer coisas, CAPTURA erros caso ocorram, e FAZ algo sobre.
       
       boolean is_numeric = true; //vamos presumir que é
       
       try{
           Double.parseDouble(arg); //converter pra double. 
           
       } catch(NumberFormatException e){ //...caso isso dê uma exception do tipo Exception (ou seja, qualquer uma)
           is_numeric = false;
       }
       
       return is_numeric;
       
    }
    
}