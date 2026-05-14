"""
╔══════════════════════════════════════════════════════════════╗
║                 JOGO DA FORCA - TEMA: FUTEBOL                ║
║                  Palavra Secreta do Futebol                  ║
╚══════════════════════════════════════════════════════════════╝
Autor: Vitor Zago Guedes Batista
RA: 26008322
Descrição: Jogo de forca com tema futebol.
"""
# py "forca-de-futebol.py" #

import os
import random
import datetime

# ─────────────────────────────────────────────
#  CONFIGURAÇÃO DE ARQUIVOS
# ─────────────────────────────────────────────
ARQUIVO_PALAVRAS = "palavras.txt"
ARQUIVO_PLACAR   = "placar.txt"

# ─────────────────────────────────────────────
#  CONFIGURAÇÕES DE JOGO
# ─────────────────────────────────────────────
TENTATIVAS_MAX = {"FACIL": 8, "MEDIO": 6, "DIFICIL": 4}
PONTOS_ACERTO  = {"FACIL": 10, "MEDIO": 20, "DIFICIL": 35}
PONTOS_ERRO    = {"FACIL": -3, "MEDIO": -5, "DIFICIL": -8}
BONUS_VITORIA  = {"FACIL": 30, "MEDIO": 60, "DIFICIL": 100}

# ─────────────────────────────────────────────
#  BARRA DE TENTATIVAS
# ─────────────────────────────────────────────
def barra_tentativas(erros, max_erros):
    """Exibe barra de vidas restantes com emojis."""
    restantes = max_erros - erros
    barra = "  Vidas : " + "🟢 " * restantes + "🔴 " * erros
    print(barra)
    if erros == 0:
        print("  Status : Nenhum erro ainda — parabéns! ✅")
    elif restantes == 1:
        print("  Status : ⚠️  PERIGO! Última chance!")
    elif restantes == 0:
        print("  Status : 🟥 Cartão Vermelho! Eliminado!")
    else:
        print(f"  Status : {erros} erro(s) cometido(s)")

# ─────────────────────────────────────────────
#  UTILITÁRIOS DE TELA
# ─────────────────────────────────────────────
def limpar_tela():
    os.system("cls" if os.name == "nt" else "clear")


def linha(char="═", tam=62):
    print(char * tam)


def cabecalho():
    limpar_tela()
    linha()
    print(" ⚽  JOGO DA FORCA - VERSÃO FUTEBOL — Palavra Secreta do Futebol  ⚽")
    linha()


def pausar(msg="Pressione ENTER para continuar..."):
    input(f"\n  {msg}")


# ─────────────────────────────────────────────
#  LEITURA DO ARQUIVO DE PALAVRAS
# ─────────────────────────────────────────────
def carregar_palavras(caminho=ARQUIVO_PALAVRAS):
    """Lendo as palavras.txt"""
    palavras = []
    try:
        with open(caminho, "r", encoding="utf-8") as f:
            for linha_arq in f:
                linha_arq = linha_arq.strip()
                if not linha_arq or linha_arq.startswith("#"):
                    continue
                partes = linha_arq.split("|")
                if len(partes) == 4:
                    palavras.append({
                        "nivel":   partes[0].strip().upper(),
                        "palavra": partes[1].strip().upper(),
                        "dica":    partes[2].strip(),
                        "visiveis": int(partes[3].strip()),
                    })
    except FileNotFoundError:
        print(f"\n  [ERRO] Arquivo '{caminho}' não encontrado!")
        pausar()
    return palavras


def filtrar_por_nivel(palavras, nivel):
    return [p for p in palavras if p["nivel"] == nivel]


def escolher_palavra(palavras, nivel):
    pool = filtrar_por_nivel(palavras, nivel)
    if not pool:
        return None
    return random.choice(pool)


# ─────────────────────────────────────────────
#  MONTANDO A LÓGICA DO JOGO
# ─────────────────────────────────────────────
def normalizar(texto):
    """Remove acentos para comparação."""
    mapa = {
        "Á":"A","À":"A","Ã":"A","Â":"A","É":"E","Ê":"E",
        "Í":"I","Ó":"O","Õ":"O","Ô":"O","Ú":"U","Ç":"C",
        "á":"a","à":"a","ã":"a","â":"a","é":"e","ê":"e",
        "í":"i","ó":"o","õ":"o","ô":"o","ú":"u","ç":"c",
    }
    return "".join(mapa.get(c, c) for c in texto).upper()


def montar_display(palavra, letras_reveladas, visiveis):
    """
    Monta a palavra com traços, revelando as letras já acertadas e as primeiras letras (pistas iniciais)
    Espaços são revelados automaticamente.
    """
    pistas = set()
    for i in range(min(visiveis, len(palavra))):
        if palavra[i] != " ":
            pistas.add(normalizar(palavra[i]))

    display = []
    for ch in palavra:
        if ch == " ":
            display.append("  ")
        elif normalizar(ch) in letras_reveladas or normalizar(ch) in pistas:
            display.append(f" {ch} ")
        else:
            display.append(" _ ")
    return "".join(display)


