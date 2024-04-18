#include <iostream>

using std::cout;
using std::endl;
using std::string;

typedef struct Livro
    {
        string strTitulo;
        string strAutor;
        int iPublicado;   
    } Livro; 

struct Ponto
    {
        unsigned short usRed;
        unsigned short usGreen;
        unsigned short usBlue; 
    };  

typedef struct Biblioteca
    {
        string strNome;
        int iTamAcervo;
        struct Livro livros[1000]; 
    } Biblioteca;    

void listarLivros(struct Biblioteca);
void adicionarLivros(struct Biblioteca&, struct Livro);         

int main()
{   
    struct Biblioteca biblioteca;
    biblioteca.strNome = "Biblioteca do Palácio Botafogo";
    biblioteca.iTamAcervo = 0;
 
    struct Livro livro1;
    livro1.strTitulo = "Outliers: The Story of Success";
    livro1.strAutor = "Malcolm Gladwell";
    livro1.iPublicado = 2008;

    struct Livro livro2;
    livro2.strTitulo = "How to Grow Old";
    livro2.strAutor = "MarusTullius Cicero";
    livro2.iPublicado = -44;

    struct Livro livro3;
    livro3.strTitulo = "1984";
    livro3.strAutor = "George Orwell";
    livro3.iPublicado = 1949;

    listarLivros(biblioteca);

    adicionarLivros(biblioteca, livro1);
    adicionarLivros(biblioteca, livro2);
    adicionarLivros(biblioteca, livro3);

    listarLivros(biblioteca);




    /*
    struct Ponto telaComputador[640][480];
    telaComputador[0][0].usRed = 255;
    telaComputador[0][0].usGreen = 255;
    telaComputador[0][0].usBlue = 255;

    cout << "RGB [0,0] (" << telaComputador[0][0].usRed << "," << telaComputador[0][0].usGreen << "," << telaComputador[0][0].usBlue << ")" << endl;
    */
    
    /*
    struct
    {
        int iIdade;
        string strNome;   
    } alunoEMAp;

    alunoEMAp.iIdade = 18;
    alunoEMAp.strNome = "Ana";

    cout << "Idade do alunoEMAp: " << alunoEMAp.iIdade << endl;
    cout << "Nome do alunoEMAp: " << alunoEMAp.strNome << endl;

    struct
    {
        int iIdade;
        string strNome;   
    } alunoEMAp1, alunoEMAp2;

    alunoEMAp1.iIdade = 20;
    alunoEMAp1.strNome = "Antonio";

    cout << "Idade do alunoEMAp1: " << alunoEMAp1.iIdade << endl;
    cout << "Nome do alunoEMAp1: " << alunoEMAp1.strNome << endl;
    
    alunoEMAp2.iIdade = 17;
    alunoEMAp2.strNome = "Henzo";

    cout << "Idade do alunoEMAp2: " << alunoEMAp2.iIdade << endl;
    cout << "Nome do alunoEMAp2: " << alunoEMAp2.strNome << endl;
    */
    

    return 0;
}


void listarLivros(struct Biblioteca biblioteca)
{   
    cout << "\nLivros do Acervo da " << biblioteca.strNome << "\n\n" << endl;

    for (int i = 0; i < biblioteca.iTamAcervo; i++)
    {
        cout << "Titulo: " << biblioteca.livros[i].strTitulo << ", por " << biblioteca.livros[i].strAutor << endl;
        cout << "Publicado em: " << biblioteca.livros[i].iPublicado << ".\n" << endl;
    }
}

// Verificar se está completo
void adicionarLivros(struct Biblioteca& biblioteca, struct Livro novoLivro)
{
    biblioteca.livros[biblioteca.iTamAcervo] = novoLivro;
    biblioteca.iTamAcervo+=1;
}