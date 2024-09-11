typedef struct number
{
    int nb, nb2, nb3, nb4;
    //int power[8], power2[8], power3[8], power4[8];
    /*int bin[8]={0};
    int bin2[8]={0};
    int bin3[8]={0};
    int bin4[8]={0};*/
}number;
void debug_ip();
void calcul_binaire(number n1);
void affichage_binaire(number n1, int bin[8], int bin2[8], int bin3[8], int bin4[8]);
void IPclass(number n1);