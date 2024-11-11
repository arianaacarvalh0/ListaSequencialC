# Lista Sequecial na Linguagem C
Trabalho da faculdade UniFatecie da matéria Estrutura de Dados.
- Problema:

  Em determinado momento, você percebeu que guardou todos os livros que leu e que ganhou ao longo de sua vida. Com a intenção de organizá-los, criou um programa e inseriu os dados de todos os seus livros.

  ​​​​​​​Passados alguns anos, você resolveu doar alguns livros e com isso veio a necessidade de atualizar o seu programa, removendo os que foram doados. Para tanto, vai precisar escrever o código para removê-los.

- Solução:
 
  Damos algumas opções para o usuário, se ele escolhe a opção 2 - Remover livro, pedimos o ISBN (Padrão Internacional de Numeração de Livro), e chamamos a função remove_lista da nossa biblioteca ListaDeLivros.

  Essa função recebe dois parâmetros, a lista e o id (ISBN). Fazemos a busca pela posição do id, para o remover e depois realocar os outros itens para o lugar correto, e assim nossa lista é atualizada.
