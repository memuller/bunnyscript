# -*- coding: utf-8 -*-
# Escreva um programa que calcule o salário devido a um funcionário
# por uma semana de trabalho.
# o programa deve ler a quantidade de horas trabalhadas e o valor
# de cada hora.
# caso o funcionário tenha trabalhado mais que 40hs semanais,
# cada hora acima de 40 tem seu valor acrescido de 20%.
# - crie uma função que realize este cálculo, tendo
#   o valor e quantidade de horas como parâmetros.


def sal(horas, val):
    if horas>40:
        h2=horas-40
        horas-=h2
        return float((horas*val)+(h2*val*1.2))
    else:
        return float(horas*val)
        
horas=input("Digite as horas de desespero desta semana: ")
val=input("Digite o valor de cada hora deste desespero: ")
print ("Seu salário é: {}".format(sal(horas, val)))