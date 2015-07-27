# -*- coding: utf-8 -*-
# Escreva um programa que funcione como o anterior (02), mas que:
# - realize a soma utilizando uma função que, dados dois parâmetros,
#   retorna a soma entre eles.
# - tenha uma função 'main' onde os números são lidos, a função de
#   soma é usada, e o resultado é impresso. esta função main deve
#   ser chamada quando o programa for executado.  

# def nome_do_metodo(parametro, outro_parametro):
#     # faz as coisas
#     return to_jesus      

def main():
    n1=input("N1: ")
    n2=input("N2: ")
    print("A soma entre {} e {} é {}".format(n1, n2, soma(n1,n2)))
    
def soma(n1, n2):
    n3=n1+n2
    return n3
    
main()