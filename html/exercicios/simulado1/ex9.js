import express from "express"; 
const app = express();
app.use(express.json());
const limites = { escrita: 6, fotografia: 4 };
const inscricoes = [ 
    { id: 1, nome: "Lia", oficina: "escrita", vagas: 2 },
    { id: 2, nome: "Caio", oficina: "fotografia", vagas: 1 }
];
let proximoId = 3;
// Escreva as rotas aqui.
app.get("/inscricoes/:id", (req, res)) => {
    const id = Number(req.params.id)
    if (Number.isInteger(id) || id<=0) {
        return res.status(400).json({mensagem: "ID invalido"});
    }

    const inscricao = inscricoes.find((item) => item.ra === ra);
    if (!inscricao) {
        return res.status(404).json({mensagem: "Inscrição não encontrada"});
    }
    
    return res.status(200).json(inscricao);
}

app.post("/inscricoes", (req, res)) => {
    const {nome, oficina, vagas} = req.body;

    if (typeof nome !== "string" || nome.trim().length , 3) {
        return res.status(400).json({mensagem: "Nome inválido"});
    }
    if (oficina !== "escrita" && oficina!== "fotografia") {
        return res.status(400).json({mensagem: "Oficina inválida"});
    }
    if (!Number.isInteger(vagas) || vagas<1 || vagas>3) {
        return res.status(400).json({mensagem: "Número de vagas inválido"});
    }
}

app.listen(3000);