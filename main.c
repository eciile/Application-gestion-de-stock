#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100  // nombre maximum de produits pouvant �tre stock�s

// Structure pour repr�senter un produit
typedef struct {
  char name[100];
  char description[200];
  int quantity;
  int entry_history[30];  // historique des entr�es pour le produit (une entr�e par jour)
  int exit_history[30];   // historique des sorties pour le produit (une sortie par jour)
} product_t;

// Structure de donn�es pour stocker tous les produits en stock
product_t products[MAX_PRODUCTS];
int num_products = 0;  // nombre de produits actuellement en stock
int main() {
  // Initialiser le tableau products et num_products
  memset(products, 0, sizeof(products));
  num_products = 0;

  // Afficher le menu principal et g�rer les entr�es de l'utilisateur
  int choice;

  while (1) {
    // Afficher le menu
    printf("\n \n \n -------------------Stock Management System--------------------\n");
    printf("1. Ajouter un Produit\n");
    printf("2. Description d'un Produit\n");
    printf("3. Supprimer un Produit\n");
    printf("4. Modifier un Produit\n");
    printf("5. Rechercher un Produit\n");
    printf("6. Afficher l'historique des entrees et des sorties\n");
    printf("7. Afficher l'historique quotidien des entrees et des sorties\n");
    printf("8. Archiver historique\n");
    printf("9. Quitter\n");
    printf("Entrez votre choix: ");

    // Lire le choix de l'utilisateur
    scanf("%d", &choice);

    // G�rer le choix de l'utilisateur
    switch (choice) {
      case 1:
        add_product();
        break;
      case 2:
        display_product_description();
        break;
      case 3:
        delete_product();
        break;
      case 4:
        modify_product();
        break;
      case 5:
        search_product();
        break;
      case 6:
        display_history();
        break;
      case 7:
        display_daily_history();
        break;
      case 8:
        archive_history();
        break;
      case 9:
        return;  // Sortir du Programme
      default:
        printf("Invalid choice.\n");
        break;
    }
  }
}

// Fonction pour ajouter un produit au stock
void add_product() {
  // Demander � l'utilisateur les d�tails du produit
  printf("Entrez le nom du produit: ");
  scanf("%s", products[num_products].name);
  printf("Entrez une courte description du produit: ");
  scanf("%s", products[num_products].description);
  printf("Entrez la quantit� actuelle en stock: ");
  scanf("%d", &products[num_products].quantity);

  // Incrementer le nombre de produits en stock
  num_products++;
}

