import java.util.*;

public class Ex3 {
	public static void main(String args[]){

	}
}


class BanheiroOcupado extends ArrayIndexOutOfBoundsException {
	public String toString(){ return "Desculpe - O banheiro está lotado"; }
}

class BanheiroVazio extends ArrayIndexOutOfBoundsException {
	public String toString(){ return "O banheiro está vazio"; }
}

class Alerta extends RuntimeException {
	public String toString(){ return "Homens e mulheres não podem usar o banheiro ao mesmo tempo"; }
}

class Espera extends RuntimeException {
	public String toString(){ return "Aguarde um momento por favor"; }
}

class Humano {
	public int identificador;
	public String genero;
	public Banheiro banheiro;

	Humano(Banheiro banheiro, int identificador){
		this.banheiro = banheiro; this.identificador = identificador;
	}
}