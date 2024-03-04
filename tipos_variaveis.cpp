#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    //-2,147,483,648 a 2,147,483,648
    //4 bytes
    //int iNum1 = 42, iNum2, iNum3 = 17; //Não

    int iNum1 = 42;
    int iNum2 = 0;
    int iNum3 = 17; //Sim

    cout << "iNum1: " << iNum1 << "\nTamanho de iNum1: " << sizeof(iNum1) << endl;
    cout << "iNum2: " << iNum2 << "\nTamanho de iNum2: " << sizeof(iNum2) << endl;
    cout << "iNum3: " << iNum3 << "\nTamanho de iNum3: " << sizeof(iNum3) << endl;

    //-32,768 a 32,768
    //2 bytes
    short sNum = 17;

    cout << "sNum: " << sNum << "\nTamanho de sNum: " << sizeof(sNum) << endl;

    //-9,223,372,032,854,775,808 a 9,223,372,032,854,775,808
    //8 bytes
    long lNum = 17;

    cout << "lNum: " << lNum << "\nTamanho de lNum: " << sizeof(lNum) << endl;

    //?
    //8, 12 ou 16 bytes
    long long llNum = 17;

    cout << "llNum: " << llNum << "\nTamanho de llNum: " << sizeof(llNum) << endl;

    float fNum = 42.123456789;
    double dNum = 42.123456789;
    long double ldNum = 42.123456789;

    cout << "\nfNum: " << fNum << "\nTamanho de fNum: " << sizeof(fNum) << endl;
    cout << "dNum: " << dNum << "\nTamanho de dNum: " << sizeof(dNum) << endl;
    cout << "ldNum: " << ldNum << "\nTamanho de ldNum: " << sizeof(ldNum) << endl;

    char cValue = 'E';

    cout << "\ncValue: " << cValue << "\nTamanho de cValue: " << sizeof(cValue) << endl;
    cout << "(int) cValue: " << int(cValue) << endl;

    char cPalavraPreferida_1 = 77;
    char cPalavraPreferida_2 = 0x41;
    char cPalavraPreferida_3 = 0b1110000;

    cout << "\n" << cValue;
    cout << cPalavraPreferida_1;
    cout << cPalavraPreferida_2;
    cout << cPalavraPreferida_3 << endl;

    string strValue_1 = "Eu adoro a";
    string strValue_2 = "EMAp";
    cout << "strValue_1: " << strValue_1 << "\nTamanho de strValue_1: " << sizeof(strValue_1) << endl;
    cout << "strValue_2: " << strValue_2 << "\nTamanho de strValue_2: " << sizeof(strValue_2) << endl;

    cout << "\n" << strValue_1 << " " << strValue_2 << endl;

    bool bValeu_1 = true;
    bool bValeu_2 = false;
    bool bValeu_3 = 42;
    bool bValeu_4 = 0;

    cout << "\nbValeu_1: " << bValeu_1 << "\nTamanho de bValeu_1: " << sizeof(bValeu_1) << endl;
    cout << "bValeu_2: " << bValeu_2 << "\nTamanho de bValeu_2: " << sizeof(bValeu_2) << endl;
    cout << "bValeu_3: " << bValeu_3 << "\nTamanho de bValeu_3: " << sizeof(bValeu_3) << endl;
    cout << "bValeu_4: " << bValeu_4 << "\nTamanho de bValeu_4: " << sizeof(bValeu_4) << endl;

    const int iNUMERO = 42;
    //iNUMERO = 111; //Não pode fazer isso, pois o valor de iNUMERO só pode ser 42
    cout << "\niNUMERO: " << iNUMERO << "\nTamanho de iNUMERO: " << sizeof(iNUMERO) << endl;

    unsigned short usNUMERO = 42;
    cout << "\nusNUMERO: " << usNUMERO << "\nTamanho de usNUMERO: " << sizeof(usNUMERO) << endl;

    unsigned long long int ulliNUMERO_1 = 42;
    cout << "\nulliNUMERO_1: " << ulliNUMERO_1 << "\nTamanho de ulliNUMERO_1: " << sizeof(ulliNUMERO_1) << endl;
    
    return 0;
}