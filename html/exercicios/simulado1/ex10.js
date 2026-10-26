import express from "express";
const app = express();
app.use(express.json());
const armarios = [
    { id: 1, local: "Sala A", capacidade: 8, ocupados: 3, ativo: true },
    { id: 2, local: "Sala B", capacidade: 5, ocupados: 0, ativo: true }
];
// Escreva as rotas aqui. 11 app.listen(3001);
app.put("/armarios/:id", (req, res)) => {
    const id = Number(req.params.id);
    if(!Number.isInteger(id) || id < 0) {
        return res.status(400).json({mensagem: "ID inválido"});
    }
    const armario = armarios.find(item=>item.id === id);
    if(!armario) {
        return res.status(400).json({mensagem: "Armário não encontrado"});
    }
    
}

app.listen(3001);