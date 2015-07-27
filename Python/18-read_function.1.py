# -*- coding: utf-8 -*-
'''
Escreva uma função

lista ler_lista(mensagem, tipo='string')

que, dado uma mensagem e um tipo de dado, leia do usuário uma quantidade
indeterminada de dados até que este insira algo vazio,
e retorne uma lista com estes dados.

- a mensagem fornecida deve ser impressa na leitura de cada dado
- caso a mensagem possua {}, este deve ser substituído pela posição sequencial
  do dado sendo solicitado agora.
- o parâmetro tipo, caso 'string' (o padrão) deve usar raw_input() para ler os dados.
  caso seja qualquer coisa diferente de 'string', deve usar input()
'''

# ao criar um método, você pode colocar um valor padrão em um parâmetro.
# isso faz com que o parâmetro se torne opcional - o método agora pode ser
# chamado sem fornecê-lo e, neste caso, seu valor é o padrão.


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


coco=ler_lista("Insira o {}o valor\n")
# quero que, caso eu passe um {} assim, as mensagens sejam impressas como
# Insira o 1o valor:
# Insira o 2o valor:
# ...etc.

print str(coco)