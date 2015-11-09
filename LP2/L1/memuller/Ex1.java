class Ex1 {
    public static void main(String[] args){
        int qtd=0;
        String frase = "";
        qtd = args.length;
        for(int i = 0; i < qtd; i+=1){
            frase += concatenaCortando(frase, args[i]);
        }
        0
        System.out.println(frase);
        
    }
    
    public static String terminacoesIguais(String s1, String s2){
        String match = "";
        boolean matched = false;
        int ls1 = s1.length(); int ls2 = s2.length(); 
        int j = 0; int i = 0;
        int lsmaller = ls1 < ls2 ? ls1 : ls2;
        for(i = 0; i < lsmaller; i++){
            if(!s1.substring(ls1-1-i,ls1-i).equals(s2.substring(i,i+1))){
                break;
            }
            match += s2.substring(i,i+1);
        }
        return match;
    }
    
    public static String concatenaCortando(String s1, String s2){
        String match = terminacoesIguais(s1, s2);
        if(match.length() > 0){
            int lmatch = match.length();
            s1 = s1.substring(0, s1.length()-lmatch);
            s2 = s2.substring(lmatch, s2.length());
        }
        
        return s1 + s2;
    }
}