struct Score;
char*** init_tuiles(int);          /*initialise la grille tuiles à partir des chaines fournies par l'utilisateur. */
char*** init_jeu(char***);      /*initialise la grille jeu à partir de la grille tuiles.*/
int retourner2(char*** jeu, char*** tuiles,int*); /*demande 4 entiers a,b,c,d  à l'utilisateur et retourne face découverte 2 tuiles dont les coordonnées sur les grilles sont (a,b) et (c,d) à condition bien sur que les tuiles soient faces cachées et que les entiers saisis correspondent bien aux dimensions de la grille. Si entrées valides, @return 0, sinon @return 1.*/
int tour(char*** jeu, char*** tuiles,int*); /* simule un tour de jeu : @return 0 si le joueur marque 1 point et doir rejouer, sinon, @return 1 . Le main servira à simuler la partie entière.*/
int paires(char*** jeu); /*compte le nombre de paires déja découvertes*/
int strcmp(const char *str1, const char *str2);
