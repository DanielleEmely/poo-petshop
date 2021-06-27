#include "../hpp/produto.hpp"

Produto::Produto(string nome, double preco, int quantidade, long id)
{
    setNome(nome);
    setPreco(preco);
    setQuantidade(quantidade);
    setId(id);
}
Produto::~Produto() {}

void Produto::setNome(string nome)
{
    const char *novoNome = nome.data();
    int length = nome.size();
    length = (length < M ? length : M - 1);
    strncpy(this->nome, novoNome, length);
    this->nome[length] = '\0';
}
void Produto::setPreco(double preco)
{
    this->preco = preco;
}
void Produto::setId(long id)
{
    this->id = id;
}

void Produto::setQuantidade(int quantidade)
{
    this->quantidade = quantidade;
}

string Produto::getNome()
{
    return this->nome;
}
double Produto::getPreco()
{
    return this->preco;
}
long Produto::getId()
{
    return this->id;
}

int Produto::getQuantidade()
{
    return this->quantidade;
}

bool Produto::operator==(Produto produto)
{
    return this->nome == produto.getNome() &&
           this->preco == produto.getPreco() &&
           this->quantidade == produto.getQuantidade() &&
           this->id == produto.getId();
}
ostream &operator<<(ostream &os, const Produto &produto)
{
    os << produto.id << " - " << produto.nome << "- R$" << produto.preco;
    return os;
}
