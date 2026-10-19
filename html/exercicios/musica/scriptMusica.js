// Endereço da API
const API_URL = "http://localhost:3000/musicas";

// Elementos do HTML
const form = document.getElementById("formMusica");
const campoId = document.getElementById("idMusica");
const campoTitulo = document.getElementById("titulo");
const campoArtista = document.getElementById("artista");
const campoGenero = document.getElementById("genero");
const campoAno = document.getElementById("anoLancamento");
const campoDuracao = document.getElementById("duracao");
const campoSituacao = document.getElementById("situacao");

const corpoTabela = document.getElementById("corpoTabela");
const mensagem = document.getElementById("mensagemFormulario");

let musicas = [];

// Mostra mensagens no formulário
function mostrarMensagem(texto, tipo) {
    mensagem.textContent = texto;
    mensagem.className = tipo || "";
}

// Verifica a conexão com a API
function atualizarStatus(conectado) {
    const status = document.getElementById("statusApi");

    status.textContent = conectado
        ? "API conectada"
        : "API desconectada";

    status.className = conectado
        ? "status online"
        : "status offline";
}

// Transforma segundos em minutos e segundos
function formatarDuracao(segundos) {
    const minutos = Math.floor(segundos / 60);
    const resto = segundos % 60;

    return `${minutos}:${String(resto).padStart(2, "0")}`;
}

// Atualiza os números do resumo
function atualizarResumo() {
    document.getElementById("totalMusicas").textContent =
        musicas.length;

    document.getElementById("totalAtivas").textContent =
        musicas.filter(m => m.situacao === "Ativa").length;

    document.getElementById("totalInativas").textContent =
        musicas.filter(m => m.situacao === "Inativa").length;
}

// Cria uma célula da tabela com segurança
function criarCelula(texto) {
    const td = document.createElement("td");
    td.textContent = texto;
    return td;
}

// Monta a tabela de músicas
function listarMusicas(lista) {
    corpoTabela.replaceChildren();

    document.getElementById("resultadoFiltro").textContent =
        `${lista.length} música(s) encontrada(s)`;

    if (lista.length === 0) {
        const linha = document.createElement("tr");
        const celula = criarCelula("Nenhuma música encontrada.");
        celula.colSpan = 6;
        linha.appendChild(celula);
        corpoTabela.appendChild(linha);
        return;
    }

    lista.forEach(musica => {
        const linha = document.createElement("tr");

        // Título e artista
        const tdMusica = document.createElement("td");
        const nome = document.createElement("div");
        nome.className = "nome-musica";
        nome.textContent = "♫ " + musica.titulo;

        const artista = document.createElement("div");
        artista.className = "nome-artista";
        artista.textContent = musica.artista;

        tdMusica.append(nome, artista);
        linha.appendChild(tdMusica);

        linha.appendChild(criarCelula(musica.genero));
        linha.appendChild(criarCelula(musica.anoLancamento));
        linha.appendChild(criarCelula(
            formatarDuracao(musica.duracao)
        ));

        // Situação
        const tdSituacao = document.createElement("td");
        const etiqueta = document.createElement("span");

        etiqueta.className = "etiqueta " +
            (musica.situacao === "Ativa" ? "ativa" : "inativa");

        etiqueta.textContent = musica.situacao;
        tdSituacao.appendChild(etiqueta);
        linha.appendChild(tdSituacao);

        // Botões de ação
        const tdAcoes = document.createElement("td");
        const acoes = document.createElement("div");
        acoes.className = "acoes-tabela";

        const editar = document.createElement("button");
        editar.type = "button";
        editar.className = "botao-acao";
        editar.textContent = "Editar";
        editar.addEventListener("click", () => editarMusica(musica.id));

        const inativar = document.createElement("button");
        inativar.type = "button";
        inativar.className = "botao-acao";
        inativar.textContent = "Inativar";
        inativar.disabled = musica.situacao === "Inativa";
        inativar.addEventListener("click", () => inativarMusica(musica.id));

        acoes.append(editar, inativar);
        tdAcoes.appendChild(acoes);
        linha.appendChild(tdAcoes);

        corpoTabela.appendChild(linha);
    });
}

// Carrega as músicas da API
async function carregarMusicas() {
    try {
        const resposta = await fetch(API_URL);

        if (!resposta.ok) {
            throw new Error("Erro ao carregar as músicas.");
        }

        musicas = await resposta.json();

        atualizarStatus(true);
        atualizarResumo();
        aplicarFiltros();

    } catch (erro) {
        atualizarStatus(false);

        corpoTabela.innerHTML = "";

        const linha = document.createElement("tr");
        const celula = criarCelula(
            "Não foi possível conectar. Verifique se a API está rodando na porta 3000."
        );

        celula.colSpan = 6;
        linha.appendChild(celula);
        corpoTabela.appendChild(linha);

        console.error(erro);
    }
}

