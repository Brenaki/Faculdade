public class Pilha{
	private static int pilha[] = new int[3];
	private static int top = -1;
	
	public static boolean vazia(){
		if(top == -1){
			return true;
		}
		return false;
	}

	public static void push(int value){
		if(top == 3){
			System.out.println("Não há espaço suficiente na pilha");
			return;
		}
		top +=1;
		pilha[top] = value;
	}

	public static int pop(){
		int value;
		if(vazia()){
			System.out.println("Pilha está vazia");
			return -1;
		}
		value = pilha[top];
		top-=1;
		return value;
	}

	public static void imprimir(){
		System.out.println(" ");
		for(int i=top; i>=0;i--){
			System.out.println("["+pilha[i]+"]");
		}
	}

	public static void main(String[] args){
		push(3);
		imprimir();
		push(5);
		imprimir();
		push(6);
		imprimir();
		pop();
		imprimir();
		pop();
		imprimir();

	}
}
