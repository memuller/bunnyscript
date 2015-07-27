# -*- coding: utf-8 -*-
# Escreva um programa que funcione como o anterior (6),
# mas aceite também que o usuário utilize as iniciais das
# respostas (y/n).

# ||
# 0 or 1  #1
# 1 or 1  #1
# 0 or 0  #0
 
# &&
# 0 and 1 #0
# 0 and 0 #1
# 1 and 1 #1

r=raw_input("Are you okay(y/yes/n/no):\n")
if r=='y' or r=='yes':
 print("Que bom")
elif r=='n' or r=='no':
 print("That's rough buddy")
else:
 print("l2type")