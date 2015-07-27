# -*- coding: utf-8 -*-

# DICIONÁRIOS
# dicionários são um tipo de dados frequente em várias linguagens;
# na prática funcionam como arrays indexados por coisas arbitrárias
# ao invés de necessariamente por uma sequência ordinal de inteiros.

# você cria um dicionário inicialmente com {} e separando chaves e valores com :
# attributes = {'for': 15, 'dex' : 11, 'con': 14, 'int': 13, 'wis': 10, 'car': 12 }

# depois pode acessá-los e colocar novos valores usando [], como no caso de arrays.
# attributes['for'] # 15
# attributes['hawtness'] = 99

# em termos de C, são uma mistura de array dinâmico com struct.
# mas diferente do struct você não precisa declarar um 'modelo' antes.
# então mais fácil pensar neles como arrays que usam outras coisas como índice mesmo.
# note que em função disso uma lista não possui 'ordem'.

'''
Leia a sigla de um estado brasileiro fornecida pelo usuário via teclado
e imprima o seu nome completo.

Uma relação de estados e suas siglas está no arquivo estado.txt; leia esta lista
transformando-a em um dicionário de siglas e nomes para conseguir fazer o pedido.

'''
