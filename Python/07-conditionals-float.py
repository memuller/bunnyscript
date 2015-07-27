# -*- coding: utf-8 -*-
# Escreva um programa que leia uma temperatura (um número decimal)
# fornecida pelo usuário.
# Tenha no mínimo quatro opções diferentes de vestuário adequado
# para faixas de temperatura específicas, e recomende uma delas
# ao usuário baseado na temperatura fornecida.

# if coisa:
#   # faz coisas 
# elif outra_coisa:
#   # faz outras coisas
# else:
#   # zetsubou da


t=input("Digite a temperatura atual (em Celsius): ")
if t<15:
    print("Dude just get naked inside a kotatsu")
elif t<30:
    print("Siga os conselhos de como se vestir para o templo de Salomão")
elif t<45:
    print("Vista um biquini/boxer e seja feliz")
else:
    print("Vista um ar condicionado")