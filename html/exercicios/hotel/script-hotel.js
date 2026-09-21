const formulario = document.querySelector("#formReserva");

const campoNome = document.querySelector("#nome");
const campoEmail = document.querySelector("#email");
const campoTelefone = document.querySelector("#telefone");
const campoNascimento = document.querySelector("#nascimento");
const campoCheckin = document.querySelector("#checkin");
const campoCheckout = document.querySelector("#checkout");
const campoHospedes = document.querySelector("#hospedes");
const campoQuarto = document.querySelector("#quarto");
const campoSenha = document.querySelector("#senha");
const campoConfirmarSenha = document.querySelector("#confirmarSenha");
const campoAceite = document.querySelector("#aceite");

const resultado = document.querySelector("#resultado");

function mostrarErro(campo, idErro, mensagem){

    campo.classList.add("is-invalid");

    const erro = document.querySelector(idErro);
    erro.textContent = mensagem;

}

function limparErros(){

    resultado.innerHTML = "";

    const campos = document.querySelectorAll(".form-control, .form-select");

    campos.forEach((campo)=>{
        campo.classList.remove("is-invalid");
    });

    const erros = document.querySelectorAll(".invalid-feedback");

    erros.forEach((erro)=>{
        erro.textContent = "";
    });

    document.querySelector("#erroAceite").textContent = "";
}

formulario.addEventListener("submit", function(event){

    event.preventDefault();

    limparErros();

    let valido = true;

    const nome = campoNome.value.trim();

    if(nome.length < 5){
        mostrarErro(campoNome,"#erroNome","O nome deve possuir pelo menos 5 caracteres.");
        valido = false;
    }else if(nome.split(" ").length < 2){
        mostrarErro(campoNome,"#erroNome","Digite nome e sobrenome.");
        valido = false;
    }

    if(!campoEmail.checkValidity()){
        mostrarErro(campoEmail,"#erroEmail","Digite um e-mail válido.");
        valido = false;
    }

    const telefone = campoTelefone.value;

    const regexTelefone = /^[0-9]{11}$/;

    if(!regexTelefone.test(telefone)){
        mostrarErro(campoTelefone,"#erroTelefone","O telefone deve possuir exatamente 11 números.");
        valido = false;
    }

    const nascimento = new Date(campoNascimento.value);
    const hoje = new Date();

    let idade = hoje.getFullYear() - nascimento.getFullYear();

    const aniversario = new Date(
        hoje.getFullYear(),
        nascimento.getMonth(),
        nascimento.getDate()
    );

    if(hoje < aniversario){
        idade--;
    }

    if(idade < 18 || isNaN(idade)){
        mostrarErro(campoNascimento,"#erroNascimento","É necessário possuir 18 anos ou mais.");
        valido = false;
    }

    const checkin = new Date(campoCheckin.value);
    const checkout = new Date(campoCheckout.value);

    const dataHoje = new Date();
    dataHoje.setHours(0,0,0,0);

    if(checkin < dataHoje){
        mostrarErro(campoCheckin,"#erroCheckin","O check-in não pode ser anterior à data atual.");
        valido = false;
    }

    if(checkout <= checkin){
        mostrarErro(campoCheckout,"#erroCheckout","O check-out deve ser posterior ao check-in.");
        valido = false;
    }

    const hospedes = Number(campoHospedes.value);

    if(hospedes < 1 || hospedes > 5){
        mostrarErro(campoHospedes,"#erroHospedes","A quantidade deve estar entre 1 e 5 hóspedes.");
        valido = false;
    }

    const quarto = campoQuarto.value;

    if(quarto === ""){
        mostrarErro(campoQuarto,"#erroQuarto","Selecione um tipo de quarto.");
        valido = false;
    }

    if(quarto === "Individual" && hospedes > 1){
        mostrarErro(campoQuarto,"#erroQuarto","Quarto Individual aceita apenas 1 hóspede.");
        valido = false;
    }

    if(quarto === "Duplo" && hospedes > 2){
        mostrarErro(campoQuarto,"#erroQuarto","Quarto Duplo aceita até 2 hóspedes.");
        valido = false;
    }

    if(quarto === "Familia" && hospedes > 5){
        mostrarErro(campoQuarto,"#erroQuarto","Quarto Família aceita até 5 hóspedes.");
        valido = false;
    }

    const senha = campoSenha.value;

    const regexMaiuscula = /[A-Z]/;
    const regexNumero = /[0-9]/;

    if(senha.length < 8 ||
       !regexMaiuscula.test(senha) ||
       !regexNumero.test(senha)){

        mostrarErro(campoSenha,"#erroSenha",
        "A senha deve possuir 8 caracteres, uma letra maiúscula e um número.");

        valido = false;
    }

    if(campoConfirmarSenha.value !== senha){
        mostrarErro(campoConfirmarSenha,
        "#erroConfirmarSenha",
        "As senhas não coincidem.");

        valido = false;
    }

    if(!campoAceite.checked){
        document.querySelector("#erroAceite").textContent =
        "Você deve aceitar as condições da reserva.";

        valido = false;
    }

    if(valido){

        const diarias = Math.floor(
            (checkout - checkin)/(1000*60*60*24)
        );

        const reserva = {
            nome: nome,
            email: campoEmail.value,
            telefone: telefone,
            checkin: campoCheckin.value,
            checkout: campoCheckout.value,
            hospedes: hospedes,
            quarto: quarto,
            diarias: diarias
        };

        resultado.innerHTML = `
            <div class="alert alert-success">
                Solicitação de reserva realizada com sucesso!
            </div>

            <h4>Dados da Reserva</h4>

            <pre>${JSON.stringify(reserva,null,2)}</pre>
        `;
    }

});