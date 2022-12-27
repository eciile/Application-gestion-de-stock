# Application-gestion-de-stock
C project (cmd app)
Les fonctions:

*Main()

Cette fonction affiche un menu d'options à l'utilisateur et lit son choix à 
l'aide de scanf. Il utilise ensuite une instruction switch pour gérer le choix 
de l'utilisateur en appelant la fonction correspondante. La fonction continue
d'afficher le menu et d'accepter l'entrée de l'utilisateur jusqu'à ce que 
l'utilisateur choisisse de quitter le programme.

* delete_product()

La fonction delete_product permet à l'utilisateur de supprimer un produit du 
stock en recherchant un produit avec un nom correspondant et en le supprimant 
du tableau des produits. Si le produit n'est pas trouvé, la fonction affiche 
un message indiquant que le produit n'a pas été trouvé.

*add_product()

l'utilisateur pour le nom du produit, sa description et la quantité actuelle en
 stock, et stocker ces informations dans une structure product_t. La fonction 
ajoute ensuite ce nouveau produit au tableau products et incrémente le compteur
 num_products pour refléter l'ajout du nouveau produit.

*display_product_description()

La fonction display_product_description permet à l'utilisateur d'afficher la 
description d'un produit en demandant à l'utilisateur le nom du produit et en
 recherchant dans le tableau products un produit avec un nom correspondant. 
Si un produit correspondant est trouvé, la fonction affiche la description du 
produit. Si le produit n'est pas trouvé, la fonction affiche un message 
indiquant que le produit n'a pas été trouvé.

* display_history()

Cette fonction demande à l'utilisateur le nom du produit et le mois pour 
lequel il souhaite afficher l'historique. Il recherche ensuite dans le tableau 
des produits un produit dont le nom correspond et affiche l'historique d'entrée 
et de sortie du produit pour le mois spécifié. L'historique des entrées 
et des sorties est affiché sous forme de tableaux d'entiers représentant le 
nombre d'entrées et de sorties chaque jour du mois. Si un produit avec un nom 
correspondant n'est pas trouvé, la fonction affiche un message indiquant que 
le produit n'a pas été trouvé.

Notez que cette fonction suppose que les tableaux entry_history et exit_history 
stockent une entrée ou une sortie par jour pour un total de 30 entrées ou sorties
 par mois. La fonction utilise l'entrée du mois pour calculer les indices de début
 et de fin des tableaux d'entrée et de sortie pour le mois spécifié. 
Par exemple, si l'entrée du mois est 2 (février), la fonction affichera 
les entrées et les sorties pour les 30 jours allant du 31e jour du mois 
précédent (janvier) au 28 ou 29 février, selon qu'il s'agit une année bissextile.

*search_product()

Cette fonction invite l'utilisateur à entrer le nom du produit qu'il souhaite 
rechercher, puis recherche dans le tableau des produits un produit dont le nom 
correspond. Si un produit avec un nom correspondant est trouvé, la fonction 
affiche le nom, la description et la quantité en stock du produit. Si un produit 
avec un nom correspondant n'est pas trouvé, la fonction affiche un message 
indiquant que le produit n'a pas été trouvé.

*modify_product()

Cette fonction invite l'utilisateur à entrer le nom du produit qu'il souhaite 
modifier, recherche un produit avec un nom correspondant, puis permet à 
l'utilisateur d'entrer de nouveaux détails pour le nom, la description et la 
quantité en stock du produit. Si un produit avec un nom correspondant n'est pas 
trouvé, la fonction affiche un message indiquant que le produit n'a pas été 
trouvé.

*archive_history()

Cette fonction crée deux nouveaux tableaux pour stocker les historiques d'entrée 
et de sortie archivés pour tous les produits, puis copie les historiques d'entrée
 et de sortie du tableau des produits vers les tableaux archivés. Il efface 
ensuite les historiques d'entrée et de sortie de tous les produits du tableau de 
produits en les mettant à zéro. Enfin, il stocke les historiques archivés dans 
un fichier à l'aide de fprintf, avec l'historique de chaque produit sur une 
ligne distincte.
Notez que cette fonction suppose que les tableaux entry_history et exit_history 
stockent une entrée ou une sortie par jour pour un total de 30 entrées ou sorties
 par mois. Vous pouvez modifier la fonction pour gérer différentes périodes de 
temps (par exemple, une entrée ou une sortie par semaine, par trimestre, etc.) 
en changeant la taille des tableaux archivés et les limites de boucle dans les 
appels memcpy et memset, et en changeant le format des données écrites dans le 
fichier.

* display_daily_history()

Cette fonction demande à l'utilisateur le nom du produit et recherche dans 
le tableau des produits un produit avec un nom correspondant. Si un produit
avec un nom correspondant est trouvé, la fonction affiche l'historique d'entrée
et de sortie du produit jour par jour à l'aide d'une boucle qui itère sur les 
tableaux entry_history et exit_history. Pour chaque jour, la fonction affiche le
nombre d'entrées et de sorties. Si un produit avec un nom correspondant n'est 
pas trouvé, la fonction affiche un message indiquant que le produit n'a pas été 
trouvé.
