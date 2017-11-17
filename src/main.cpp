#include <bits/stdc++.h>
#include "Scanner.h"
#include "Token.h"
#include "KeywordTable.h"
#include "DelimiterTable.h"
#include "ConstTable.h"
#include "SymbolTable.h"
#include "RDAnalyzer.h"
#include "Vall.h"
#include "QuadrupleTable.h"
using namespace std;

void testScanner(Scanner &sc)
{
    while (sc.getLastToken().type != ERROR &&
            sc.getLastToken().type != END)
    {
        sc.next();
        if (sc.getLastToken().type != END)
            cout << sc.getLastToken().word << endl;
        else
            cout << "END" << endl;
    }
}

void testAnalyzer(RDAnalyzer &ra)
{
    cout << ra.analyze() << endl;
}

int main(int argc, char *argv[])
{
    /*Scanner(string s, KeywordTable *kt, DelimiterTable *dt, CharConstTable *cct,
        StrConstTable *strct, IntConstTable *ict, FloatConstTable *fct,
        SymbolTable *st)*/
    string test = "float a = 3; int b = 2 + 3;const int c = 5; int d = 2 , e;\n";//((1+2)*3)/1e4; a = 3 + x / 3.14;\n";
    KeywordTable kt;
    DelimiterTable dt;
    CharConstTable cct;
    StrConstTable strct;
    IntConstTable ict;
    FloatConstTable fct;
    SymbolTable st;
    Vall vall;
    TypeTable tt;
    Scanner sc(test, &kt, &dt, &cct, &strct, &ict, &fct, &st, &vall, &tt);

    //testScanner(sc);
    //st.print();

    QuadrupleTable qt;
    RDAnalyzer ra(&sc, &qt);

    testAnalyzer(ra);

    return 0;
}