// Fonction pour afficher la description d'un produit
void display_product_description() {
  char name[100];

  // Demander � l'utilisateur le nom du produit
  printf("Entrez le nom du produit: ");
  scanf("%s", name);

  // Rechercher un produit avec un nom correspondant
  for (int i = 0; i < num_products; i++) {
    if (strcmp(name, products[i].name) == 0) {
      // Produit trouv�, afficher sa description
      printf("Description: %s\n", products[i].description);
      return;
    }
  }

  // Produit non trouv�
  printf("Produit introuvable.\n");
}
void delete_product() {
char name[100];

printf("Entrez le nom du produit: ");
scanf("%s", name);

// Rechercher un produit avec un nom correspondant
for (int i = 0; i < num_products; i++) {
if (strcmp(name, products[i].name) == 0) {
// Produit trouv�, supprimez-le en d�calant les produits restants dans le tableau
for (int j = i; j < num_products - 1; j++) {
products[j] = products[j + 1];
}
num_products--; // d�cr�menter le nombre de produits en stock
printf("Produit supprime avec succes.\n");
return;
}
}

// Produit non trouv�
printf("Produit introuvable.\n");
}
void modify_product() {
  char name[100];

  printf("Entrez le nom du produit: ");
  scanf("%s", name);

  for (int i = 0; i < num_products; i++) {
    if (strcmp(name, products[i].name) == 0) {
      // Produit trouv�, afficher ses informations actuelles et demander � l'utilisateur les nouveaux d�tails
      printf("Nom actuel: %s\n", products[i].name);
      printf("Entrez le nouveau nom du produit: ");
      scanf("%s", products[i].name);
      printf("Description actuelle: %s\n", products[i].description);
      printf("Entrez la nouvelle description du produit: ");
      scanf("%s", products[i].description);
      printf("Quantite actuelle: %d\n", products[i].quantity);
      printf("Saisir la nouvelle quantit� en stock: ");
      scanf("%d", &products[i].quantity);

      printf("Produit modifie avec succes\n");
      return;
    }
  }

  // Produit introuvable
  printf("Produit introuvable.\n");
}
void search_product() {
  char name[100];

  printf("Entrez le nom du produit: ");
  scanf("%s", name);

  for (int i = 0; i < num_products; i++) {
    if (strcmp(name, products[i].name) == 0) {
      // Produit trouv�, afficher ses informations
      printf("Nom: %s\n", products[i].name);
      printf("Description: %s\n", products[i].description);
      printf("la quantite en stock: %d\n", products[i].quantity);
      return;
    }
  }

  // Produit introuvable
  printf("Produit introuvable.\n");
}
void display_history() {
  char name[100];
  int month;

// Demander � l'utilisateur le nom du produit et le mois
  printf("Entrez le nom du produit: ");
  scanf("%s", name);
  printf(" Entrez le mois (1-12): ");
  scanf("%d", &month);

  // Validation de la saisie du mois
  if (month < 1 || month > 12) {
    printf("Mois invalide.\n");
    return;
  }

  for (int i = 0; i < num_products; i++) {
    if (strcmp(name, products[i].name) == 0) {
     // Produit trouv�, affiche son historique d'entr�e et de sortie pour le mois sp�cifi�
      printf("Produit: %s\n", products[i].name);
      printf("Mois: %d\n", month);
      printf("Entrees: ");
      for (int j = (month - 1) * 30; j < month * 30; j++) {
        printf("%d ", products[i].entry_history[j]);
      }
      printf("\nSorties: ");
      for (int j = (month - 1) * 30; j < month * 30; j++) {
        printf("%d ", products[i].exit_history[j]);
      }
      printf("\n");
      return;
    }
  }

  // Produit introuvable
  printf("Produit introuvable.\n");
}
void archive_history() {
  // Cr�er un nouveau tableau pour stocker les historiques archiv�s
  int archived_entry_history[MAX_PRODUCTS][30];
  int archived_exit_history[MAX_PRODUCTS][30];

  // Copiez les historiques d'entr�e et de sortie de tous les produits dans les baies archiv�es
  for (int i = 0; i < num_products; i++) {
    memcpy(archived_entry_history[i], products[i].entry_history, sizeof(products[i].entry_history));
    memcpy(archived_exit_history[i], products[i].exit_history, sizeof(products[i].exit_history));
  }

  // Clear the entry and exit histories of all products
  for (int i = 0; i < num_products; i++) {
    memset(products[i].entry_history, 0, sizeof(products[i].entry_history));
    memset(products[i].exit_history, 0, sizeof(products[i].exit_history));
  }

  // Stocker les historiques archiv�s dans un fichier
  FILE *fp = fopen("archived_histories.txt", "w");
  if (fp == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return;
  }
  for (int i = 0; i < num_products; i++) {
    fprintf(fp, "Produit: %s\n", products[i].name);
    fprintf(fp, "Historique des entrees: ");
    for (int j = 0; j < 30; j++) {
      fprintf(fp, "%d ", archived_entry_history[i][j]);
    }
    fprintf(fp, "\n Historique des sorties: ");
    for (int j = 0; j < 30; j++) {
      fprintf(fp, "%d ", archived_exit_history[i][j]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);

  printf("Historiques archives avec succes.\n");
}
void display_daily_history() {
  char name[100];

  printf("Entrez le nom du produit: ");
  scanf("%s", name);

  for (int i = 0; i < num_products; i++) {
    if (strcmp(name, products[i].name) == 0) {
      //Produit trouv�, affichez son historique d'entr�e et de sortie jour par jour
      printf("Produit: %s\n", products[i].name);
      for (int j = 0; j < 30; j++) {
        printf("Jour %d: entrees %d, sorties %d\n", j + 1, products[i].entry_history[j], products[i].exit_history[j]);
      }
      return;
    }
  }

  // Produit introuvable
  printf("Produit introuvable.\n");
}
