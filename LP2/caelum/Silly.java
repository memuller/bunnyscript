class Silly{
    public static void main(String[] args){
        // ex1(150);
        // ex2(1000);
        // ex3(100);
        // ex4(10);
        // fatRec(4);
        // fib(100);
        fib2(10);
    }
    
    // imprimir sequência de números    
    public static void ex1(int n){   
        int i;
        for(i=0; i<n+1; i++){
            System.out.println(i+n);
            
        }
    }
    
    
    // imprimir a soma dos números de 1 à n. soma de uma p.a.
    public static void ex2(int n){
        int i=1, soma;
        
        soma = (i+n) * ((n-i+1)/2);
        
        System.out.println(soma);
    }
    
    // imprimir múltiplos de 3 de 1 à n
    public static void ex3(int n){
        int i;
        
        for(i=1; i<n+1; i++){
            if (i%3 == 0){
                System.out.println(i);
            }
        }
    }
    
    // imprimir fatoriais de 1 até n
    public static void ex4(int n){
        int i, fat, k;
    
        for(k=n; k>0; k--){
            fat=k;
            for(i=1; i<k; i++){
                fat=fat*i;
            }
            System.out.println(fat);
        }
    }
    
    public static int fatRec(int n){
        if (n <= 1){
            return 1;
        } else {
            return (n*fatRec(n-1));
        }
    }
    
    public static void fib(int n){
        int prox=0, ant=0, atual=1;
        
        System.out.print(ant + ", " + atual + ", ");
        
        while (prox<n){
            if (prox >= n){
                break;
            }
            prox=atual+ant;
            System.out.print(prox + ",");
            ant=atual;
            atual=prox;
            

        }
    }
    
    public static void fib2(int n){
        int n1=0, n2=1, i;
        
        for (i=0; i<n; i++) {
            n2=n1+n2;
            n1=n2-n1;
            System.out.println(n2);
        }
    }
    
}

