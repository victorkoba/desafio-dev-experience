estoque_atual = {
    "Celular": 100,
    "Notebook": 50,
    "Mouse": 150,
    "Teclado": 80,
    "Monitor": 60,
    "Pen-drive": 200,
    "Tv": 30,
    "Headset": 90,
    "Carregador": 70,
    "Webcam": 40
}


movimentacoes = [
    {"produto": "Celular", "tipo": "saida", "quantidade": 20},
    {"produto": "Notebook", "tipo": "saida", "quantidade": 15},
    {"produto": "Mouse", "tipo": "saida", "quantidade": 30},
    {"produto": "Teclado", "tipo": "entrada", "quantidade": 10},
    {"produto": "Monitor", "tipo": "saida", "quantidade": 25},
    {"produto": "Pen-drive", "tipo": "saida", "quantidade": 170},
    {"produto": "Tv", "tipo": "entrada", "quantidade": 20},
    {"produto": "Headset", "tipo": "saida", "quantidade": 50},
    {"produto": "Carregador", "tipo": "entrada", "quantidade": 40},
    {"produto": "Webcam", "tipo": "saida", "quantidade": 5},
    {"produto": "Notebook", "tipo": "entrada", "quantidade": 6},
    {"produto": "Monitor", "tipo": "entrada", "quantidade": 5},
    {"produto": "Celular", "tipo": "entrada", "quantidade": 2},
    {"produto": "Impressora", "tipo": "entrada", "quantidade": 15}, 
    {"produto": "Headset", "tipo": "saida", "quantidade": 0}
]


historico = []

for mov in movimentacoes:
    produto = mov["produto"]
    tipo = mov["tipo"]
    quantidade = mov["quantidade"]

    if produto not in estoque_atual and tipo == "entrada":
        estoque_atual[produto] = 0

    if tipo == "entrada":
        estoque_atual[produto] += quantidade
        historico.append(f"[ENTRADA] {quantidade} unidades adicionadas de {produto}. Estoque atual: {estoque_atual[produto]}")
    elif tipo == "saida":
        if produto in estoque_atual:
            estoque_atual[produto] -= quantidade
            historico.append(f"[SAIDA] {quantidade} unidades retiradas de {produto}. Estoque atual: {estoque_atual[produto]}")
        else:
            historico.append(f"[ERRO] Produto '{produto}' nao encontrado para saida.")


print()
print(" ESTOQUE INICIAL:")
for produto, qtd in {
    "Celular": 100, "Notebook": 50, "Mouse": 150, "Teclado": 80,
    "Monitor": 60, "Pen-drive": 200, "Tv": 30, "Headset": 90,
    "Carregador": 70, "Webcam": 40
}.items():
    print(f"- {produto:12}: {qtd} unidades")
print()

print(" MOVIMENTACOES OCORRIDAS:")
for evento in historico:
    print(evento)
print()

print(" ESTOQUE FINAL:")
for produto, qtd in estoque_atual.items():
    print(f"- {produto:12}: {qtd} unidades")
print()

print(" PRODUTOS QUE PRECISAM DE REPOSICAO (<= 50 NO ESTOQUE):")

for produto, qtd in estoque_atual.items():
    if qtd <= 50:
        print(f"- {produto:12}: {qtd} unidades")