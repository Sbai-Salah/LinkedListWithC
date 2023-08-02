#include <stdio.h>
#include <stdlib.h>
// si on declare pas les fonctions avant qu'on les appels 
// on va obtenir un error qui dit : "Conflicting type ... "
struct Node {
	double valeur; 
	struct Node *suivant;
};
// les declarations////////////////////////////////////////////////////////
void remplir_par_tete();
void remplir_par_queue();
struct Node *insertion_tete(struct Node *liste);
void parcours_gd_nonRec(struct Node *liste);
struct Node* insertion_fin(struct Node*liste);
void parcours_gd_recursif(struct Node *liste);
void acces_par_position(struct Node *liste);
struct Node* accee_recursif_par_position(struct Node *liste, int k);
void acce_a_la_valeur(struct Node *liste);
struct Node *dernier(struct Node* liste);
struct Node *suprimetete(struct Node *Li);
void supprimerk(struct Node *Li);
struct Node *concat(struct Node *li);
int size_of_linked_list(struct Node* liste);
void Tri(struct Node* liste);
///////////////////////////////////////////////////////////////////////////


typedef enum{
	false = 0,
	true
}bool;
// Their is no bool type in C
// i used enum structure to define the new type bool that takes false if it's 0 and true if 1


struct Node *liste = NULL; 




int main(int argc, char *argv[]) {
	int choix; double e;
    int k;
	Menu();
	   
	 while(1){
	 		printf("\n>>Votre choix : ");
	        scanf("%d",&choix);
	        printf("--------------------\n");
	        
	 	switch(choix){
			case 1: remplir_par_tete();
			        break;
			case 2: remplir_par_queue();
			        break;
			case 3: parcours_gd_nonRec(insertion_tete(liste));
			        break;
			case 4: insertion_fin(liste);
			        break;
		    case 5: suprimetete(liste);
		            break;
		    case 6: supprimerk(liste);
		            break; 
		    case 7: parcours_gd_nonRec(liste);
		            break; 
		    case 8: parcours_gd_recursif(liste);
		            break; 
		    case 9: acce_a_la_valeur(liste);
		            break; 
		    case 10: acces_par_position(liste);
		            break; 
		    case 11:
			        printf(">Enter position to access : ");
			        scanf("%d",&k);
			        parcours_gd_nonRec(accee_recursif_par_position(liste, k));
		            break;
		    case 12: parcours_gd_recursif(concat(liste));
		            break;
			case 13: printf("Size of The linked list is : %d", size_of_linked_list(liste));
			         break; 
			case 14: Tri(liste);  
			         break;    
			case 15: printf("\n\t\t\t --Thank you --\n");
			         exit(-1);
			default: 
			     printf("\n\n Choose from the list above\n\n");
		 }
	 }

	
	return 0;
}






//------------------


void parcours_gd_recursif(struct Node *liste){
	if(liste != NULL){
		printf("%lf --> ",liste->valeur);
		parcours_gd_recursif(liste->suivant);
	}
	
}



void parcours_gd_nonRec(struct Node *liste){
	struct Node *liste1;
	liste1 = liste;
   //  !! avoid manipilating the original root
printf("\n--------------------------------------\n");
	while(liste1 != NULL){
		
		printf("%lf --> ",liste1->valeur);
		liste1 = liste1->suivant;
	}
printf("\n--------------------------------------");
}

/* ALGORITHMES POUR ACCEDER A UNE LISTE CHAINE*/
void acces_par_position(struct Node *liste){

	int k;
	bool trouve;
	
	struct Node *pointk;
	
	printf("> Enter position to access : ");
	scanf("%d",&k);
	
	struct Node *liste1;
	int i;
	
	liste1 = liste;
	i = 1;
	
	while(i<k && liste1 != NULL){
		i = i + 1;
		liste1 = liste1->suivant;
	}
	trouve = (i == k) && liste != NULL; 
	pointk = liste1;
	if(trouve == true){
		printf("\n%lf IT IS IN THE LINKED LIST \n", pointk->valeur);
	}else{
		printf("\nTHERE IS NOTHIG AT THIS POSITION (POSITION : %d)\n", k);

	}
	
}

struct Node* accee_recursif_par_position(struct Node *liste, int k){

	
	if(liste == NULL){
		return NULL;
	}else {
		if (k == 1){
			return liste;
		}else {
			return accee_recursif_par_position(liste->suivant, k-1);
			
		}
	}
	
	
	
}

