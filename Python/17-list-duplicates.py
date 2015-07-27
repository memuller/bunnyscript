# -*- coding: utf-8 -*-
'''
Escreva um programa que leia palavras fornecidas pelo usuário.
Caso a palavra não tenha sido fornecida anteriormente, a adicionamos em uma lista.
Paramos de ler palavras quando o usuário não inserir nenhuma.

Ao final do programa, imprimimos a lista das palavras não-repetidas inseridas.

'''
i=0
words=list()
word=raw_input("Digite uma palavra: ")
words.append(word)
while "uma coisa" != "outra coisa":
    insira=True
    word=raw_input("Digite uma palavra: ")
    if(word == ""):
        break
    for i in range(0,len(words)):
        if word == words[i]:
           insira=False 

    if insira:
        words.append(word)
        

# works well enough. mas novamente, posso só
#...assumir que sempre quero inserir a palavra que estou lendo agora.
# o loop me faz mudar de idéia ou não, mas a cada nova palavra
# estou disposto a inserir.

print words