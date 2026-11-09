import express, {Request, Response} from "express";
import cors from "cors";
import oracledb from "oracledb";

async function getConn() {
    return await oracledb.getConnection({
        user: "BD21082615",
        password: "Etqdu10",
        connectString: "localhost:1521/XEPDB1"
    });
}

const app = express();
const PORT = 3000;

app.use(express.json());
app.use(cors());
type CursoAluno = "Engenharia de Software" | "Sistemas de Informação"; 

type SituacaoAluno = "Ativo" | "Trancado" | "Formado" | "Inativo";

interface Aluno {
    ra: number;
    nome: string;
    email: string;
    curso: CursoAluno;
    semestre: number;
    situacao: SituacaoAluno;
}

let alunos:Aluno[] = [
    {
        ra: 1,
        nome: "João da Silva",
        email: "joão@aluno.edu.br",
        curso: "Engenharia de Software",
        semestre: 2,
        situacao: "Ativo"
    },
    {
        ra: 2,
        nome: "Maria dos Santos",
        email: "maria@aluno.edu.br",
        curso: "Engenharia de Software",
        semestre: 8,
        situacao: "Formado" 
    }
];

app.listen(PORT, () => {
    console.log(`Servidor ativo na porta ${PORT}`);
});

app.get("/", (req: Request, res: Response) => {
    res.send("Hello World!");
});

app.get("/alunos", async (req: Request, res:Response) => {
    let conn;
    try {
        conn = await getConn();
        const result = await conn.execute(
            `SELECT ra as "ra", nome as "nome", email as "email", curso as "curso", semestre as "semestre", situacao as "situacao"
            FROM alunos`
        );
        res.json(result.rows);
    } catch (erro) {
        console.error("Erro ao buscar alunos:", erro);
        res.status(500).json({ mensagem: "Erro na consulta" });
    } finally {
        if (conn) await conn.close();
    }
});

app.get("/alunos/:ra", (req:Request, res:Response) => {
    const ra = Number(req.params.ra);
    const aluno = alunos.find((item) => item.ra === ra);

    if(!aluno) {
        return res.status(404).json({mensagem: "Aluno não encontrado."});
    }

    return res.status(200).json(aluno);
});

app.post("/aluno", (req: Request, res:Response) => {
    const {ra, nome, email, curso, semestre} = req.body;

    //validações
    if(!ra || !nome || !email || !curso || !semestre) {
        return res.status(404).json({mensagem:"Campos obrigatórios"});
    }

    const novoAluno: Aluno = {
        ra,nome,email,curso,semestre, situacao: "Ativo"
    };

    alunos.push(novoAluno);
    return res.status(201).json(novoAluno);
});

app.put("/alunos/:ra", (req: Request, res: Response) => {
    const ra = Number(req.params.ra);
    const aluno = alunos.find((item) => item.ra === ra);

    if(!aluno) {
        return res.status(404).json({mensagem: "Aluno não encontrado!"});
    }

    const {nome, email, curso, semestre, situacao} = req.body;

    //Validações
    if(!nome || !email || !curso || !semestre || !situacao) {
        return res.status(400).json({mensagem: "Todos os campos são obrigatórios"});
    }

    aluno.nome = nome;
    aluno.email = email;
    aluno.curso = curso;
    aluno.semestre = semestre;
    aluno.situacao = situacao;

    return res.status(200).json(aluno);
});

app.delete("/alunos/:ra", (req:Request, res:Response) => {
    const ra = Number(req.params.ra);
    let aluno  = alunos.find((item) => item.ra === ra);

    if(!aluno) {
        return res.status(404).json({mensagem:"Aluno não encontrado"});
    }
        
    aluno.situacao = "Inativo";
    

    return res.status(200).json({
        mensasgem: "Aluno inativado com sucesso!",
        aluno
    });
});