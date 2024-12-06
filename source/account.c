#include <stdio.h>
#include <string.h>
#include "account.h"

// Fichier CSV pour stocker les comptes
#define ACCOUNT_FILE "data/accounts.csv"

// Fonction pour enregistrer un nouveau compte
void registerAccount() {
    Account account;

    printf("Numéro de compte : ");
    scanf("%s", account.account_number);

    printf("Nom : ");
    scanf("%s", account.last_name);

    printf("Prénom : ");
    scanf("%s", account.first_name);

    printf("Adresse : ");
    scanf(" %[^\n]", account.address);

    printf("Email : ");
    scanf("%s", account.email);

    printf("Téléphone : ");
    scanf("%s", account.phone);

    printf("Solde initial : ");
    scanf("%f", &account.balance);

    strcpy(account.status, "actif"); // Par défaut, le compte est actif

    // Sauvegarder le compte dans le fichier CSV
    saveAccountToCSV(&account, ACCOUNT_FILE);

    printf("Compte enregistré avec succès !\n");
}

// Fonction pour sauvegarder un compte dans le fichier CSV
void saveAccountToCSV(const Account *account, const char *filename) {
    FILE *file = fopen(filename, "a"); // Ouvre le fichier en mode ajout
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier CSV");
        return;
    }

    fprintf(file, "%s,%s,%s,%s,%s,%s,%.2f,%s\n",
            account->account_number,
            account->last_name,
            account->first_name,
            account->address,
            account->email,
            account->phone,
            account->balance,
            account->status);

    fclose(file);
}
//fonction pour afficher la liste des comptes avec les attributs demandés
#include<stdio.h>
#include<string.h>
#include"account.h"
void displayaccounts( const char *name_file[]){
    FILE*file=fopen(filename,"r");
    if(file==NULL){
            printf("erreur:impossible d'ouvrir le fichier %s \n",filename);
return ;
    } 
Account account;
printf("\n Liste des comptes enregistrés:\n");
printf("-------------------------------------------------------------------------------------------------------------------\n");
printf("Numéro de compte|Nom|Prénom|Solde|Email|Statut du compte\n");
printf("--------------------------------------------------------------------------------------------------------------------\n");
while(fscanf(file,"%19[^,],%49[^,],%49[^,],%f,%49[^,],%9[^,]\n",&account.account_number,account.last_name,account.first_name,account.adress,account.email
,account.phone,account.balance,account.status)==8){
    printf("%s|%s|%s|%8.3f|%s|%s\n",account.account_number,account.last_name,account.first_name,account.adress,account.email,account.phone,account.balance,account.status);

    printf("--------------------------------------------------------------------------------------------------------------------\n");
}
fclose(file);
}
