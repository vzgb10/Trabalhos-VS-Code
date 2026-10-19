/*
  Arquivo: api.js
  Responsabilidade: concentrar as chamadas para a API.

  Backend esperado:
  http://localhost:3000

  Rotas disponíveis no backend:
  GET    /alunos
  GET    /alunos?situacao=Ativo
  GET    /alunos/:ra
  POST   /alunos
  PUT    /alunos/:ra
  DELETE /alunos/:ra
*/

const API_BASE_URL = "http://localhost:3000";

async function listarAlunosApi(situacao = "") {
  let url = `${ALI_BASE_URL}/alunos`;

if(situacao) {
  url += `?situacao=${encodeURIComponent(situacao)}`;
}

const resposta = await fetch(url);
return await tratarRespostaApi(resposta);
  // TODO Aula 09:
  // 1. Montar a URL /alunos ou /alunos?situacao=...
  // 2. Fazer fetch com método GET
  // 3. Converter resposta para JSON
  // 4. Retornar a lista de alunos
}

async function tratarRespostaApi(resposta) {
  const dados = await resposta.json();
  if(!resposta.ok) {
    const mensagem = dados.mensagem || "Erro na requisição";
    throw new Error(mensagem);
  }
  return dados;
}

async function buscarAlunoApi(ra) {
  // TODO Aula 09:
  // GET http://localhost:3000/alunos/:ra
  const resposta = await fetch(`${API_BASE_URL}/alunos/${ra}`);
  return await tratarRespostaApi(resposta);
}

async function cadastrarAlunoApi(aluno) {
  // TODO Aula 09:
  // POST http://localhost:3000/alunos
  // headers: { "Content-Type": "application/json" }
  // body: JSON.stringify(aluno)
  const resposta = await fetch(`${API_BASE_URL}/alunos`,
    {
      method: "POST",
      headers: {
        "Content-Type" : "application/json"
      },
      body: JSON.stringify(aluno)
    }
  );
  return await tratarRespostaApi(resposta);
}

async function atualizarAlunoApi(ra, aluno) {
  // TODO Aula 09:
  // PUT http://localhost:3000/alunos/:ra
  // headers: { "Content-Type": "application/json" }
  // body: JSON.stringify(aluno)
    const resposta = await fetch(`${API_BASE_URL}/alunos`,
    {
      method: "PUT",
      headers: {
        "Content-Type" : "application/json"
      },
      body: JSON.stringify(aluno)
    }
  );
  return await tratarRespostaApi(resposta);
}

async function inativarAlunoApi(ra) {
  // TODO Aula 09:
  // DELETE http://localhost:3000/alunos/:ra
    const resposta = await fetch(`${API_BASE_URL}/alunos`,
    {
      method: "DELETE",
    }
  );
  return await tratarRespostaApi(resposta);
}