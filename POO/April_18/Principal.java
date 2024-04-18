public class Principal{
	public static void main(String[] args){
		Data data[] = new Data[5];
		Endereco end[] = new Endereco[5];
		Cartao card[] = new Cartao[5];

		data[0] = new Data(12,6,2024);
		data[1] = new Data(13,6,2024);
		data[2] = new Data(13,11);
		data[3] = new Data(6,5,2024);
		data[4] = new Data(25,12, 2023);

		end[0] = new Endereco("Rua Jacob Fanta", 376);
		end[1] = new Endereco("Rua Leão", 78, "Curitiba");
		end[2] = new Endereco("Av. Coronel Manoel Bonfim", 118, "Jaguariaiva");
		end[3] = new Endereco("Av. Gertulio Vargas", 2312, "Rio de Janeiro");
		end[4] = new Endereco("Rua João Pedro Borsato", 123, "Ponta Grossa");

		card[0] = new CartaoNamorados("João Pedro Borsato", "Larissa Zanon", end[4], data[0]);
		card[1] = new CartaoAniversario("Victor Angelo Legat Cerqueira", "Luis Roberto Molotto", end[0], data[1]);
		card[2] = new CartaoAniversario("João Pedro Borsato", "Victor Angelo Legat Cerqueira", end[3], data[2]);
		card[3] = new CartaoAniversario("Luis Roberto Molotto", "Vinicius Eduardo", end[1], data[3]);
		card[4] = new CartaoNatal("Géssika Legat", "Angelo Bonfim Cerqueira", end[2], data[4]);

		for(int i=0;i<5;i++){
			System.out.println(card[i]);
		}
	}

}
