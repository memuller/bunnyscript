# -*- coding: utf-8 -*-
'''
Escreva um programa que leia uma série de palavras fornecidas pelo usuário e
as coloque em uma lista (use a funcão anteriormente criada).

Feito isso, imprima esta lista sem elementos duplicados.
'''

def ler_lista(msg, tipo="string"):
  cont=1
  lista=[]
  while True:
    if tipo=="string":
      lis=raw_input(msg.format(cont))
      if lis == "":
        break
      lista.append(lis)
      cont+=1
      
    else:
      lis=input(msg.format(cont))
      if lis == "":
        break
      lista.append(lis)
      cont+=1
  return lista
  
msg="Digite a {}a coisa: " 
lista2=ler_lista(msg)
lista3=[]
cont=0

for i in range(0,len(lista2)):
  cont=0
  for j in range(0,len(lista2)):
    if lista2[i]==lista2[j]:
      cont+=1
  if cont==1:
    lista3.append(lista2[i])
        
print str(lista3)