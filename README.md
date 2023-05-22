# Fila de Vacinação: uso da estrutura de dados heap
 * Projeto desenvolvido para a disciplina de Estrutura de Dados do Departamento de Computação da Universidade Federal de Sergipe.

## Descrição do projeto

* Dados do cidadão
1.	String Nome
2.	String CPF
3. 	Int Prioridade

* Grupos de Prioridade:
1.	Profissionais da saúde e portadores de deficiências mentais
2.	Pessoas com comorbidades, grávidas e puérperas
3.	Pessoas como idade acima de 60 anos, professores e motoristas (os últimos porque lidam com grande fluxo de pessoas)
4.     Crianças de 0 a 5 anos (Crianças de colo geralmente tem prioridade. Imaginei até 5 anos porque não costumam ficar quietas e ficam mais sujeitas à contaminação.)
5.	Pessoas com idade entre 6 e 60 anos

* As prioridades iniciarão por 1 para os profissionais de saúde, sendo 101 para o primeiro profissional a comparecer ao local de votação, 102 para o segundo, 103 para o terceiro e assim por diante.
* As prioridades iniciarão por 2 para as pessoas com comorbidades, sendo 201 para a primeira pessoas com comorbidades a comparecer ao local de votação, 202 para o segundo, 203 para o terceiro e assim por diante.  
* Prioridades iniciarão por 3 para idosos acima de 60 anos, seguindo a mesma lógica. Iniciarão por 4 para pessoas com idade entre 10 e 60 e assim por diante.

* O heap será ordenado pela prioridade. Assim serão removidos do heap mínimo os de prioridade iniciada por 1, depois os iniciados por 2 e assim por diante.


* Funcionalidades:
1.	Inclusão: insere um novo cidadão na fila de espera pela vacina
2.	Exclusão: remove um determinado cidadão da fila
3.	Consulta: Verifica se um cidadão já está na espera pela vacina
4.	Consulta total: identifica quantas pessoas estão no aguardo pela vacina, ordenando por grupo de prioridade
5.	Alterar: possibilita a alteração de algum dado de determinado cidadão que esteja na espera pela vacina