// Aplica os filtros do catálogo
function aplicarFiltros() {
    const artista = document.getElementById("filtroArtista")
        .value.trim().toLowerCase();

    const genero = document.getElementById("filtroGenero")
        .value.trim().toLowerCase();

    const situacao = document.getElementById("filtroSituacao")
        .value;

    const resultado = musicas.filter(musica => {
        const combinaArtista =
            musica.artista.toLowerCase().includes(artista);

        const combinaGenero =
            musica.genero.toLowerCase().includes(genero);

        const combinaSituacao =
            situacao === "" || musica.situacao === situacao;

        return combinaArtista && combinaGenero && combinaSituacao;
    });

    listarMusicas(resultado);
}

// Cadastra uma música ou atualiza uma existente
form.addEventListener("submit", async function(evento) {
    evento.preventDefault();

    const id = campoId.value;

    const dados = {
        titulo: campoTitulo.value.trim(),
        artista: campoArtista.value.trim(),
        genero: campoGenero.value.trim(),
        anoLancamento: Number(campoAno.value),
        duracao: Number(campoDuracao.value)
    };

    if (id) {
        dados.situacao = campoSituacao.value;
    }

    if (
        !dados.titulo ||
        !dados.artista ||
        !dados.genero ||
        !Number.isInteger(dados.anoLancamento) ||
        dados.anoLancamento <= 0 ||
        !Number.isFinite(dados.duracao) ||
        dados.duracao <= 0
    ) {
        mostrarMensagem(
            "Preencha todos os campos corretamente.",
            "erro"
        );
        return;
    }

    try {
        const resposta = await fetch(
            id ? `${API_URL}/${id}` : API_URL,
            {
                method: id ? "PUT" : "POST",
                headers: {
                    "Content-Type": "application/json"
                },
                body: JSON.stringify(dados)
            }
        );

        const resultado = await resposta.json();

        if (!resposta.ok) {
            throw new Error(
                resultado.mensagem || "Erro ao salvar música."
            );
        }

        limparFormulario();

        mostrarMensagem(
            id
                ? "Música atualizada com sucesso!"
                : "Música cadastrada com sucesso!",
            "sucesso"
        );

        await carregarMusicas();

    } catch (erro) {
        mostrarMensagem(
            erro.message || "Erro ao conectar com a API.",
            "erro"
        );
    }
});

// Preenche o formulário para edição
function editarMusica(id) {
    const musica = musicas.find(m => m.id === id);

    if (!musica) return;

    campoId.value = musica.id;
    campoTitulo.value = musica.titulo;
    campoArtista.value = musica.artista;
    campoGenero.value = musica.genero;
    campoAno.value = musica.anoLancamento;
    campoDuracao.value = musica.duracao;
    campoSituacao.value = musica.situacao;

    document.getElementById("tituloFormulario").textContent =
        "Editar música";

    document.getElementById("botaoSalvar").textContent =
        "Salvar alterações";

    document.getElementById("cancelarEdicao").hidden = false;
    document.getElementById("campoSituacao").hidden = false;

    mostrarMensagem("Edite os dados e salve as alterações.", "");

    document.getElementById("formMusica").scrollIntoView({
        behavior: "smooth"
    });
}

// Limpa o formulário
function limparFormulario() {
    form.reset();
    campoId.value = "";

    document.getElementById("tituloFormulario").textContent =
        "Cadastrar música";

    document.getElementById("botaoSalvar").textContent =
        "Cadastrar música";

    document.getElementById("cancelarEdicao").hidden = true;
    document.getElementById("campoSituacao").hidden = true;
}

// Cancela a edição
document.getElementById("cancelarEdicao")
    .addEventListener("click", () => {
        limparFormulario();
        mostrarMensagem("", "");
    });

// Inativa uma música sem excluí-la
async function inativarMusica(id) {
    const musica = musicas.find(m => m.id === id);

    if (!musica || musica.situacao === "Inativa") {
        return;
    }

    const confirmar = confirm(
        `Deseja inativar a música "${musica.titulo}"?`
    );

    if (!confirmar) return;

    try {
        const resposta = await fetch(`${API_URL}/${id}`, {
            method: "DELETE"
        });

        const resultado = await resposta.json();

        if (!resposta.ok) {
            throw new Error(
                resultado.mensagem || "Erro ao inativar música."
            );
        }

        await carregarMusicas();

    } catch (erro) {
        alert(erro.message || "Erro ao conectar com a API.");
    }
}

// Botão para atualizar a lista
document.getElementById("atualizarLista")
    .addEventListener("click", carregarMusicas);

// Eventos dos filtros
document.getElementById("filtroArtista")
    .addEventListener("input", aplicarFiltros);

document.getElementById("filtroGenero")
    .addEventListener("input", aplicarFiltros);

document.getElementById("filtroSituacao")
    .addEventListener("change", aplicarFiltros);

// Limpa todos os filtros
document.getElementById("limparFiltros")
    .addEventListener("click", function() {
        document.getElementById("filtroArtista").value = "";
        document.getElementById("filtroGenero").value = "";
        document.getElementById("filtroSituacao").value = "";

        aplicarFiltros();
    });

// Executa ao abrir a página
carregarMusicas();