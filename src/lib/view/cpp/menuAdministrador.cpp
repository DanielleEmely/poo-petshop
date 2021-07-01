#include "../hpp/menuAdministrador.hpp"

MenuAdministrador::MenuAdministrador(PetShop *petshop) : Menu(petshop)
{
}

MenuAdministrador::~MenuAdministrador()
{
}

Administrador *MenuAdministrador::getAdministrador()
{
    Administrador *administrador = dynamic_cast<Administrador *>(this->petshop->getSessaoAtual());
    if (!administrador)
    {
        printErro("ERRO NO CASTING");
        return NULL;
    }
    return administrador;
}

void MenuAdministrador::menuCadastrarVendedor()
{
    printTitulo("Cadastrando Vendedor...");
    Administrador *administrador = getAdministrador();
    string nome;
    string usuario;
    string senha;
    double salario;

    cout << "Vendedor" << endl
         << "\tNome: ";
    cin >> nome;
    cout << "\tUsuário: ";
    cin >> usuario;
    cout << "\tSenha: ";
    cin >> senha;
    cout << "\tSalário: ";
    cin >> salario;

    administrador->cadastrarVendedor(nome, usuario, senha, salario);
    this->popUp = "Cadastro realizado com sucesso!";
}

void MenuAdministrador::menuCadastrarVeterinario()
{
    printTitulo("Cadastrando Veterinário...");
    Administrador *administrador = getAdministrador();
    string nome;
    string usuario;
    string senha;
    double salario;

    cout << "Veterinário" << endl
         << "\tNome: ";
    cin >> nome;
    cout << "\tUsuário: ";
    cin >> usuario;
    cout << "\tSenha: ";
    cin >> senha;
    cout << "\tSalário: ";
    cin >> salario;
    administrador->cadastrarVeterinario(nome, usuario, senha, salario);
    this->popUp = "Cadastro realizado com sucesso!";
}

void MenuAdministrador::menuCadastrarProdutos()
{
    printTitulo("Cadastrando Produto...");
    Administrador *administrador = getAdministrador();
    string nome;
    double preco;
    int quantidade;
    long id;

    cout << "Produto" << endl
         << "\tNome: ";
    cin >> nome;
    cout << "\tPreço: ";
    cin >> preco;
    cout << "\tQuantidade: ";
    cin >> quantidade;
    cout << "\tId: ";
    cin >> id;

    bool jaCadastrado = false;
    //administrar->buscarCadastroProduto();
    if (jaCadastrado)
    {
        this->popUp = "Produto já cadastrado";
    }
    else
    {
        //administrador->cadastrarProdutos(nome, usuario, senha, salario);
        this->popUp = "Cadastro realizado com sucesso!";
    }
}

void MenuAdministrador::menuCadastrarServicos()
{
    printTitulo("Cadastrando Serviço...");
    Administrador *administrador = getAdministrador();
    string nome;
    double preco;
    long id;

    cout << "Serviço" << endl
         << "\tNome: ";
    cin >> nome;
    cout << "Preço: " << endl;
    cin >> preco;
    cout << "Id: " << endl;
    cin >> id;
    
    bool jaCadastrado = false;
    //administrar->buscarCadastroServico();
    if (jaCadastrado)
    {
        this->popUp = "Serviço já cadastrado";
    }
    else
    {
        //administrador->cadastrarServicos(nome, preco, id);
        this->popUp = "Cadastro realizado com sucesso!";
    }
}

void MenuAdministrador::menuListarFuncionarios()
{
    printTitulo("Listando Funcionários...");
    Administrador *administrador = getAdministrador();

    cout << "Usuários" << endl;
    for (auto usuario : this->petshop->getUsuarios())
    {
        cout << usuario << endl;
    }  
}

void MenuAdministrador::menuReporEstoque()
{
    printTitulo("Repondo Estoque...");
    Administrador *administrador = getAdministrador();
    string nome;
    int quantidade;

    cout << "Produto" << endl
         << "\tNome: ";
    cin >> nome;

    //bucar cadastro atraves do nome
    if(true){
        cout << "\tQuantidade: ";
        cin >> quantidade; 
        //aqui eu passo a quantidade

        this->popUp = "Reposição de estoque realizad com sucesso!";
    }
    else{
        this->popUp = "Produto inexistente no estoque!";
    }


}

void MenuAdministrador::menuPagamentoContas()
{
    printTitulo("Pagando Contas...");
    Administrador *administrador = getAdministrador();
    string descricao;
    Data dataVencimento;
    double valor;

    cout << "Conta" << endl
         << "\tDescricao: ";
    cin >> descricao;
    /*cout << "\tData: ";
    cin >> dataVencimento;*/
    cout << "\tValor: ";
    cin >> valor;

    administrador->pagarConta(descricao, dataVencimento, valor);
    this->popUp = "Pagamento realizado com sucesso!";

}

void MenuAdministrador::menuRelatorios()
{
}

void MenuAdministrador::printMenu()
{
    Menu::printMenu();
    printTitulo("MENU VENDEDOR");
    printOpcao(CADASTRAR_VENDEDOR, "Cadastrar novo vendedor");
    printOpcao(CADASTRAR_VETERINARIO, "Cadastrar novo veterinário");
    printOpcao(CADASTRAR_PRODUTOS, "Cadastrar novo produto");
    printOpcao(CADASTRAR_SERVICOS, "Cadastrar novo serviço");
    printOpcao(LISTAR_FUNCIONARIOS, "Listar funcionários");
    printOpcao(REPOR_ESTOQUE, "Repor estoque");
    printOpcao(PAGAR_CONTAS, "Pagar contas");
    printOpcao(GERAR_RELATORIOS, "Gerar relatórios");    
    cout << endl
         << endl;
}

void MenuAdministrador::realizaOperacao(int op)
{
    Menu::realizaOperacao(op);
    cout << endl
         << endl;
    switch (op)
    {
    case CADASTRAR_VENDEDOR:
        menuCadastrarVendedor();
        break;
    case CADASTRAR_VETERINARIO:
        menuCadastrarVeterinario();
        break;
    case CADASTRAR_PRODUTOS:
        menuCadastrarProdutos();
        break;
    case CADASTRAR_SERVICOS:
        menuCadastrarServicos();
        break;
    case LISTAR_FUNCIONARIOS:
        menuListarFuncionarios();
        break;
    case REPOR_ESTOQUE:
        menuReporEstoque();
        break;
    case PAGAR_CONTAS:
        menuPagamentoContas();
        break;
    case GERAR_RELATORIOS:
        menuRelatorios();
        break;
    default:
        if (op != OPCODE_SAIDA)
            //Coloca para a mensagem aparecer lá em cima do menu principal.
            this->popUp = "Opção não encontrada";
        break;
    }
}