// accer par le biai d'une valeur
void acce_a_la_valeur(struct Node *liste){
	double val;
	struct Node* liste_from_the_value;
	bool trouver;
	
	printf(">> Enter value you are looking for : ");
	scanf("%lf",&val);
	
	struct Node *liste1;
	liste1 = liste;
	
	while(liste1 != NULL && liste1->valeur != val){
		liste1 = liste1->suivant;
	}
	
	trouver = (liste1 != NULL);
	liste_from_the_value = liste1;
	 // we can use the display function here if we want
	if(trouver){
		printf("\n%lf EST DANS LA LISTE CHAINNE \n", val);
	}
	
}


/*Inserer un element dans la LC*/

struct Node *insertion_tete(struct Node *liste){
	
	double e;
	printf(">Enter value to add into head : ");
	scanf("%lf",&e);
	
	// we create the new Node p
	struct Node *p;
	p = (struct Node*)malloc(sizeof(struct Node));
	
	p->valeur = e; 
	p->suivant = liste; // remember that liste = NULL at first
	liste = p; // we make liste points to p
	return liste; // we return just the starting point
}

// dernier : helps us finding the last element in the linked list

struct Node *dernier(struct Node* liste){
	struct Node *p, *last_elm;
	p = liste;
	while(p != NULL){
		last_elm = p;
		p = p->suivant;
	}
	return last_elm;
}

struct Node* insertion_fin(struct Node*liste){
	struct Node *der, *p;
	double e;
	printf(">Enter value to add into back : ");
	scanf("%lf",&e);
	if(liste == NULL){
		insertion_tete(liste);
	}else{
		der = dernier(liste); 
		p = (struct Node*)malloc(sizeof(struct Node));
        p->valeur = e;
        p->suivant = NULL;
        der->suivant = p;
	}
	return liste;
}


//--------remplir une list par la tete---------- 


void remplir_par_tete(){
	
	double e;
	printf(">Enter value to add into head : ");
	scanf("%lf",&e);
	struct Node *p;
	p = (struct Node*)malloc(sizeof(struct Node));
	
	p->valeur = e;
	p->suivant = liste;
	liste = p;
}

//---------------------------------------------
//--------remplir une list par la queue---------- 

void remplir_par_queue(){
	struct Node *der, *p;
	double e;
	

	if(liste == NULL){
		printf("\nThe list is empty add a number to the head::\n");
		remplir_par_tete();
	}else{
			printf("\n>Enter value to add into back : ");
	        scanf("%lf",&e);
		der = dernier(liste); 
		p = (struct Node*)malloc(sizeof(struct Node));
        p->valeur = e;
        p->suivant = NULL;
        der->suivant = p;
	}
	
	
}

//---------------------------------------------





// supression de l'element en tete 

struct Node *suprimetete(struct Node *Li){
	struct Node *p = Li ; 
	
	Li = Li->suivant ; 
	return Li;
}
// supression de l'element en k-eme position

void supprimerk(struct Node *Li){
	int k;
	printf("> Enter position to delete : ");
	scanf("%d",&k);
	struct Node *p, *precedent ;
	
	if(Li != NULL && k == 1){
		suprimetete(Li) ; 
	}
	else {
	    precedent = accee_recursif_par_position(Li,k-1);
	}	
	
	if(precedent != NULL){
		p = precedent->suivant ; 
		if(p != NULL)
			precedent->suivant = p->suivant ; 
	}
}

struct Node *concat(struct Node *li){
	// creation du liste a concatener
	// ici j'ai concatener la liste avec elle meme
	//on peut prendre deux liste pour ce faire
	// et donner a cette fonction deux arguements de typee struct Node
	
	
	struct Node* Li = NULL;
	
	struct Node *der ; 
	struct Node *L ; 
	
	if(li == NULL){
		L = Li ; 
		return L ;
	}
	else{
		L = li ; 
		if(Li != NULL){
			der = dernier(li) ; 
			der->suivant = Li ; 
		}
		L = li ;
		return L ; 
	}
}



int size_of_linked_list(struct Node* liste){
	
	int counter = 0;
	
	while(liste != NULL){
		counter++;
		liste = liste->suivant;
	}
	
	return counter;
}


void Tri(struct Node* liste){
	struct Node *i = liste, *j;
	double temp; // meme type du valeur
	
while(i->suivant != NULL){
	j = i->suivant;
	while(j!=NULL){
		if(i->valeur > j->valeur){
			temp = i->valeur;
			i->valeur = j->valeur;
			j->valeur = temp;
		}
		j = j->suivant;
	}
	i = i->suivant;
}

parcours_gd_recursif(liste);

}