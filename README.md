# 🃏 Super Trunfo - Países

Projeto desenvolvido por **Marcos Augusto do Couto** como parte do desafio.  
Este programa simula a fase inicial do jogo *Super Trunfo*, com o tema **Países**, permitindo o cadastro e comparação de cartas representando cidades brasileiras.

## 🏆 Nível: Mestre

- Cadastro de duas cartas com os seguintes atributos:
  - Estado (letra A a H)
  - Código da carta (ex: A01, B02)
  - Nome da cidade
  - População (`unsigned long int`)
  - Área (`float`)
  - PIB (`float`)
  - Pontos turísticos (`int`)
- Cálculo automático de:
  - Densidade demográfica (`população / área`)
  - PIB per capita (`PIB / população`)
- Comparação entre os atributos das duas cartas
- Cálculo do **Super Poder**:
  - Soma de todos os atributos, com a densidade demográfica invertida (`1 / densidade`)

## 📦 Estrutura do Projeto

## 🛠️ Compilação e Execução
./super_trunfo

### Requisitos:
- Compilador C (ex: GCC)

### Compilar:
```bash
gcc super_trunfo.c -o super_trunfo

📸 Exemplo de Uso
Durante a execução, o programa solicitará os dados de duas cidades e exibirá:
- Todos os atributos cadastrados
- Atributos calculados
- Resultado da comparação
- Carta vencedora com base no Super Poder
📚 Créditos
Desenvolvido por Marcos Augusto do Couto