def jogo_completo(palavra, letras_reveladas, visiveis):
    """Verifica se todas as letras relevantes foram reveladas."""
    pistas = set()
    for i in range(min(visiveis, len(palavra))):
        if palavra[i] != " ":
            pistas.add(normalizar(palavra[i]))

    for ch in palavra:
        if ch == " ":
            continue
        if normalizar(ch) not in letras_reveladas and normalizar(ch) not in pistas:
            return False
    return True


# ─────────────────────────────────────────────
#  ARQUIVO DE PLACAR
# ─────────────────────────────────────────────
def salvar_resultado(nome, nivel, palavra, pontos, tentativas_usadas, tentativas_max, venceu):
    data = datetime.datetime.now().strftime("%d/%m/%Y %H:%M")
    resultado = "VITÓRIA" if venceu else "DERROTA"
    linha_reg = (
        f"{data} | Jogador: {nome:15s} | Nível: {nivel:8s} | "
        f"Palavra: {palavra:20s} | Pontos: {pontos:+5d} | "
        f"Tentativas: {tentativas_usadas}/{tentativas_max} | {resultado}\n"
    )
    with open(ARQUIVO_PLACAR, "a", encoding="utf-8") as f:
        f.write(linha_reg)


def exibir_placar():
    cabecalho()
    print("  📋  HALL DA FAMA — Histórico de Partidas\n")
    try:
        with open(ARQUIVO_PLACAR, "r", encoding="utf-8") as f:
            linhas = f.readlines()
        if not linhas:
            print("  Nenhuma partida registrada ainda.")
        else:
            # Mostra últimas 15
            for l in linhas[-15:]:
                print(" ", l.rstrip())
    except FileNotFoundError:
        print("  Nenhuma partida registrada ainda.")
    pausar()


# ─────────────────────────────────────────────
#  TELA DE JOGO
# ─────────────────────────────────────────────
def tela_jogo(nome, nivel, palavra_info):
    palavra   = palavra_info["palavra"]
    dica      = palavra_info["dica"]
    visiveis  = palavra_info["visiveis"]
    max_tent  = TENTATIVAS_MAX[nivel]
    pt_acerto = PONTOS_ACERTO[nivel]
    pt_erro   = PONTOS_ERRO[nivel]
    bonus     = BONUS_VITORIA[nivel]

    letras_reveladas = set()
    letras_erradas   = []
    letras_certas    = []
    pontos   = 0
    acertos  = 0
    erros    = 0
    tentativas_usadas = 0

    # Revela as pistas iniciais no conjunto
    for i in range(min(visiveis, len(palavra))):
        if palavra[i] != " ":
            letras_reveladas.add(normalizar(palavra[i]))

    while tentativas_usadas < max_tent:
        cabecalho()

        # Info do jogador
        print(f"  Jogador : {nome}")
        print(f"  Nível   : {nivel}  |  Max tentativas: {max_tent}")
        print(f"  Pontos  : {pontos:+d}  |  Acertos: {acertos}  |  Erros: {erros}")
        linha("─")
        barra_tentativas(erros, max_tent)
        linha("─")
        print(f"  Dica    : {dica}")
        print(f"\n  Palavra : {montar_display(palavra, letras_reveladas, visiveis)}\n")
        print(f"  Letras erradas : {' '.join(letras_erradas) if letras_erradas else '—'}")
        print(f"  Tentativas restantes: {max_tent - tentativas_usadas}")
        linha("─")

        # Verifica vitória
        if jogo_completo(palavra, letras_reveladas, visiveis):
            pontos += bonus
            cabecalho()
            print(f"\n  🏆  GOOOOL!  VOCÊ ACERTOU!  🏆")
            print(f"\n  A palavra era: {palavra}")
            print(f"  Bônus de vitória: +{bonus} pontos!")
            print(f"  Pontuação final : {pontos:+d}")
            salvar_resultado(nome, nivel, palavra, pontos, tentativas_usadas, max_tent, True)
            pausar()
            return pontos, True

        # Entrada do jogador
        entrada = input("  Digite uma letra ou a palavra completa: ").strip().upper()

        if not entrada:
            print("  ⚠ Digite algo!")
            pausar("Pressione ENTER para tentar novamente...")
            continue

        # Chute da palavra inteira
        if len(entrada) > 1:
            tentativas_usadas += 1
            if normalizar(entrada) == normalizar(palavra):
                pontos += bonus * 2
                cabecalho()
                print(f"\n  🏆  GOOOOL!  ACERTOU A PALAVRA COMPLETA!  🏆")
                print(f"\n  A palavra era: {palavra}")
                print(f"  Bônus especial: +{bonus * 2} pontos!")
                print(f"  Pontuação final: {pontos:+d}")
                salvar_resultado(nome, nivel, palavra, pontos, tentativas_usadas, max_tent, True)
                pausar()
                return pontos, True
            else:
                erros += 1
                pontos += pt_erro
                print(f"  ❌ Palavra errada! Você perdeu uma tentativa.")
                pausar()
                continue

        if not entrada.isalpha() or len(entrada) != 1:
            print("  ⚠ Digite apenas UMA letra válida!")
            pausar("Pressione ENTER para tentar novamente...")
            continue

        letra_norm = normalizar(entrada)

        if letra_norm in letras_reveladas or entrada in letras_erradas:
            print("  ⚠ Você já tentou essa letra! Tente outra.")
            pausar("Pressione ENTER para continuar...")
            continue

        tentativas_usadas += 1

        # Verifica se a letra está na palavra
        achou = False
        for ch in palavra:
            if normalizar(ch) == letra_norm:
                achou = True
                break

        if achou:
            letras_reveladas.add(letra_norm)
            letras_certas.append(entrada)
            pontos += pt_acerto
            acertos += 1
        else:
            letras_erradas.append(entrada)
            pontos += pt_erro  # negativo
            erros += 1

    # Fim por esgotamento de tentativas
    cabecalho()
    print(f"\n  🟥  CARTÃO VERMELHO! Tentativas esgotadas!\n")
    print(f"  A palavra era: {palavra}")
    print(f"  Pontuação final: {pontos:+d}")
    salvar_resultado(nome, nivel, palavra, pontos, tentativas_usadas, max_tent, False)
    pausar()
    return pontos, False


