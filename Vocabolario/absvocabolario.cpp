#include "absvocabolario.h" // class's header file

// class constructor

int AbsVocabolario::GetMin (int a, int b, int c)
{
    int min =a;
    if (b < min)
        min=b;
    if (c < min)
        min=c;
    return min;
}

int AbsVocabolario::DistEdit(string word1 , string word2)
{
    int n = word1.length();
    int m = word2.length();
    int i,j;
    char w_1 , w_2;
    int sizem = m+1;
    int sizen = n+1;
    int costo;

              // se la stringa sorgente è vuota
    if (n == 0) // la distanza è il num di char della dest.
    {
        return m;
    }
        // se la stringa destinazione è vuota
    if (m == 0) // la distanza è il num di chr della sorg.
    {
        return n;
    }
    // creo la matrice (n+1)*(m+1)
    int d[sizen][sizem];

        // la prima riga della mat. conterrà le distanze da 0 a n
        // la distanza 1 è associata al primo chr della stringa, 0 al vuoto
        //  esempio:
        // 0 1 2 3 4 5 6 7 8
        // - f a g g i a n o
    for (i = 0; i <= n; i++)
    {
            d[i][0] = i;
    }
      // la prima colonna della mat. conterrà le distanze da 0 a m
        // la distanza 1 è associato al primo chr della stringa, 0 al vuoto
        // Nel caso del nostro esempio:
        // - 0
        // f 1
        // a 2
        // b 3
        // b 4
        // r 5
        // i 6
        // a 7
        // n 8
        // o 9
    for (j = 0; j <= m; j++)
    {
            d[0][j] = j;
    }

    for (i=1;i <= n;i++)
    {
        w_1 = word1[i-1];
        for (j = 1 ;j <= m ; j++)
        {
            w_2 = word2[j-1];
            if (w_1==w_2)
                costo=0;
            else
                costo=1;
        // imposto la cella d[i][j] scegliendo il valore minimo tra:
        //   - la cella immediatamente superiore + 1
        //   - la cella immediatamente a sinistra + 1
        //   - la cella diagonalmente in alto a sinistra più il costo
            d[i][j] = GetMin(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + costo);
        }

    }
    return d[n][m];
}
