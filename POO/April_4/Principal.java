public class Principal {
  public static void main(String[] args) {
    Data d[];
    Pessoa p[];
    Funcionario f[];
    Aluno a[];

    d = new Data[6];

    d[0] = new Data(13, 6);
    d[1] = new Data(24, 8, 1998);
    d[2] = new Data(18, 9, 2005);
    d[3] = new Data(15, 10, 1987);
    d[4] = new Data(1, 8, 1967);
    d[5] = new Data(26, 3);

    // Datas
    System.out.println("\n**Datas**");
    for (int i = 0; i < 6; i++) {
      System.out.println(d[i]);
    }

    p = new Pessoa[2];

    p[0] = new Pessoa("João", "123456789", d[0]);
    p[1] = new Pessoa("Maria", d[5]);

    // Pessoas
    System.out.println("\n**Pessoas**");
    for (int i = 0; i < 2; i++) {
      System.out.println(p[i]);
    }

    a = new Aluno[2];

    a[0] = new Aluno("Pedro", "987654321", d[1], "123456");
    a[0].matricular(4);
    a[1] = new Aluno("Julia", d[2], "654321");

    // Alunos
    System.out.println("\n**Alunos**");
    for (int i = 0; i < 2; i++) {
      System.out.println(a[i]);
    }

    f = new Funcionario[6];

    f[0] = new Funcionario("José", "987654321", d[3], "123456", 1000.0);
    f[1] = new Funcionario("Ana", d[4], "654321", 2000.0);

    // Funcionarios
    System.out.println("\n**Funcionarios**");
    for (int i = 0; i < 2; i++) {
      System.out.println(f[i]);
    }

    f[2] = new Chefe("Victor", "998178928", d[0], "1306205", 10000.0, "Diretor de Aplicações Web");
    f[3] = new Chefe("Vinicius", d[3], "2501205", 9000.0, "Gestor de Projetos");
    
    // Chefe
    System.out.println("\n***Chefes***");
    for(int i=2;i<4;i++){
	System.out.println(f[i]);
    }

    f[4] = new Professor("Gustavo", "911092067", d[2], "167290", 50.0, 40);
    f[5] = new Professor("Kevin", d[5], "1782679", 80.0, 60);
    
    // Professor
    System.out.println("\n***Professores***");
    for(int i=4;i<6;i++){
	System.out.println(f[i]);
    }

    // Somando os salarios dos funcionarios
    

  }
}