# ─────────────────────────────────────────────
#  MENU DE NÍVEL
# ─────────────────────────────────────────────
def menu_nivel():
    cabecalho()
    print("  Escolha o nível de dificuldade:\n")
    print("  [1] 🟢 FÁCIL    — 8 tentativas | +10/-3 pontos")
    print("  [2] 🟡 MÉDIO    — 6 tentativas | +20/-5 pontos")
    print("  [3] 🔴 DIFÍCIL  — 4 tentativas | +35/-8 pontos")
    print("  [0] Voltar ao menu principal")
    linha("─")
    op = input("  Opção: ").strip()
    mapa = {"1": "FACIL", "2": "MEDIO", "3": "DIFICIL"}
    return mapa.get(op, None)


# ─────────────────────────────────────────────
#  MENU PRINCIPAL
# ─────────────────────────────────────────────
def menu_principal():
    cabecalho()
    print("  Bem-vindo ao JOGO DA FORCA - VERSÃO FUTEBOL! ⚽\n")
    print("  [1] Nova Partida")
    print("  [2] Ver Placar")
    print("  [3] Como Jogar")
    print("  [0] Sair")
    linha("─")
    return input("  Opção: ").strip()


def tela_como_jogar():
    cabecalho()
    print("  ℹ️  COMO JOGAR\n")
    print("  • O computador escolhe uma palavra secreta do futebol.")
    print("  • Você vê a dica e alguns traços ( _ ) representando letras.")
    print("  • Digite UMA letra por vez para tentar adivinhar a palavra.")
    print("  • Letra certa  → ganha pontos e a letra aparece na palavra.")
    print("  • Letra errada → perde pontos e o boneco avança na forca.")
    print("  • Acerte a palavra antes das tentativas acabarem e VENÇA!")
    print("  • Bônus de vitória é concedido ao acertar a palavra!")
    print("\n  PONTUAÇÃO POR NÍVEL:")
    print("  Fácil  : +10 por acerto | -3 por erro | +30 bônus vitória")
    print("  Médio  : +20 por acerto | -5 por erro | +60 bônus vitória")
    print("  Difícil: +35 por acerto | -8 por erro | +100 bônus vitória")
    print("\n  Boa sorte! ⚽🏆")
    pausar()


# ─────────────────────────────────────────────
#  LOOP PRINCIPAL
# ─────────────────────────────────────────────
def main():
    palavras = carregar_palavras()
    if not palavras:
        print("\n  [ERRO] Não foi possível carregar as palavras. Encerrando.")
        return

    # Pede nome do jogador
    cabecalho()
    print("  Antes de começar, informe seu nome:\n")
    nome = input("  Seu nome: ").strip()
    if not nome:
        nome = "Jogador"

    while True:
        op = menu_principal()

        if op == "0":
            cabecalho()
            print(f"\n  Obrigado por jogar, {nome}! Até a próxima! ⚽\n")
            break

        elif op == "1":
            nivel = menu_nivel()
            if nivel is None:
                continue
            palavra_info = escolher_palavra(palavras, nivel)
            if palavra_info is None:
                print(f"\n  [ERRO] Nenhuma palavra disponível para o nível {nivel}.")
                pausar()
                continue
            tela_jogo(nome, nivel, palavra_info)

        elif op == "2":
            exibir_placar()

        elif op == "3":
            tela_como_jogar()

        else:
            print("  Opção inválida! Tente novamente.")
            pausar()


# ─────────────────────────────────────────────
#  PONTO DE ENTRADA
# ─────────────────────────────────────────────
if __name__ == "__main__":
    main()
