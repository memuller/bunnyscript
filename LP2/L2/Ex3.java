import java.util.*;

public class Ex3 {
	public static void main(String args[]){
		Banheiro banheiro = new Banheiro();

		Humano m1 = new Humano(banheiro, 1, true);
		Humano m2 = new Humano(banheiro, 2, true);
		Humano h = new Humano(banheiro, 1, false);

		banheiro.entraBanheiro(m1);
		banheiro.entraBanheiro(h);
		banheiro.entraBanheiro(m2);

	}
}


class BanheiroOcupado extends ArrayIndexOutOfBoundsException {
	public String toString(){ return "Desculpe - O banheiro está lotado"; }
}

class BanheiroVazio extends ArrayIndexOutOfBoundsException {
	public String toString(){ return "O banheiro está vazio"; }
}

class VaiPraFila extends RuntimeException {}

class Alerta extends VaiPraFila {
	public String toString(){ return "Homens e mulheres não podem usar o banheiro ao mesmo tempo"; }
}

class Espera extends VaiPraFila {
	public String toString(){ return "Aguarde um momento por favor"; }
}

class Humano {
	public int identificador;
	public String genero;
	public Banheiro banheiro;
	public static String[] genders = {"Homem", "Mulher"};

	Humano(Banheiro banheiro, int identificador){
		this.banheiro = banheiro; this.identificador = identificador;
	}

	Humano(Banheiro banheiro, int identificador, boolean woman){
		this.banheiro = banheiro; this.identificador = identificador;
		if(woman)
			this.genero = Humano.genders[1];
		else
			this.genero = Humano.genders[0];
	}
}

class Banheiro {
	public int quantidade ;
	public int capacidade = 5;
	public Humano[] cabines;
	public Hashtable<String,Integer> line = new Hashtable<String,Integer>();

	Banheiro() {
		cabines = new Humano[capacidade];

		line.put(Humano.genders[0], 0);
		line.put(Humano.genders[1], 0);
	}

	public int findEmptyCabin(){
		int empty_cabin = -1; int i = 0;

		for(Humano human : cabines){
			if(human == null)
				empty_cabin = i;
			i++;
		}
		return empty_cabin;
	}

	public boolean isFull() {
		return findEmptyCabin() == -1;
	}

	public boolean isEmpty(){
		for(Humano human : cabines){
			if(human != null)
				return false;
		}
		return true;
	}

	public boolean genderMatch(Humano h){
		String gender = h.genero;
		for (Humano human : cabines) {
			if(human == null) continue;
		 	if(!human.genero.equals(gender))
		 		return false;
		 }
		 return true; 
	}

	public int numGender(String gender){
		int count = 0;
		for (Humano human : cabines){
			if(human == null) continue;
			if(human.genero.equals(gender))
				count++;
		}
		return count;
	}

	public int numFemales(){ return numGender("Mulher"); }
	public int numMales(){ return numGender("Homem"); }

	public boolean deservesToEnter(Humano h){
		return true;
	}

	public void entraBanheiro(Humano h){
		String gender = h.genero;
		int empty_cabin = findEmptyCabin();

		if(empty_cabin == -1)
			throw(new BanheiroOcupado());

		if(!genderMatch(h))
			throw(new Alerta());

		cabines[empty_cabin] = h;


		System.out.println(h.genero + " " + h.identificador + " Entrou");
	}

	public void saiBanheiro(){
		if(isEmpty())
			throw(new BanheiroVazio());

	}


}

class BanheiroExt extends Banheiro {
	BanheiroExt(int capacidade){
		this.capacidade = capacidade;
	}


}
