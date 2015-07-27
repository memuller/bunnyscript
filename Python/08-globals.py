# -*- coding: utf-8 -*-
# Escreva um programa que leia do usuário o raio de um círculo
# e lhe exiba seu diâmetro e área.
# - o programa deve ter uma variável global com o valor de PI,
#   usada para os cálculos.
# - deve possuir uma função que, dado seu raio, retorne o diâmetro
#   da circunferência; e outra similar para a área.
# - deve possuir uma função main, chamada na execução do programa, 
#   para fazer a leitura e impressão dos dados.

# criar uma variável no corpo do programa fora de funções faz dela
# global - disponível para uso dentro de qualquer função.


pi=3.14

def area(r):
    return r*r*pi

def dim(r):
    return 2*r

def main():
    r=input("Digite o raio do círculo enquanto eu vou tomar banho: ")
    print("Área: {} | Diâmetro: {}".format(area(r), dim(r)))

main()

