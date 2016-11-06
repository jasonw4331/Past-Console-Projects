# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <string>
# include <time.h>
# include <windows.h>
# define l 3
# define c 3
using namespace std;

bool validatePosition (char pos, char mt[l][c], bool player1);
bool fake_ValidatePostition (char pos, char mt[l][c], bool player1);
bool gameOver (char mt[l][c],short op,short &cont_p1,short &cont_p2,short &cont_cpu);
void showGame  (char mt[l][c],short op);
void cpu(char mt[l][c]);
void cpu_hard(char mt[l][c]);
void cpu_cheat(char mt[l][c]);
string changeName1();
string changeName2();
short i,j,op,opt,cont_p1 = 0 ,cont_p2 = 0,cont_cpu = 0;
char op2;
char mt[l][c],pos;
bool player1 = false,mult = false,is_cpu = false;
string p1,p2;


int main(void)
{
    cout << "General Public License v3 \n";
    cout << "Programmer: jasonwynn10" << endl;
    cout << "Legend: \nPlayer 1: X \nPlayer 2 OR CPU: O\n\n";


        do
        {
            cout <<"Choose your option:\n1-Multiplayer 2-CPU\n";
            cin>>op;
            if(op == 1)
                mult = true;
            else if (op == 2)
                is_cpu = true;
            if(op!=1 && op!=2)
                cout<<"Choose your option, type only 1 or 2\n";
        }
        while(op != 1 && op != 2);

        if(is_cpu && mult)
        {
            cont_p1 = 0;
            cont_p2 = 0;
            cont_cpu = 0;
        }
        if(op == 2)
        {
            mult = false;
            cout<<"Choose level:1-Easy 2-Hard\n"<<endl;
            cin>>opt;
        }
        fflush(stdin);

        if(op == 1)
        {
            is_cpu = false;
            p1 = changeName1();
            p2 = changeName2();
        }
        else
            p1 = changeName1();
        do
    {
        cout << "Enter the number corresponding to the desired location: \n" << endl << endl;

        ///Starting matrix
        for (i = 0; i < l; i++)
        {
            for (j = 0; j < c; j ++)
            {
                mt[i][j] = '?';
            }
        }
        /// -----------
        int count = 1;
        /// Showing the positions
        for (i = 0; i < l*2; i++)
        {
            cout << "                    ";
            for (j = 0; j < c*2; j++)
            {
                if(i % 2 == 0)
                {
                    if(j%2 == 0)
                    {
                        cout << "["<<count<<"]" <<" ";
                        count ++;
                    }
                    else
                    {
                        if(j != c*2-1)
                            cout <<"| ";
                    }
                }
                else
                {
                    if(j%2 != 0)
                        cout <<"-----";
                }
            }
            cout << endl;
        }
        ///---------char pos, char mt [l][c], bool player1
        cout  << endl;
        do
        {
            do
            {
                /// Getting position player 1
                do
                {
                    cout << "Player 1:" << p1 <<"\n";
                    cin >> pos;
                }
                while (isdigit (pos) == 0);
                player1 = true;
            }
            while (!validatePosition (pos, mt, player1));
            system ("CLS");
            showGame(mt,op);

            if (gameOver(mt,op,cont_p1,cont_p2,cont_cpu))
                break;

            if(opt == 1)
            {
                Sleep(1000);
                cpu(mt);
                system ("CLS");
                showGame(mt,op);
            }
            if(opt == 2)
            {
                Sleep(1000);
                cpu_hard(mt);
                system ("CLS");
                showGame(mt,op);
            }
            if(opt == 7)
            {
                printf("/nCheat Mode Initiated/nLoading.../n");
                Sleep(1000);
                cpu_cheat(mt);
                system ("CLS");
                showGame(mt,op);
            }
            else if(op == 1)
            {
                do
                {
                    cout << "Player 2:" << p2 <<"\n";
                    cin >> pos;
                    player1 = false;
                }
                while (!validatePosition (pos, mt, player1));
                system ("CLS");
                showGame(mt,op);
            }

            if (gameOver(mt,op,cont_p1,cont_p2,cont_cpu))
                break;
        }
        while (true);
        cout << "Do you want to continue?\nY to continue or anything else to quit.\n" << endl;
        cin >> op2;
        system ("CLS");
        }
    while (op2 == 'Y'||op2=='y');
    system("pause");
if(op == 1)
        {
            cout <<"Ranking:\n"<<p1<<": "<< cont_p1 <<endl<<p2<<": "<< cont_p2 <<endl;
        }
        else
            cout <<"Ranking:\n"<<p1<<": "<< cont_p1 <<"\nCPU:"<< cont_cpu <<endl;
}
bool validatePosition (char pos, char mt [l][c], bool player1)
{
    if (pos == '1')
    {
        if (mt [0][0] != '?')
        {
            cout << "Position already used,type another position." << endl;
        }
        else
        {
            if (player1 == true)
                mt [0][0] = 'X';
            else
                mt [0][0] = 'O';
            return true;
        }
    }
    else if (pos == '2')
    {
        if (mt [0][1] != '?')
        {
            cout << "Position already used, type another position." << endl;
        }
        else
        {
            if (player1 == true)
                mt [0][1] = 'X';
            else
                mt [0][1] = 'O';
            return true;
        }
    }
    else if (pos == '3')
    {
        if (mt[0][2] != '?')
        {
            cout << "Position already used, type another position." << endl;
        }
        else
        {
            if (player1 == true)
                mt [0][2] = 'X';
            else
                mt [0][2] = 'O';
            return true;
        }
    }
    else if (pos == '4')
    {
        if (mt [1][0] != '?')
        {
            cout << "Position already used, type another position." << endl;
        }
        else
        {
            if (player1 == true)
                mt [1][0] = 'X';
            else
                mt [1][0] = 'O';
            return true;
        }
    }
    else if (pos == '5')
    {
        if (mt [1][1] != '?')
        {
            cout << "Position already used, type another position." << endl;
        }
        else
        {
            if (player1 == true)
                mt [1][1] = 'X';
            else
                mt [1][1] = 'O';
            return true;
        }
    }
    else if (pos == '6')
    {
        if (mt [1][2] != '?')
        {
            cout << "Position already used, type another position." << endl;
        }
        else
        {
            if (player1 == true)
                mt [1][2] = 'X';
            else
                mt [1][2] = 'O';
            return true;
        }
    }
    else if (pos == '7')
    {
        if (mt [2][0] != '?')
        {
            cout  << "Position already used, type another position." << endl;
        }
        else
        {
            if (player1 == true)
                mt [2] [0] = 'X';
            else
                mt [2] [0] = 'O';
            return true;
        }
    }
    else if (pos == '8')
    {
        if (mt [2][1] != '?')
        {
            cout << "Position already used, type another position." << endl;
        }
        else
        {
            if (player1 == true)
                mt [2][1] = 'X';
            else
                mt [2][1] = 'O';
            return true;
        }
    }
    else if (pos == '9')
    {
        if (mt [2][2] != '?')
        {
            cout << "Position already used, type another position." << endl;
        }
        else
        {
            if (player1 == true)
                mt [2] [2] = 'X';
            else
                mt [2][2] = 'O';
            return true;
        }
    }
    else
        cout << "Invalid number, type number 1-9.";
    return false;
}
bool fake_ValidatePostition(char pos, char mt [l][c], bool player1)
{
    if (pos == '1')
    {

            if (player1 == true)
                mt [0][0] = 'X';
            else
                mt [0][0] = 'X';
            return true;
    }
    else if (pos == '2')
    {
            if (player1 == true)
                mt [0][1] = 'X';
            else
                mt [0][1] = 'X';
            return true;

    }
    else if (pos == '3')
    {
            if (player1 == true)
                mt [0][2] = 'X';
            else
                mt [0][2] = 'X';
            return true;

    }
    else if (pos == '4')
    {
            if (player1 == true)
                mt [1][0] = 'X';
            else
                mt [1][0] = 'X';
            return true;
    }
    else if (pos == '5')
    {
            if (player1 == true)
                mt [1][1] = 'X';
            else
                mt [1][1] = 'X';
            return true;
    }
    else if (pos == '6')
    {
            if (player1 == true)
                mt [1][2] = 'X';
            else
                mt [1][2] = 'X';
            return true;
    }
    else if (pos == '7')
    {
            if (player1 == true)
                mt [2] [0] = 'X';
            else
                mt [2] [0] = 'X';
            return true;
    }
    else if (pos == '8')
    {
            if (player1 == true)
                mt [2][1] = 'X';
            else
                mt [2][1] = 'X';
            return true;
    }
    else if (pos == '9')
    {
            if (player1 == true)
                mt [2] [2] = 'X';
            else
                mt [2][2] = 'X';
            return true;
    }
    else
        cout << "Invalid number, type number 1-9.";
    return false;
}
void showGame(char mt[l][c],short op)
{

    cout << "General Public License v3 \n";
    cout << "Programmer: jasonwynn10\n" << endl;
    if(op == 1)
    {
        cout << "Legend: \nPlayer 1: X \nPlayer 2: O\n" << endl << endl;
    }
    else
        cout << "Legend: \nPlayer 1: X \nCPU: O\n" << endl << endl;

    int count = 1;
    for (int i = 0; i < l; i++)
    {
        cout << "                    ";
        for  (int j = 0; j < c; j ++)
        {
            if (mt [i][j] == '?')
            {
                cout << "["<<count<<"]| ";
            }
            else if (mt [i][j] == 'X')
            {
                cout << "[X]| ";
            }
            else
                cout << "[O]| ";
            count ++;
        }
        cout <<"\n\t            --------------\n";
    }
    cout << endl;
}
bool gameOver (char mt[l][c],short op,short &cont_p1,short &cont_p2,short &cont_cpu)
{
    /// Check if there was a winner or a tie
    int  ct = 0 ;/// total counter
    int d = c-1 ;/// auxiliary variable for secondary diagonal
    int contd = 0 ;/// counter diagonal
    int contd2 = 0 ;/// counter for diagonal secondary
    int contc ;/// counter for column
    int contl ;/// counter for line player 1
    int contdj2 = 0 ;/// counter diagonal for player 2
    int contd2j2 = 0 ;/// counter for diagonal secondary player 2
    int contcj2;/// counter for the column player 2
    int contlj2;/// counter for line player 2

    for (int i = 0; i < l; i ++)
    {
        contc = 0;
        contcj2 = 0;
        contl = 0;
        contlj2 = 0;
        if (mt [i][i] == 'O')
            contdj2 ++;
        if (mt [i][d] == 'O')
            contd2j2 ++;
        if (mt [i][i] == 'X')
            contd ++;
        if (mt [i][d] == 'X')
            contd2 ++;
        d--;
        for (int j = 0; j < c; j ++)
        {
            if (mt[i][j] != '?')
                ct ++;
            if (mt [i][j] == 'O')
                contlj2 ++;
            if (mt [j][i] == 'O')
                contcj2 ++;
            if (mt [i][j] == 'X')
                contl ++;
            if (mt [j][i] == 'X')
                contc ++;
        }
        if (contl == 3 || contd == 3 || contc == 3 || contd2 == 3)
        {
            cont_p1++;
            cout << "Player 1 wins!" << endl;
            if(op == 1)
            {
                cout <<" Ranking:\nPlayer 1:"<< cont_p1 <<"\nPlayer 2:"<< cont_p2 <<"\n";
            }
            else
            {
                cout <<" Ranking:\nPlayer 1:"<< cont_p1 <<"\nCPU:"<< cont_cpu <<"\n";
            }

            return true;
        }
        if (contlj2 == 3 || contdj2 == 3 || contcj2 == 3 || contd2j2 == 3)
        {
            if(op == 1)
            {
                cout << "Player 2 wins!" << endl;
                cont_p2++;
                cout <<" Ranking:\nPlayer 1:"<< cont_p1 <<"\nPlayer 2:"<< cont_p2 <<"\n";
            }
            else
            {
                cout << "CPU wins!" << endl;
                cont_cpu++;
                cout <<" Ranking:\nPlayer 1:"<< cont_p1 <<"\nCPU:"<< cont_cpu <<"\n";
            }
            return true;
        }
    }
    if (ct==l*c)
    {
        cout << "Cats Game!\n" << endl;
        if(op == 1)
        {
            cout <<" Ranking:\nPlayer 1:"<< cont_p1 <<"\nPlayer 2:"<< cont_p2 <<"\n";
        }
        else
            cout <<" Ranking:\nPlayer 1:"<< cont_p1 <<"\nCPU:"<< cont_cpu <<"\n";
        return true;
    }
    return false;
}
void cpu(char mt[l][c])
{
    /* initialize random seed: */
    srand (time(NULL));

    int x,cont;
    bool found = false;
    while(found == false)
    {
        x = rand()%9+1;
        cont = 1;
        for(int i = 0; i < l; i++ )
        {
            for(int j = 0; j < c; j++ )
            {
                if(cont == x)
                {
                    if(mt[i][j] != 'X' && mt[i][j] != 'O')
                    {
                        mt[i][j] = 'O';
                        found = true;
                    }
                }
                cont++;
            }
        }
    }
}
void cpu_hard(char mt[l][c])
{

    int d = c-1 ;// auxiliary variable for secondary diagonal
    int contd = 0 ;// counter diagonal
    int contd2 = 0 ;// counter for secondary diagonal
    int contc ;// counter for column
    int contl ;// counter for line player 1

    int contd_Cpu = 0 ;// counter diagonal for cpu
    int contd2_Cpu = 0 ;// counter for secondary diagonal of cpu
    int contc2;// counter for the column cpu
    int contl2;// counter for line cpu
    bool found = false;

    for (int i = 0; i < l; i ++)
    {
        contc = 0;
        contl = 0;
        contc2 = 0;
        contl2 = 0;

        if (mt [i][i] == 'X')
            contd ++;
        if (mt [i][d] == 'X')
            contd2 ++;
        if (mt [i][i] == 'O')
            contd_Cpu ++;
        if (mt [i][d] == 'O')
            contd2_Cpu ++;
        d--;
        for (int j = 0; j < c; j ++)
        {
            if (mt [i][j] == 'X')
                contl ++;
            if (mt [j][i] == 'X')
                contc ++;
            if (mt [i][j] == 'O')
                contl2 ++;
            if (mt [j][i] == 'O')
                contc2 ++;
        }
        if(contd2_Cpu == 2 || contc2 == 2 || contd_Cpu == 2 || contl2 == 2)
        {
            if (contl2 == 2)
            {
                for (int z = 0; z < c; z ++)
                {
                    if (mt [i][z] == '?')
                    {
                        mt[i][z] = 'O';
                        found = true;
                    }
                }
            }
            else if(contd_Cpu == 2)
            {
                for (int z = 0; z < c; z ++)
                {
                    if (mt [z][z] == '?')
                    {
                        mt[z][z] = 'O';
                        found = true;
                    }
                }
            }
            else if(contc2 == 2)
            {
                for (int z = 0; z < c; z ++)
                {
                    if (mt [z][i] == '?')
                    {
                        mt[z][i] = 'O';
                        found = true;
                    }
                }
            }
            else if(contd2_Cpu == 2)
            {
                int x = 0;
                for (int z = c-1; z >= 0; z --)
                {
                    if (mt [x][z] == '?')
                    {
                        mt[x][z] = 'O';
                        found = true;
                    }
                    x++;
                }
            }
        }
        else
        {
            if (contl == 2)
            {
                for (int z = 0; z < c; z ++)
                {
                    if (mt [i][z] == '?')
                    {
                        mt[i][z] = 'O';
                        found = true;
                    }
                }
            }
            else if(contd == 2)
            {
                for (int z = 0; z < c; z ++)
                {
                    if (mt [z][z] == '?')
                    {
                        mt[z][z] = 'O';
                        found = true;
                    }
                }
            }
            else if(contc == 2)
            {
                for (int z = 0; z < c; z ++)
                {
                    if (mt [z][i] == '?')
                    {
                        mt[z][i] = 'O';
                        found = true;
                    }
                }
            }
            else if(contd2 == 2)
            {
                int x = 0;
                for (int z = c-1; z >= 0; z --)
                {
                    if (mt [x][z] == '?')
                    {
                        mt[x][z] = 'O';
                        found = true;
                    }
                    x++;
                }
            }
        }
        if(found)
            break;
    }
    if(!found)
        cpu(mt);
}
void cpu_cheat(char mt[l][c])
{
 /* initialize random seed: */
    srand (time(NULL));

    int x,cont;
    bool found = false;
    while(found == false)
    {
        x = rand()%9+1;
        cont = 1;
        for(int i = 0; i < l; i++ )
        {
            for(int j = 0; j < c; j++ )
            {
                if(cont == x)
                {
                    if(mt[i][j] != 'X' && mt[i][j] != 'O')
                    {
                        mt[i][j] = 'X';
                        found = true;
                    }
                }
                cont++;
            }
        }
    }
}
string changeName1()
{
    string name1;
    cout << "Enter name of player 1" << endl;
    getline(cin, name1);
    return name1;

}
string changeName2()
{
    string name2;
    cout << "Enter name of player 2" << endl;
    getline(cin, name2);
    return name2;
}
